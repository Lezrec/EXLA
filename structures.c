#include "structures.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
struct token {
    char *string;
    int length;
};

struct string_literal {
    char *string;
    int length;
};

struct char_literal {
    char chr;
    int is_whitespace;
    int contains_escape;
};

struct int_literal {
    int value;
    int length;
    int is_negative;
    char *string_rep;
};

struct float_literal {
    float value;
    int length;
    int is_negative;
    char *string_rep;
};

struct matrix_literal { //todo, possibly one of different types?
    int rows, cols;
    int total_slots;
};

struct string_array_literal { //todo
    struct string_literal *strings;
    int length;
};

struct char_array_literal {
    struct char_literal *chars;
    int length;
};

struct int_array_literal {
    struct int_literal *nums;
    int length;
};

struct float_array_literal {
    struct float_literal *nums;
    int length;
};

struct group { //todo
    int size;
    int *types;
    int **data; //todo: https://www.tutorialspoint.com/cprogramming/c_data_types.htm, use types to have appropriate data sizes
};
*/
struct string_literal _construct_string_literal(char *strl) {
    int len = 0;
    while (strl[len] != '\0') {
        len++;
    }
    return (struct string_literal){strl, len};
}

struct char_literal _construct_char_literal(char cl) {
    switch(cl) {
        case '\e':
        case '\\': return (struct char_literal){cl, 0, 1};

        case '\n':
        case '\t':
        case '\v':
        case '\r':
        case '\f': return (struct char_literal){cl, 1, 1};

        case ' ': return (struct char_literal){cl, 1, 0};

        default:   return (struct char_literal){cl, 0, 0};
    }
}
struct int_literal _construct_int_literal(int il) {
    //val length negative, length only includes digits
    int len = 0;
    int is_negative = 0;
    char *str_rep = calloc(12, sizeof(char)); //int max digits including negative size + null terminator
    sprintf(str_rep, "%d", il);
    while(str_rep[len] != '\0') {
        if (!is_negative && str_rep[len] == '-') is_negative = 1;
        len++;
    }
    str_rep[len] = '\0';
    return (struct int_literal){il, len, is_negative, str_rep};
}

struct float_literal _construct_float_literal(float fl) {
    int len = 0;
    int is_negative = 0;
    char *str_rep = calloc(40, sizeof(char)); //idk lol
    sprintf(str_rep, "%f", fl);
    while(str_rep[len] != '\0') {
        if (!is_negative && str_rep[len] == '-') is_negative = 1;
        if (str_rep[len] == '.') {
            len++;
            continue;
        }
        len++;
    }
    str_rep[len] = '\0';
    return (struct float_literal){fl, len, is_negative, str_rep};
}

struct float_array_literal _construct_float_array_literal(struct float_literal *fls) {
    int len = 0;
    while(&(fls[len])) { //todo test this part
        len++;
    }
    return (struct float_array_literal){fls, len};
}

struct int_array_literal _construct_int_array_literal(struct int_literal *ils) {
    int len = 0;
    while(&(ils[len])) { //todo test this part
        len++;
    }
    return (struct int_array_literal){ils, len};
}

struct string_array_literal _construct_string_array_literal(struct string_literal *strs) {
    int len = 0;
    while(&(strs[len])) {
        len++;
    }
    return (struct string_array_literal){strs, len};
}

struct char_array_literal _construct_char_array_literal(struct char_literal *chars) {
    int len = 0;
    while(&(chars[len])) {
        len++;
    }
    return (struct char_array_literal){chars, len};
}

struct matrix_literal _construct_matrix_literal(void); //todo

struct group _construct_group(void); //todo

struct string_literal _append_string_string_literals(struct string_literal sl1, struct string_literal sl2) {
    int total_len = sl1.length + sl2.length;
    char *appended = calloc(total_len + 1, sizeof(char)); //+1 for escape
    int i = 0;
    while(sl1.string[i] != '\0') {
        appended[i] = sl1.string[i];
        i++;
    }
    while (sl2.string[i] != '\0') {
        appended[i] = sl2.string[i];
        i++;
    }
    appended[total_len] = '\0';
    return _construct_string_literal(appended);
}

struct string_literal _append_char_string_literals(struct char_literal cl1, struct string_literal sl1) {
    int total_len = sl1.length + 1; //1 for char;
    char *appended = calloc(total_len + 1, sizeof(char)); // +1 for escape
    appended[0] = cl1.chr;
    int i = 1;
    while (sl1.string != '\0') {
        appended[i] = sl1.string[i];
        i++;
    }
    appended[total_len] = '\0';
    return _construct_string_literal(appended);
}

struct string_literal _append_string_char_literals(struct string_literal sl1, struct char_literal cl1) {
    int total_len = sl1.length + 1; //1 for char;
    char *appended = calloc(total_len + 1, sizeof(char)); // +1 for escape
    int i = 0;
    while (sl1.string != '\0') {
        appended[i] = sl1.string[i];
        i++;
    }
    appended[total_len-1] = cl1.chr;
    appended[total_len] = '\0';
    return _construct_string_literal(appended);
}

struct string_literal _append_char_char_literals(struct char_literal cl1, struct char_literal cl2) {
    char *appended = calloc(3, sizeof(char));
    appended[0] = cl1.chr;
    appended[1] = cl2.chr;
    appended[2] = '\0';
    return _construct_string_literal(appended);
}

struct char_literal _add_char_char_literals(struct char_literal cl1, struct char_literal cl2) {
    return _construct_char_literal(cl1.chr + cl2.chr);
}

struct int_literal _add_int_int_literals(struct int_literal il1, struct int_literal il2) { //todo add subtract and max size check
    return _construct_int_literal(il1.value + il2.value);
}

struct float_literal _add_float_float_literals(struct float_literal fl1, struct float_literal fl2) {
    return _construct_float_literal(fl1.value + fl2.value);
}

struct float_literal _add_int_float_literals(struct int_literal il1, struct float_literal fl1) {
    return _construct_float_literal(fl1.value + (float)il1.value);
}

struct float_literal _add_float_int_literals(struct float_literal fl1, struct int_literal il1) {
    return _construct_float_literal(fl1.value + (float)il1.value);
}

struct int_literal _bitwise_not_int_literal(struct int_literal il1) {
    return _construct_int_literal(!il1.value);
}

struct int_literal _bitwise_and_int_literal(struct int_literal il1, struct int_literal il2) {
    return _construct_int_literal(il1.value & il2.value);
}

struct int_literal _bitwise_or_int_literal(struct int_literal il1, struct int_literal il2) {
    return _construct_int_literal(il1.value | il2.value);
}

struct int_literal _bitwise_xor_int_literal(struct int_literal il1, struct int_literal il2) {
    return _construct_int_literal(il1.value ^ il2.value);
}

struct int_literal _bitwise_nor_int_literal(struct int_literal il1, struct int_literal il2) {
    return _construct_int_literal(!(il1.value | il2.value));
}

struct int_literal _bitwise_nand_int_literal(struct int_literal il1, struct int_literal il2) {
    return _construct_int_literal(!(il1.value & il2.value));
}

struct int_literal _round_float_literal(struct float_literal fl1) {
    return _construct_int_literal(round(fl1.value));
}

struct int_literal _ceil_float_literal(struct float_literal fl1) {
    return _construct_int_literal(ceil(fl1.value));
}

struct int_literal _floor_float_literal(struct float_literal fl1) {
    return _construct_int_literal(floor(fl1.value));
}

struct int_literal _divide_int_int_literal(struct int_literal il1, struct int_literal il2) {
    return _construct_int_literal(il1.value/il2.value);
}

struct float_literal _divide_float_int_literal(struct float_literal fl1, struct int_literal il1) {
    return _construct_float_literal(fl1.value/(float)il1.value);
}

struct float_literal _divide_int_float_literal(struct int_literal il1, struct float_literal fl1) {
    return _construct_float_literal((float)il1.value/fl1.value);
}

struct float_literal _divide_float_float_literal(struct float_literal fl1, struct float_literal fl2) {
    return _construct_float_literal(fl1.value/fl2.value);
}

struct int_literal _multiply_int_int_literal(struct int_literal il1, struct int_literal il2) {
    return _construct_int_literal(il1.value*il2.value);
}
struct float_literal _multiply_float_int_literal(struct float_literal fl1, struct int_literal il1) {
    return _construct_float_literal(fl1.value * (float)il1.value);
}
struct float_literal _multiply_int_float_literal(struct int_literal il1, struct float_literal fl1) {
    return _construct_float_literal((float)il1.value * fl1.value);
}
struct float_literal _multiply_float_float_literal(struct float_literal fl1, struct float_literal fl2) {
    return _construct_float_literal(fl1.value*fl2.value);
}