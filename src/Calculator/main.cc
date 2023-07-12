#include "calculator/controller/headers/calculator-controller.h"
#include "calculator/view/calculator/headers/calculator-view.h"
#include "common/model/calculator/headers/calculator-model.h"

#include <QApplication>

using namespace s21;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  CalculationView w;
  w.show();
  return a.exec();

//struct CalculatorModel::DepositCalculation::InputData Data;

//QString deposit_amount;
//QString placement_term;
//QString interest_rate;
//QString tax_rate;
//QString payment_frequency;
//QString interest_capitalization;
//int status_capitalisation;

//Data.setDepositAmount("50000");
//Data.setPlacementTerm("365");
//Data.setInterestRate("4.7");
//Data.setTaxRate("1");
//Data.setPaymentFrequency("1");
//Data.setStatusCapitalisation(0);

//    QString res;
}

//    сумма вклада
//    срок размещения
//    процентная ставка
//    налоговая ставка 13 процентов, если больше 12.5 процентов
//    периодичность выплат: 1 раз в год
//    капитализация процентов: 1 раз в год
//    список пополнений: 1 раз в год
//    список частичных снятий: 1 раз в год
