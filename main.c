#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"
#include <stdio.h>

int main(int argc, const char* argv[]) {
    printf("Initializing VM...\n");
    initVM();
    Chunk chunk;
    printf("Initializing Chunk...\n");
    initChunk(&chunk);

    printf("Adding constant...\n");
    int constant = addConstant(&chunk, 1.2);
    printf("Writing OP_CONSTANT...\n");
    writeChunk(&chunk, OP_CONSTANT, 123);
    printf("Writing constant...\n");
    writeChunk(&chunk, constant, 123);
  
    printf("Writing OP_RETURN...\n");
    writeChunk(&chunk, OP_RETURN, 123);

    printf("Disassembling chunk...\n");
    disassembleChunk(&chunk, "test chunk");
    printf("Interpreting chunk...\n");
    interpret(&chunk);
    printf("Freeing VM...\n");
    freeVM();
    printf("Freeing Chunk...\n");
    freeChunk(&chunk);
    printf("Exiting program...\n");
    return 0;
}