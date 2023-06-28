#include "../headers/calculator-view.h"
#include "ui_main.h"

namespace s21 {

CalculatorView::CalculatorView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalculatorView) {
  ui->setupUi(this);
}

CalculatorView::~CalculatorView() { delete ui; }

};
