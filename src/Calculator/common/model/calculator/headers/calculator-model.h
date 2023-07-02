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
    std::map<std::string, int> operators_ = { // TODO change on const
        {"+", 1},          {"-", 1},    {"*", 2},    {"/", 2},
        {"^", 3},          {"mod", 2},  {"cos", 4},  {"sin", 4},
        {"tan", 4},        {"acos", 4}, {"asin", 4}, {"atan", 4},
        {"sqrt", 4},       {"ln", 4},   {"log", 4},  {"unary_minus", 5},
        {"unary_plus", 5}, {"(", 0},    {")", 0}};

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

  class CreditCalculation {
   private:
    class CommonType {
     private:
      double monthly_payment_;
      double credit_overpayment_;
      double total_payment_;

     public:
      void setMonthlyPayment(double monthly_payment);
      void setCreditOverpayment(double credit_overpayment);
      void setTotalPayment(double total_payment);

      double getMonthlyPayment() noexcept;
      double getCreditOverpayment() noexcept;
      double getTotalPayment() noexcept;

     protected:
      std::vector<double> validateExpressions(QString total_loan_amount,
                                              QString period,
                                              QString interest_rate);
    };

   public:
    class Annuity : public CommonType {
     public:
      void calculate(QString total_loan_amount, QString period,
                     QString interest_rate);
    private:
      void calculateCredit(std::vector<double> variables);
    };

    class Differential : public CommonType {
     private:
      std::vector<double> month_payments_;

     public:
      std::vector<double> getMonthPayments();
      void setMonthPayments(std::vector<double> month_payments);
      void calculate(QString total_loan_amount, QString period,
                     QString interest_rate);
      private:
      void calculateCredit(std::vector<double> variables);
    };

   public:
    void setAnnuityCalc(Annuity calculation);
    void setDiffCalc(Differential calculation);
    std::vector<Annuity> getAnnuityCalc() noexcept;
    std::vector<Differential> getDiffCalc() noexcept;

    std::vector<Annuity> Annuity_calculation{};
    std::vector<Differential> Differential_calculation{};
  };

 public:
  QVector<Calculation> getCalculations() noexcept;
  Calculation getLastCalculation();
  void setCalculations(QVector<Calculation> calculations) noexcept;
  void setLastCalculation(Calculation calculation) noexcept;

  QVector<CreditCalculation> getCreditCalculation() noexcept;
  CreditCalculation getLastCreditCalculation();
  void setCreditCalculations(QVector<CreditCalculation> credit_calculations) noexcept;
  void setLastCreditCalculation(CreditCalculation credit_calculation) noexcept;
  void reset();

 private:
  QVector<Calculation> calculations{};
  QVector<CreditCalculation> credit_calculations{};
};

};      // namespace s21
#endif  // CALCULATORMODEL_H
