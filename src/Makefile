OS=$(shell uname)
CC=gcc
ODIR = core
CFLAGS = -std=c11 -g
pFLAGS = -std=c11 -Werror -Wextra -Wall -g -lm
LIB_TEST_DIR = tests
ifeq ($(OS), Darwin)
 CHECK= -lcheck -lpthread -lm 
else
 CHECK= -lcheck -lpthread -lm -lsubunit
endif
SOURCE = s21_*.c tests/s21_*.c core/s21_*.c
SRC = $(wildcard s21_*.c)
# TARGET = Calculator_v1.0

all: main

main: clear s21_calc.a test

s21_calc.o:
	$(CC) $(pFLAGS) -c $(SRC) core/s21_*.c


s21_calc.a: s21_calc.o
	ar rcs s21_calc.a s21_*.o
	ranlib s21_calc.a

test: s21_calc.a
	$(CC) $(CFLAGS) tests/s21_*.c s21_calc.a $(CHECK) -o test
	./test

rebuild: clean all

start: 
	gcc s21*.c s21*.h $(pFLAGS)
	./a.out
gcov_report: s21_calc.a
	$(CC) $(CFLAGS) --coverage $(SOURCE) s21_calc.a -L. $(CHECK) -o ./test 
	./test
	mkdir report
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html
	rm -rf *.gcda *.gcno *.out *.o
	
clear: clean
	

clean:
	rm -rf test *.out
	rm -rf $(ODIR)/*.o $(ODIR)/*.gc*
	rm -rf $(ODIR)/*/*.o $(ODIR)/*/*.gc*
	rm -rf ./gcov/*.o ./gcov/*.gc*
	rm -rf ./*.gc*
	rm -rf $(BUILD_LIB)/$(PROJECT_NAME).a
	rm -rf report*
	rm -rf *.o *.a
	rm -rf *.dSYM
	rm -rf *.info
	rm -rf $(TEST_NAME)
	rm -rf build

clang:
	clang-format --style=Google -i *.c *.h ${LIB_TEST_DIR}/*.c core/*.c core/*.h

valgrind:
	valgrind -s --tool=memcheck --leak-check=full --track-origins=yes test

valgrind+:
	CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

gcc: clean 
	gcc *.c *.h -g core/*.c  core/*.h -lm
	./a.out

TARGET = Calculator_v1.0

install:       
	echo "Installation of $(TARGET).app:"
	mkdir -p build
	cd ./for_qt/FrontForCalc && qmake && make && make clean && rm -rf Makefile && mv frontForCalc.app ../../build/$(TARGET).app
	echo "Installation completed! You can find app in the build/ folder!"

uninstall:
	rm -rf build
	echo "Uninstall completed!"
	
dist: install
	mkdir -p ../dist
	@cp -R build/$(TARGET).app ../dist
	@cp -R . ../dist/src
	@cd ../dist && tar cvzf $(TARGET).tgz *
	@cd ../dist && rm -rf $(TARGET).app
	@rm -rf ../dist/src
	echo "Archive creation completed successfully!"

dvi:
	doxygen dvi_config
	open ./html/index.html