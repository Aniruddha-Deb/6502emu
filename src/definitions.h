#include <inttypes.h>

typedef uint8_t byte;
typedef uint16_t word;

typedef struct CPU {
    stat_reg SR;
    byte SP;
    word PC;
    byte X;
    byte Y;
    byte A;
} CPU;

typedef struct stat_reg_flags {
    byte C: 1;
    byte Z: 1;
    byte I: 1;
    byte D: 1;
    byte B: 1;
    byte E: 1;
    byte V: 1;
    byte N: 1;
} stat_reg_flags;

typedef union stat_reg {
    byte SR;
    stat_reg_flags SR_F;
} stat_reg;
