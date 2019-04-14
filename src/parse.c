#include "parse.h"
#include "structures.h"
#include "tokens.h"
#include <stdlib.h>
#include <stdio.h>

void parse_file(FILE *file) {
    token **buffer = _init_token_buffer();
    char *reading_str = calloc(25, sizeof(char));
    int pivot = 0;
    int index = 0;
    while ((reading_str[index] = fgetc(file)) != EOF) {
        if (is_preset_token(buffer, reading_str, index-pivot)) {
            pivot = index; //todo
        }
        else if (is_nonpreset_token(buffer, reading_str, index-pivot)) {
            pivot = index; //todo
        }
        index++;

        if (index-pivot >= 25) {
            printf("ERROR: Highest token size reached...\n");
            return; //if everything is correct this doesnt happen
        }
    }
}

token *convert_str_to_token(char *str) {
    int length = 0;
    token *tok = malloc(sizeof(token));
    while(str[length] != '\0') length++;
    if (is_preset_token(get_current_buffer(), str, length)) {
        tok->string = str;
        tok->length = length;
        tok->is_preset = 1;
    }
    else if (is_nonpreset_token(get_current_buffer(), str, length)) {
        tok->string = str;
        tok->length = length;
        tok->is_preset = 0;
    }
    else {
        free(tok);
        tok = NULL;
        printf("Invalid token to parse.\n");
        return 0; //invalid token 
    }
    return tok;
}