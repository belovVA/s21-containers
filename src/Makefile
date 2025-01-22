CC = gcc
CFLAG = -Werror -Wextra -Wall -std=c++17 --coverage
TESTC = TestContaner/*.cpp
TESTC0 = TestContaner/test_main.cpp
TESTC1 = TestContaner/test_multiset.cpp
TESTC2 = TestContaner/test_set.cpp
COMMON = */*.tpp
TESTFLAGS= -pthread -lgtest -lgcov -lm 
LCOVFLAGS = --ignore-errors inconsistent
CHECK_FLAG = -lstdc++

all: test

test: clean
	$(CC) $(CFLAG) $(TESTC) $(COMMON) $(CHECK_FLAG) $(TESTFLAGS) -o test 
	./test

clean:
	rm -rf test gcov_report report *test coverage *.o *.gcda *.gcno *.info *.dSYM *.txt

check:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format --style=Google -n */*.cpp */*.h *.h */*.tpp
	rm .clang-format

format:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format --style=Google -i */*.cpp */*.h *.h */*.tpp
	rm .clang-format

gcov_report: test
	lcov -t "test" -o test.info -c -d ./ --no-external $(LCOVFLAGS)
	lcov --remove test.info 'TestContaner/*.cpp' --output-file test.info
	genhtml -o report test.info $(LCOVFLAGS)
	open report/index.html
	rm -rf *.gcda *.gcno test test.info
