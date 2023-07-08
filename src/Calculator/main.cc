#include "calculator/controller/headers/calculator-controller.h"
#include "calculator/view/calculator/headers/calculator-view.h"
#include "common/model/calculator/headers/calculator-model.h"

#include <QApplication>

using namespace s21;

int main(int argc, char *argv[]) {
//  QApplication a(argc, argv);
//  CalculatorView w;

//  w.show();
//  return a.exec();

    CalculatorModel::CreditCalculation::Annuity test;
    QString total_loan_amount = "100000";
    QString period = "12";
    QString interest_rate = "8";
    test.calculate(total_loan_amount, period, interest_rate);

    QString res;
}
