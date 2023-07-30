#include "../headers/calculator-view.h"

namespace s21 {

// Begin View CalculationView

CalculationView::CalculationView(QWidget *parent)
    : QMainWindow(parent), ui_calculation_(new Ui::CalculationView) {
  ui_calculation_->setupUi(this);
  setWindowTitle("Calculator");

  first_group->addButton(ui_calculation_->pushButton_dot);
  first_group->addButton(ui_calculation_->pushButton_X);
  first_group->addButton(ui_calculation_->pushButton_01);
  first_group->addButton(ui_calculation_->pushButton_02);
  first_group->addButton(ui_calculation_->pushButton_03);
  first_group->addButton(ui_calculation_->pushButton_04);
  first_group->addButton(ui_calculation_->pushButton_05);
  first_group->addButton(ui_calculation_->pushButton_06);
  first_group->addButton(ui_calculation_->pushButton_07);
  first_group->addButton(ui_calculation_->pushButton_08);
  first_group->addButton(ui_calculation_->pushButton_09);
  first_group->addButton(ui_calculation_->pushButton_0);

  second_group->addButton(ui_calculation_->pushButton_openBracket);
  second_group->addButton(ui_calculation_->pushButton_closeBracket);
  second_group->addButton(ui_calculation_->pushButton_mult);
  second_group->addButton(ui_calculation_->pushButton_div);
  second_group->addButton(ui_calculation_->pushButton_degree);
  second_group->addButton(ui_calculation_->pushButton_mod);
  second_group->addButton(ui_calculation_->pushButton_plus);
  second_group->addButton(ui_calculation_->pushButton_minus);

  third_group->addButton(ui_calculation_->pushButton_sin);
  third_group->addButton(ui_calculation_->pushButton_cos);
  third_group->addButton(ui_calculation_->pushButton_tan);
  third_group->addButton(ui_calculation_->pushButton_asin);
  third_group->addButton(ui_calculation_->pushButton_acos);
  third_group->addButton(ui_calculation_->pushButton_atan);
  third_group->addButton(ui_calculation_->pushButton_ln);
  third_group->addButton(ui_calculation_->pushButton_log);
  third_group->addButton(ui_calculation_->pushButton_logxy);
  third_group->addButton(ui_calculation_->pushButton_sqrt);

  connect(first_group, SIGNAL(buttonClicked(int)), this,
          SLOT(bttn_pressed(int)));

  connect(second_group, SIGNAL(buttonClicked(int)), this,
          SLOT(operators_pressed(int)));

  connect(third_group, SIGNAL(buttonClicked(int)), this,
          SLOT(function_pressed(int)));

  connect(ui_calculation_->pushButton_EXP, SIGNAL(clicked()), this,
          SLOT(constant_pressed()));
  connect(ui_calculation_->pushButton_PI, SIGNAL(clicked()), this,
          SLOT(constant_pressed()));

  connect(ui_calculation_->pushButton_graf, SIGNAL(clicked()), this,
          SLOT(on_pushButton_graf_clicked()));

  connect(ui_calculation_->pushButton_credit, SIGNAL(clicked()), this,
          SLOT(on_pushButton_credit_clicked()));

  this->ui_calculation_->pushButton_dot->setCheckable(true);
}

CalculationView::~CalculationView() {
  delete ui_calculation_;
  delete first_group;
  delete second_group;
  delete third_group;
}

void CalculationView::bttn_pressed(int sender) {
  if (sender == -2 && ui_calculation_->pushButton_dot->isCheckable()) {
    ui_calculation_->result_tmp->setText(
        ui_calculation_->result_tmp->text() +
        ui_calculation_->pushButton_dot->text());
    ui_calculation_->pushButton_dot->setCheckable(false);
  } else {
    QString tmp;
    if (sender == -3) tmp = ui_calculation_->pushButton_X->text();
    if (sender == -4) tmp = ui_calculation_->pushButton_01->text();
    if (sender == -5) tmp = ui_calculation_->pushButton_02->text();
    if (sender == -6) tmp = ui_calculation_->pushButton_03->text();
    if (sender == -7) tmp = ui_calculation_->pushButton_04->text();
    if (sender == -8) tmp = ui_calculation_->pushButton_05->text();
    if (sender == -9) tmp = ui_calculation_->pushButton_06->text();
    if (sender == -10) tmp = ui_calculation_->pushButton_07->text();
    if (sender == -11) tmp = ui_calculation_->pushButton_08->text();
    if (sender == -12) tmp = ui_calculation_->pushButton_09->text();
    if (sender == -13) tmp = ui_calculation_->pushButton_0->text();

    ui_calculation_->result_tmp->setText(ui_calculation_->result_tmp->text() +
                                         tmp);
  }
}

void CalculationView::operators_pressed(int sender) {
  ui_calculation_->pushButton_dot->setCheckable(true);

  QString tmp;

  if (sender == -2) tmp = ui_calculation_->pushButton_openBracket->text();
  if (sender == -3) tmp = ui_calculation_->pushButton_closeBracket->text();
  if (sender == -4) tmp = ui_calculation_->pushButton_mult->text();
  if (sender == -5) tmp = ui_calculation_->pushButton_div->text();
  if (sender == -6) tmp = ui_calculation_->pushButton_degree->text();
  if (sender == -7) tmp = ui_calculation_->pushButton_mod->text();
  if (sender == -8) tmp = ui_calculation_->pushButton_plus->text();
  if (sender == -9) tmp = ui_calculation_->pushButton_minus->text();

  ui_calculation_->result_tmp->setText(ui_calculation_->result_tmp->text() +
                                       tmp);
}

void CalculationView::function_pressed(int sender) {
  ui_calculation_->pushButton_dot->setCheckable(true);

  QString tmp;

  if (sender == -2) tmp = ui_calculation_->pushButton_sin->text();
  if (sender == -3) tmp = ui_calculation_->pushButton_cos->text();
  if (sender == -4) tmp = ui_calculation_->pushButton_tan->text();
  if (sender == -5) tmp = ui_calculation_->pushButton_asin->text();
  if (sender == -6) tmp = ui_calculation_->pushButton_acos->text();
  if (sender == -7) tmp = ui_calculation_->pushButton_atan->text();
  if (sender == -8) tmp = ui_calculation_->pushButton_ln->text();
  if (sender == -9) tmp = ui_calculation_->pushButton_log->text();
  if (sender == -10) tmp = ui_calculation_->pushButton_logxy->text();
  if (sender == -11) tmp = ui_calculation_->pushButton_sqrt->text();

  ui_calculation_->result_tmp->setText(ui_calculation_->result_tmp->text() +
                                       tmp + "(");
}

void CalculationView::constant_pressed() {
  ui_calculation_->pushButton_dot->setCheckable(true);

  QPushButton *button = (QPushButton *)sender();

  if (button->text() == "EXP")
    ui_calculation_->result_tmp->setText(ui_calculation_->result_tmp->text() +
                                         QString::number(M_E));
  else if (button->text() == "PI")
    ui_calculation_->result_tmp->setText(ui_calculation_->result_tmp->text() +
                                         QString::number(M_PI));
}

void CalculationView::on_pushButton_AC_clicked() {
  this->ui_calculation_->pushButton_dot->setCheckable(true);

  ui_calculation_->result_tmp->clear();
  ui_calculation_->result_show->clear();

  ui_calculation_->lineEdit_xMinValue->clear();
  ui_calculation_->lineEdit_xMaxValue->clear();
  ui_calculation_->lineEdit_yMinValue->clear();
  ui_calculation_->lineEdit_yMaxValue->clear();
  ui_calculation_->widget->clearGraphs();
  ui_calculation_->widget->replot();
}

void CalculationView::on_pushButton_eq_clicked() {
  QString new_label = ui_calculation_->result_tmp->text();
  if (ui_calculation_->result_tmp->text().contains('x')) {
    if (ui_calculation_->lineEdit_x_value->text().isEmpty()) {
      graf_error_messages(3);
    }

    bool status = true;

    double tmp = ui_calculation_->lineEdit_x_value->text().toDouble(&status);

    if (!status || !std::isnormal(tmp)) {
      graf_error_messages(4);
      return;
    }

    new_label = ui_calculation_->result_tmp->text().replace(
        QString("x"),
        QString("(" + ui_calculation_->lineEdit_x_value->text() + ")"));
  };

  ui_calculation_->result_show->clear();

  try {
    double res = this->controller->calculatorAction(new_label);

    QString strValue = QString::number(res, 'f', 7);

    ui_calculation_->result_show->setText(strValue);
  } catch (std::exception &e) {
    ui_calculation_->result_show->setText("Error");
    return;
  }
}

void CalculationView::on_pushButton_back_clicked() {
  if (ui_calculation_->result_tmp->text() != "") {
    QString text = ui_calculation_->result_tmp->text();
    if (text.contains("=")) {
      text = ui_calculation_->result_show->text();
      ui_calculation_->result_show->clear();
    } else {
      text.chop(1);
    }
    if (text.isEmpty()) {
      text = "";
    }
    ui_calculation_->result_tmp->setText(text);
  } else if (ui_calculation_->result_show->text() != "") {
    QString text = ui_calculation_->result_show->text();
    text.chop(1);
    if (text.isEmpty()) {
      text = "";
    }
    ui_calculation_->result_show->setText(text);
  }
}

void CalculationView::on_pushButton_credit_clicked() {
  if (ui_calculation_->pushButton_credit->isCheckable()) {
    CreditView credit_w(this);

    credit_w.start(this->controller);

    ui_calculation_->pushButton_credit->setCheckable(false);
  } else {
    ui_calculation_->pushButton_credit->setCheckable(true);
  }
}

void CalculationView::on_pushButton_graf_clicked() {
  if (!ui_calculation_->result_tmp->text().contains('x')) return;

  ui_calculation_->widget->clearGraphs();
  x_.clear();
  y_.clear();

  if (graf_validate_data()) {
    xBegin_ = ui_calculation_->lineEdit_xMinValue->text().toDouble();
    xEnd_ = ui_calculation_->lineEdit_xMaxValue->text().toDouble();
    yBegin_ = ui_calculation_->lineEdit_yMinValue->text().toDouble();
    yEnd_ = ui_calculation_->lineEdit_yMaxValue->text().toDouble();
    Count_points = ui_calculation_->lineEdit_xStep->text().toInt();
  } else {
    graf_error_messages(2);
    return;
  }

  if (Count_points > 50000) {
    graf_error_messages(1);
    Count_points = 500;
    return;
  }

  ui_calculation_->widget->xAxis->setRange(xBegin_, xEnd_);
  ui_calculation_->widget->yAxis->setRange(yBegin_, yEnd_);

  graf_logic();
}

void CalculationView::graf_error_messages(int checker) {
  switch (checker) {
    case 1:
      QMessageBox::information(this, "Limit of points is 50.000.", "");
      break;
    case 2:
      QMessageBox::information(this, "Error. Try again", "");
      break;
    case 3:
      QMessageBox::information(this, "Please. Input x data", "");
      break;
    case 4:
      QMessageBox::information(this, "Invalid data", "");
      break;
  }
}

bool CalculationView::graf_validate_data() {
  bool status = true;
  double tmp_d = ui_calculation_->lineEdit_xMinValue->text().toDouble(&status);
  if (ui_calculation_->lineEdit_xMinValue->text().isEmpty() || !status ||
      tmp_d >= 0.0)
    return false;
  tmp_d = ui_calculation_->lineEdit_yMinValue->text().toDouble(&status);

  if (ui_calculation_->lineEdit_yMinValue->text().isEmpty() || !status ||
      tmp_d >= 0.0)
    return false;
  tmp_d = ui_calculation_->lineEdit_xMaxValue->text().toDouble(&status);

  if (ui_calculation_->lineEdit_xMaxValue->text().isEmpty() || !status ||
      tmp_d <= 0.0)
    return false;
  tmp_d = ui_calculation_->lineEdit_yMaxValue->text().toDouble(&status);

  if (ui_calculation_->lineEdit_yMaxValue->text().isEmpty() || !status ||
      tmp_d <= 0.0)
    return false;

  int tmp = ui_calculation_->lineEdit_xStep->text().toInt(&status);
  if (!status || tmp < 500) return false;

  if (ui_calculation_->result_tmp->text().isEmpty()) return false;

  return true;
}

void CalculationView::graf_logic() {
  int Points_InGraph = 0;
  int PointsTotalCnt = 0;
  int iGraph = 0;
  double X = 0.0, Y = 0.0;

  ui_calculation_->lineEdit_xStep->setText(QString::number(Count_points, 10));

  h_ = ((xEnd_ - xBegin_) / Count_points);

  if ((xEnd_ > xBegin_) && (yEnd_ > yBegin_)) {
    for (int i = 0; i < Count_points; i++) {
      X = xBegin_ + h_ * i;
      QString y_text;
      y_text = ui_calculation_->result_tmp->text();
      y_text.replace(QString("x"),
                     QString("(" + QString::number(X, 'f', 7) + ")"));
      try {
        Y = controller->calculatorAction(y_text);
      } catch (...) {
        graf_error_messages(2);
        return;
      }
      x_.push_back(X);
      y_.push_back(Y);
      PointsTotalCnt++;
      Points_InGraph += (!((yBegin_ > Y) || (Y > yEnd_)));

      if (((yBegin_ * 3 > Y) || (Y > yEnd_ * 3))) {
        ui_calculation_->widget->addGraph();
        ui_calculation_->widget->graph(iGraph++)->addData(x_, y_);
        x_.clear();
        y_.clear();
      }
    }

    ui_calculation_->widget->addGraph();
    ui_calculation_->widget->graph(iGraph++)->addData(x_, y_);
    ui_calculation_->widget->replot();
    while (iGraph) ui_calculation_->widget->graph(--iGraph)->data()->clear();
  }

  if (PointsTotalCnt == 0 || (xEnd_ < xBegin_)) graf_error_messages(2);
  if ((PointsTotalCnt > 0 && Points_InGraph == 0) || (yEnd_ < yBegin_))
    graf_error_messages(2);
}

void CalculationView::start(CalculatorController *controller) {
  this->controller = controller;
  this->show();
};
// End View CalculationView

};  // namespace s21
