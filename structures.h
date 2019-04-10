#ifndef __STRUCTS__
#define __STRUCTS__

struct token {
    char *string;
    int length;
    int is_preset;
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

struct string_literal _construct_string_literal(char *strl);
struct char_literal _construct_char_literal(char cl);
struct int_literal _construct_int_literal(int il);
struct float_literal _construct_float_literal(float fl);
struct float_array_literal _construct_float_array_literal(struct float_literal *fls);
struct int_array_literal _construct_int_array_literal(struct int_literal *ils);
struct string_array_literal _construct_string_array_literal(struct string_literal *strs);
struct char_array_literal _construct_char_array_literal(struct char_literal *chars);
struct matrix_literal _construct_matrix_literal(void); //todo
struct group _construct_group(void); //todo
struct string_literal _append_string_string_literals(struct string_literal sl1, struct string_literal sl2);
struct string_literal _append_char_string_literals(struct char_literal cl1, struct string_literal sl1);
struct string_literal _append_string_char_literals(struct string_literal sl1, struct char_literal cl1);
struct string_literal _append_char_char_literals(struct char_literal cl1, struct char_literal cl2);
struct char_literal _add_char_char_literals(struct char_literal cl1, struct char_literal cl2);
struct int_literal _add_int_int_literals(struct int_literal il1, struct int_literal il2);
struct float_literal _add_float_float_literals(struct float_literal fl1, struct float_literal fl2);
struct float_literal _add_int_float_literals(struct int_literal il1, struct float_literal fl1);
struct float_literal _add_float_int_literals(struct float_literal fl1, struct int_literal il1);
struct int_literal _bitwise_not_int_literal(struct int_literal il1);
struct int_literal _bitwise_and_int_literal(struct int_literal il1, struct int_literal il2);
struct int_literal _bitwise_or_int_literal(struct int_literal il1, struct int_literal il2);
struct int_literal _bitwise_xor_int_literal(struct int_literal il1, struct int_literal il2);
struct int_literal _bitwise_nor_int_literal(struct int_literal il1, struct int_literal il2);
struct int_literal _bitwise_nand_int_literal(struct int_literal il1, struct int_literal il2);
struct int_literal _round_float_literal(struct float_literal fl1);
struct int_literal _ceil_float_literal(struct float_literal fl1);
struct int_literal _floor_float_literal(struct float_literal fl1);
struct int_literal _divide_int_int_literal(struct int_literal il1, struct int_literal il2);
struct float_literal _divide_float_int_literal(struct float_literal fl1, struct int_literal il1);
struct float_literal _divide_int_float_literal(struct int_literal il1, struct float_literal fl1);
struct float_literal _divide_float_float_literal(struct float_literal fl1, struct float_literal fl2);
struct int_literal _multiply_int_int_literal(struct int_literal il1, struct int_literal il2);
struct float_literal _multiply_float_int_literal(struct float_literal fl1, struct int_literal il1);
struct float_literal _multiply_int_float_literal(struct int_literal il1, struct float_literal fl1);
struct float_literal _multiply_float_float_literal(struct float_literal fl1, struct float_literal fl2);
#endif