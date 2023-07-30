#include "../headers/calculator-model.h"

namespace s21 {

// Begin Class Calculator

const std::string CalculatorModel::Calculation::checkFunction(size_t &i) {
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

void CalculatorModel::Calculation::clear() {
  this->lexems_.clear();
  this->polish_notation_.clear();
  this->expression_.clear();
}

const std::string CalculatorModel::Calculation::checkOperator(size_t &i) {
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
  return (i == 0 || expression_[i - 1] == '(');
}

double CalculatorModel::Calculation::calculate(const std::string &expression) {
  try {
    this->clear();

    this->setExpression(expression);

    this->devideOnLexems();

    this->polishConverter();

    this->polishCalculate();

    return this->data;
  } catch (const std::exception &e) {
    throw e;
  }
}

const std::string CalculatorModel::Calculation::expChecker(size_t &i) {
  std::string number{};
  if (i == 0 || !std::isdigit(expression_[i - 1])) {
    throw std::invalid_argument(
        "error: there is no number before the exponent");
  }
  lexems_.push_back("*");
  lexems_.push_back("10");
  lexems_.push_back("^");
  lexems_.push_back("(");
  ++i;
  if (expression_[i] == '+') {
    lexems_.push_back("unary_plus");
  } else if (expression_[i] == '-') {
    lexems_.push_back("unary_minus");
  } else {
    throw std::invalid_argument("error: incorrect exponent");
  }
  ++i;
  if (std::isdigit(expression_[i])) {
    number = numberValidation(i);
  } else {
    throw std::invalid_argument("error: incorrect exponent");
  }
  return number;
}

void CalculatorModel::Calculation::setExpression(
    const std::string &expression) {
  std::string str_check = expression;
  if (str_check == "") throw std::logic_error("incorrect expression");

  int count = std::count(str_check.begin(), str_check.end(), ')') +
              std::count(str_check.begin(), str_check.end(), '(');

  if ((count % 2)) throw std::logic_error("incorrect expression");

  this->expression_ = expression;
};

void CalculatorModel::Calculation::devideOnLexems() {
  for (size_t i{}; i < expression_.size();) {
    if (expression_[i] == 'e') {
      this->lexems_.push_back(expChecker(i));
      this->lexems_.push_back(")");
    } else if (std::isdigit(expression_[i])) {
      this->lexems_.push_back(numberValidation(i));
    } else if (std::isalpha(expression_[i])) {
      this->lexems_.push_back(checkFunction(i));
    } else {
      this->lexems_.push_back(checkOperator(i));
    }
  }
};

const std::string CalculatorModel::Calculation::numberValidation(size_t &i) {
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
          tmp_result.clear();
          throw std::invalid_argument("error: incorrect expression");
        }
      }
    }
    ++i;
  }
  if (tmp_result.size() != 1) {
    tmp_result.clear();
    throw std::invalid_argument("error: incorrect expression");
  }
  this->data = tmp_result[0];
  tmp_result.clear();
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
        int priority_in_stack =
            this->operators_.find(operator_stack.back())->second;
        while (priority_in_stack >= priority_in_expression) {
          polish_notation_.push_back(operator_stack.back());
          operator_stack.pop_back();
          if (operator_stack.empty()) {
            break;
          }
          priority_in_stack =
              this->operators_.find(operator_stack.back())->second;
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

// End Class Calculator

// Begin Class CommonType

std::vector<double>
CalculatorModel::CreditCalculation::CommonType::validateExpressions(
    const std::string &total_loan_amount, const std::string &period,
    const std::string &interest_rate) {
  if (total_loan_amount == "" || period == "" || interest_rate == "" ||
      !this->isNumber(total_loan_amount) || !this->isNumber(period) ||
      !this->isNumber(interest_rate))
    throw std::logic_error("conversion's numbers error");

  std::string total_loan_amount_tmp = total_loan_amount;
  std::string period_tmp = period;
  std::string interest_rate_tmp = interest_rate;

  double total_loan_res;
  double period_res;
  double interest_rate_res;

  total_loan_res = std::stod(total_loan_amount_tmp, nullptr);
  period_res = std::stod(period_tmp, nullptr);
  interest_rate_res = std::stod(interest_rate_tmp, nullptr);

  if (total_loan_res <= 0 || period_res <= 0 || interest_rate_res <= 0 ||
      !std::isnormal(total_loan_res) || !std::isnormal(period_res) ||
      !std::isnormal(interest_rate_res))
    throw std::logic_error("conversion's numbers error");

  std::vector<double> res;
  res.push_back(total_loan_res);
  res.push_back(period_res);
  res.push_back(interest_rate_res);

  return res;
}

bool CalculatorModel::CreditCalculation::CommonType::isNumber(
    const std::string &str) {
  std::string::const_iterator it = str.begin();
  while (it != str.end() && std::isdigit(*it)) ++it;
  return !str.empty() && it == str.end();
}

// End Class CommonType

// Begin Class Annuity

std::map<std::string, std::vector<double>>
CalculatorModel::CreditCalculation::Annuity::calculate(
    const std::string &total_loan_amount, const std::string &period,
    const std::string &interest_rate) {
  try {
    std::vector<double> variables =
        this->validateExpressions(total_loan_amount, period, interest_rate);
    this->calculateCredit(variables);

    return this->getResult();

  } catch (std::exception &e) {
    throw e;
  }
}

void CalculatorModel::CreditCalculation::Annuity::calculateCredit(
    const std::vector<double> &variables) {
  if (variables.empty() && variables.size() < 3)
    throw std::logic_error("empty error");

  double S = variables[0];
  double N = variables[1];
  double R = variables[2] / 12.0 / 100.0;

  double res_mounth = S * (R * pow(1 + R, N)) / (pow(1 + R, N) - 1);
  res_mounth = round(res_mounth * 100.0) / 100.0;
  double res_overpay = res_mounth * N - S;
  res_overpay = round(res_overpay * 100.0) / 100.0;
  double res_common_pay = res_overpay + S;
  res_common_pay = round(res_common_pay * 100) / 100;

  if (!std::isnormal(res_mounth) || !std::isnormal(res_common_pay) ||
      !std::isnormal(res_overpay))
    throw std::logic_error("error");

  std::vector<double> res_mounths;

  for (int i = 0; i < (int)N; i++) res_mounths.push_back(res_mounth);

  std::map<std::string, std::vector<double>> res = {
      {"TotalPayment", {res_common_pay}},
      {"CreditOverpayment", {res_overpay}},
      {"MounthPayments", res_mounths}};

  this->setResult(res);
}

// End Class Annuity

// Begin Class Differential

std::map<std::string, double> calculateCredit(
    const std::vector<double> &variables);

std::map<std::string, std::vector<double>>
CalculatorModel::CreditCalculation::Differential::calculate(
    const std::string &total_loan_amount, const std::string &period,
    const std::string &interest_rate) {
  try {
    std::vector<double> variables =
        this->validateExpressions(total_loan_amount, period, interest_rate);
    this->calculateCredit(variables);

    return this->getResult();

  } catch (std::exception &e) {
    throw e;
  }
}

void CalculatorModel::CreditCalculation::Differential::calculateCredit(
    const std::vector<double> &variables) {
  if (variables.empty() && variables.size() < 3)
    throw std::logic_error("empty error");

  double S = variables[0];
  double N = variables[1];
  double R = variables[2] / 100.0 / 12.0;
  double D = S / N;
  double res_overpay = 0;

  std::vector<double> res_mounths;

  for (int i = 1; i <= N; i++) {
    double q = S / N;
    double tmp = D + (S - D * (i - 1)) * R;
    tmp = round(tmp * 100) / 100;
    res_mounths.push_back(tmp);

    res_overpay += tmp - q;
  }

  double res_common_pay = res_overpay + S;
  res_common_pay = round(res_common_pay * 100) / 100;

  if (!std::isnormal(res_mounths[0]) || !std::isnormal(res_overpay) ||
      !std::isnormal(res_common_pay))
    throw std::logic_error("error");

  std::map<std::string, std::vector<double>> res = {
      {"TotalPayment", {res_common_pay}},
      {"CreditOverpayment", {res_overpay}},
      {"MounthPayments", res_mounths}};

  this->setResult(res);
}
// End Class Differential

};  //  namespace s21
