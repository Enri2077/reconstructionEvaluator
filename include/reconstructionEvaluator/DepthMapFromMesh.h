/*
 * DepthMapFromMesh.h
 *
 *  Created on: Dec 14, 2016
 *      Author: andrea
 */

#ifndef SRC_DEPTHMAPFROMMESH_H_
#define SRC_DEPTHMAPFROMMESH_H_

#include <types.hpp>
#include <CImg/CImg.h>
namespace reconstructorEvaluator {

typedef Kernel::Ray_3 Ray;
class DepthMapFromMesh {
public:
  DepthMapFromMesh(Polyhedron *mesh);
  virtual ~DepthMapFromMesh();

  void setMeshGt(Polyhedron*& mesh) {
    mesh_ = mesh;

    std::cout << "mesh_->size_of_vertices(): " << mesh_->size_of_vertices() << std::endl << std::endl << std::endl << std::endl;
  }

  cimg_library::CImg<float> computeMap(const CameraType &cam,int nnum=0, std::string filname = "");

//  const cimg_library::CImg<float>& getDepth() const {
//    return depth;
//  }

private:

  void computeRayFromCurCam(const float & x, const float &y, glm::vec3 &ray);

  void printRays(const std::vector<Ray> &rays, int num);

  Polyhedron *mesh_;
  CameraType curCam;
//  cimg_library::CImg<float> depth_;
};

} /* namespace reconstructorEvaluator */

#endif /* SRC_DEPTHMAPFROMMESH_H_ */
