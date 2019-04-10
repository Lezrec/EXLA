#include <stdio.h>
#ifndef __DEBUG__
#define __DEUBG__

struct file_container {
    char *file_dir;
    int length;
};

struct file_container *_debug_init(char *file_dir);
void debug_print(int debug_flag, char *str);
void debug_print_line(int debug_flag, char *str);
void debug_file_overwrite(int debug_flag, struct file_container *container, char *str);
void debug_file_clear(int debug_flag, struct file_container *container);
void debug_file_append(int debug_flag, struct file_container *container, char *str);
void debug_file_append_line(int debug_flag, struct file_container *container, char * str);
void update_container(struct file_container *container);
#endif