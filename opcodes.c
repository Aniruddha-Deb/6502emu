#include "opcodes.h"
#include <stdio.h>

int nimp(CPU* cpu, byte* mem) {
    cpu->PC += 1;
    printf("Not implemented\n");
    return 0;
}

int halt(CPU* cpu, byte* mem) {
    printf("Halting.\n");
    return 1;
}
