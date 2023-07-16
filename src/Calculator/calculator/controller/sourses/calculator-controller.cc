#include "../headers/calculator-controller.h"

#include <stdio.h>

#include <QDebug>

namespace s21 {

double CalculatorController::calculatorAction(const QString *str_action) {
  double res;
  try {
    CalculatorModel::Calculation *calc = new CalculatorModel::Calculation();

    res = calc->calculate(str_action);

  } catch (std::exception &e) {
    throw e;
  }
  return res;
};

};  // namespace s21
