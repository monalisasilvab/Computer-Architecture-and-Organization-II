#include <stdio.h>
#include <string.h>
#include "decoder_regs.h"

void name_reg(int num, int TYPE, char *buffer){
	int reg, immed, register_list, flag = 0;

	char temp_buffer[1024];
	switch(TYPE){
		case TYPE_1:
			//primeiro registrador
			reg = num & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);

			//segundo registrador
			reg = (num & 0x38) >> 3;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);

			//imediato
			immed = (num>>6) & 0x1F;
			snprintf(temp_buffer, 1024, "%s #%d", buffer, immed);
		break;

		case TYPE_1_1:
			//primeiro registrador
			reg = num & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
					
			//segundo registrador
			reg = (num & 0x38) >> 3;
			snprintf(temp_buffer, 1024, "%s [%s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//imediato
			immed = (num>>6) & 0x1F;
			snprintf(temp_buffer, 1024, "%s #%d]", buffer, immed);

		case TYPE_1_2:
			//primeiro registrador
			reg = num & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));	
			strcpy(buffer, temp_buffer);
				
			//segundo registrador
			reg = (num & 0x38) >> 3;
			snprintf(temp_buffer, 1024, "%s [%s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//imediato
			immed = (num>>6) & 0x1F;
			snprintf(temp_buffer, 1024, "%s #%d]", buffer, 2 * immed);

		case TYPE_1_3:
			//primeiro registrador
			reg = num & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
					
			//segundo registrador
			reg = (num & 0x38) >> 3;
			snprintf(temp_buffer, 1024, "%s [%s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//imediato
			immed = (num>>6) & 0x1F;
			snprintf(temp_buffer, 1024, "%s #%d]", buffer, 4 * immed);
		break;
		
		case TYPE_2_1:
			//primeiro registrador
			reg = num & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));	
			strcpy(buffer, temp_buffer);
				
			//segundo registrador
			reg = (num & 0x38) >> 3;
			snprintf(temp_buffer, 1024, "%s [%s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//terceiro registrador
			reg = (num & 0x1C0) >> 6;
			snprintf(temp_buffer, 1024, "%s %s]", buffer, decoder_reg(reg));
		break;
		
		case TYPE_2_2:
			//primeiro registrador
			reg = num & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));	
			strcpy(buffer, temp_buffer);
				
			//segundo registrador
			reg = (num & 0x38) >> 3;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//terceiro registrador
			reg = (num & 0x1C0) >> 6;
			snprintf(temp_buffer, 1024, "%s %s", buffer, decoder_reg(reg));
		break;

		case TYPE_3:
			//segundo registrador
			reg = num & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
					
			//segundo registrador
			reg = (num & 0x38) >> 3;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//imediato
			immed = (num>>6) & 0x7;
			snprintf(temp_buffer, 1024, "%s #%d", buffer, immed);
		break;

		case TYPE_4:
			//registrador
			reg = (num>>8) & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//imediato
			immed = num & 0xFF;
			snprintf(temp_buffer, 1024, "%s #%d", buffer, immed);
		break;	

		case TYPE_4_1:
			//registrador
			reg = (num>>8) & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//imediato
			immed = 4 * (num & 0xFF);
			snprintf(temp_buffer, 1024, "%s [pc, #%d]", buffer, immed);
		break;

		case TYPE_4_2:
			//registrador
			reg = (num>>8) & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//imediato
			immed = 4 * (num & 0xFF);
			snprintf(temp_buffer, 1024, "%s [sp, #%d]", buffer, immed);
		break;	

		case TYPE_4_3:
			//registrador
			reg = (num>>8) & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//imediato
			immed = 4 * (num & 0xFF);
			snprintf(temp_buffer, 1024, "%s pc, #%d", buffer, immed);
		break;

		case TYPE_4_4:
			//registrador
			reg = (num>>8) & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));
			strcpy(buffer, temp_buffer);
			
			//imediato
			immed = 4 * (num & 0xFF);
			snprintf(temp_buffer, 1024, "%s sp, #%d", buffer, immed);
		break;	

		case TYPE_5:
			//primeiro registrador
			reg = num & 0x7;
			snprintf(temp_buffer, 1024, "%s %s,", buffer, decoder_reg(reg));	
			strcpy(buffer, temp_buffer);
				
			//segundo registrador
			reg = (num >> 3) & 0x7;
			snprintf(temp_buffer, 1024, "%s %s", buffer, decoder_reg(reg));
		break;	

		case TYPE_6:
			//registrador
			reg = (num >> 8) & 0x7;
			snprintf(temp_buffer, 1024, "%s %s!", buffer, decoder_reg(reg));

			//Register List
			register_list = num & 0xFF;
			strcat(temp_buffer, ", {");
			if(register_list & 0x1){
				strcat(temp_buffer, "r0");
				flag = 1;
			}
			if(register_list & 0x2){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r1");
				flag = 1;
			}
			if(register_list & 0x4){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r2");
				flag = 1;
			}
			if(register_list & 0x8){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r3");
				flag = 1;
			}
			if(register_list & 0x10){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r4");
				flag = 1;
			}
			if(register_list & 0x20){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r5");
				flag = 1;
			} 
			if(register_list & 0x40){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r6");
				flag = 1;
			}
			if(register_list & 0x80){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r7");
				flag = 1;
			}
			strcat(temp_buffer, "}");
		break;

		case TYPE_6_1:
			strcpy(temp_buffer, buffer);
			strcat(temp_buffer, " {");

			register_list = num & 0x1FF;
			if(register_list & 0x1){
				strcat(temp_buffer, "r0");
				flag = 1;
			}
			if(register_list & 0x2){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r1");
				flag = 1;
			}
			if(register_list & 0x4){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r2");
				flag = 1;
			}
			if(register_list & 0x8){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r3");
				flag = 1;
			}
			if(register_list & 0x10){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r4");
				flag = 1;
			}
			if(register_list & 0x20){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r5");
				flag = 1;
			} 
			if(register_list & 0x40){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r6");
				flag = 1;
			}
			if(register_list & 0x80){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r7");
				flag = 1;
			}
			if(register_list & 0x100){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "lr");
			}
			strcat(temp_buffer, "}");
		break;

		case TYPE_6_2:
			strcpy(temp_buffer, buffer);
			register_list = num & 0x1FF;
			strcat(temp_buffer, " {");
			if(register_list & 0x1){
				strcat(temp_buffer, "r0");
				flag = 1;
			}
			if(register_list & 0x2){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r1");
				flag = 1;
			}
			if(register_list & 0x4){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r2");
				flag = 1;
			}
			if(register_list & 0x8){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r3");
				flag = 1;
			}
			if(register_list & 0x10){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r4");
				flag = 1;
			}
			if(register_list & 0x20){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r5");
				flag = 1;
			} 
			if(register_list & 0x40){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r6");
				flag = 1;
			}
			if(register_list & 0x80){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "r7");
				flag = 1;
			}
			if(register_list & 0x100){
				if(flag) strcat(temp_buffer, ", ");
				strcat(temp_buffer, "pc");
			}
			strcat(temp_buffer, "}");
		break;

		case TYPE_7:
			immed = num & 0xFF;
			snprintf(temp_buffer, 1024, "%s #%d", buffer, 4 + (immed * 2));
		break;

		case TYPE_8:
			immed = num & 0x7FF;
			snprintf(temp_buffer, 1024, "%s #%d", buffer, 4 + (immed * 2));
		break;

		case TYPE_9:
			immed = num & 0x7FF;
			immed = ~immed & 0x1;
			snprintf(temp_buffer, 1024, "%s #%d", buffer, 4 + (immed * 2));
		break;

		case TYPE_10:	
			reg = (num >> 3) & 0xF;
			snprintf(temp_buffer, 1024, "%s %s", buffer, decoder_reg(reg)); 
		break;
	}

	strcpy(buffer, temp_buffer);
}

char *decoder_reg(int reg){
	switch(reg){
		case R0:
			return "r0";
			break;
		case R1:
			return "r1";
			break;
		case R2:
			return "r2";
			break;
		case R3:
			return "r3";
			break;
		case R4:
			return "r4";
			break;		
		case R5:
			return "r5";
			break;
		case R6:
			return "r6";
			break;
		case R7:
			return "r7";
			break;
		case R8:
			return "r8";
			break;
		case R9:
			return "r9";
			break;
		case R10:
			return "r10";
			break;
		case R11:
			return "r11";
			break;
		case R12:
			return "r12";
			break;
		case R13:
			return "r13";
			break;
		case R14:
			return "r14";
			break;
		case R15:
			return "r15";
			break;													
	}
}