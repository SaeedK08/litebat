#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>

typedef struct Input Input;
Input* read_input(int argc, char **args);
char const* get_file_name(const Input* fileInfo);
bool is_input_tty(const Input* fileInfo);

#endif