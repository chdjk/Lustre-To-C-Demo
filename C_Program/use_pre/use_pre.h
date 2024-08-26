#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#ifndef _ctx_TYPES
#define _ctx_TYPES
typedef float real;
typedef struct {
    int _memory ;
} pre_int_ctx_type;
typedef struct {
	int test;
	pre_int_ctx_type pre_int_ctx_tab[1];
} result_ctx_type;
#endif