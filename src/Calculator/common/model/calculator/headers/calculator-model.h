#ifndef CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_COMMON_MODEL_CALCULATOR_HEADERS_CALCULATORMODEL_H
#define CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_COMMON_MODEL_CALCULATOR_HEADERS_CALCULATORMODEL_H

#include <algorithm>
#include <cmath>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

namespace s21 {

class CalculatorModel {
 public:
  class Calculation {  // This inner class used to calculate a common
                       // calculations
   public:
    double calculate(const std::string &expression);
    double getData() noexcept { return this->data; };
    std::string getExpression() noexcept { return this->expression_; };
    void clear();

   private:
    const std::string checkFunction(size_t &i);
    const std::string checkOperator(size_t &i);
    bool unaryOperator(size_t i) noexcept;
    void setExpression(const std::string &expression);
    void devideOnLexems();
    void polishCalculate();
    void polishConverter();
    const std::string numberValidation(size_t &i);
    const std::string expChecker(size_t &i);

    std::string expression_;
    std::vector<std::string> lexems_{};
    std::vector<std::string> polish_notation_{};
    double data;
    const std::map<std::string, int> operators_ = {
        {"+", 1},          {"-", 1},    {"*", 2},    {"/", 2},
        {"^", 3},          {"mod", 2},  {"cos", 4},  {"sin", 4},
        {"tan", 4},        {"acos", 4}, {"asin", 4}, {"atan", 4},
        {"sqrt", 4},       {"ln", 4},   {"log", 4},  {"unary_minus", 5},
        {"unary_plus", 5}, {"(", 0},    {")", 0}};
  };

  class CreditCalculation {  // This inner class used to calculate a
                             // credit calculations
   private:
    class CommonType {
     public:
      const std::map<std::string, std::vector<double>> &getResult()
          const noexcept {
        return this->result_;
      };

      void setResult(const std::map<std::string, std::vector<double>> &result) {
        this->result_ = result;
      };

     protected:
      std::vector<double> validateExpressions(
          const std::string &total_loan_amount, const std::string &period,
          const std::string &interest_rate);
      bool isNumber(const std::string &str);

     private:
      std::map<std::string, std::vector<double>> result_;
    };

   public:
    class Annuity : public CommonType {
     public:
      std::map<std::string, std::vector<double>> calculate(
          const std::string &total_loan_amount, const std::string &period,
          const std::string &interest_rate);

     private:
      void calculateCredit(const std::vector<double> &variables);
    };

    class Differential : public CommonType {
     public:
      std::map<std::string, std::vector<double>> calculate(
          const std::string &total_loan_amount, const std::string &period,
          const std::string &interest_rate);

     private:
      void calculateCredit(const std::vector<double> &variables);
    };

    Annuity annuity_calculation;
    Differential differential_calculation;
  };

  s21::CalculatorModel::Calculation calculator;
  s21::CalculatorModel::CreditCalculation::Annuity credit_calculator_annuity;
  s21::CalculatorModel::CreditCalculation::Differential credit_calculator_diff;
};
};      // namespace s21
#endif  // CPP3_3_SMARTCALC_V2_0_1_SRC_CALCULATOR_COMMON_MODEL_CALCULATOR_HEADERS_CALCULATORMODEL_H
