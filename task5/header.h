#ifndef HEADER_H
#define HEADER_H
#define MAX_SIZE 256

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[1000];
    int len;
}Word;

typedef enum{
    ALLOCATION_ERROR = 2,
    FILE_ERROR = 1,
    ARG_ERROR = -1,
    VALID = 0,

}status_code;

#endif