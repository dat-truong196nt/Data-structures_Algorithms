ifndef CUR_DIR
CUR_DIR := $(shell pwd)
endif

ifndef OUT_DIR
OUT_DIR := $(CUR_DIR)/output
endif

ifndef LIB_DIR
LIB_DIR := $(CUR_DIR)/lib
endif

all:array main

main:

array:
	@echo Compiling: $@
	@mkdir -p $(LIB_DIR)
	@g++ -c -o $@.o $@.cpp
	@gcc -shared -o $(LIB_DIR)/$@.so $@.o
	@rm -f $@.o

