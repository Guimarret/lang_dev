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


    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_ADD, 123);
    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_DIVIDE, 123);
    printf("Writing OP_CONSTANT...\n");
    writeChunk(&chunk, OP_NEGATE, 123);
    
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