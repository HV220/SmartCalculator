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
class CreditCalculationView;
class DepositCalculationView;
} // namespace Ui
QT_END_NAMESPACE

namespace s21 {
#define OK 0

class CalculationView : public QMainWindow {
  Q_OBJECT
public:
  CalculationView(QWidget *parent = nullptr);
  ~CalculationView();

private:
  Ui::CalculationView *ui_calculation;
  Ui::CreditCalculationView *ui_credit;
  Ui::DepositCalculationView *ui_deposit;
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
  void draw_axis();
  void on_pushButton_deposit_clicked();
};

class CreditCalculationView {
public:
  CreditCalculationView(QWidget *parent = nullptr, CalculatorController *controller = nullptr);
  ~CreditCalculationView();

private:
  Ui::CreditCalculationView *ui_credit;
};

class DepositCalculationView {
public:
  DepositCalculationView(QWidget *parent = nullptr, CalculatorController *controller = nullptr);
  ~DepositCalculationView();

private:
  Ui::DepositCalculationView *ui_deposit;
};

} // namespace s21

#endif // CALCULATORVIEW_H
