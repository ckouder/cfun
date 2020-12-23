CC 	:= gcc
LD 	:= gcc

CFLAGS 	:= -g -Wall -Werror -Wextra -Wpedantic -O0
LDFLAGS := 

TARGETS := fundot

SRC_DIR := src
DEP_DIR := include
OBJ_DIR := obj

SRCS 	:= $(wildcard $(SRC_DIR)/*.c)
OBJS 	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BINS 	:= $(BIN_DIR)/$(TARGETS)

.PHONY: all clean

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -o $@ -c $< -I $(DEP_DIR) $(CFLAGS)

$(OBJ_DIR):
	mkdir $@

clean:
	rm -r obj
