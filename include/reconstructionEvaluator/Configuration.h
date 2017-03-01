/*
 * Configuration.h
 *
 *  Created on: Dec 13, 2016
 *      Author: andrea
 */

#ifndef SRC_CONFIGURATION_H_
#define SRC_CONFIGURATION_H_

#include <string>
#include <vector>
#include <fstream>
#include <types.hpp>

namespace reconstructorEvaluator {

class Configuration {
public:
  Configuration(const std::string &path);
  Configuration();
  virtual ~Configuration();
  void setConfiguration(const std::string &path);
  void parse();

  const std::vector<CameraType>& getCameras() const {
    return cameras_;
  }

  const std::vector<int>& getCamerasIdx() const {
    return camerasIdx_;
  }

  const std::string& getMeshPath() const {
    return meshPath_;
  }

  const std::string& getOuputFilename() const {
    return ouputFilename_;
  }

  const std::string& getGtPath() const {
    return gtPath_;
  }

  const std::vector<CameraType>& getCamerasGt() const {
    return camerasGt_;
  }

  const int & getInitFrame() const {
    return initFrame_;
  }

  const int& getLastFrame() const {
    return lastFrame_;
  }

  const int& getStep() const {
    return step_;
  }

private:
  std::ifstream file_;
  bool parseWhichCams(const std::string &path);

  std::string meshPath_;
  std::string ouputFilename_;
  std::string gtPath_;
  std::vector<CameraType> cameras_;
  std::vector<CameraType> camerasGt_;
  std::vector<int> camerasIdx_;
  int initFrame_;
  int lastFrame_;
  int step_;

};

} /* namespace reconstructorEvaluator */

#endif /* SRC_CONFIGURATION_H_ */
