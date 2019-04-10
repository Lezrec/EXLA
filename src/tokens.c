#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "structures.h"
#define TOKEN_BUFFER_SIZE 150
/*
struct token {
    char *token_str;
    int token_length;
};
*/

token **_init_token_buffer(void) {
    token **token_buffer = calloc(TOKEN_BUFFER_SIZE, sizeof(token*));
    token_buffer[0]  = _init_preset_token("`", 1);
    token_buffer[1]  = _init_preset_token("'", 1);
    token_buffer[2]  = _init_preset_token("\"", 1);
    token_buffer[3]  = _init_preset_token("(", 1);
    token_buffer[4]  = _init_preset_token(")", 1);
    token_buffer[5]  = _init_preset_token(".", 1);
    token_buffer[6]  = _init_preset_token("-", 1);
    token_buffer[7]  = _init_preset_token("+", 1);
    token_buffer[8]  = _init_preset_token("/", 1);
    token_buffer[9]  = _init_preset_token("*", 1);
    token_buffer[10] = _init_preset_token("!", 1);
    token_buffer[11] = _init_preset_token("->", 2);
    token_buffer[12] = _init_preset_token("as", 2);
    token_buffer[13] = _init_preset_token("fl", 2);
    token_buffer[14] = _init_preset_token("int", 3);
    token_buffer[15] = _init_preset_token("chr", 3);
    token_buffer[16] = _init_preset_token("mat", 3);
    token_buffer[17] = _init_preset_token("ary", 3);
    token_buffer[18] = _init_preset_token("str", 3);
    token_buffer[19] = _init_preset_token("grp", 3);
    token_buffer[20] = _init_preset_token("var_c", 5);
    token_buffer[21] = _init_preset_token("var_d", 5);
    return token_buffer;
}

token *_init_token(char *str, int length, int is_preset) {
    token *token = malloc(sizeof(token));
    token->length = length;
    token->string = str;
    token->is_preset = is_preset;
    printf("buffer?\n");
    return token;
}

token *_init_preset_token(char *str, int length) {
    return _init_token(str, length, 1);
}

int preset_token_buffer_size(token **buffer) {
    int size = 0;
    while(buffer[size]) {
        size++;
    }
    return size;
}

int is_preset_token(token **buffer, char *str, int length) {
    int str_len = 0;
    while(str[str_len] != '\0') {
        str_len++;
    }
    for(int i = 0; i < preset_token_buffer_size(buffer); i++) {
        token *token = buffer[i];
        if (token->length == length) {
            for(int i = 0; i < length; i++) {
                if (token->string[i] != str[i]) return 0;
            } return 1;
        }
    }
    return 0;
}
