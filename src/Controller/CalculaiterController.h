#ifndef SRC_CONTROLLER_CALCULAITERCONTROLLER_H
#define SRC_CONTROLLER_CALCULAITERCONTROLLER_H

#include "../Model/CalculaiterModel.h"

class CalculaiterController {
private:
  CalculaiterModel *model;

public:
  CalculaiterController(CalculaiterModel *m) : model(m){};
  double add(double a);
  double sub(double a);
  double mult(double a);
  double div(double a);
  void reset();
};

#endif // SRC_CONTROLLER_CALCULAITERCONTROLLER_H