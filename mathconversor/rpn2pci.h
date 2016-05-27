#ifndef RPN2PCI_H
#define RPN2PCI_H

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef struct{
    int operation;
    int level;
    int argument;
} Tinstruction;

#endif

Tinstruction* toInstruction(char *epr);

#endif