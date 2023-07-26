#include "calculator/controller/headers/calculator-controller.h"
#include "calculator/view/calculator/headers/calculator-view.h"
#include "common/model/calculator/headers/calculator-model.h"

#include <QApplication>

using namespace s21;

int main(int argc, char *argv[]) {

    s21::CalculatorModel::Calculation q = s21::CalculatorModel::Calculation();
    std::string str = "1+51//";

    q.calculate(str);
//  QApplication a(argc, argv);
//  CalculationView w;
//  w.show();
//  return a.exec();
}
