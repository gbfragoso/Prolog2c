#include "rpn2pci.h"
#include <ctype.h>
#include <stdlib.h>

Tinstruction* toInstruction(char *epr){
	int i;
	int aux = 0; // Array position
	int totalInstructions = 1;
	static Tinstruction instructions[50];
	
	// Solution from dasblinkenlight - Stackoverflow
	// Catch numbers from string
	char *p = epr;
	
	// Reserve space
	Tinstruction intInst;
	intInst.operation = 5;
	intInst.level = 0;
	intInst.argument = 5;
	instructions[0] = intInst;
	
	while (*p) { // While there are more characters to process...
	    if (isdigit(*p)) { // Upon finding a digit, ...
	        int val = (int)strtol(p, &p, 10); // Read a number, ...
	        Tinstruction instruction;
	        instruction.operation = 0;
	        instruction.level = 0;
	        instruction.argument = val;
	        
	        Tinstruction instruction2;
	        instruction2.operation = 3;
	        instruction2.level = 0;
	        instruction2.argument = aux;
	        
	        // Store instructions
	        instructions[totalInstructions] = instruction;
	        instructions[totalInstructions+1] = instruction2;
	        totalInstructions += 2;
	        
	        // Points next array position
	        aux++;
	    }else { // Otherwise, move on to the next character.
	        switch(*p){
	        	case '&':{
	        		Tinstruction andLod;
	        		andLod.operation = 2;
	        		andLod.level = 0;
	        		andLod.argument = aux - 1;
	        		
	        		Tinstruction andLod2;
	        		andLod2.operation = 2;
	        		andLod2.level = 0;
	        		andLod2.argument = aux - 2;
	        		
	        		Tinstruction andOpr;
	        		andOpr.operation = 1;
	        		andOpr.level = 0;
	        		andOpr.argument = 1;
	        		
	        		Tinstruction andSto;
	        		andSto.operation = 3;
	        		andSto.level = 0;
	        		andSto.argument = aux-2;
	        		
	        		instructions[totalInstructions] = andLod;
	        		instructions[totalInstructions+1] = andLod2;
	        		instructions[totalInstructions+2] = andOpr;
	        		instructions[totalInstructions+3] = andSto;
	        		
	        		totalInstructions += 4;
	        		aux--;
	        		break;
	        	}
	        	case '|':{
	        		Tinstruction orLod;
	        		orLod.operation = 2;
	        		orLod.level = 0;
	        		orLod.argument = aux - 1;
	        		
	        		Tinstruction orLod2;
	        		orLod2.operation = 2;
	        		orLod2.level = 0;
	        		orLod2.argument = aux - 2;
	        		
	        		Tinstruction orOpr;
	        		orOpr.operation = 1;
	        		orOpr.level = 0;
	        		orOpr.argument = 2;
	        		
	        		Tinstruction orSto;
	        		orSto.operation = 3;
	        		orSto.level = 0;
	        		orSto.argument = aux-2;
	        		
	        		instructions[totalInstructions] = orLod;
	        		instructions[totalInstructions+1] = orLod2;
	        		instructions[totalInstructions+2] = orOpr;
	        		instructions[totalInstructions+3] = orSto;
	        		
	        		totalInstructions += 4;
	        		aux--;
	        		break;
	        	}
	        	case ':':{
	        		Tinstruction impLod;
	        		impLod.operation = 2;
	        		impLod.level = 0;
	        		impLod.argument = aux - 1;
	        		
	        		Tinstruction impLod2;
	        		impLod2.operation = 2;
	        		impLod2.level = 0;
	        		impLod2.argument = aux - 2;
	        		
	        		Tinstruction impOpr;
	        		impOpr.operation = 1;
	        		impOpr.level = 0;
	        		impOpr.argument = 4;
	        		
	        		Tinstruction impSto;
	        		impSto.operation = 3;
	        		impSto.level = 0;
	        		impSto.argument = aux-2;
	        		
	        		instructions[totalInstructions] = impLod;
	        		instructions[totalInstructions+1] = impLod2;
	        		instructions[totalInstructions+2] = impOpr;
	        		instructions[totalInstructions+3] = impSto;
	        		
	        		totalInstructions += 4;
	        		aux--;
	        		break;
	        	}
	        	case '-':{
	        		Tinstruction bicLod;
	        		bicLod.operation = 2;
	        		bicLod.level = 0;
	        		bicLod.argument = aux - 1;
	        		
	        		Tinstruction bicLod2;
	        		bicLod2.operation = 2;
	        		bicLod2.level = 0;
	        		bicLod2.argument = aux - 2;
	        		
	        		Tinstruction bicOpr;
	        		bicOpr.operation = 1;
	        		bicOpr.level = 0;
	        		bicOpr.argument = 5;
	        		
	        		Tinstruction bicSto;
	        		bicSto.operation = 3;
	        		bicSto.level = 0;
	        		bicSto.argument = aux-2;
	        		
	        		instructions[totalInstructions] = bicLod;
	        		instructions[totalInstructions+1] = bicLod2;
	        		instructions[totalInstructions+2] = bicOpr;
	        		instructions[totalInstructions+3] = bicSto;
	        		
	        		totalInstructions += 4;
	        		aux--;
	        		break;
	        	}
	        	case '!':{
	        		Tinstruction notLod;
	        		notLod.operation = 2;
	        		notLod.level = 0;
	        		notLod.argument = aux-1;
	        		
	        		Tinstruction notOpr;
	        		notOpr.operation = 1;
	        		notOpr.level = 0;
	        		notOpr.argument = 3;
	        		
	        		Tinstruction notSto;
	        		notSto.operation = 3;
	        		notSto.level = 0;
	        		notSto.argument = aux-1;
	        		
	        		instructions[totalInstructions] = notLod;
	        		instructions[totalInstructions+1] = notOpr;
	        		instructions[totalInstructions+2] = notSto;
	        		
	        		totalInstructions += 3;
	        		break;
	        	}
	        }
	        p++;
	    }
	}
	
	// Last Instruction
	Tinstruction rtn;
	rtn.operation = 1;
	rtn.level = 0;
	rtn.argument = 0;
	
	instructions[totalInstructions] = rtn;
	
	return instructions;
}
