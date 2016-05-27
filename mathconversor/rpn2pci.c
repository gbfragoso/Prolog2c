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
	        	case '+':{
	        		Tinstruction plusLod;
	        		plusLod.operation = 2;
	        		plusLod.level = 0;
	        		plusLod.argument = aux - 1;
	        		
	        		Tinstruction plusLod2;
	        		plusLod2.operation = 2;
	        		plusLod2.level = 0;
	        		plusLod2.argument = aux - 2;
	        		
	        		Tinstruction plusOpr;
	        		plusOpr.operation = 1;
	        		plusOpr.level = 0;
	        		plusOpr.argument = 2;
	        		
	        		Tinstruction plusSto;
	        		plusSto.operation = 3;
	        		plusSto.level = 0;
	        		plusSto.argument = aux-2;
	        		
	        		instructions[totalInstructions] = plusLod;
	        		instructions[totalInstructions+1] = plusLod2;
	        		instructions[totalInstructions+2] = plusOpr;
	        		instructions[totalInstructions+3] = plusSto;
	        		
	        		totalInstructions += 4;
	        		aux--;
	        		break;
	        	}
	        	case '-':{
	        		Tinstruction subLod;
	        		subLod.operation = 2;
	        		subLod.level = 0;
	        		subLod.argument = aux - 1;
	        		
	        		Tinstruction subLod2;
	        		subLod2.operation = 2;
	        		subLod2.level = 0;
	        		subLod2.argument = aux - 2;
	        		
	        		Tinstruction subOpr;
	        		subOpr.operation = 1;
	        		subOpr.level = 0;
	        		subOpr.argument = 3;
	        		
	        		Tinstruction subSto;
	        		subSto.operation = 3;
	        		subSto.level = 0;
	        		subSto.argument = aux-2;
	        		
	        		instructions[totalInstructions] = subLod;
	        		instructions[totalInstructions+1] = subLod2;
	        		instructions[totalInstructions+2] = subOpr;
	        		instructions[totalInstructions+3] = subSto;
	        		
	        		totalInstructions += 4;
	        		aux--;
	        		break;
	        	}
	        	case '*':{
	        		Tinstruction multLod;
	        		multLod.operation = 2;
	        		multLod.level = 0;
	        		multLod.argument = aux - 1;
	        		
	        		Tinstruction multLod2;
	        		multLod2.operation = 2;
	        		multLod2.level = 0;
	        		multLod2.argument = aux - 2;
	        		
	        		Tinstruction multOpr;
	        		multOpr.operation = 1;
	        		multOpr.level = 0;
	        		multOpr.argument = 4;
	        		
	        		Tinstruction multSto;
	        		multSto.operation = 3;
	        		multSto.level = 0;
	        		multSto.argument = aux-2;
	        		
	        		instructions[totalInstructions] = multLod;
	        		instructions[totalInstructions+1] = multLod2;
	        		instructions[totalInstructions+2] = multOpr;
	        		instructions[totalInstructions+3] = multSto;
	        		
	        		totalInstructions += 4;
	        		aux--;
	        		break;
	        	}
	        	case '/':{
	        		Tinstruction divLod;
	        		divLod.operation = 2;
	        		divLod.level = 0;
	        		divLod.argument = aux - 1;
	        		
	        		Tinstruction divLod2;
	        		divLod2.operation = 2;
	        		divLod2.level = 0;
	        		divLod2.argument = aux - 2;
	        		
	        		Tinstruction divOpr;
	        		divOpr.operation = 1;
	        		divOpr.level = 0;
	        		divOpr.argument = 5;
	        		
	        		Tinstruction divSto;
	        		divSto.operation = 3;
	        		divSto.level = 0;
	        		divSto.argument = aux-2;
	        		
	        		instructions[totalInstructions] = divLod;
	        		instructions[totalInstructions+1] = divLod2;
	        		instructions[totalInstructions+2] = divOpr;
	        		instructions[totalInstructions+3] = divSto;
	        		
	        		totalInstructions += 4;
	        		aux--;
	        		break;
	        	}
	        	case '~':{
	        		Tinstruction neqLod;
	        		neqLod.operation = 2;
	        		neqLod.level = 0;
	        		neqLod.argument = aux-1;
	        		
	        		Tinstruction neqOpr;
	        		neqOpr.operation = 1;
	        		neqOpr.level = 0;
	        		neqOpr.argument = 1;
	        		
	        		Tinstruction neqSto;
	        		neqSto.operation = 3;
	        		neqSto.level = 0;
	        		neqSto.argument = aux-1;
	        		
	        		instructions[totalInstructions] = neqLod;
	        		instructions[totalInstructions+1] = neqOpr;
	        		instructions[totalInstructions+2] = neqSto;
	        		
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