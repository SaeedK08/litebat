#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


typedef struct Input Input;
Input* readInput (int argc, char ** args);

#endif