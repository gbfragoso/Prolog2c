# Prolog2c
An prolog generator that receive an expression (logic or arithmetic) and pass it to an output file. This file will be used by C program to convert it into pci.

# Running
> Prolog: run(expr).

> C: ./compiled

# Compiling
gcc -o teste pcode.c rpn2pci.c main.c

# Limitation
This implementation of  converter does not accept unnary operators. 

# Example
1. Open logic2rpn.pl to generate rpn for logic expressions or open expr2rpn to generate arithmetic expressions;
2. Query: "run(['(',0,&,1,')'])." for logic or "run(['(',2,+,2,')'])." for math; (Note ' ' surrounding the brackets inside list)
3. The expr.txt will be created;
4. Run C program;
5. The output.txt file with pcode execution trace will be generated.
