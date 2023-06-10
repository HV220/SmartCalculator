#include "CalculaiterModel.h"

void CalculaiterModel::add(double a) 
{
    data += a;
} 

void CalculaiterModel::mult(double a) 
{
    data *= a;
}

void CalculaiterModel::reset()
{
    data = 0;
}

double CalculaiterModel::getData()
{
    return data;
}