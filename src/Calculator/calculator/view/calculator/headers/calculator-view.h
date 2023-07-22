#ifndef CALCULATORVIEW_H
#define CALCULATORVIEW_H

#include "../Calculator/calculator/controller/headers/calculator-controller.h"
#include <QMainWindow>
#include <QByteArray>
#include <QDialog>
#include <QMessageBox>
#include <list>
#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QWidget>
#include <cctype>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculationView;
class CreditView;
class DepositCalculationView;
} // namespace Ui
QT_END_NAMESPACE

namespace s21 {
#define OK 0

class CreditView : public QDialog {
    Q_OBJECT
public:
  CreditView(QWidget *parent = nullptr, CalculatorController *controller = nullptr);
  ~CreditView();

private:
  Ui::CreditView *ui_credit;
  CalculatorController *common_controller;

private slots:
  void calculationCredit();
  void on_pushButton_closecredit_clicked();
  void on_pushButton_12_clicked();
};

class DepositCalculationView {
public:
  DepositCalculationView(QWidget *parent = nullptr, CalculatorController *controller = nullptr);
  ~DepositCalculationView();

private:
  Ui::DepositCalculationView *ui_deposit;
  CalculatorController *common_controller;
};

class CalculationView : public QMainWindow {
  Q_OBJECT
public:
  CalculationView(QWidget *parent = nullptr);
  ~CalculationView();

private:
  Ui::CalculationView *ui_calculation;
  CalculatorController *common_controller;

  QVector<double> x;
  QVector<double> y;
  double xBegin, xEnd, yBegin, yEnd, h;

private slots:
  void bttn_pressed();
  void function_pressed();
  void constant_pressed();
  void operators_pressed();
  void on_pushButton_AC_clicked();
  void on_pushButton_eq_clicked();
  void on_pushButton_back_clicked();
  void on_pushButton_close_clicked();
  void on_pushButton_credit_clicked();
  int on_pushButton_graf_clicked();
};


} // namespace s21

#endif // CALCULATORVIEW_H
