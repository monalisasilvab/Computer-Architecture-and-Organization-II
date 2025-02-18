#include "decoder_cond.h"

char *decoder_cond(int num){
	int cond = (num>>8) & 0xF;
	switch(cond){
		case EQ:
			return "EQ";
		break;

		case NE:
			return "NE";
		break;

		case CS_HS:
			return "CS_HS";
		break;

		case CC_LO:
			return "CC_LO";
		break;

		case MI:
			return "MI";
		break;

		case PL:
			return "PL";
		break;

		case VS:
			return "VS";
		break;

		case VC:
			return "VC";
		break;

		case HI:
			return "HI";
		break;

		case LS:
			return "LS";
		break;

		case GE:
			return "GE";
		break;

		case LT:
			return "LT";
		break;

		case GT:
			return "GT";
		break;

		case LE:
			return "LE";
		break;
	}
}