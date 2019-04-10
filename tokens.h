#include "structures.h"
#ifndef __TOKENS__
#define __TOKENS__

struct token **_init_token_buffer(void);
struct token *_init_token(char *str, int length, int is_preset);
struct token *_init_preset_token(char *str, int length);
int preset_token_buffer_size(struct token **buffer);
int is_preset_token(struct token **buffer, char *str);

#endif