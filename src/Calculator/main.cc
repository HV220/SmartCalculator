#include "calculator/controller/headers/calculator-controller.h"
#include "calculator/view/calculator/headers/calculator-view.h"
#include "common/model/calculator/headers/calculator-model.h"

#include <QApplication>

using namespace s21;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  CalculatorView w;

  w.show();
  return a.exec();
}
