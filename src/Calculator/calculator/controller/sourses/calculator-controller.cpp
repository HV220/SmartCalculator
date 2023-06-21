#include "../headers/calculator-controller.h"
#include "ui_main.h"

CalculatorController::CalculatorController(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorController)
{
    ui->setupUi(this);
}

CalculatorController::~CalculatorController()
{
    delete ui;
}

