#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "../Calculator/common/model/calculator/headers/calculator-model.h"

namespace s21 {
class CalculatorController {
private:
CalculatorModel model;
public:
void calculatorAction();
void creditCalculatorAction();
void depositCalculatorAction();
void graficCalculatorAction();
};
}

#endif // CALCULATORCONTROLLER_H
