/* -*- coding: utf-8-dos -*- */
#ifndef MYSTDLIB_H_INCLUDED
#define MYSTDLIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <malloc.h>
#include <stdarg.h>
#include <time.h>
#include <errno.h>
enum error { NO_ERROR = 0, INVALID_INPUT };
typedef enum error error_tm;

int read_number(void);
void my_gets(char *buf, size_t buf_size);
void my_fgets(char *buf, size_t buf_size, FILE *file);
int parse_number(const char *str, error_tm * err);

#endif                          // MYSTDLIB_H_INCLUDED
