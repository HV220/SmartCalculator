#ifndef CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_CALCULATOR_CONTROLLER_HEADERS_CALCULATOR_CONTROLLER_H_
#define CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_CALCULATOR_CONTROLLER_HEADERS_CALCULATOR_CONTROLLER_H_

#include <QString>
#include <vector>

#include "../Calculator/common/model/calculator/headers/calculator-model.h"

namespace s21 {
class CalculatorController {
 public:
  CalculatorController(CalculatorModel *model) { this->model = model; }

  s21::CalculatorModel *model;

  double calculatorAction(const QString &str_action);

  std::map<std::string, std::vector<double>> creditCalculatorAction(
      const QString &total_loan_amount, const QString &period,
      const QString &interest_ratebool, bool isAnnuityType = true);
};
};  // namespace s21

#endif  // CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_CALCULATOR_CONTROLLER_HEADERS_CALCULATOR_CONTROLLER_H_
