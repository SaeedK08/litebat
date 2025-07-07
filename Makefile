SRCDIR := src
OBJDIR := obj
BINDIR := bin
INCDIR := include

## Compiler
CC := clang
CFLAGS := -g -Wall -Wextra -MMD -MP 


## Find all .c files and generate .o file names
# SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
#DEPS := $(patsubst $(OBJDIR)/%.o, $(INCDIR)/%.h, $(wildcard $(OBJDIR)/*.o))

## Target binary name
TARGET := $(BINDIR)/main

## Default build
all: $(TARGET)

## Link object files to final binary
$(TARGET): $(OBJ) | $(BINDIR)
#@mkdir -p $(BINDIR)
	$(CC) $^ -o $@

## Compile each .c to .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
#@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

$(BINDIR): 
	@mkdir $(BINDIR)

#Run the app
run: all
	./$(TARGET)

## Clean up
clean:
	rm -rf $(OBJDIR) $(BINDIR)

-include $(OBJ:.o=.d)





