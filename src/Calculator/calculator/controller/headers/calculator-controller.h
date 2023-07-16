#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "../Calculator/common/model/calculator/headers/calculator-model.h"

namespace s21 {
class CalculatorController {
 private:
  CalculatorModel *model;

 public:
  double calculatorAction(const QString *str_action);
  void creditCalculatorAction();
  void depositCalculatorAction();
  void graficCalculatorAction();
};
}  // namespace s21

#endif  // CALCULATORCONTROLLER_H
