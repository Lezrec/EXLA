#ifndef __STRUCTS__
#define __STRUCTS__

typedef struct token {
    char *string;
    int length;
    int is_preset;
} token;

typedef struct string_literal {
    char *string;
    int length;
} string_literal;

typedef struct char_literal {
    char chr;
    int is_whitespace;
    int contains_escape;
} char_literal;

typedef struct int_literal {
    int value;
    int length;
    int is_negative;
    char *string_rep;
} int_literal;

typedef struct float_literal {
    float value;
    int length;
    int is_negative;
    char *string_rep;
} float_literal;

typedef struct matrix_literal { //todo, possibly one of different types?
    int rows, cols;
    int total_slots;
} matrix_literal;

typedef struct string_array_literal { //todo
    struct string_literal *strings;
    int length;
} string_array_literal;

typedef struct char_array_literal {
    struct char_literal *chars;
    int length;
} char_array_literal;

typedef struct int_array_literal {
    struct int_literal *nums;
    int length;
} int_array_literal;

typedef struct float_array_literal {
    struct float_literal *nums;
    int length;
} float_array_literal;

typedef struct group { //todo
    int size;
    int *types;
    int **data; //todo: https://www.tutorialspoint.com/cprogramming/c_data_types.htm, use types to have appropriate data sizes
} group;

string_literal _construct_string_literal(char *strl);
char_literal _construct_char_literal(char cl);
int_literal _construct_int_literal(int il);
float_literal _construct_float_literal(float fl);
float_array_literal _construct_float_array_literal( float_literal *fls);
int_array_literal _construct_int_array_literal( int_literal *ils);
string_array_literal _construct_string_array_literal( string_literal *strs);
char_array_literal _construct_char_array_literal( char_literal *chars);
matrix_literal _construct_matrix_literal(void); //todo
group _construct_group(void); //todo
string_literal _append_string_string_literals( string_literal sl1,  string_literal sl2);
string_literal _append_char_string_literals( char_literal cl1,  string_literal sl1);
string_literal _append_string_char_literals( string_literal sl1,  char_literal cl1);
string_literal _append_char_char_literals( char_literal cl1,  char_literal cl2);
char_literal _add_char_char_literals( char_literal cl1,  char_literal cl2);
int_literal _add_int_int_literals( int_literal il1,  int_literal il2);
float_literal _add_float_float_literals( float_literal fl1,  float_literal fl2);
float_literal _add_int_float_literals( int_literal il1,  float_literal fl1);
float_literal _add_float_int_literals( float_literal fl1,  int_literal il1);
int_literal _bitwise_not_int_literal( int_literal il1);
int_literal _bitwise_and_int_literal( int_literal il1,  int_literal il2);
int_literal _bitwise_or_int_literal( int_literal il1,  int_literal il2);
int_literal _bitwise_xor_int_literal( int_literal il1,  int_literal il2);
int_literal _bitwise_nor_int_literal( int_literal il1,  int_literal il2);
int_literal _bitwise_nand_int_literal( int_literal il1,  int_literal il2);
int_literal _round_float_literal( float_literal fl1);
int_literal _ceil_float_literal( float_literal fl1);
int_literal _floor_float_literal( float_literal fl1);
int_literal _divide_int_int_literal( int_literal il1,  int_literal il2);
float_literal _divide_float_int_literal( float_literal fl1,  int_literal il1);
float_literal _divide_int_float_literal( int_literal il1,  float_literal fl1);
float_literal _divide_float_float_literal( float_literal fl1,  float_literal fl2);
int_literal _multiply_int_int_literal( int_literal il1,  int_literal il2);
float_literal _multiply_float_int_literal( float_literal fl1,  int_literal il1);
float_literal _multiply_int_float_literal( int_literal il1,  float_literal fl1);
float_literal _multiply_float_float_literal( float_literal fl1,  float_literal fl2);
#endif