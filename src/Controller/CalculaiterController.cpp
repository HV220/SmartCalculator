#include "CalculaiterController.h"

double CalculaiterController::add(double a)
{
    model->add(a);
    return model->getData();
}

double CalculaiterController::sub(double a)
{
    model->add(-a);
    return model->getData();
}

double CalculaiterController::mult(double a)
{
    model->mult(a);
    return model->getData();
}

double CalculaiterController::div(double a)
{
    model->mult(1.0/a);
    return model->getData();
}

void CalculaiterController::reset(){
    model->reset();
}