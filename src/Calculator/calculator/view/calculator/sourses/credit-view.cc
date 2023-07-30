#include "../headers/credit-view.h"

// Begin View CreditView

namespace s21 {

CreditView::CreditView(QWidget *parent)
    : QDialog(parent), ui_credit_(new Ui::CreditView) {
  ui_credit_->setupUi(this);

  ui_credit_->MounthPayments->setMinimumSize(QSize(300, 100));

  ui_credit_->MounthPayments->setColumnCount(1);

  ui_credit_->MounthPayments->setHorizontalHeaderLabels(QStringList()
                                                        << "Выплата");

  ui_credit_->MounthPayments->horizontalHeader()->setSectionResizeMode(
      QHeaderView::ResizeToContents);
  ui_credit_->MounthPayments->setEditTriggers(
      QAbstractItemView::NoEditTriggers);
  ui_credit_->MounthPayments->horizontalHeader()->setMinimumSectionSize(400);

  connect(ui_credit_->pushButton_12, SIGNAL(clicked()), this,
          SLOT(on_pushButton_calccredit_clicked(controller)));

  connect(ui_credit_->pushButton_closecredit, SIGNAL(clicked()), this,
          SLOT(on_pushButton_closecredit_clicked()));
}

CreditView::~CreditView() { delete ui_credit_; }

void CreditView::on_pushButton_closecredit_clicked() { QWidget::close(); };

void CreditView::calculationCredit(bool Annuity) {
  ui_credit_->MounthPayments->clearContents();
  try {
    std::map<std::string, std::vector<double>> res;

    if (Annuity) {
      res = this->controller_->creditCalculatorAction(
          ui_credit_->total_loan_amount->text(), ui_credit_->period->text(),
          ui_credit_->interest_ratebool->text());
    } else {
      res = this->controller_->creditCalculatorAction(
          ui_credit_->total_loan_amount->text(), ui_credit_->period->text(),
          ui_credit_->interest_ratebool->text(), false);
    }

    auto tmp = (res.find("MounthPayments"))->second;

    ui_credit_->MounthPayments->setRowCount(tmp.size());

    int i = 0;

    for (auto it = tmp.begin(); it != tmp.end(); it++) {
      QTableWidgetItem *tmp =
          new QTableWidgetItem(QString::number(*it, 'f', 7));
      ui_credit_->MounthPayments->setItem(i, 0, tmp);
      i++;
    }

    ui_credit_->CreditOverpayment->setText(
        QString::number((res.find("CreditOverpayment")->second)[0], 'f', 7));

    ui_credit_->TotalPayment->setText(
        QString::number((res.find("TotalPayment")->second)[0], 'f', 7));
  } catch (std::exception &e) {
    QMessageBox::information(this, "Error!", "Something wrong, try it again");
  }
};

void CreditView::on_pushButton_12_clicked() {
  if (ui_credit_->radioButton_annuit->isChecked()) {
    this->calculationCredit(true);
  } else if (ui_credit_->radioButton_diff->isChecked()) {
    this->calculationCredit(false);
  }
}

void CreditView::start(s21::CalculatorController *controller) {
  this->controller_ = controller;
  this->setWindowTitle("Credit Calculator");
  this->setModal(true);
  this->exec();
};

};  // namespace s21

// End View CreditView
