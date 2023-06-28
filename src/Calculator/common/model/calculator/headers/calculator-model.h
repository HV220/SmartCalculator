#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QMap>
#include <QSet>
#include <QStack>
#include <QVector>
#include <cmath>

namespace s21 {

class CalculatorModel {

public:
  class Calculation {
   private:
    std::string expression_;
    std::vector<std::string> lexems_{};
    std::vector<std::string> polish_notation_{};
    double data;
    std::map<std::string, int> operators_ =
    {
                {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"^", 3},
                {"mod", 2}, {"cos", 4}, {"sin", 4}, {"tan", 4},
                {"acos", 4}, {"asin", 4}, {"atan", 4},
                {"sqrt", 4}, {"ln", 4}, {"log", 4},
                {"unary_minus", 5}, {"unary_plus", 5},
                {"(", 0}, {")", 0}
    };
  public:
    double calculate(QString expression);
    double getData() noexcept;
    void clear() noexcept;
  private:
    std::string getExpression() noexcept;
    const std::string checkFunction(size_t& i);
    const std::string checkOperator(size_t& i);
    bool unaryOperator(size_t i) noexcept;
    void setExpression(QString expression);
    void devideOnLexems();
    void polishCalculate();
    void polishConverter();
    const std::string numberValidation(size_t& i);
  };

public:
  QVector<Calculation> getCalculations() noexcept;
  Calculation getLastCalculation();
  void setCalculations(QVector<Calculation> calculations) noexcept;
  void setLastCalculation(Calculation calculation) noexcept;
  void reset();

private:
  QVector<Calculation> calculations{};
};

};
#endif // CALCULATORMODEL_H
