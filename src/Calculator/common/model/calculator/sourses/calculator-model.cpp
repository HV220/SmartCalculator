#include "../headers/calculator-model.h"

// Begin Struct Operators

const QMap<QString, int> CalculatorModel::Operators::operators{
    {"(", 1},    {")", 1},   {"+", 2},    {"-", 2},    {"", 3},
    {"/", 3},    {"mod", 3}, {"log", 3},  {"ln", 3},   {"sin", 3},
    {"cos", 3},  {"tan", 3}, {"asin", 3}, {"acos", 3}, {"atan", 3},
    {"sqrt", 3}, {"pi", 4},  {"x", 4},    {"^", 4}
};

int CalculatorModel::Operators::checkPriority(const QString &lexem) noexcept {
    auto it = CalculatorModel::Operators::operators.find(lexem);
    return it == CalculatorModel::Operators::operators.end() ? 0 : it.value();
};

int CalculatorModel::Operators::isOperatorOrFunc(const QString &opr) noexcept {
      if (!CalculatorModel::Operators::checkPriority(opr))
        return 0;

      const QSet<QString> opr_compaire{"+", "-", "*", "/", "mod", "^"};

      return opr_compaire.find(opr) != opr_compaire.end() ? 1 : 2;
};

// End Struct Operators

// Begin Class Calculator

QString CalculatorModel::Calculation::getExpression() noexcept {
  return this->expression;
};

QVector<QString> CalculatorModel::Calculation::getLexems() noexcept {
  return this->lexems;
};

double CalculatorModel::Calculation::getData() noexcept { return this->data; };

void CalculatorModel::Calculation::setExpression(QString expression) {
    if (expression.isEmpty() || expression.isNull())
      throw std::logic_error("incorrect expression");

    expression = expression.simplified();
    expression.replace(" ", "");

    this->expression = expression;
};

void CalculatorModel::Calculation::setLexem(QString lexem) {
    this->lexems.push_back(lexem);
};

void CalculatorModel::Calculation::validateExpression() {

    QString str_tmp;
    QString str_check = this->getExpression();
    bool unar_check = false;

    for (int i = 0; str_check[i] != '\0'; ++i) {

      if (str_check[i] == '(' || str_check[i] == ')') {
        if (str_check[i] == '(' && str_check[i + 1] == '-')
          unar_check = true;

        str_tmp += str_check[i];
        this->setLexem(str_tmp);
      }

      else if (str_check[i].isLetter()) {
        str_tmp += str_check[i];

        for (; str_check[i + 1] != str_check.end() && str_check[i + 1].isLetter();
             i++) {
          str_tmp += str_check[i + 1];
        }

        if (!CalculatorModel::Operators::isOperatorOrFunc(str_tmp)) {
          throw std::logic_error("error");
        }

        this->setLexem(str_tmp);
      }

      else if (str_check[i].isNumber()) {
        if (unar_check) {
          str_tmp += '-';
          unar_check = false;
        };

        str_tmp += str_check[i];

        for (; str_check[i + 1] != str_check.end() &&
               (str_check[i + 1].isNumber() || str_check[i + 1] == '.');
             ++i) {
          str_tmp += str_check[i + 1];
        }

        this->setLexem(str_tmp);
      }

      else if (!unar_check && !str_check[i].isNumber() &&
               !str_check[i].isLetter()) {
        str_tmp += str_check[i];

        if (!CalculatorModel::Operators::isOperatorOrFunc(str_tmp)) {
          throw std::logic_error("error");
        }

        this->setLexem(str_tmp);
      }
      str_tmp = "";
    }
};

void CalculatorModel::Calculation::calculate() {

};

void CalculatorModel::Calculation::clearCalculation() {

};

// End Class Calculator

// Begin Class CalculatorModel

QVector<CalculatorModel::Calculation>
CalculatorModel::getCalculations() noexcept {
  return this->calculations;
};

CalculatorModel::Calculation CalculatorModel::getLastCalculation() {
  return this->calculations.back();
};

void CalculatorModel::setCalculations(
    QVector<CalculatorModel::Calculation> calculations) noexcept {
  this->calculations = calculations;
};

void CalculatorModel::setLastCalculation(Calculation calculation) noexcept {
    this->calculations.push_back(calculation);
};

void CalculatorModel::reset() { this->calculations.clear(); };

// End Class CalculatorModel
