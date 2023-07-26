#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

namespace s21 {

class CalculatorModel {
 public:
 CalculatorModel() = default;
 ~CalculatorModel() {
  this->calculations_.clear();
  this->credit_calculations_.clear();
 }

  class Calculation {
   private:
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

   public:
   Calculation() = default;
   ~Calculation() {
    this->lexems_.clear();
    this->polish_notation_.clear();
    this->expression_.clear();
   };

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
  };

  class CreditCalculation {
   private:
    class CommonType {
     private:
      std::map<std::string, std::vector<double>> result_;
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

   public:
    void setAnnuityCalc(const Annuity &calculation) {
      this->annuity_calculation_.push_back(calculation);
    };

    void setDiffCalc(const Differential &calculation) {
      this->differential_calculation_.push_back(calculation);
    };

    std::vector<Annuity> getAnnuityCalc() noexcept {
      return this->annuity_calculation_;
    };
    std::vector<Differential> getDiffCalc() noexcept {
      return this->differential_calculation_;
    };

    std::vector<Annuity> annuity_calculation_{};
    std::vector<Differential> differential_calculation_{};
  };

 public:
  const std::vector<Calculation> &getCalculations() noexcept {
    return this->calculations_;
  };
  const Calculation &getLastCalculation() {
    return this->calculations_.back();
  };

  const std::vector<CreditCalculation> &getCreditCalculation() noexcept {
    return this->credit_calculations_;
  };
  const CreditCalculation &getLastCreditCalculation() {
    return this->credit_calculations_.back();
  };

  void reset();

  void save(const Calculation *calc = nullptr,
            const CreditCalculation *credit_calc = nullptr);

 private:
  std::vector<Calculation> calculations_{};
  std::vector<CreditCalculation> credit_calculations_{};
};

};      // namespace s21
#endif  // CALCULATORMODEL_H
