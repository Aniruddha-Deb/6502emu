#include "opcodes.h"
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Optable: a jump table, each of whose functions take in CPU and MEM and then
// return an int once execution is done

int (*optable[256])(CPU*, byte*) = {
    &nimp, &halt, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, 
    &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, 
    &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, 
    &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, 
    &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, 
    &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, 
    &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, 
    &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp, &nimp
};

byte* MEM;
// TODO make the thing cycle stepped rather than instruction stepped later on?
// uint64_t cycles;

int main(int argc, char** argv) {

    byte* pbuf;
    if (argc < 1) {
        printf("Did not specify program to run. Exiting.");
        return 0;
    }
    // load file
    FILE *fileptr = fopen(argv[1], "rb");
    long filelen = 0;
    fseek(fileptr, 0, SEEK_END);
    filelen = ftell(fileptr);
    if (filelen > 64000) {
        fprintf(stderr, "Program too large to be loaded into memory\n", 43);
        fclose(fileptr);
        return 0;
    }
    rewind(fileptr);

    pbuf = (byte*) malloc(filelen);
    fread(pbuf, filelen, 1, fileptr);
    fclose(fileptr);

    MEM = (byte*) malloc(65536);
    memcpy(MEM+512, pbuf, filelen);
    
    // now init and run program
    CPU *cpu = (CPU*) malloc(sizeof(CPU));
    cpu->S = 256;
    cpu->PC = 512;
    cpu->PSR = 0;

    int rtc = 1;
    do {
        printf("Loc %x : ", cpu->PC);
        rtc = optable[MEM[cpu->PC]](cpu,MEM);
    } while (!rtc);
    
    return 0;
}
