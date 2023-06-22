#include "calculator/controller/headers/calculator-controller.h"

#include "common/model/calculator/headers/calculator-model.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  CalculatorModel *test = new CalculatorModel();
  CalculatorModel::Calculation *tmp =
      new CalculatorModel::Calculation("(-1+2-3)-4-5-6");
  tmp->validateExpression();
  tmp->calculate();
  test->setLastCalculation(*tmp);

  QApplication a(argc, argv);
  CalculatorController w;
  w.show();
  return a.exec();
}
