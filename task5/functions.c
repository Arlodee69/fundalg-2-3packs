#include "header.h"

status_code some_function(FILE *file_in, FILE *file_out){
    if (!file_in || !file_out){
        return FILE_ERROR;
    }

    Word *Words = NULL;
    int count = 0;
    int capacity = 10;
    Words = (Word *)malloc(sizeof(Word) * capacity);

    if (!Words){
        return ALLOCATION_ERROR;
    }

    char current_char;
    while (current_char = fgetc(file_in) != EOF){
        int str_len = 0;
        while (current_char != ',' && current_char != ' ' && current_char != '\t'){
            if (current_char == '\n') break;
            Words[str_len].len++;
            Words[str_len].name[str_len] = current_char;
            str_len++;
            current_char = fgetc(file_in);
        }
    }
    /*char simple_check[81];
    if (fgets(simple_check, sizeof(simple_check), file_in) != NULL){
        size_t len = strlen(simple_check);
        if (len > 0 && simple_check[len - 1] == '\n'){
            simple_check[len - 1] = '\0';
            len--;
        }
        if (len < 80){
            fprintf(file_out, "%s\n", simple_check);
        }
        else{
            printf("xyi tebe\n");
        }
    }*/
}