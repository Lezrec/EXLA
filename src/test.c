#
#include "structures.h"
#include "debug.h"
#include "tokens.h"
#include "test.h"

void test(void) {
    printf("Here?\n");
    token **buffer = _init_token_buffer();
    char *test_str = "->";
    printf("what about here?\n");
    int found_in_buffer = is_preset_token(buffer, test_str, 2);
    if (found_in_buffer) debug_print_line(1, "Token was found");
    else debug_print_line(1, "Token was not found");
}