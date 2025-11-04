#include "header.h"

int main(int argc, char* argv[]){
    char file_in[MAX_SIZE];
    if (scanf("%255s", file_in) == -1) return ARG_ERROR;
    char file_out[MAX_SIZE];
    if (scanf("%255s", file_out) == -1) return ARG_ERROR;

    char *real_in = realpath(file_in, NULL);
    char *real_out = realpath(file_out, NULL);

    if (!real_in || !real_out) {
        printf("Ошибка получения абсолютного пути\n");
        free(real_in);
        free(real_out);
        return FILE_ERROR;
    }

    if (strcmp(real_in, real_out) == 0) {
        printf("Введены одинаковые файлы на чтение и запись\n");
        free(real_in);
        free(real_out);
        return ARG_ERROR;
    }

    free(real_in);
    free(real_out);

    FILE *input_file = fopen(file_in, "r");
    FILE *output_file = fopen(file_out, "w");
    if(!input_file || !output_file){
        fclose(input_file);
        fclose(output_file);
        return FILE_ERROR;
    }

    status_code some_code = some_function(input_file, output_file);
}