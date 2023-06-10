#ifndef SRC_VIEW_CONSOLEVIEW_H
#define SRC_VIEW_CONSOLEVIEW_H

#include "../Controller/CalculaiterController.h"

enum Choice {
  SUM = 1,
  SUB = 2,
  MUL = 3,
  DIV = 4,
  RES = 5,
  EXIT = 0,
  NONE = -1
};

class ConsoleView {
private:
  CalculaiterController *controller;

public:
  ConsoleView(CalculaiterController *c) : controller(c){};
  void displayMenu();
  int performChoice();
  double performNumericInput();
  void startEventLoop();
};

#endif // SRC_VIEW_CONSOLEVIEW_H