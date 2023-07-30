#ifndef CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_CALCULATOR_VIEW_CALCULATOR_HEADERS_CALCULATOR_VIEW_H_
#define CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_CALCULATOR_VIEW_CALCULATOR_HEADERS_CALCULATOR_VIEW_H_

#include <QButtonGroup>
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
#include "common/helpers/qcustomplot.h"
#include "main-view.h"
#include "ui_credit.h"
#include "ui_main.h"

namespace s21 {
#define OK 0

class CalculationView : public QMainWindow {
  Q_OBJECT
 public:
  CalculationView(QWidget* parent = nullptr);
  ~CalculationView();
  CalculatorController* controller;
  void start(CalculatorController* controller);

 private slots:
  void bttn_pressed(int);
  void function_pressed(int);
  void constant_pressed();
  void operators_pressed(int);
  void on_pushButton_AC_clicked();
  void on_pushButton_eq_clicked();
  void on_pushButton_back_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_graf_clicked();

 private:
  void graf_logic();
  void change_group_bttn(QButtonGroup* group);
  bool graf_validate_data();
  void graf_error_messages(int checker);
  QButtonGroup* first_group = new QButtonGroup(this);
  QButtonGroup* second_group = new QButtonGroup(this);
  QButtonGroup* third_group = new QButtonGroup(this);
  Ui::CalculationView* ui_calculation_;
  QVector<double> x_;
  QVector<double> y_;
  double xBegin_ = -10;
  double xEnd_ = 10;
  double yBegin_ = -10;
  double yEnd_ = 10;
  double h_;
  int Count_points = 500;
};

};  // namespace s21

#endif  // CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_CALCULATOR_VIEW_CALCULATOR_HEADERS_CALCULATOR_VIEW_H_
