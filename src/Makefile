GCC = g++ -std=c++17 -g -Wall -Werror -Wextra
TEST = Calculator/common/tests/*-test.cc
MODEL = Calculator/common/model/calculator/sourses/*.cc
GCOV =--coverage
LIBA = *.a
LIBO = *.o
OS = $(shell uname)
FILECASE= Calculator/common/model/calculator/headers/*.h \
	Calculator/common/model/calculator/sourses/*.cc \
	Calculator/calculator/controller/headers/*.h \
	Calculator/calculator/controller/sourses/*.cc \
	Calculator/calculator/view/calculator/sourses/*.cc \
	Calculator/calculator/view/calculator/headers/*.h

ifeq ($(OS), Darwin)
LIBFLAGS = -lm -lgtest -lstdc++ -lgtest_main
else
	LIBFLAGS=-lstdc++ `pkg-config --cflags --libs gtest  --libs gtest_main`
endif

all: clean test

tests: clean
	$(GCC) $(TEST) $(MODEL) $(LIBFLAGS)  -o test
	./test

clean:
	rm -rf *.o *.a  *.out test *.dSYM  report coverage.info *.gcda *.gcno *.txt


dvi:
	open ./readme.html

dist:
	rm -rf Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/src
	cp -rf Makefile Calculator Archive_SmartCalc_v2.0/src/
	tar cvzf Archive_SmartCalc_v2.0.tgz Archive_SmartCalc_v2.0/
	mv Archive_SmartCalc_v2.0.tgz $(HOME)/Desktop/
	rm -rf Archive_SmartCalc_v2.0/

s21_calculator.a: clean
	$(GCC) -c $(TEST)
	ar rcs $(LIBA) $(LIBO)
	ranlib $(LIBA)

gcov_report: s21_calculator.a
	$(GCC) $(GCOV) $(MODEL) $(LIBA) -L. $(LIBA)  $(LIBFLAGS) -o test
	./test
	lcov -t "test" -c -d  ./ --no-external --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

install:
ifeq ($(OS), Darwin)
else
	make clean
	mkdir build
	cd build && qmake ../Calculator/Calculator.pro && make
	./build/Calculator
endif

uninstall: 
	rm -rf build*

check:
	cp ../materials/linters/.clang-format ./
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(FILECASE)
	clang-format -style=Google -n $(FILECASE)
	clang-format -style=Google -i $(FILECASE)

ifeq ($(OS), Darwin)
	leaks --atExit -- test
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
endif