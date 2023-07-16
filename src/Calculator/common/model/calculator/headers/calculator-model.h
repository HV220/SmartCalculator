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
    std::map<std::string, int> operators_ = {  // TODO change on const
        {"+", 1},          {"-", 1},    {"*", 2},    {"/", 2},
        {"^", 3},          {"mod", 2},  {"cos", 4},  {"sin", 4},
        {"tan", 4},        {"acos", 4}, {"asin", 4}, {"atan", 4},
        {"sqrt", 4},       {"ln", 4},   {"log", 4},  {"unary_minus", 5},
        {"unary_plus", 5}, {"(", 0},    {")", 0}};

   public:
    struct graficData {
     private:
      std::vector<double> x{};
      std::vector<double> y{};
      double xBegin, xEnd, yBegin, yEnd, h;

     public:
      const std::vector<double>& getX() const { return x; }
      const std::vector<double>& getY() const { return y; }
      double getXBegin() const { return xBegin; }
      double getXEnd() const { return xEnd; }
      double getYBegin() const { return yBegin; }
      double getYEnd() const { return yEnd; }
      double getH() const { return h; }

      void setX(const std::vector<double>& newX) { x = newX; }
      void setY(const std::vector<double>& newY) { y = newY; }
      void setXBegin(double newXBegin) { xBegin = newXBegin; }
      void setXEnd(double newXEnd) { xEnd = newXEnd; }
      void setYBegin(double newYBegin) { yBegin = newYBegin; }
      void setYEnd(double newYEnd) { yEnd = newYEnd; }
      void setH(double newH) { h = newH; }
    };

   public:
    const struct graficData& calculateGrafic(
        const struct graficData& grafic_data, const QString* expression);
    double calculate(const QString* expression);
    double getData() noexcept;
    void clear() noexcept;

   private:
    std::string getExpression() noexcept;
    const std::string checkFunction(size_t& i);
    const std::string checkOperator(size_t& i);
    bool unaryOperator(size_t i) noexcept;
    void setExpression(const QString* expression);
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
      double getMonthlyPayment() noexcept;
      void setMonthlyPayment(double monthly_payment);

      double getCreditOverpayment() noexcept;
      void setCreditOverpayment(double credit_overpayment);

      double getTotalPayment() noexcept;
      void setTotalPayment(double total_payment);

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

  class DepositCalculation {
   private:
    double accrued_interest_;
    double amount_taxation_;
    double end_sum_deposit_;

   public:
    struct InputData {
     private:
      QString deposit_amount;
      QString placement_term;
      QString interest_rate;
      QString tax_rate;
      QString payment_frequency;
      QString interest_capitalization;
      int status_capitalisation;

      std::vector<QString> replenishment_list;
      std::vector<QString> partial_withdrawals_list;

     public:
      const QString& getDepositAmount() const { return deposit_amount; }
      void setDepositAmount(const QString& amount) { deposit_amount = amount; }

      const QString& getPlacementTerm() const { return placement_term; }
      void setPlacementTerm(const QString& term) { placement_term = term; }

      const QString& getInterestRate() const { return interest_rate; }
      void setInterestRate(const QString& rate) { interest_rate = rate; }

      const QString& getTaxRate() const { return tax_rate; }
      void setTaxRate(const QString& rate) { tax_rate = rate; }

      const QString& getPaymentFrequency() const { return payment_frequency; }
      void setPaymentFrequency(const QString& frequency) {
        payment_frequency = frequency;
      }

      const QString& getInterestCapitalization() const {
        return interest_capitalization;
      }
      void setInterestCapitalization(const QString& capitalization) {
        interest_capitalization = capitalization;
      }

      const int& getStatusCapitalisation() const {
        return status_capitalisation;
      }
      void setStatusCapitalisation(const int& status) {
        status_capitalisation = status;
      }

      const std::vector<QString>& getReplenishmentList() const {
        return replenishment_list;
      }
      void setReplenishmentList(const std::vector<QString>& list) {
        replenishment_list = list;
      }

      const std::vector<QString>& getPartialWithdrawalsList() const {
        return partial_withdrawals_list;
      }
      void setPartialWithdrawalsList(const std::vector<QString>& list) {
        partial_withdrawals_list = list;
      }
    } InputData;

   public:
    const double& getAccruedInterest() const {
      return this->accrued_interest_;
    };
    void setAccruedInterest(const double& interest) {
      this->accrued_interest_ = interest;
    };

    const double& getAmountTaxation() const { return this->amount_taxation_; };
    void setAmountTaxation(const double& taxation) {
      this->amount_taxation_ = taxation;
    };

    const double& getEndSumDeposit() const { return this->end_sum_deposit_; };
    void setEndSumDeposit(const double& sum_deposit) {
      this->end_sum_deposit_ = sum_deposit;
    };

    void calculate(const struct InputData Data);

   private:
    std::map<QString, double> validateExpressions(const struct InputData Data);
    std::map<QString, std::vector<double>> validateList(
        const struct InputData Data);
    void calculateDeposit(const std::map<QString, double> variables,
                          const std::map<QString, std::vector<double>> lists,
                          const struct InputData& Data);
    QString validateNullorEmpty(QString str);
    double changeToDouble(QString num);
    std::vector<double> changeToDouble(const std::vector<QString> num);
    void simplePercent(const std::map<QString, double> variables,
                       const std::map<QString, std::vector<double>> lists,
                       const struct InputData& Data);
  };
  //  Расчет по простой формуле

  //  Начисления процентов по вкладам без капитализации по простой формуле:

  //  S=(P*I*t:K):100.

  //  Обозначения:

  //      S – начисленный профит.
  //      P – сумма вклада.
  //      I – годовая ставка по депозиту.
  //      t – срок депозита (к-во дней).
  //      K – число дней в году (при расчете процентов всегда берется 365 дней,
  //      даже в високосный год).

  //  Если клиент вложил 50 000 руб. сроком на год под 4,7%, его доход составит
  //  2350 рублей: (50 000*4,7*365):100=2350.
 public:
  QVector<Calculation> getCalculations() noexcept;
  Calculation getLastCalculation();
  void setCalculations(QVector<Calculation> calculations) noexcept;
  void setLastCalculation(Calculation calculation) noexcept;

  QVector<CreditCalculation> getCreditCalculation() noexcept;
  CreditCalculation getLastCreditCalculation();
  void setCreditCalculations(
      QVector<CreditCalculation> credit_calculations) noexcept;
  void setLastCreditCalculation(CreditCalculation credit_calculation) noexcept;
  void reset();

 private:
  QVector<Calculation> calculations{};
  QVector<CreditCalculation> credit_calculations{};
};

};      // namespace s21
#endif  // CALCULATORMODEL_H
