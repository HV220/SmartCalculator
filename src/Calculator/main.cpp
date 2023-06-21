#include "calculator/controller/headers/calculator-controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorController w;
    w.show();
    return a.exec();
}
