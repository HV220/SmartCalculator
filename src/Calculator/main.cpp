#include "Controller/calculatorController.h"
#include "Model/calculatorModel.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
      auto test = new CalculatorModel();
      QString test1 = "(-1)+sin((sin()+cos()))";
      QString test2 = "(123123123)+sin((sin()+cos()))\0";
      test->addExpression(test1);
      test->addExpression(test2);
      test->validateLastExpression();
        test->getLastCalculation()->getLexems();

//    QApplication a(argc, argv);
//    Calculator w;
//    w.show();
//    return a.exec();
    qDebug() << "test";
}
