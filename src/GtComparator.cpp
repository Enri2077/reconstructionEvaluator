/*
 * GtComparator.cpp
 *
 *  Created on: Dec 13, 2016
 *      Author: andrea
 */

#include <GtComparator.h>
#include <Polyhedron_AssimpToCgal.h>
#include <assimp/Importer.hpp>  // OO version Header!
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <DepthMapFromMesh.h>
#include <DepthFromVelodyne.h>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <utilities.hpp>
#include <CImg/CImg.h>

namespace reconstructorEvaluator {

typedef Polyhedron::HalfedgeDS HalfedgeDS;
GtComparator::GtComparator(const std::string& path) {
  configuration_.setConfiguration(path);
  configuration_.parse();
  scale_ = 1.0;
  countImages_ = 0;
}

GtComparator::~GtComparator() {

}

void GtComparator::run() {
  registerCameras();

  //importGT();
  //importMesh();
  std::ifstream file(configuration_.getMeshPath());
  file >> meshToBeCompared_;

//  std::cout << "GtComparator:: writing mesh...";
//  std::cout.flush();
//  std::ofstream fileTest1("testMesh.off");
//  fileTest1 << meshToBeCompared_;
//  std::cout << "DONE." << std::endl;

//  std::cout<<"GtComparator:: writing mesh gt...";
//  std::cout.flush();
//  std::ofstream fileTest2("testGT.off");
//  fileTest2 << meshGt_;
//  std::cout<<"DONE."<<std::endl;

  for (int curFrame = configuration_.getInitFrame(); curFrame < configuration_.getLastFrame(); curFrame += configuration_.getStep()) {
    std::cout << "GtComparator:: collecting errors frame num " << curFrame << std::endl;
    std::cout.flush();

    DepthMapFromMesh dmfm(&meshToBeCompared_);
//    dmfm.computeMap(configuration_.getCameras()[curFrame], curFrame, configuration_.getOuputFilename());
    DepthFromVelodyne frv(configuration_.getGtPath(), configuration_.getCameras()[0].imageHeight, configuration_.getCameras()[0].imageWidth);

    frv.createDepthFromIdx(curFrame+1);

    std::cout << "GtComparator::computeMap" << std::endl;
    cimg_library::CImg<float> meshDepthMap = dmfm.computeMap(configuration_.getCameras()[curFrame], curFrame, configuration_.getOuputFilename());

    accumulateDepthMaps(frv.getDepth(), meshDepthMap);
    countImages_++;
    std::cout << "DONE." << std::endl;
  }

  compareDepthMaps();
  printComparison();
}

void GtComparator::importGT() {

  Assimp::Importer importer;

  std::cout << "GtComparator::importGT importing...";
  std::cout.flush();
  const aiScene* scene = importer.ReadFile(configuration_.getGtPath(), aiProcess_Triangulate | aiProcess_JoinIdenticalVertices);
  std::cout << "DONE." << std::endl;

  aiMesh* mesh = scene->mMeshes[0];

  std::cout << "GtComparator::poly_builderGT importing...";
  std::cout.flush();
  MeshBuilder<HalfedgeDS> poly_builder(mesh);
  meshGt_.delegate(poly_builder);
  std::cout << "DONE." << std::endl;

}

void GtComparator::importMesh() {

  Assimp::Importer importer;

  std::cout << "GtComparator::importMesh importing...";
  std::cout.flush();
  const aiScene* scene = importer.ReadFile(configuration_.getMeshPath(), aiProcess_Triangulate | aiProcess_JoinIdenticalVertices);
  std::cout << "DONE." << std::endl;

  aiMesh* mesh = scene->mMeshes[0];

  std::cout << "GtComparator::poly_builder importing...";
  std::cout.flush();
  MeshBuilder<HalfedgeDS> poly_builder(mesh);
  meshToBeCompared_.delegate(poly_builder);
  std::cout << "DONE." << std::endl;
}

void GtComparator::compareDepthMaps(const std::vector<cimg_library::CImg<float>> &depthGTVec, const std::vector<cimg_library::CImg<float>> &depthVec) {
  if (depthGTVec.size() != depthVec.size()) {
    std::cout << " compareDepthMaps error the two vectors have different dimensions" << std::endl;
    return;
  }

  for (int curFrame = 0; curFrame < depthGTVec.size(); ++curFrame) {
    cimg_library::CImg<float> depthGT = depthGTVec[curFrame];
    cimg_library::CImg<float> depth = depthVec[curFrame];
    accumulateDepthMaps(depthGT, depth);

  }
  compareDepthMaps();
}

void GtComparator::compareDepthMaps() {

  float sum = std::accumulate(res.errs_.begin(), res.errs_.end(), 0.0);

  std::vector<float> sqrVec;
  std::transform(res.errs_.begin(), res.errs_.end(), std::back_inserter(sqrVec), [](int n) {return std::pow(n,2);});
  float sumSqr = std::accumulate(sqrVec.begin(), sqrVec.end(), 0.0);
  std::vector<float> absVec;
  std::transform(res.errs_.begin(), res.errs_.end(), std::back_inserter(absVec), [](int n) {return std::fabs(n);});
  float sumAbs = std::accumulate(absVec.begin(), absVec.end(), 0.0);

  res.mean = sum / res.errs_.size();
  res.rmse = std::sqrt(sumSqr/ res.errs_.size()) ;
  res.mae = sumAbs / res.errs_.size();

  std::vector<double> diff(res.errs_.size());
  std::transform(res.errs_.begin(), res.errs_.end(), diff.begin(), std::bind2nd(std::minus<double>(), res.mean));
  double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
  res.stddev = std::sqrt(sq_sum / res.errs_.size());
}

void GtComparator::accumulateDepthMaps(const cimg_library::CImg<float>& depthGT, const cimg_library::CImg<float>& depth) {

  cimg_library::CImg<float> depthErrrr = cimg_library::CImg<float>(depthGT.width(), depth.height());

  depthErrrr.fill(-1.0);
  if (depthGT._width != depth._width || depthGT._height != depth._height) {
    std::cout << " compareDepthMaps error the two depth maps have different dimensions" << std::endl;
    return;
  }

  for (int x = 0; x < depthGT._width; ++x) {
    for (int y = 0; y < depthGT._height; ++y) {
      if (depth(x, y) > 0.0 && depthGT(x, y) > 0.0) {
        res.errs_.push_back((scale_ * depth(x, y) - depthGT(x, y)));

        depthErrrr(x, y) = std::fabs((scale_ * depth(x, y) - depthGT(x, y)));
      }
    }
  }
  depthErrrr.normalize(0, 255);
  depthErrrr.save_png("err.png");
}

void GtComparator::registerCameras() {
  if (configuration_.getCameras().size() <= 3 || configuration_.getCamerasGt().size() <= 3) {
    std::cout << "GtComparator::registerCameras not enough cameras to estimate the rototranslation" << std::endl;
  }
  /*find rototrasl*/

  glm::vec3 accumulator = glm::vec3(0.0), accumulatorGt = glm::vec3(0.0);
  float count = 0;
  /*centroid cameras*/
  for (int curCam = 0;
      curCam
          < (configuration_.getCameras().size() < configuration_.getCamerasGt().size() ?
              configuration_.getCameras().size() : configuration_.getCamerasGt().size()); curCam++) {
    accumulator = accumulator + configuration_.getCameras()[curCam].center;
    accumulatorGt = accumulatorGt + configuration_.getCamerasGt()[curCam].center;
    count = count + 1.0;
  }
  std::vector<glm::vec3> newCenters, newCentersGt;

  glm::vec3 centroid = accumulator / count;
  glm::vec3 centroidGt = accumulatorGt / count;

  Eigen::Matrix4f M;
  M.setZero(4, 4);
  for (int curCam = 0;
      curCam
          < (configuration_.getCameras().size() < configuration_.getCamerasGt().size() ?
              configuration_.getCameras().size() : configuration_.getCamerasGt().size()); curCam++) {

    glm::vec3 curPt = configuration_.getCameras()[curCam].center - centroid;
    newCenters.push_back(curPt);
    glm::vec4 a = glm::vec4(0.0, curPt[0], curPt[1], curPt[2]);

    Eigen::Matrix4f Ma;
    Ma << a[0], -a[1], -a[2], -a[3],  //
    a[1], a[0], a[3], -a[2],  //
    a[2], -a[3], a[0], a[1], //
    a[3], a[2], -a[1], a[0];

    curPt = configuration_.getCamerasGt()[curCam].center - centroidGt;
    newCentersGt.push_back(curPt);
    glm::vec4 b = glm::vec4(0.0, curPt[0], curPt[1], curPt[2]);
    Eigen::Matrix4f Mb;
    Mb << b[0], -b[1], -b[2], -b[3],  //
    b[1], b[0], -b[3], b[2],  //
    b[2], b[3], b[0], -b[1], //
    b[3], -b[2], b[1], b[0];

    M = M + Ma.transpose() * Mb;

//    std::cout << "M: " << M << std::endl;
//    std::cout << "Ma: " << Ma << std::endl;
//    std::cout << "Mb: " << Mb << std::endl;

//    utilities::printMatrix(" configuration_.getCamerasGt()[curCam].center", configuration_.getCamerasGt()[curCam].center);
//    utilities::printMatrix("centroidGt",centroidGt);
//    utilities::printMatrix("curPt",curPt);
  }

  Eigen::Matrix4f ris;
  Eigen::EigenSolver<Eigen::Matrix4f> ges(M);

  Eigen::Matrix4f eig = ges.pseudoEigenvectors();

  int idx = 0;
  float maxeig = -1000000;
  for (int curR = 0; curR < 4; curR++) {
    if (ges.pseudoEigenvalueMatrix()(curR, curR) > maxeig) {
      maxeig = (float) ges.pseudoEigenvalueMatrix()(curR, curR);
      idx = curR;
    }
  }

  Eigen::Vector4f e = eig.col(idx);
  Eigen::Matrix4f M0;
  M0 << e[0], -e[1], -e[2], -e[3], //
  e[1], e[0], e[3], -e[2], //
  e[2], -e[3], e[0], e[1], //
  e[3], e[2], -e[1], e[0];
  Eigen::Matrix4f M1;
  M1 << e[0], -e[1], -e[2], -e[3], //
  e[1], e[0], -e[3], e[2], //
  e[2], e[3], e[0], -e[1], //
  e[3], -e[2], e[1], e[0];

  Eigen::Matrix4f R = M0.transpose() * M1;

//  std::cout << "M1: " << M1 << std::endl;
//  std::cout << "M0: " << M0 << std::endl;
//  std::cout << "M: " << M << std::endl;
//  std::cout << "eig: " << eig << std::endl;
//  std::cout << "vvv: " << ges.pseudoEigenvalueMatrix() << std::endl;
//  std::cout << "e: " << e << std::endl;

  Rsub = R.block<3, 3>(1, 1);

  float a = 0, b = 0;
  for (int curCam = 0; curCam < (newCenters.size()); curCam++) {

    glm::vec3 curPt = newCenters[curCam];
    glm::vec3 curPtGt = newCentersGt[curCam];
    Eigen::Vector3f va, vb;
    va << curPt[0], curPt[1], curPt[2];
    vb << curPtGt[0], curPtGt[1], curPtGt[2];

    a = a + (vb.transpose() * Rsub * va)[0];
    b = b + (vb.transpose() * vb)[0];
    //          a = a + Bn(:,i)'*R*An(:,i);
    //          b = b + Bn(:,i)'*Bn(:,i);
  }
  scale_ = b / a;

//  std::cout << "b: " << b << std::endl;
//  std::cout << "a: " << a << std::endl;

  Eigen::Vector3f centroidGtEig(centroidGt[0], centroidGt[1], centroidGt[2]);
  Eigen::Vector3f centroidEig(centroid[0], centroid[1], centroid[2]);

  //%Compute the final translation
  T = centroidGtEig - scale_ * Rsub * centroidEig;

//  std::cout << "centroidEig: " << centroidEig << std::endl;
//  std::cout << "centroidGtEig: " << centroidGtEig << std::endl;
  std::cout << "R: " << Rsub << std::endl;
  std::cout << "T: " << T << std::endl;
  std::cout << "s: " << scale_ << std::endl;

//  std::ofstream file1("centroid.txt");
//  std::ofstream file2("centroidGT.txt");
//  std::ofstream file3("centroidTransf.txt");
//  for (int curCam = 0;
//      curCam
//          < (configuration_.getCameras().size() < configuration_.getCamerasGt().size() ?
//              configuration_.getCameras().size() : configuration_.getCamerasGt().size()); curCam++) {
//    CameraType c = configuration_.getCameras()[curCam];
//    file1 << c.center[0] << " " << c.center[1] << " " << c.center[2] << " " << std::endl;
//  }
//  for (int curCam = 0;
//      curCam
//          < (configuration_.getCameras().size() < configuration_.getCamerasGt().size() ?
//              configuration_.getCameras().size() : configuration_.getCamerasGt().size()); curCam++) {
//    CameraType c = configuration_.getCamerasGt()[curCam];
//    file2 << c.center[0] << " " << c.center[1] << " " << c.center[2] << " " << std::endl;
//  }
//  for (int curCam = 0;
//      curCam
//          < (configuration_.getCameras().size() < configuration_.getCamerasGt().size() ?
//              configuration_.getCameras().size() : configuration_.getCamerasGt().size()); curCam++) {
//
//    CameraType c = configuration_.getCameras()[curCam];
//    Eigen::Vector3f va, f;
//    va << c.center[0], c.center[1], c.center[2];
//    f = scale_ * Rsub * va + T;
//
//    file3 << f[0] << " " << f[1] << " " << f[2] << " " << std::endl;
//  }
//  file1.close();
//  file2.close();
//  file3.close();
}

void GtComparator::printComparison() {

  std::cout << "Error statistics: " << std::endl;
  std::cout << "mean: " << res.mean << " stddev: " << res.stddev << std::endl;
  std::cout << "RMSE: " << res.rmse << " mae: " << res.mae << std::endl;

  float maxEl = *std::max_element(res.errs_.begin(), res.errs_.end());
  float minEl = *std::min_element(res.errs_.begin(), res.errs_.end());
  const float binSize = 0.2;
  int numBin = min(11, (int) ceil((maxEl - minEl) / binSize)); // requires <cmath>
  std::vector<int> histError(numBin, 0);

  for (auto e : res.errs_) {
    int bucket = (int) floor(fabs(e) / binSize);

    histError[bucket < numBin ? bucket : numBin - 1] += 1;
  }

  int totNum = std::accumulate(histError.begin(), histError.end(), 0);

  std::cout << "Errors histogram \tnumBin: " << numBin << "\tminEl: " << minEl << "\tmaxEl: " << maxEl << std::endl;
  std::cout << "Errors histogram (%): " << std::endl;
  for (auto c : histError) {
    std::cout << setfill(' ') << setw(10) << std::fixed << std::setprecision(1);
    std::cout << 100.0 * static_cast<float>(c) / totNum << " ";
  }
  std::cout << std::endl;
  std::cout << "Errors histogram: (num)" << std::endl;
  for (auto c : histError) {
    std::cout << setfill(' ') << setw(10) << std::fixed << std::setprecision(1);
    std::cout << c << " ";
  }
  std::cout << std::endl;


  std::ofstream f;
  f.open(configuration_.getOuputFilename().c_str());
  f << fixed;

  f << "Error statistics: " << std::endl;
  f << "mean: " << res.mean << std::endl;
  f << "stddev: " << res.stddev << std::endl;
  f << "RMSE: " << res.rmse << std::endl;
  f << "mae: " << res.mae << std::endl;

  f << "Errors histogram \tnumBin: " << numBin << "\tminEl: " << minEl << "\tmaxEl: " << maxEl << std::endl;
  f << "Errors histogram (%): " << std::endl;
  for (auto c : histError) {
    f << setfill(' ') << setw(10) << std::fixed << std::setprecision(1);
    f << 100.0 * static_cast<float>(c) / totNum << " ";
  }
  f << std::endl;
  f << "Errors histogram: (num)" << std::endl;
  for (auto c : histError) {
    f << setfill(' ') << setw(10) << std::fixed << std::setprecision(1);
    f << c << " ";
  }
  f << std::endl;
  f.close();

}

} /* namespace reconstructorEvaluator */
