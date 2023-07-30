#include "../headers/calculator-controller.h"

#include <stdio.h>

namespace s21 {

double CalculatorController::calculatorAction(const QString &str_action) {
  try {
    std::string tmp = str_action.toStdString();

    double res = model->calculator.calculate(tmp);

    return res;
  } catch (std::exception &e) {
    throw e;
  }
};

std::map<std::string, std::vector<double>>
CalculatorController::creditCalculatorAction(const QString &total_loan_amount,
                                             const QString &period,
                                             const QString &interest_rate,
                                             bool isAnnuityType) {
  try {
    if (isAnnuityType)
      return model->credit_calculator_annuity.calculate(
          total_loan_amount.toStdString(), period.toStdString(),
          interest_rate.toStdString());

    return model->credit_calculator_diff.calculate(
        total_loan_amount.toStdString(), period.toStdString(),
        interest_rate.toStdString());
  } catch (std::exception &e) {
    throw e;
  }
};

};  // namespace s21
