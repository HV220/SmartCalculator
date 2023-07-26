#include <gtest/gtest.h>

#include <iostream>
#include <iterator>
#include <map>
#include "../../model/calculator/headers/calculator-model.h"

using namespace s21;

TEST(s21_parser_test, trueTest) {
    
    s21::CalculatorModel::Calculation q = s21::CalculatorModel::Calculation();
    std::string str = "1+51/2/4123432432/423/4234/24/324234";
  
    // ck_assert_ptr_eq(tmp, NULL);
    // str =
    //     "cos(10)+sin(10)-tan(12)/acos(12)*asin(12)+atan(12)-2^2*ln(12)+log(9)/"
    //     "(-1)*(12331)("
    //     "2mod3(";
    // tmp = parcer(str);
    // EXPECT_NO_THROW(test);
    // EXPECT_ANY_THROW(q.calculate(str));
    // str = "2mo3";
    // tmp = parcer(str);
    // ck_assert_ptr_eq(tmp, NULL);
    // while (tmp) clear_stack(&tmp);
}

TEST(s21_OPN_test, trueTest) {
    // lexems_t *res = NULL;
    // lexems_t *buf = NULL;
    // int error = 0;
    // char *src =
    //     "(+1)-sin(1)-sin(1)+sin(1)-cos(1)+tan(1)-(cos(1)-cos(1))-sqrt(1)-2^2/"
    //     "(4+1-1*23*5/4/6)/((cos(1)+cos(2))/(1+2+3))/7";
    // res = parcer(src);
    // transpose_struct(&buf, res);
    // double test = OPN(buf, &error);
    // ck_assert_double_eq_tol(test, -132.3770670067721922, 1e-7);
    // while (res) clear_stack(&res);
    // while (buf) clear_stack(&buf);
    // src = "(-1)+2+log(1)";
    // res = parcer(src);
    // transpose_struct(&buf, res);
    // test = OPN(buf, &error);
    // ck_assert_double_eq_tol(test, (double)1, 1e-7);
    // while (res) clear_stack(&res);
    // while (buf) clear_stack(&buf);
    // src = "12//";
    // res = parcer(src);
    // transpose_struct(&buf, res);
    // test = OPN(buf, &error);
    // ck_assert_double_eq_tol(test, (double)1, 1e-7);
    // while (res) clear_stack(&res);
    // while (buf) clear_stack(&buf);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}