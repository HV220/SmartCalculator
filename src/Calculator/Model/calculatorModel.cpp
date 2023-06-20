#include "calculatorModel.h"

// Begin Class Calculator

QString CalculatorModel::Calculation::getExpression() noexcept {
    return this->expression;
};

QVector<QString> CalculatorModel::Calculation::getLexems() noexcept {
  return this->lexems;
};

double CalculatorModel::Calculation::getData() noexcept {
    return this->data;
};

void CalculatorModel::Calculation::setLexems(QVector<QString> lexems) noexcept {
    this->lexems = lexems;
};

void CalculatorModel::Calculation::setLastLexem(QString lexem) noexcept {
    this->lexems.push_back(lexem);
};

void CalculatorModel::Calculation::setData(double data) noexcept {
    this->data = data;
};

void CalculatorModel::Calculation::setExpression(QString expression) noexcept {
    this->expression = expression;
};

// End Class Calculator

// Begin Class CalculatorModel

QVector<CalculatorModel::Calculation> CalculatorModel::getCalculations() noexcept {
    return this->calculations;
};

CalculatorModel::Calculation* CalculatorModel::getLastCalculation() {
    return &(this->calculations.back());
};

QMap<QString, int> CalculatorModel::getOperators() noexcept {
    return this->operators;
}

void CalculatorModel::setCalculations(QVector<CalculatorModel::Calculation> calculations) noexcept {
    this->calculations = calculations;
};

void CalculatorModel::setLastCalculation(CalculatorModel::Calculation calculation) noexcept {
    this->calculations.push_back(calculation);
};

void CalculatorModel::addExpression(const QString &str) {
    if(str.isEmpty() || str.isNull())
        throw std::logic_error("incorrect expression");

    QString str_check = str;

    str_check = str_check.simplified();
    str_check.replace( " ", "" );

    Calculation *tmp = new Calculation(str_check);

    this->setLastCalculation(*tmp);
}

void CalculatorModel::calculateExpression() {
    // TODO Describe the polish notation
}

void CalculatorModel::validateLastExpression() {

        QString str_tmp;
        QString str_check = this->getLastCalculation()->getExpression();

        str_check = str_check.simplified();
        str_check.replace( " ", "" );

        bool unar_check = false;

        for(int i = 0; str_check[i] != '\0'; ++i){

            if(str_check[i] == '(' || str_check[i] == ')')
            {
                if(str_check[i] == '(' && str_check[i+1] == '-') unar_check = true;

                str_tmp += str_check[i];
                this->getLastCalculation()->setLastLexem(str_tmp);
            }

            else if(str_check[i].isLetter())
            {
                str_tmp += str_check[i];

                for (;str_check[i+1] != str_check.end() && str_check[i+1].isLetter();i++)
                {
                    str_tmp += str_check[i+1];
                }

                if(!this->isOperatorOrFunc(str_tmp)) {
                    throw std::logic_error("error");
                }

                 this->getLastCalculation()->setLastLexem(str_tmp);
            }

            else if(str_check[i].isNumber())
            {
                if(unar_check) {
                str_tmp += '-';
                unar_check = false;
                };

                str_tmp += str_check[i];

                for (; str_check[i+1] != str_check.end() && (str_check[i+1].isNumber() || str_check[i+1] == '.');++i)
                {
                    str_tmp += str_check[i+1];
                }

                 this->getLastCalculation()->setLastLexem(str_tmp);
            }

            else if(!unar_check && !str_check[i].isNumber() && !str_check[i].isLetter())
            {
                str_tmp += str_check[i];

                if(!this->isOperatorOrFunc(str_tmp)) {
                    throw std::logic_error("error");
                }

                 this->getLastCalculation()->setLastLexem(str_tmp);
            }
            str_tmp = "";
        }
};

void CalculatorModel::reset() {
    this->calculations.clear();
};


int CalculatorModel::checkPriority(const QString &lexem) noexcept {
   auto it = this->operators.find(lexem);

   return it == this->operators.end() ? 0 : it.value();
};

int CalculatorModel::isOperatorOrFunc(const QString &opr) noexcept {

    if(!this->checkPriority(opr)) return 0;

    const QSet<QString> opr_compaire{"+", "-", "*", "/", "mod", "^"};

    return opr_compaire.find(opr) != opr_compaire.end() ? 1 : 2;
}

// End Class CalculatorModel
