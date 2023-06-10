#include "View/consoleView.h"

int main() {
    CalculaiterModel model;
    CalculaiterController controller(&model);
    ConsoleView view(&controller);
    view.startEventLoop();
    return 1;
}