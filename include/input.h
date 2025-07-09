#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <string.h>

typedef struct Input Input;
void parseArgs(int argNum, char **args);
bool check_input_source(void);
char* read_input(char *args, int *exitVale);
// char const* get_file_name(const Input* fileInfo);
// bool is_input_tty(const Input* fileInfo);

#endif