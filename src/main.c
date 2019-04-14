#include <stdio.h>
#include "parse.h"
#include "tokens.h"
#include "structures.h"
#include "debug.h"
#include "test.h"

int main(int argc, char **argv) {
    int _debug_on = 1;
    int i = 1;
    do {
        char* current_arg = argv[i];
        i++;
    } while(argv[i]);
     file_container *_debug_file_container = _debug_init("E:/EXLA/src/debug.txt");
    debug_file_overwrite(_debug_on, _debug_file_container, "hmm");
    debug_file_append(_debug_on, _debug_file_container, "attatched");
    test();
    FILE *file = fopen("test.exla", "r");
    parse_file(file);
    fclose(file);
    return 0;
}