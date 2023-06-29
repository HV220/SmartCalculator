#include "../headers/calculator-model.h"

namespace s21 {

// Begin Class Calculator

const std::string CalculatorModel::Calculation::checkFunction(size_t& i) {
  std::string function{};
  while (std::isalpha(expression_[i])) {
    function += expression_[i];
    ++i;
  }
  if (this->operators_.find(function) == this->operators_.end()) {
    throw std::invalid_argument("error: the function does not exist");
  }
  if (function != "mod" && expression_[i] != '(') {
    throw std::invalid_argument("error: missing function argument");
  }
  return function;
}

const std::string CalculatorModel::Calculation::checkOperator(size_t& i) {
  std::string oper{};
  if (expression_[i] == '-' && unaryOperator(i)) {
    oper += "unary_minus";
  } else if (expression_[i] == '+' && unaryOperator(i)) {
    oper += "unary_plus";
  } else {
    oper += expression_[i];
  }
  ++i;
  if (this->operators_.find(oper) == this->operators_.end()) {
    throw std::invalid_argument("error: the operator does not exist");
  }
  return oper;
}

bool CalculatorModel::Calculation::unaryOperator(size_t i) noexcept {
  return (i == 0 || expression_[i-1] == '(');
}

double CalculatorModel::Calculation::calculate(QString expression)
{
   this->setExpression(expression);
   this->devideOnLexems();
   this->polishConverter();
   this->polishCalculate();
   return this->data;
}

std::string CalculatorModel::Calculation::getExpression() noexcept {
  return this->expression_;
};

double CalculatorModel::Calculation::getData() noexcept { return this->data; };

void CalculatorModel::Calculation::setExpression(QString expression) {

  if (expression.isEmpty() || expression.isNull())
    throw std::logic_error("incorrect expression");

  int count = std::count(expression.begin(), expression.end(), ')') +
              std::count(expression.begin(), expression.end(), '(');

  if ((count % 2))
    throw std::logic_error("incorrect expression");

  this->expression_ = expression.toLower().simplified().replace(" ", "").toStdString();
};

void CalculatorModel::Calculation::devideOnLexems() {
    for (size_t i{}; i < expression_.size();) {
       if (std::isdigit(expression_[i])) {
         this->lexems_.push_back(numberValidation(i));
       } else if (std::isalpha(expression_[i])) {
         this->lexems_.push_back(checkFunction(i));
       } else {
         this->lexems_.push_back(checkOperator(i));
       }
     }
};

const std::string CalculatorModel::Calculation::numberValidation(size_t& i) {
  std::string number{};
  int check_of_dot{};
  while (std::isdigit(expression_[i]) || expression_[i] == '.') {
    number += expression_[i];
    ++i;
    if (expression_[i] == '.') {
      ++check_of_dot;
    }
  }
  if (check_of_dot > 1) {
    throw std::invalid_argument("error: too many dots in the number");
  }
  return number;
}

void CalculatorModel::Calculation::polishCalculate() {
    double number_one{};
      double number_two{};
      std::vector<double> tmp_result{};
      size_t i{};
      while (i < polish_notation_.size()) {
        if (std::isdigit(polish_notation_[i][0])) {
          tmp_result.push_back(std::stod(polish_notation_[i]));
        } else {
          size_t size_tmp_result = tmp_result.size();
          if (size_tmp_result >= 1) {
            number_two = tmp_result[size_tmp_result - 1];
            if (polish_notation_[i] == "unary_minus") {
              tmp_result[size_tmp_result - 1] = -number_two;
            } else if (polish_notation_[i] == "cos") {
              tmp_result[size_tmp_result - 1] = cos(number_two);
            } else if (polish_notation_[i] == "sin") {
              tmp_result[size_tmp_result - 1] = sin(number_two);
            } else if (polish_notation_[i] == "tan") {
              tmp_result[size_tmp_result - 1] = tan(number_two);
            } else if (polish_notation_[i] == "acos") {
              tmp_result[size_tmp_result - 1] = acos(number_two);
            } else if (polish_notation_[i] == "asin") {
              tmp_result[size_tmp_result - 1] = asin(number_two);
            } else if (polish_notation_[i] == "atan") {
              tmp_result[size_tmp_result - 1] = atan(number_two);
            } else if (polish_notation_[i] == "sqrt") {
              tmp_result[size_tmp_result - 1] = sqrt(number_two);
            } else if (polish_notation_[i] == "ln") {
              tmp_result[size_tmp_result - 1] = log(number_two);
            } else if (polish_notation_[i] == "log") {
              tmp_result[size_tmp_result - 1] = log10(number_two);
            }
          }
          std::string pattern("+-*/^mod");
          if (pattern.find(polish_notation_[i]) != std::string::npos) {
            if (size_tmp_result >= 2) {
              number_one = tmp_result[size_tmp_result - 2];
              if (polish_notation_[i] == "+") {
                tmp_result[size_tmp_result - 2] = number_one + number_two;
              } else if (polish_notation_[i] == "-") {
                tmp_result[size_tmp_result - 2] = number_one - number_two;
              } else if (polish_notation_[i] == "*") {
                tmp_result[size_tmp_result - 2] = number_one * number_two;
              } else if (polish_notation_[i] == "/") {
                tmp_result[size_tmp_result - 2] = number_one / number_two;
              } else if (polish_notation_[i] == "^") {
                tmp_result[size_tmp_result - 2] = std::pow(number_one, number_two);
              } else if (polish_notation_[i] == "mod") {
                tmp_result[size_tmp_result - 2] = std::fmod(number_one, number_two);
              }
              tmp_result.pop_back();
            } else {
              throw std::invalid_argument("error: incorrect expression");
            }
          }
        }
        ++i;
      }
      if (tmp_result.size() != 1) {
        throw std::invalid_argument("error: incorrect expression");
      }
      this->data = tmp_result[0];
    }

void CalculatorModel::Calculation::polishConverter() {
    std::vector<std::string> operator_stack{};
      for (const auto &str : this->lexems_) {
        if (std::isdigit(str[0])) {
          polish_notation_.push_back(str);
        } else if (str == "(") {
          operator_stack.push_back(str);
        } else if (str == ")") {
          while (operator_stack.back() != "(") {
            polish_notation_.push_back(operator_stack.back());
            operator_stack.pop_back();
          }
          operator_stack.pop_back();
        } else {
          if (!operator_stack.empty()) {
            int priority_in_expression = this->operators_.find(str)->second;
            int priority_in_stack = this->operators_.find(operator_stack.back())->second;
            while (priority_in_stack >= priority_in_expression) {
              polish_notation_.push_back(operator_stack.back());
              operator_stack.pop_back();
              if (operator_stack.empty()) { break; }
              priority_in_stack = this->operators_.find(operator_stack.back())->second;
            }
          }
          operator_stack.push_back(str);
        }
      }
      while (!operator_stack.empty()) {
        polish_notation_.push_back(operator_stack.back());
        operator_stack.pop_back();
      }
}

void CalculatorModel::Calculation::clear() noexcept {
    this->lexems_.clear();
    this->polish_notation_.clear();
    this->expression_ = "";
    this->data = 0;
}

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

// Begin Class CommonType

void setMonthlyPayment(double monthly_payment);
void setCreditOverpayment(double credit_overpayment);
void setTotalPayment(double total_payment);

double getMonthlyPayment() noexcept;
double getCreditOverpayment() noexcept;
double getTotalPayment() noexcept;

void calculate(double total_loan_amount, double period, double interest_rate);

void CalculatorModel::CreditCalculation::CommonType::setMonthlyPayment(double monthly_payment) {
    this->monthly_payment_ = monthly_payment;
}

void CalculatorModel::CreditCalculation::CommonType::setCreditOverpayment(double credit_overpayment) {
    this->credit_overpayment_ = credit_overpayment;
}

void CalculatorModel::CreditCalculation::CommonType::setTotalPayment(double total_payment) {
    this->total_payment_ = total_payment;
}

double CalculatorModel::CreditCalculation::CommonType::getMonthlyPayment() noexcept {

    return this->monthly_payment_;
}

double CalculatorModel::CreditCalculation::CommonType::getCreditOverpayment() noexcept {
    return this->credit_overpayment_;
}

double CalculatorModel::CreditCalculation::CommonType::getTotalPayment() noexcept {
    return this->total_payment_;
}

void CalculatorModel::CreditCalculation::Annuity::calculate(double total_loan_amount, double period, double interest_rate) {
 // TODO validator input
 double res_mounth = (total_loan_amount * (interest_rate * pow((1 + interest_rate), period)))/(pow(1 + interest_rate, period) - 1);
 double res_common_pay = res_mounth * period;
 double res_overpay = res_common_pay - total_loan_amount;

 this->setMonthlyPayment(res_mounth);
 this->setTotalPayment(res_common_pay);
 this->setCreditOverpayment(res_overpay);
}

void CalculatorModel::CreditCalculation::Differential::calculate(double total_loan_amount, double period, double interest_rate) {
 // TODO this
}

};
