#include "../headers/calculator-view.h"
#include "ui_main.h"

namespace s21 {

CalculationView::CalculationView(QWidget *parent)
    : QMainWindow(parent), ui_calculation(new Ui::CalculationView) {
  ui_calculation->setupUi(this);
}

CalculationView::~CalculationView() { delete ui_calculation; }

void s21::CalculationView::function_pressed() {}

void s21::CalculationView::constant_pressed() {}

void s21::CalculationView::on_pushButton_AC_clicked() {}

void s21::CalculationView::on_pushButton_eq_clicked() {}

void s21::CalculationView::on_pushButton_dot_clicked() {}

void s21::CalculationView::on_pushButton_dot_coma_clicked() {}

void s21::CalculationView::on_pushButton_back_clicked() {}

void s21::CalculationView::on_pushButton_close_clicked() {}

void s21::CalculationView::on_pushButton_credit_clicked() {}

int s21::CalculationView::on_pushButton_graf_clicked() { return 0; }

void s21::CalculationView::draw_axis() {}

void s21::CalculationView::on_pushButton_deposit_clicked() {}

}; // namespace s21
