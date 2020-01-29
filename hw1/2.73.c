#include <limits.h>
int saturating_add(int x, int y)
{
	//need to saturate at positive overflow and at negative overflow addition
	//positive overflow happens when the leading bit of the result differs from either of the parameters
	//negative overflow happens when the leading result differs from either of the parameters
	//note: that in any case that the leading bit of the parameters are different from one another the value is fine
	int sign = INT_MIN;//1000... in two's complement
	//both leading 0
    int length = sizeof(int)<<3;
    int leading_x = x >> (length-1);//0
    int leading_y = y >> (length-1);//0
    int leading_x_y = (x + y) >> (length-1);//1
    int x_y = x+y;


    int positive_overflow = ((~(leading_x|leading_y))&(~(leading_x^0x0)))&(leading_x^leading_x_y);//000000 if false, 11111 if true
    int negative_overflow = (leading_x&leading_y)&(leading_x^leading_x_y);
    return ((INT_MAX &positive_overflow)|(INT_MIN&negative_overflow))|((x+y)&(~negative_overflow)&(~positive_overflow));


    //positive overflow

    //negative overflow

    //nooverflow

}