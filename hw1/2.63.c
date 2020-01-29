#include "limits.h"
unsigned long srl(unsigned long x, int k) {
	/* perform shift arithmatically*/
	long length = 8 * sizeof(long)-1;
	k = (k > length ? length : (k<0 ? 0:k));

	//k %= length;//ensure k is within the length of the max number of bits//not right
	unsigned int mask = (1 << (length + 1 - k)) - 1;//00..0011...1
	unsigned xsra = (int)x >> k;
	xsra &= mask;
	return xsra;
}

//perform signed right shift
long sra(long x, int k) {
	/*Perform shift logically*/
	long length = 8 * sizeof(long) - 1;//accounting for sign
	k = (k > length ? length : (k < 0 ? 0 : k));
	unsigned long sign = (INT_MIN) & x;
	int xsrl = (unsigned)x >> k;//has been shifted right by k % length bits
	// get bit pattern 1...10...0 such that the transition occurs at the beginning of the first integer

	unsigned long mask = ~((1 << (length - k)) - 1); // MAKE THIS EQUAL TO THE BIT PATTERN ABOVE
	xsrl = (sign == 0 ? xsrl : xsrl | mask);
	return xsrl;
}