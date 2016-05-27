#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pcode.h"
#include "rpn2pci.h"

typedef char * string;

/*
	Author: Gustavo B. Fragoso
*/

int main (int argc, char **argv){
	
	// Vector with only integers, used as a datastore
	int stack[50] = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
	int productions[50], i;	    							// Result of Pushdown Automata
    	string rpn = (string)malloc(50*sizeof(char));               			// Reverse Polish Notation
    
    	FILE *input = fopen("expr.txt","r");
	FILE *output = fopen("output.txt", "w");
	
	if(input !=NULL){
		fscanf(input,"%[^\n]",rpn);
		if(output!=NULL){
			printf("Step 1. Catch logic expression ... done!\n");
	
			// RPN -> PCI
			printf("Step 2. Convert RPN into pcode instructions ... ");
			Tinstruction * instructions = toInstruction(rpn);
			printf("done!\n");
					
			// Array of instructions
			printf("Step 3. Running pcode machine ... ");
			fprintf(output,"\nOutput:\n");
			fprintf(output,"%-10s %-7s %-7s %-7s %-7s %-15s %s\n","Inst","Level","Arg","Top","Counter","Base","Stack");
			pcode(instructions, stack, output);
			printf("done!\n");
					
			free(rpn);
			// Closing File
			fclose(output);
			    	
			printf("Output file generated.\n");	
		
			
		}else{
			printf("\nError when opening the output file.");
		}
	}else{
		printf("\nError when opening the input file.");
	}
	return 0;
}

