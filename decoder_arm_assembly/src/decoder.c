#include <stdio.h>
#include <string.h>

#include "decoder.h"
#include "decoder_regs.h"
#include "decoder_cond.h"

void instruction_decoder(int instruction, int opcode, int num, char *buffer){
	static int poff = 0;
	static int poff_set = 0;

	instruction = num >> 12;
	int reg = 0, immed = 0;
	switch(instruction){
		case 0x0:
		if(!opcode){
			snprintf(buffer, 1024, "LSL");
			name_reg(num,TYPE_1, buffer);
		}	
		else{
			snprintf(buffer, 1024, "LSR");
			name_reg(num,TYPE_1, buffer);
		}
		break;
				
		case 0x1:
			if(opcode == 0){
				snprintf(buffer, 1024, "ASR");
				name_reg(num,TYPE_1, buffer);
			}
			else if(opcode == 4){
				snprintf(buffer, 1024, "ADD");
				name_reg(num,TYPE_2_2, buffer);
			}
			else if(opcode == 5){
				snprintf(buffer, 1024, "SUB");
				name_reg(num,TYPE_2_2, buffer);
			}	
			else if(opcode == 6){
				snprintf(buffer, 1024, "ADD");	
				name_reg(num,TYPE_3, buffer);
			}
			else if(opcode == 7){
				snprintf(buffer, 1024, "SUB");
				name_reg(num,TYPE_3, buffer);
			}
			break;

		case 0x2:
			if(opcode == 0){
				snprintf(buffer, 1024, "MOV");
				name_reg(num, TYPE_4, buffer);
			}	
			else{
				snprintf(buffer, 1024, "CMP");
				name_reg(num, TYPE_4, buffer);
			}	
		break;

		case 0x3:
			if(opcode == 0){
				snprintf(buffer, 1024, "ADD");
				name_reg(num, TYPE_4, buffer);
			}	
			else{
				snprintf(buffer, 1024, "SUB");
				name_reg(num, TYPE_4, buffer);
			}	
		break;

		case 0x4:
			switch(opcode){
				case 0x0:
					snprintf(buffer, 1024, "AND");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x1:
					snprintf(buffer, 1024, "EOR");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x2:
					snprintf(buffer, 1024, "LSL");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x3:
					snprintf(buffer, 1024, "LSR");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x4:
					snprintf(buffer, 1024, "ASR");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x5:
					snprintf(buffer, 1024, "ADC");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x6:
					snprintf(buffer, 1024, "SBC");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x7:
					snprintf(buffer, 1024, "ROR");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x8:
					snprintf(buffer, 1024, "TST");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x9:
					snprintf(buffer, 1024, "NEG");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0xA:
					snprintf(buffer, 1024, "CMP");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0xB:
					snprintf(buffer, 1024, "CMN");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0xC:
					snprintf(buffer, 1024, "ORR");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0xD:
					snprintf(buffer, 1024, "MUL");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0xE:
					snprintf(buffer, 1024, "BIC");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0xF:
					snprintf(buffer, 1024, "MVN");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x11:
					snprintf(buffer, 1024, "ADD");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x12:
					snprintf(buffer, 1024, "ADD");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x13:
					snprintf(buffer, 1024, "ADD");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x19:
					snprintf(buffer, 1024, "MOV");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x1A:
					snprintf(buffer, 1024, "MOV");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x1B:
					snprintf(buffer, 1024, "MOV");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x18:
					snprintf(buffer, 1024, "CPY");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x15:
					snprintf(buffer, 1024, "CMP");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x16:
					snprintf(buffer, 1024, "CMP");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x17:
					snprintf(buffer, 1024, "CMP");
					name_reg(num, TYPE_5, buffer);
				break;
				case 0x1C:
					snprintf(buffer, 1024, "BX");
					name_reg(num, TYPE_10, buffer);
				break;
				case 0x1E:
					snprintf(buffer, 1024, "BLX");
					name_reg(num, TYPE_10, buffer);
				break;
				case 0xFF:
					snprintf(buffer, 1024, "LDR");
					name_reg(num, TYPE_4_1, buffer);
				break;
			}
		break;

		case 0x5:
			switch(opcode){
				case 0x0:
					snprintf(buffer, 1024, "STR");
				break;
				case 0x1:
					snprintf(buffer, 1024, "STRH") ;
				break;
				case 0x2:
					snprintf(buffer, 1024, "STRB") ;
				break;
				case 0x3:
					snprintf(buffer, 1024, "LDRSB") ;
				break;
				case 0x4:
					snprintf(buffer, 1024, "LDR") ;
				break;
				case 0x5:
					snprintf(buffer, 1024, "LDRH") ;
				break;
				case 0x6:
					snprintf(buffer, 1024, "LDRB") ;
				break;
				case 0x7:
					snprintf(buffer, 1024, "LDRSH") ;
				break;
			}
			name_reg(num,TYPE_2_1, buffer);
		break;

		case 0x6:
			if(!opcode)
				snprintf(buffer, 1024, "STR");
			else
				snprintf(buffer, 1024, "LDR");
			name_reg(num, TYPE_1_3, buffer); 
		break;

		case 0x7:
			if(!opcode)
				snprintf(buffer, 1024, "STRB");
			else
				snprintf(buffer, 1024, "LDRB");
			name_reg(num, TYPE_1_1, buffer);
		break;

		case 0x8:
			if(!opcode)
				snprintf(buffer, 1024, "STRH") ;
			else
				snprintf(buffer, 1024, "LDRH");
			name_reg(num, TYPE_1_2, buffer); 
		break;

		case 0x9:
			if(!opcode)
				snprintf(buffer, 1024, "STR") ;
			else
				snprintf(buffer, 1024, "LDR") ;
			name_reg(num, TYPE_4_2, buffer);
		break;

		case 0xA:
			snprintf(buffer, 1024, "ADD") ;
			if(!opcode)
				name_reg(num, TYPE_4_3, buffer);	
			else
				name_reg(num, TYPE_4_4, buffer);

		break;
		
		case 0xB:
			switch(opcode){
				case 0x0:
					immed = num & 0x7F;
					snprintf(buffer, 1024, "ADD sp, #%d\n", immed);
				break;
				
				case 0x1:
					immed = num & 0x7F;
					snprintf(buffer, 1024, "SUB sp, #%d\n", immed);
				break;

				case 0x8:
					snprintf(buffer, 1024, "SXTH");
					name_reg(num, TYPE_5, buffer);
				break;
				
				case 0x9:
					snprintf(buffer, 1024, "SXTB");
					name_reg(num, TYPE_5, buffer);
				break;

				case 0xA:
					snprintf(buffer, 1024, "UXTH");
					name_reg(num, TYPE_5, buffer);
				break;

				case 0xB:
					snprintf(buffer, 1024, "UXTB");
					name_reg(num, TYPE_5, buffer);
				break;

				case 0x28:
					snprintf(buffer, 1024, "REV");
					name_reg(num, TYPE_5, buffer);
				break;
				
				case 0x29:
					snprintf(buffer, 1024, "REV16");
					name_reg(num, TYPE_5, buffer);
				break;
		
				case 0x2B:
					snprintf(buffer, 1024, "REVSH");
					name_reg(num, TYPE_5, buffer);
				break;
			
				case 0x2:
					snprintf(buffer, 1024, "PUSH");
					name_reg(num, TYPE_6_1, buffer);

				break;
				
				case 0x6:
					snprintf(buffer, 1024, "POP");
					name_reg(num, TYPE_6_1, buffer);
				break;

				case 0x14:
					snprintf(buffer, 1024, "SETEND LE");
				break;
			
				case 0x15:
					snprintf(buffer, 1024, "SETEND BE");
				break;

				case 0xC:
					snprintf(buffer, 1024, "CPSIE");
				break;

				case 0xE:
					snprintf(buffer, 1024, "CPSID");					
				break;

				case 0xF:
					snprintf(buffer, 1024, "BKPT");
					name_reg(num, TYPE_7, buffer);
				break;	

				default:
					snprintf(buffer, 1024, "Instrução Inválida!\n");
				break;
			}
		break;

		case 0xC:
			if(!opcode)
				snprintf(buffer, 1024, "STMIA");
			else
				snprintf(buffer, 1024, "LDMIA");
			name_reg(num, TYPE_6, buffer);
		break;

		case 0xD:
			if(opcode == 0xF){
				snprintf(buffer, 1024, "SWI");
			}else{
				snprintf(buffer, 1024, "B%s", decoder_cond(num));
			}
			name_reg(num, TYPE_7, buffer);
		break;

		case 0xE:
			if(!opcode){
				snprintf(buffer, 1024, "B");
				name_reg(num, TYPE_8, buffer);
			}
			else{
				snprintf(buffer, 1024, "BLX");
				name_reg(num, TYPE_9, buffer);
			}
		break;

		case 0xF:
			immed = num & 0x7FF;
			snprintf(buffer, 1024, "BL #%d", (4 + (immed * 2)));
		break;

		default:
			snprintf(buffer, 1024, "Instrução Inválida!\n");
		break;
	}
}

int opcode(int instruction, int num){
	int opcode = 0;
	instruction = num >> 12;

	switch(instruction){
		case 0x0:
			opcode = (num>>11) & 0b1;
		break;

		case 0x1:
			if(((num>>11) & 0b1) == 0)
				opcode = 0;
			else if(((num>>11) & 0b1) && ((num>>10) & 0b1))
				opcode = ((num>>9) & 0b111);
			else
				opcode = ((num>>9) & 0b111);
		break;

		case 0x2:
				opcode = (num>>11) & 0b1;
		break;

		case 0x3:
				opcode = (num>>11) & 0b1;
		break;
				
		case 0x4:
				if(!((num>>11)&0b1)){
					if(((num>>8) & 0b111) == 0b111)
						opcode = ((num>>7) & 0b1111) * 2;  //para evitar o conflito com o outro opcode
					else
						opcode = (num>>6) & 0b11111;
				}
				else
					opcode = 0b11111111;
		break;

		case 0x5:
				opcode = (num>>9) & 0b111;
		break;
		
		case 0x6 ... 0xA:
			opcode = (num>>11) & 0b1;
		break;
		
		case 0xB:
			if(((num>>9) & 0b11) == 0b10)
				opcode = (num>>9 & 0b111);

			if((num>>8 & 0b1111) == 0)
				opcode = (num>>7 & 0b1);

			if((num>>8 & 0b11) == 0b10)
				opcode = (num>>6 & 0b111111);

			if((num>>9 & 0b11) == 0b11)
				opcode = (num>>3 & 0b1111) * 2;
			
			if((num>>9 & 0b111) == 0b111)
				opcode = 0b1111;
		break;

		case 0xC:
			opcode = ((num>>11) & 0b1);
		break;

		case 0xD:
			opcode = ((num>>8) & 0b1111);
		break;

		case 0xE:
			opcode = (num>>11) & 0b1;
		break;

		case 0xF:
			opcode = (num>>11) & 0b1;
		break;

		default:
			opcode = 0;
		break;					
	}

	return opcode;
}
