#include "../headers/calculator-controller.h"

#include <stdio.h>

namespace s21 {

double CalculatorController::calculatorAction(const QString &str_action) {
  try {
    std::string tmp = str_action.toStdString();
    CalculatorModel::Calculation *calc = new CalculatorModel::Calculation();

    double res = calc->calculate(tmp);

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
  if (isAnnuityType) {
    CalculatorModel::CreditCalculation::Annuity *res =
        new CalculatorModel::CreditCalculation::Annuity();
    return res->calculate(total_loan_amount.toStdString(), period.toStdString(),
                          interest_rate.toStdString());
  } else {
    CalculatorModel::CreditCalculation::Differential *res =
        new CalculatorModel::CreditCalculation::Differential();
    return res->calculate(total_loan_amount.toStdString(), period.toStdString(),
                          interest_rate.toStdString());
  }
};

};  // namespace s21
