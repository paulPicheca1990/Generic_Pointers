#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

#define typename(x) _Generic((x),                   \
  _Bool: "_Bool",                                   \
  char: "char",                                     \
  signed char: "signed char",                       \
  unsigned char: "unsigned char",                   \
  int: "int",                                       \
  short int: "short int",                           \
  long int: "long int",                             \
  long long int: "long long int",                   \
  unsigned int: "unsigned int",                     \
  unsigned short int: "unsigned short int",         \
  unsigned long int: "unsigned long int",           \
  unsigned long long int: "unsigned long long int", \
  float: "float",                                   \
  double: "double",                                 \
  long double: "long double",                       \
  void *: "pointer to void",                        \
  int *: "pointer to int",                          \
  char *: "pointer to char",                        \
  float *: "pointer to float",                      \
  double *: "pointer to double",                    \
  default: "other"                                  \
)

#define datatype_index(x) _Generic((x), \
  _Bool: 1,                       \
  char: 2,                        \
  signed char: 3,                 \
  unsigned char: 4,               \
  int: 5,                         \
  short int: 6,                   \
  long int: 7,                    \
  long long int: 8,               \
  unsigned int: 9,                \
  unsigned short int: 10,         \
  unsigned long int: 11,          \
  unsigned long long int: 12,     \
  float: 13,                      \
  double: 14,                     \
  long double: 15,                \
  void *: 16,                     \
  int *: 17,                      \
  char *: 18,                     \
  float *: 19,                    \
  double *: 20,                   \
  default: 0                      \
)

int main(int argc, char **argv) {
  int value = 1;    
  void *vptr = &value;    

  printf( "\n[Variable Info]:\n"
    "  Value: %10d | Datatype: %22s | DatatypeIndex: %d\n", 
    value, typename(value), datatype_index(value) );  

  printf( "\n[Pointer Info]:\n"
    "  Address: %p | Datatype: %22s | DatatypeIndex: %d\n"
    "  Value: %10d | Datatype: %22s | DatatypeIndex: %d\n",          
    vptr,   typename(vptr),         datatype_index(vptr),
    *(__typeof__(value) *)vptr,  typename(*(__typeof__(value) *)vptr), datatype_index(*(__typeof__(value) *)vptr) );          

  return 0;
}