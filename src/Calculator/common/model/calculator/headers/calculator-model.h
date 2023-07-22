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
    const std::map<std::string, int> operators_ = {
        {"+", 1},          {"-", 1},    {"*", 2},    {"/", 2},
        {"^", 3},          {"mod", 2},  {"cos", 4},  {"sin", 4},
        {"tan", 4},        {"acos", 4}, {"asin", 4}, {"atan", 4},
        {"sqrt", 4},       {"ln", 4},   {"log", 4},  {"unary_minus", 5},
        {"unary_plus", 5}, {"(", 0},    {")", 0}};

   public:
    double calculate(const std::string &expression);
    double getData() noexcept { return this->data; };
    std::string getExpression() noexcept { return this->expression_; };

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

  //  class DepositCalculation {
  //  private:
  //    double accrued_interest_;
  //    double amount_taxation_;
  //    double end_sum_deposit_;

  //  public:
  //    struct InputData {
  //    private:
  //      std::string deposit_amount;
  //      std::string placement_term;
  //      std::string interest_rate;
  //      std::string tax_rate;
  //      std::string payment_frequency;
  //      std::string interest_capitalization;
  //      int status_capitalisation;

  //      std::vector<std::string> replenishment_list;
  //      std::vector<std::string> partial_withdrawals_list;

  //    public:
  //      const std::string &getDepositAmount() const { return deposit_amount; }
  //      void setDepositAmount(const std::string &amount) { deposit_amount =
  //      amount; }

  //      const std::string &getPlacementTerm() const { return placement_term; }
  //      void setPlacementTerm(const std::string &term) { placement_term =
  //      term; }

  //      const std::string &getInterestRate() const { return interest_rate; }
  //      void setInterestRate(const std::string &rate) { interest_rate = rate;
  //      }

  //      const std::string &getTaxRate() const { return tax_rate; }
  //      void setTaxRate(const std::string &rate) { tax_rate = rate; }

  //      const std::string &getPaymentFrequency() const { return
  //      payment_frequency; } void setPaymentFrequency(const std::string
  //      &frequency) {
  //        payment_frequency = frequency;
  //      }

  //      const std::string &getInterestCapitalization() const {
  //        return interest_capitalization;
  //      }

  //      void setInterestCapitalization(const std::string &capitalization) {
  //        interest_capitalization = capitalization;
  //      }

  //      const int &getStatusCapitalisation() const {
  //        return status_capitalisation;
  //      }
  //      void setStatusCapitalisation(const int &status) {
  //        status_capitalisation = status;
  //      }

  //      const std::vector<std::string> &getReplenishmentList() const {
  //        return replenishment_list;
  //      }

  //      void setReplenishmentList(const std::vector<std::string> &list) {
  //        replenishment_list = list;
  //      }

  //      const std::vector<std::string> &getPartialWithdrawalsList() const {
  //        return partial_withdrawals_list;
  //      }
  //      void setPartialWithdrawalsList(const std::vector<std::string> &list) {
  //        partial_withdrawals_list = list;
  //      }
  //    } InputData;

  //  public:
  //    const double &getAccruedInterest() const {
  //      return this->accrued_interest_;
  //    };
  //    void setAccruedInterest(const double &interest) {
  //      this->accrued_interest_ = interest;
  //    };

  //    const double &getAmountTaxation() const { return this->amount_taxation_;
  //    }; void setAmountTaxation(const double &taxation) {
  //      this->amount_taxation_ = taxation;
  //    };

  //    const double &getEndSumDeposit() const { return this->end_sum_deposit_;
  //    }; void setEndSumDeposit(const double &sum_deposit) {
  //      this->end_sum_deposit_ = sum_deposit;
  //    };

  //    void calculate(const struct InputData& Data);

  //  private:
  //    std::map<std::string, double> validateExpressions(const struct InputData
  //    Data); std::map<std::string, std::vector<double>> validateList(const
  //    struct InputData Data); void calculateDeposit(const
  //    std::map<std::string, double> variables,
  //                          const std::map<std::string, std::vector<double>>
  //                          lists, const struct InputData &Data);
  //    std::string validateNullorEmpty(std::string str);
  //    double changeToDouble(std::string num);
  //    std::vector<double> changeToDouble(const std::vector<std::string> num);
  //    void simplePercent(const std::map<std::string, double> variables,
  //                       const std::map<std::string, std::vector<double>>
  //                       lists, const struct InputData &Data);
  //  };

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
