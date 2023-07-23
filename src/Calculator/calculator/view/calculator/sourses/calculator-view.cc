#include "../headers/calculator-view.h"

#include <cmath>

#include "ui_credit.h"
#include "ui_main.h"

namespace s21 {

// Begin View CalculationView

CalculationView::CalculationView(QWidget *parent)
    : QMainWindow(parent), ui_calculation(new Ui::CalculationView) {
  ui_calculation->setupUi(this);

  setWindowTitle("Calculator");
  connect(ui_calculation->pushButton_X, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_0, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_01, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_02, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_03, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_04, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_05, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_06, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_07, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_08, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_09, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(bttn_pressed()));
  connect(ui_calculation->pushButton_openBracket, SIGNAL(clicked()), this,
          SLOT(operators_pressed()));
  connect(ui_calculation->pushButton_closeBracket, SIGNAL(clicked()), this,
          SLOT(operators_pressed()));
  connect(ui_calculation->pushButton_mult, SIGNAL(clicked()), this,
          SLOT(operators_pressed()));
  connect(ui_calculation->pushButton_div, SIGNAL(clicked()), this,
          SLOT(operators_pressed()));
  connect(ui_calculation->pushButton_degree, SIGNAL(clicked()), this,
          SLOT(operators_pressed()));
  connect(ui_calculation->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(operators_pressed()));
  connect(ui_calculation->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(operators_pressed()));
  connect(ui_calculation->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(operators_pressed()));

  connect(ui_calculation->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(function_pressed()));
  connect(ui_calculation->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(function_pressed()));
  connect(ui_calculation->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(function_pressed()));
  connect(ui_calculation->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(function_pressed()));
  connect(ui_calculation->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(function_pressed()));
  connect(ui_calculation->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(function_pressed()));
  connect(ui_calculation->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(function_pressed()));
  connect(ui_calculation->pushButton_log, SIGNAL(clicked()), this,
          SLOT(function_pressed()));
  connect(ui_calculation->pushButton_logxy, SIGNAL(clicked()), this,
          SLOT(function_pressed()));
  connect(ui_calculation->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(function_pressed()));

  connect(ui_calculation->pushButton_EXP, SIGNAL(clicked()), this,
          SLOT(constant_pressed()));
  connect(ui_calculation->pushButton_PI, SIGNAL(clicked()), this,
          SLOT(constant_pressed()));

  connect(ui_calculation->pushButton_graf, SIGNAL(clicked()), this,
          SLOT(on_pushButton_eq_clicked()));

  connect(ui_calculation->pushButton_credit, SIGNAL(clicked()), this,
          SLOT(on_pushButton_credit_clicked()));

  ui_calculation->pushButton_dot->setCheckable(true);
}

CalculationView::~CalculationView() { delete ui_calculation; }

void CalculationView::bttn_pressed() {
  QPushButton *button = (QPushButton *)sender();

  if (button->text() == "." && button->isCheckable()) {
    ui_calculation->result_tmp->setText(ui_calculation->result_tmp->text() +
                                        button->text());
    button->setCheckable(false);
  } else if (button->text() != ".") {
    ui_calculation->result_tmp->setText(ui_calculation->result_tmp->text() +
                                        button->text());
  }
}

void s21::CalculationView::operators_pressed() {
  ui_calculation->pushButton_dot->setCheckable(true);

  QPushButton *button = (QPushButton *)sender();

  ui_calculation->result_tmp->setText(ui_calculation->result_tmp->text() +
                                      button->text());
}

void s21::CalculationView::function_pressed() {
  ui_calculation->pushButton_dot->setCheckable(true);

  QPushButton *button = (QPushButton *)sender();

  ui_calculation->result_tmp->setText(ui_calculation->result_tmp->text() +
                                      button->text() + "(");
}

void s21::CalculationView::constant_pressed() {
  ui_calculation->pushButton_dot->setCheckable(true);

  QPushButton *button = (QPushButton *)sender();

  if (button->text() == "EXP")
    ui_calculation->result_tmp->setText(ui_calculation->result_tmp->text() +
                                        QString::number(M_E));
  else if (button->text() == "PI")
    ui_calculation->result_tmp->setText(ui_calculation->result_tmp->text() +
                                        QString::number(M_PI));
}

void s21::CalculationView::on_pushButton_AC_clicked() {
  ui_calculation->result_tmp->clear();
  ui_calculation->result_show->clear();

  ui_calculation->lineEdit_xMinValue->clear();
  ui_calculation->lineEdit_xMaxValue->clear();
  ui_calculation->lineEdit_yMinValue->clear();
  ui_calculation->lineEdit_yMaxValue->clear();
  ui_calculation->widget->clearGraphs();
  ui_calculation->widget->replot();
}

void s21::CalculationView::on_pushButton_eq_clicked() {
  if (ui_calculation->result_tmp->text().contains('x')) return;

  ui_calculation->result_show->clear();

  QString new_label = ui_calculation->result_tmp->text();

  try {
    double res = this->common_controller->calculatorAction(new_label);

    QString strValue = QString::number(res, 'f', 7);

    ui_calculation->result_show->setText(strValue);
  } catch (std::exception &e) {
    ui_calculation->result_show->setText("Error");
    return;
  }
}

void s21::CalculationView::on_pushButton_back_clicked() {
  if (ui_calculation->result_tmp->text() != "") {
    QString text = ui_calculation->result_tmp->text();
    if (text.contains("=")) {
      text = ui_calculation->result_show->text();
      ui_calculation->result_show->clear();
    } else {
      text.chop(1);
    }
    if (text.isEmpty()) {
      text = "";
    }
    ui_calculation->result_tmp->setText(text);
  } else if (ui_calculation->result_show->text() != "") {
    QString text = ui_calculation->result_show->text();
    text.chop(1);
    if (text.isEmpty()) {
      text = "";
    }
    ui_calculation->result_show->setText(text);
  }
}

void s21::CalculationView::on_pushButton_close_clicked() { QWidget::close(); }

void s21::CalculationView::on_pushButton_credit_clicked() {
  if (ui_calculation->pushButton_credit->isCheckable()) {
    CreditView ui_credit;

    ui_credit.setWindowTitle("Credit Calculator");
    ui_credit.setModal(true);
    ui_credit.exec();

    ui_calculation->pushButton_credit->setCheckable(false);
  } else {
    ui_calculation->pushButton_credit->setCheckable(true);
  }
}

void s21::CalculationView::on_pushButton_graf_clicked() {
  int status = OK, Count_points = 500;
  ui_calculation->widget->clearGraphs();
  x.clear();
  y.clear();
  int Points_InGraph = 0;
  int PointsTotalCnt = 0;
  int iGraph = 0;

  QString xMin_text = ui_calculation->lineEdit_xMinValue->text();
  (xMin_text == "") ? xBegin = -10 : xBegin = xMin_text.toDouble();
  QString xMax_text = ui_calculation->lineEdit_xMaxValue->text();
  (xMax_text == "") ? xEnd = 10 : xEnd = xMax_text.toDouble();
  QString yMin_text = ui_calculation->lineEdit_yMinValue->text();
  (yMin_text == "") ? yBegin = -10 : yBegin = yMin_text.toDouble();
  QString yMax_text = ui_calculation->lineEdit_yMaxValue->text();
  (yMax_text == "") ? yEnd = 10 : yEnd = yMax_text.toDouble();
  ui_calculation->widget->xAxis->setRange(xBegin, xEnd);
  ui_calculation->widget->yAxis->setRange(yBegin, yEnd);

  double X = 0.0, Y = 0.0;

  Count_points = (int)ui_calculation->lineEdit_xStep->text().toDouble();

  if (Count_points < 10) {
    QMessageBox::information(this, "Not enough points. Fixed to default", "");
    Count_points = 500;
  } else if (Count_points > 1000) {
    if (QMessageBox::question(
            this, "Points>1000, It will take a lot of time. Sure?", "",
            QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
      QMessageBox::information(this, "Fixed to default", "");
      Count_points = 500;
    }
  }
  ui_calculation->lineEdit_xStep->setText(QString::number(Count_points, 10));

  h = ((xEnd - xBegin) / Count_points);

  int Old_status = status;

  if ((xEnd > xBegin) && (yEnd > yBegin)) {
    for (int i = 0; i < Count_points; i++) {
      X = xBegin + h * i;
      QString y_text;
      if (ui_calculation->result_tmp->text() == "" &&
          ui_calculation->result_show->text() == "") {
        QMessageBox::information(
            this, /*"Attention!", */ "Please, input the data.", "");
        return;
      } else if (ui_calculation->result_show->text() != "") {
        y_text = ui_calculation->result_show->text();
      } else if (ui_calculation->result_tmp->text() != "") {
        y_text = ui_calculation->result_tmp->text();
      }
      if (y_text != "") {
        if (y_text.contains("x"))
          y_text.replace(QString("x"),
                         QString("(" + QString::number(X, 'f', 7) + ")"));

        try {
          Y = common_controller->calculatorAction(y_text);
        } catch (...) {
          QMessageBox::information(
              this, /*"Attention!", */ "Please, input the correct data.", "");
          return;
        }

      } else {
        status = 1;
      }
      if (status == OK) {
        x.push_back(X);
        y.push_back(Y);
        PointsTotalCnt++;
        Points_InGraph += (!((yBegin > Y) || (Y > yEnd)));
      }
      if ((status != OK && Old_status == OK) ||
          ((yBegin * 3 > Y) || (Y > yEnd * 3))) {
        ui_calculation->widget->addGraph();
        ui_calculation->widget->graph(iGraph++)->addData(x, y);
        x.clear();
        y.clear();
      }
      Old_status = status;
    }

    ui_calculation->widget->addGraph();
    ui_calculation->widget->graph(iGraph++)->addData(x, y);
    ui_calculation->widget->replot();
    while (iGraph) ui_calculation->widget->graph(--iGraph)->data()->clear();
  }

  if (PointsTotalCnt == 0 || (xEnd < xBegin))
    QMessageBox::information(this,  //"Attention!",
                             "Function not defined in this XRange", "");
  if ((PointsTotalCnt > 0 && Points_InGraph == 0) || (yEnd < yBegin))
    QMessageBox::information(this,  //"Attention!",
                             "Function points are out of YRange", "");
}

// End View CalculationView

// Begin View CreditView

CreditView::CreditView(QWidget *parent, CalculatorController *controller)
    : QDialog(parent), ui_credit(new Ui::CreditView) {
  ui_credit->setupUi(this);

  ui_credit->MounthPayments->setMinimumSize(QSize(300, 300));

  ui_credit->MounthPayments->setColumnCount(1);

  ui_credit->MounthPayments->setHorizontalHeaderLabels(QStringList()
                                                       << "Выплата");

  ui_credit->MounthPayments->horizontalHeader()->setSectionResizeMode(
      QHeaderView::ResizeToContents);
  ui_credit->MounthPayments->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui_credit->MounthPayments->horizontalHeader()->setMinimumSectionSize(400);

  this->common_controller = controller;

  connect(ui_credit->pushButton_12, SIGNAL(clicked()), this,
          SLOT(on_pushButton_calccredit_clicked()));

  connect(ui_credit->pushButton_closecredit, SIGNAL(clicked()), this,
          SLOT(on_pushButton_closecredit_clicked()));
}

CreditView::~CreditView() { delete ui_credit; }

void CreditView::on_pushButton_closecredit_clicked() { QWidget::close(); };

void CreditView::calculationCredit(bool Annuity) {
  ui_credit->MounthPayments->clearContents();
  try {
    std::map<std::string, std::vector<double>> res;

    if (Annuity) {
      res = this->common_controller->creditCalculatorAction(
          ui_credit->total_loan_amount->text(), ui_credit->period->text(),
          ui_credit->interest_ratebool->text());
    } else {
      res = this->common_controller->creditCalculatorAction(
          ui_credit->total_loan_amount->text(), ui_credit->period->text(),
          ui_credit->interest_ratebool->text(), false);
    }

    auto tmp = (res.find("MounthPayments"))->second;

    ui_credit->CreditOverpayment->setText(
        QString::number((res.find("CreditOverpayment")->second)[0], 'f', 7));

    ui_credit->MounthPayments->setRowCount(tmp.size());

    int i = 0;

    for (auto it = tmp.begin(); it != tmp.end(); it++) {
      QTableWidgetItem *tmp =
          new QTableWidgetItem(QString::number(*it, 'f', 7));
      ui_credit->MounthPayments->setItem(i, 0, tmp);
      i++;
    }

    ui_credit->TotalPayment->setText(
        QString::number((res.find("TotalPayment")->second)[0], 'f', 7));
  } catch (std::exception &e) {
    QMessageBox::information(this, "Error!", "Something wrong, try it again");
  }
};

void s21::CreditView::on_pushButton_12_clicked() {
  if (ui_credit->radioButton_annuit->isChecked()) {
    this->calculationCredit();
  } else if (ui_credit->radioButton_diff->isChecked()) {
    this->calculationCredit(false);
  }
}

// End View CreditView

};  // namespace s21
