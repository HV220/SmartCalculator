#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include <vector>
#include <QString>

#include "../Calculator/common/model/calculator/headers/calculator-model.h"

namespace s21 {
class CalculatorController {
 private:
  CalculatorModel *model;

 public:
  double calculatorAction(const QString &str_action);

  std::map<std::string, std::vector<double>> creditCalculatorAction(
      const QString &total_loan_amount, const QString &period,
      const QString &interest_ratebool, bool isAnnuityType = true);
};
}  // namespace s21

#endif  // CALCULATORCONTROLLER_H
