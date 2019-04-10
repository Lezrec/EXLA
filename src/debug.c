#include "debug.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEBUG_FILE_SIZE 1000

struct file_container *_debug_init(char *file_dir) {
    struct file_container *ret = malloc(sizeof(struct file_container));
    ret->file_dir = file_dir;
    update_container(ret);
    return ret;
}

void debug_print(int debug_flag, char *str) {
    if (debug_flag == 1) printf(str);
}

void debug_print_line(int debug_flag, char *str) {
    if (debug_flag == 1) printf("%s\n", str);
}

void debug_file_overwrite(int debug_flag, struct file_container *container, char *str) {
    if (debug_flag == 1) {
        FILE *container_file = fopen(container->file_dir, "w+");
        fputs(str, container_file);
        fclose(container_file);
        update_container(container);
    }
}

void debug_file_clear(int debug_flag, struct file_container *container) {
    if (debug_flag == 1) {
        FILE *container_file = fopen(container->file_dir, "w+");
        container->length = 0;
        fclose(container_file);
    }
}

void debug_file_append(int debug_flag, struct file_container *container, char *str) {
    if (debug_flag == 1) {
        FILE *container_file = fopen(container->file_dir, "a");
        fputs(str, container_file); //todo test all this
        fclose(container_file);
        update_container(container);
    }
}
void debug_file_append_line(int debug_flag, struct file_container *container, char *str) {
    if (debug_flag == 1) {
        FILE *container_file = fopen(container->file_dir, "a");
        fputs(str, container_file);
        fputs("\n", container_file);
        fclose(container_file);
        update_container(container);
    }
}

void update_container(struct file_container *container) {
    FILE *container_file = fopen(container->file_dir, "r"); //must the file exist?
    int len = 0;
    while (fgetc(container_file) != EOF) {
        len++;
    }
    container->length = len;
    fclose(container_file);
}