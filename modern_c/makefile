# set RECIPEPREFIX to `+` instead of tabs
.RECIPEPREFIX = +
# each line of recipe runs in the same shell
.ONESHELL:
# set shell to `bash`
SHELL := bash
# unofficial bash strict mode
.SHELLFLAGS := -eu -o pipefail -c
# delete targets if error is encountered
.DELETE_ON_ERROR:

SOURCES := $(wildcard *.c)
TARGETS := $(basename $(SOURCES))

LIBS := -lm
CC := gcc
CFLAGS := -g -Wall -std=c11

.PHONY: all clean

all: $(TARGETS)

OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
HEADERS = $(patsubst %.c, %.h, $(SOURCES))

%.o: %.c $(HEADERS)
+ $(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
+ $(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
+ -rm -f *.o
+ -rm -f $(TARGET)
