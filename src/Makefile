.PHONY: all install uninstall clean dvi dist test check_mk gcov_report install_lcov brew lcov style_check style valgrind

CC = gcc -std=c11 -g
FLAGS = -Wall -Wextra -Werror

SOURCES = ./3d_viewer_my/affins.c ./3d_viewer_my/obj_reader.c 
TEST_DIR = test
TEST_OUT = test_viewer
TEST_FILE = test_viewer.c
REPORT_DIR = gcov_report
GCOV_FILES = *.gcno *.gcov *.info *.gcda *.dSYM *.o *.txt
TAR_FILE = build.tar
BUILD_DIR = ./build
SOURCE_BUILD = ./3d_viewer_my/
DVI_FILE = manual.html

ifeq ($(shell uname -s),Linux)
	FLAGS_TEST = -lcheck -lpthread -lrt -lm -lsubunit -coverage -g
else
	FLAGS_TEST = -coverage -lcheck -lm
endif

all: install dist

install: uninstall
	mkdir $(BUILD_DIR)
	cmake -S $(SOURCE_BUILD) -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

uninstall:
	rm -rf  $(BUILD_DIR)/

clean:
	rm -rf ./$(TEST_OUT) $(REPORT_DIR) $(TAR_FILE) $(BUILD_DIR) $(GCOV_FILES)

dvi:
	open -a Google\ Chrome $(DVI_FILE)

dist:
	tar -cvf $(TAR_FILE) $(BUILD_DIR)

test: clean check_mk
	gcc $(SOURCES) $(TEST_FILE) $(FLAGS_TEST) -o $(TEST_OUT)
	./$(TEST_OUT)
	gcov -f $(TEST_OUT)
	# make gcov_report

check_mk:
	rm -rf $(TEST_FILE)
	checkmk clean_mode=1 $(TEST_DIR)/*.check > $(TEST_FILE)
	clang-format --style=Google -i $(TEST_FILE)

gcov_report:
	# eval "$(~/goinfre/homebrew/bin/brew shellenv)"
	mkdir $(REPORT_DIR)
	lcov --directory ./ --capture --output-file report.info
	genhtml report.info --output-directory $(REPORT_DIR)
	rm -rf *.gcno *.info *.gcda
	open -a Google\ Chrome $(REPORT_DIR)/index.html

install_lcov: brew lcov

brew:
	cd ~/goinfre
	git clone https://github.com/Homebrew/brew homebrew
	eval '$$(~/goinfre/homebrew/bin/brew shellenv)'
lcov:
	brew install lcov

style_check:
	clang-format --style=Google -n $(SOURCE_BUILD)/*.c $(SOURCE_BUILD)/*.h $(SOURCE_BUILD)/*.cpp

style:
	clang-format --style=Google -i $(SOURCE_BUILD)/*.c $(SOURCE_BUILD)/*.h $(SOURCE_BUILD)/*.cpp

valgrind:
	gcc $(SOURCES) $(TEST_FILE) $(FLAGS_TEST) -o $(TEST_OUT)
	CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_OUT)
