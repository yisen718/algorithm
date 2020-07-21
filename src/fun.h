#pragma once
#include <stdbool.h>
#include <stdarg.h>


int add(int a, int b);

bool is_prime(int digit);

bool has_repeat_digit(int digit);

int max_int(int n, ...);

int errorf(const char* format, ...);

void rand_seed();

void copy_file(int argc, char* argv[]);
