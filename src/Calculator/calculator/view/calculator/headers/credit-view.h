#ifndef CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_CALCULATOR_VIEW_CALCULATOR_HEADERS_CREDIT_VIEW_H_
#define CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_CALCULATOR_VIEW_CALCULATOR_HEADERS_CREDIT_VIEW_H_

#include <QByteArray>
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QVector>
#include <QWidget>
#include <cctype>
#include <cmath>
#include <list>

#include "../Calculator/calculator/controller/headers/calculator-controller.h"
#include "main-view.h"
#include "ui_credit.h"

namespace s21 {
class CreditView : public QDialog {
  Q_OBJECT
 public:
  CreditView(QWidget *parent);
  ~CreditView();

  void start(s21::CalculatorController *controller);

 private:
  Ui::CreditView *ui_credit_;
  s21::CalculatorController *controller_;

 private slots:
  void calculationCredit(bool Annuity = true);
  void on_pushButton_closecredit_clicked();
  void on_pushButton_12_clicked();
};
};  // namespace s21

#endif  // CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_CALCULATOR_VIEW_CALCULATOR_HEADERS_CREDIT_VIEW_H_
