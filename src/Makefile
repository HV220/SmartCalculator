# all, install, uninstall, clean, dvi, dist, tests

CPP = g++ -std=c++17
CPPFLAGS = -Wall -Werror -Wextra
NAMEOFFILE = calculator-model
TESTFILES = 
SOURCE = Calculator/common/model/calculator/sourses/calculator-model.cc

all: clean $(NAMEOFFILE).a test check

clean:
	@rm -rf *.out *.gcda *.gcno *.a *.info *.o s21_matrix.dSYM test report

calculator.a:
	@$(CPP) $(CPPFLAGS) $(SOURCE) -c
	@ar rcs $(NAMEOFFILE).a *.o
	@ranlib $(NAMEOFFILE).a

test: calculator.a
	@clear
	@$(CPP) $(CPPFLAGS) Calculator/common/tests/calculator/calculator-test.cc $(NAMEOFFILE).a -o test -lgtest
	./test

gcov_report:
	@$(CPP) $(CPPFLAGS) -fprofile-arcs -ftest-coverage $(NAMEOFFILE)_test.cpp $(NAMEOFFILE).cpp -o test -lgtest
	@./test
	@lcov -t "test" -o test.info -c -d .
	@genhtml -o report test.info
	@open ./report/index.html

check:
	clang-format -style=Google -i Calculator/common/model/calculator/headers/calculator-model.h
	clang-format -style=Google -i Calculator/common/model/calculator/sourses/calculator-model.cc
	clang-format -style=Google -i Calculator/calculator/controller/headers/calculator-controller.h
	clang-format -style=Google -i Calculator/calculator/controller/sourses/calculator-controller.cc
	clang-format -style=Google -i Calculator/calculator/view/calculator/sourses/calculator-view.cc
	clang-format -style=Google -i Calculator/calculator/view/calculator/headers/calculator-view.h