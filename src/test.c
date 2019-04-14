#
#include "structures.h"
#include "debug.h"
#include "tokens.h"
#include "test.h"
#include "parse.h"

void test(void) {
    token **buffer = _init_token_buffer();
    char *test_str = "var_c";
    int found_in_buffer = is_preset_token(buffer, test_str, 5);
    if (found_in_buffer) debug_print_line(1, "Token was found");
    else debug_print_line(1, "Token was not found");
    _init_nonpreset_token(buffer, "lmao", 4);
    found_in_buffer = is_nonpreset_token(buffer, "lmao", 4);
    int pbs = preset_token_buffer_size(buffer);
    printf("%d\n", pbs);
    int npbs = nonpreset_token_buffer_size(buffer);
    printf("%d\n", npbs);
    if (found_in_buffer) debug_print_line(1, "NPS token found\n");
    else debug_print_line(1, "NPS not found");
    token *test_gen = convert_str_to_token("lmao");
    print_token(*test_gen);
}

void print_token(token tok) {
    printf("TOKEN: String = {%s}, Length = {%d}, Preset = {%d}\n", tok.string, tok.length, tok.is_preset);
}