#include "parse.h"
#include "structures.h"
#include "tokens.h"
#include <stdlib.h>
#include <stdio.h>

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