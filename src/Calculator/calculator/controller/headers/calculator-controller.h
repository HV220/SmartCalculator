#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorController; }
QT_END_NAMESPACE

class CalculatorController : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorController(QWidget *parent = nullptr);
    ~CalculatorController();

private:
    Ui::CalculatorController *ui;
};
#endif // CALCULATORCONTROLLER_H
