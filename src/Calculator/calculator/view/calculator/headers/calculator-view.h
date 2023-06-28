#ifndef CALCULATORVIEW_H
#define CALCULATORVIEW_H

#include <QMainWindow>
#include "../Calculator/calculator/controller/headers/calculator-controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculatorView;
}
QT_END_NAMESPACE

namespace s21 {
class CalculatorView : public QMainWindow {
  Q_OBJECT

public:
  CalculatorController controller;
  CalculatorView(QWidget *parent = nullptr);
  ~CalculatorView();

private:
  Ui::CalculatorView *ui;
};
}

#endif // CALCULATORVIEW_H
