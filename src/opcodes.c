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

int adci(CPU* cpu, byte* mem) {
    printf("Adding with carry, immediate\n");
    // access next memory loc
    byte M = mem[(cpu->PC)+1];
    cpu->A += (cpu->M + cpu->SR.SR_F.C);
    cpu->SR.SR_F.C


    // TODO think of a simple way to make this cycle stepped
