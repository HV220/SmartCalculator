#ifndef SRC_MODEL_CALCULAITERMODEL_H
#define SRC_MODEL_CALCULAITERMODEL_H

class CalculaiterModel {
private:
  double data;

public:
  CalculaiterModel() : data(0){};
  void add(double a);
  void mult(double a);
  void reset();
  double getData();
};

#endif // SRC_MODEL_CALCULAITERMODEL_H