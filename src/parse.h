#include "structures.h"
#ifndef __PARSE__
#define __PARSE__
token *convert_str_to_token(char *str);
void parse_file(FILE *file);
#endif