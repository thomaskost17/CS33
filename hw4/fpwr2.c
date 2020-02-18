#include <stdio.h>

static float u2f(unsigned u)
{
	union floatAndUnsinged
	{
		float f;
		unsigned un;
	} x;//the same bit pattern will go here but can be interpreted as either type
	x.un = u;

	return x.f;
}

float fpwr2(int x)
{
	// get result for exponent and fraction
	// note that we only need to set one bit in the frac as this is always going to be a power of 2
	unsigned exp, frac;
	unsigned u=0;
	int EXP_MIN = -126;
	if(x <EXP_MIN-23)  //WE CAN GO TO 2^-149 because of the fact that frac can have leading zeros
	{
		//return 0.0
		exp =0; 
		frac = 0;

	}else if(x< EXP_MIN) //less than -126, more than -149
	{
		//denormalized result
		exp =0;
		frac =(1<<(22-(x+127)));//put a 1 x+127 bits from 

	}else if(x < 128)
	{
		//normalized result
		exp = x+127;
		frac = 0;//need nothing here as leading bit is implied
	} else
	{
		// return +oo
		exp = 255;
		frac = 0;//defined as +oo

	}
	//pack values into 32 bit value
	
	u = exp<<23|frac;
	return u2f(u);
	
}
