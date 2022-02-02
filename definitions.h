#include <inttypes.h>

typedef uint8_t byte;
typedef uint16_t word;

typedef struct CPU {
    byte PSR;
    byte S;
    word PC;
    byte X;
    byte Y;
    byte A;
} CPU;
