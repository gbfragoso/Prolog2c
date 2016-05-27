#include "pcode.h"
#include <stdio.h>

void pcode(Tinstruction inst[], int stack[], FILE *output){
	int base = 1;				// Points to the base address in the stack for the current invocation of a given procedure
    int top = 0; 				// Points to the current top of the stack
    int counter = 0;  			// Points to an instruction in the program area
	
	int aux;
	int stop = 0;
	
	do{
    	Tinstruction instruction = inst[counter];
    	counter++;
    	switch (instruction.operation){
    		case LIT:
    			top++;
    			stack[top] = instruction.argument;
    			break;
    		case OPR:
    			switch(instruction.argument){
    				case RTN:
    					top = base - 1;
    					counter = stack[top+3];
    					base = stack[top+2];
    					break;
    				case NEG:
    					stack[top]= -1*stack[top];
    					break;
    				case ADD:
    					top--;
    					stack[top] += stack[top+1];
    					break;
    				case SUB:
    					top--;
    					stack[top] -= stack[top+1];
    					break;
    				case MUL:
    					top--;
    					stack[top] *= stack[top+1];
    					break;
    				case DIV:
    					top--;
    					stack[top] /= stack[top+1];
    					break;
    				case MOD:
    					top--;
    					stack[top] %= stack[top+1]; 
    					break;
    				case ODD:
    					stack[top] = (stack[top]%2 == 1);
    					break;
    				case EQL:
    					top--;
    					stack[top] = (stack[top] == stack[top+1]);
    					break;
    				case NEQ:
    					top--;
    					stack[top] = (stack[top] != stack[top+1]);
    					break;
    				case LSS:
    					top--;
    					stack[top] = (stack[top] < stack[top+1]);
    					break;
    				case LEQ:
    					top--;
    					stack[top] = (stack[top] <= stack[top+1]);
    					break;
    				case GTR:
    					top--;
    					stack[top] = (stack[top] > stack[top+1]);
    					break;
    				case GEQ:
    					top--;
    					stack[top] = (stack[top] >= stack[top+1]);
    					break;
    				default:
    					printf("Unknown OPR subfunction");
    					break;
    				}
    			break;
    		case LOD:
    			top++;
    			stack[top] = stack[ getBase(instruction.level, base, stack) + instruction.argument ];
    			stack[ getBase(instruction.level, base, stack) + instruction.argument ] = -10;
    			break;
    		case STO:
    			stack[ getBase(instruction.level, base, stack) + instruction.argument ] = stack[top];
    			top--;
    			break;
    		case CAL:
    			stack[top+1] = getBase(instruction.level, base, stack);
    			stack[top+2] = base;
    			stack[top+3] = counter;
    			base = top+1;
    			counter = instruction.argument;
    			break;
    		case INT:
    			top += instruction.argument;
    			break;
    		case JMP:
    			counter = instruction.argument-1;
    			break;
    		case JPC:
    			if (stack[top] == 0){
    				counter = instruction.argument-1;
    			}
    			top--;	
    			break;
    		default:
    			printf("Unknown function");
    	}
    		
    	// PrintStackTrace
    	fprintf(output,"%-10s %-7d %-7d %-7d %-7d %-15d", getInstructionName(instruction.operation),instruction.level, instruction.argument, top, counter, base);
    
    	for (aux = base; aux<top+1 && top > 0;aux++){
    		if(stack[aux] == -10){
    			fprintf(output,"_ ");	
    		}else{
    			fprintf(output,"%d ", stack[aux]);
    		}
    	}
    	fprintf(output,"\n");
    	
    	// If RTN, stop
    	stop = (instruction.operation == 1 && instruction.argument == 0);
	}while(stop == 0);
}

int getBase(int level, int base, int stack[]){
    int newBase;
	newBase = base;
	while (level>0){
		newBase = stack[newBase];
		level--;
	}
	return newBase;
}

char* getInstructionName(int inst){
    char* names[] = { "LIT", "OPR", "LOD", "STO", "CAL", "INT", "JMP", "JPC", "WRT" };
	return names[inst];
}
