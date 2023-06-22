#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QMap>
#include <QSet>
#include <QStack>
#include <QVector>

class CalculatorModel {

public:
  struct Operators {
  public:
    static const QMap<QString, int> operators;
    static int checkPriority(const QString &lexem) noexcept;
    static int isOperatorOrFunc(const QString &opr) noexcept;
  };

  class Calculation {
  private:
    QString expression;
    QVector<QString> lexems;
    double data;

  public:
    Calculation() : data(0.0) {}
    Calculation(QString exp) : expression(exp), data(0.0) {}

    QString getExpression() noexcept;
    QVector<QString> getLexems() noexcept;
    double getData() noexcept;
    void setExpression(QString expression);
    void setLexem(QString lexem);
    void validateExpression();
    void calculate();
    void clearCalculation();
    int opnValidate(QStack<QString> *signs, QStack<double> *numbers);
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

#endif // CALCULATORMODEL_H
