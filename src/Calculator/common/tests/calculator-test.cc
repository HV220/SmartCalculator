#include <gtest/gtest.h>

#include "../model/calculator/headers/calculator-model.h"
#include <iostream>
#include <iterator>
#include <map>

using namespace s21;
class CalcTest : public ::testing::Test {
protected:
  void SetUp() override {}
  s21::CalculatorModel model = s21::CalculatorModel();
  s21::CalculatorModel::CreditCalculation credit =
      s21::CalculatorModel::CreditCalculation();

  s21::CalculatorModel::Calculation calc = s21::CalculatorModel::Calculation();
  s21::CalculatorModel::CreditCalculation::Annuity calc_credit_annuity =
      s21::CalculatorModel::CreditCalculation::Annuity();
  s21::CalculatorModel::CreditCalculation::Differential calc_credit_diff =
      s21::CalculatorModel::CreditCalculation::Differential();

  std::string total_loan_amount;
  std::string period;
  std::string interest_rate;
};

TEST_F(CalcTest, ModelTest_1) { EXPECT_NO_THROW(model.save(&calc, &credit)); }

TEST_F(CalcTest, ModelTest_2) { EXPECT_NO_THROW(model.reset()); }

TEST_F(CalcTest, CalculationTest_1) {
  EXPECT_ANY_THROW(calc.calculate("12+1("));
}

TEST_F(CalcTest, CalculationTest_2) {
  EXPECT_ANY_THROW(calc.calculate(
      "cos(10)+sin(10)-tan(12)/acos(12)*asin(12)+atan(12)-2^2*ln(12)+log(9)/"
      "(-1)*(12331)("
      "2mod3("));
}

TEST_F(CalcTest, CalculationTest_3) {
  EXPECT_NO_THROW(calc.calculate("cos(1)+sin(1)"));
}

TEST_F(CalcTest, CalculationTest_4) { EXPECT_ANY_THROW(calc.calculate("")); }

TEST_F(CalcTest, CalculationTest_5) {
  EXPECT_ANY_THROW(calc.calculate("(1+2+3+4+5)+((1+1))+(12.23.3+123.3.4.5.6)"));
}

TEST_F(CalcTest, CalculationTest_6) {
  EXPECT_NO_THROW(calc.calculate(
      "21."
      "3333333333333333333333333333333333333333333333333333333333333333333333"
      "3333333333333333333333333333333333333333333333333333333333333333333333"
      "3333333333333333333333333333333333333333"
      "+12312313.000000"));
}

TEST_F(CalcTest, CalculationTest_7) {
  EXPECT_ANY_THROW(calc.calculate("caas(1)"));
}

TEST_F(CalcTest, CreditAnnuityTest_1) {
  total_loan_amount = "1.22.3";
  period = "12";
  interest_rate = "";

  EXPECT_ANY_THROW(
      calc_credit_annuity.calculate(total_loan_amount, period, interest_rate));
}

TEST_F(CalcTest, CreditAnnuityTest_2) {
  total_loan_amount = "12";
  period = "12";
  interest_rate = "12";

  EXPECT_NO_THROW(
      calc_credit_annuity.calculate(total_loan_amount, period, interest_rate));
}

TEST_F(CalcTest, CreditAnnuityTest_3) {
  total_loan_amount = "";
  period = "1.2";
  interest_rate = "12";

  EXPECT_ANY_THROW(
      calc_credit_annuity.calculate(total_loan_amount, period, interest_rate));
}

TEST_F(CalcTest, CreditAnnuityTest_5) {
  total_loan_amount = "123-12312";
  period = "1.2";
  interest_rate = "12";

  EXPECT_ANY_THROW(
      calc_credit_annuity.calculate(total_loan_amount, period, interest_rate));
}

TEST_F(CalcTest, CreditDiffTest_1) {
  total_loan_amount = "1.22.3";
  period = "12";
  interest_rate = "";

  EXPECT_ANY_THROW(
      calc_credit_diff.calculate(total_loan_amount, period, interest_rate));
}

TEST_F(CalcTest, CreditDiffTest_2) {
  total_loan_amount = "12";
  period = "12";
  interest_rate = "12";

  EXPECT_NO_THROW(
      calc_credit_diff.calculate(total_loan_amount, period, interest_rate));
}

TEST_F(CalcTest, CreditDiffTest_3) {
  total_loan_amount = "";
  period = "1.2";
  interest_rate = "12";

  EXPECT_ANY_THROW(
      calc_credit_diff.calculate(total_loan_amount, period, interest_rate));
}

TEST_F(CalcTest, CreditDiffTest_5) {
  total_loan_amount = "123-12312";
  period = "1.2";
  interest_rate = "12";

  EXPECT_ANY_THROW(
      calc_credit_diff.calculate(total_loan_amount, period, interest_rate));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
