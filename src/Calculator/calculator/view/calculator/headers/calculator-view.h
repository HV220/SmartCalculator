#ifndef CALCULATORVIEW_H
#define CALCULATORVIEW_H

#include "../Calculator/calculator/controller/headers/calculator-controller.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculationView;
class CreditCalculationView;
class DepositCalculationView;
} // namespace Ui
QT_END_NAMESPACE

namespace s21 {

class CalculationView : public QMainWindow {
  Q_OBJECT
public:
  CalculationView(QWidget *parent = nullptr);
  ~CalculationView();

private:
  Ui::CalculationView *ui_calculation;

private slots:
  void function_pressed();
  void constant_pressed();
  void on_pushButton_AC_clicked();
  void on_pushButton_eq_clicked();
  void on_pushButton_dot_clicked();
  void on_pushButton_dot_coma_clicked();
  void on_pushButton_back_clicked();
  void on_pushButton_close_clicked();
  void on_pushButton_credit_clicked();
  int on_pushButton_graf_clicked();
  void draw_axis();
  void on_pushButton_deposit_clicked();
};

class CreditCalculationView {
public:
  CreditCalculationView(QWidget *parent = nullptr);
  ~CreditCalculationView();

private:
  Ui::CreditCalculationView *ui_credit;
};

class DepositCalculationView {
public:
  DepositCalculationView(QWidget *parent = nullptr);
  ~DepositCalculationView();

private:
  Ui::DepositCalculationView *ui_deposit;
};

} // namespace s21

#endif // CALCULATORVIEW_H
