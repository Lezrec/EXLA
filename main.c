#include <stdio.h>
#include "parse.h"
#include "tokens.h"
#include "structures.h"
#include "debug.h"

int main(int argc, char **argv) {
    int _debug_on = 1;
    int i = 1;
    do {
        char* current_arg = argv[i];
        i++;
    } while(argv[i]);
    debug_print(_debug_on, "test 1 2 3");
    struct file_container *_debug_file_container = _debug_init("debug.txt");
    debug_file_overwrite(_debug_on, _debug_file_container, "hmm");
    debug_file_append(_debug_on, _debug_file_container, "attatched");
    return 0;
}