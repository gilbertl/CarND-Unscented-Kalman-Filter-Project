#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truths) {
  VectorXd rmse(4);
  rmse << 0,0,0,0;

  //accumulate squared residuals
  int n = 0;
  for(int i=0; i < estimations.size(); ++i){
      VectorXd estimation = estimations[i];
      VectorXd ground_truth = ground_truths[i];
      if (estimation.size() == 0) {
          continue;
      }
      if (ground_truth.size() != estimation.size()) {
          continue;
      }
      VectorXd diff = estimation - ground_truth;
      VectorXd diff2 = diff.array() * diff.array();
      rmse += diff2;
      n += 1;
  }
  rmse /= n;
  rmse = rmse.array().sqrt();

  return rmse;
}
