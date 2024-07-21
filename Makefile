SHELL = /bin/sh

CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra
LFLAGS = -lgtest -lpthread -lgtest_main
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
EXE_NAME = test
LIB_NAME = s21_matrix_oop.a

LIB_SRC = $(wildcard lib/*.cpp)
TEST_SRC = $(wildcard tests/*.cpp)

LIB_O = $(LIB_SRC:.cpp=.o)
TEST_O = $(TEST_SRC:.cpp=.o)

GCOV_NAME = gcov_tests.info

.PHONY: all clean test s21_matrix_oop.a clang_check clang_fix gcov_report rebuild valgrind_test cppcheck_test

all: clean s21_matrix_oop.a

s21_matrix_oop.a: $(LIB_O)
	@ar rc $(LIB_NAME) $(LIB_O)
	@ranlib $(LIB_NAME)
	@rm -rf lib/*.o

test: $(TEST_O) $(LIB_NAME)
	@$(CC) $(CFLAGS) $(TEST_O) -o $(EXE_NAME) -L. -l:$(LIB_NAME) $(LFLAGS)
	@rm -rf $(TEST_O)
	@./$(EXE_NAME)
	@rm $(LIB_NAME)

#if you don't have Gtest - sudo apt install libgtest-dev

gcov_report: clean
	$(CC) $(CFLAGS) -c $(LIB_SRC) --coverage
	$(CC) $(CFLAGS) -c $(TEST_SRC) 
	$(CC) *.o -o $(EXE_NAME) $(LFLAGS) $(GCOV_FLAGS)
	./$(EXE_NAME)
	lcov -t "gcov_tests" -o $(GCOV_NAME) -c -d .
	genhtml -o report $(GCOV_NAME)
	rm -rf *.o *.gcno *.gcda *.gcov $(GCOV_NAME)
	rm -rf $(EXE_NAME)

clean:
	rm -f $(LIB_NAME) $(EXE_NAME) ./lib/*.o
	rm -rf ./lib/*.o ./tests/*.o *.gcno *.gcda *.gch ./report *.o ./lib/*.gcno
	rm -rf $(EXE_NAME)

clang_check:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.cpp *.h lib/*.cpp tests/*.cpp tests/*.h
	rm -rf .clang-format

clang_fix:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.cpp *.h lib/*.cpp tests/*.cpp tests/*.h
	rm -rf .clang-format

rebuild: clean s21_matrix_oop.a test

valgrind_test: rebuild
	valgrind --tool=memcheck --leak-check=yes --show-leak-kinds=all --track-origins=yes -s ./$(EXE_NAME)

cppcheck_test: 
	cppcheck --enable=all --suppress=missingIncludeSystem $(LIB_SRC)