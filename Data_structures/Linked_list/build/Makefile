ifndef OUT_DIR
OUT_DIR			:= $(shell pwd)/../output
endif

ifndef INC_DIR
INC_DIR			:= "$(shell pwd)/../inc"
endif

ifndef LIB_DIR
LIB_DIR			:= "$(shell pwd)/../lib"
endif

ifndef TMP_DIR
TMP_DIR			:= "$(shell pwd)/../tmp"
endif

ifndef SRC_DIR
SRC_DIR			:= "$(shell pwd)/../src"
endif

ifndef MKDIR
MKDIR			:= mkdir
endif

.PHONY: all

all: main clean

main: ../src/main.cpp liblinkedlist
	@echo Compiling: $@
	@$(MKDIR) -p $(OUT_DIR)
	@g++ -std=c++11 $< -I$(INC_DIR) -L$(LIB_DIR) -llinkedlist -o $(OUT_DIR)/$@

liblinkedlist: linkedlist.o
	@echo Compiling: $@
	@$(echo $(LIB_DIR)/$@.a)
	@$(MKDIR) -p $(LIB_DIR)
	@ar crs ../lib/$@.a $(join ../tmp/,$^)

linkedlist.o: ../src/Linkedlist.cpp ../inc/Linkedlist.hpp
	@echo Compiling: $@
	@$(MKDIR) -p $(TMP_DIR)
	@g++ -c $< -o "$(TMP_DIR)/$@"

clean:
	@echo Clean build folders
	@rm -rf $(TMP_DIR) $(LIB_DIR)