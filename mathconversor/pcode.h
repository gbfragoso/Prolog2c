#ifndef PCODE_H
#define PCODE_H

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef struct{
    int operation;
    int level;
    int argument;
} Tinstruction;

#endif

#include <stdio.h>

enum { LIT, OPR, LOD, STO, CAL, INT, JMP, JPC, WRT } instructionCode;
enum { RTN, NEG, ADD, SUB, MUL, DIV, ODD, MOD, EQL, NEQ, LSS, LEQ, GTR, GEQ } operationCode;

void pcode(Tinstruction inst[], int stack[], FILE *output);
int getBase(int level, int base, int stack[]);
char* getInstructionName(int inst);

#endif