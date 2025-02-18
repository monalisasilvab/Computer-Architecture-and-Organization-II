#ifndef DECODER_COND_H_
#define DECODER_COND_H_

char *decoder_cond(int num);

typedef enum cond{
	EQ,
	NE,
	CS_HS,
	CC_LO,
	MI,
	PL,
	VS,
	VC,
	HI,
	LS,
	GE,
	LT,
	GT,
	LE,
} cond;

#endif //DECODER_COND_H_