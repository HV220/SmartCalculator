#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QMap>
#include <QSet>
#include <QStack>
#include <QVector>

class CalculatorModel
{
private:
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
        void setLexems(QVector<QString> lexems) noexcept;
        void setLastLexem(QString lexem) noexcept;
        void setData(double data) noexcept;
        void setExpression(QString expression) noexcept;
    };

public:
    QVector<Calculation> getCalculations() noexcept;
    Calculation* getLastCalculation();
    QMap<QString, int> getOperators() noexcept;
    void setCalculations(QVector<Calculation> calculations) noexcept;
    void setLastCalculation(Calculation calculation) noexcept;

    void addExpression(const QString &str);
    void calculateExpression();
    void validateLastExpression();
    void reset();

private:
    int checkPriority(const QString &lexem) noexcept;
    int isOperatorOrFunc(const QString &opr) noexcept;

    QVector<Calculation> calculations{};

    const QMap<QString, int> operators{
        {"(", 1},    {")", 1},   {"+", 2},    {"-", 2},    {"*", 3},
        {"/", 3},    {"mod", 3}, {"log", 3},  {"ln", 3},   {"sin", 3},
        {"cos", 3},  {"tan", 3}, {"asin", 3}, {"acos", 3}, {"atan", 3},
        {"sqrt", 3}, {"pi", 4},  {"x", 4},    {"^", 4}
    };
};

#endif // CALCULATORMODEL_H
