#include <limits.h>
#include <stdbool.h>
int saturating_add(int x, int y)
{
    //can simplify to seeing only the case if one zero or one one in the leading bit
    int overflow_bool = __builtin_add_overflow_p( x, y, (int) 0);
    int length = sizeof(int)<<3;
    int overflow = (overflow_bool <<(length-1))>>(length-1);


    int leading_x = x >> (length-1);//0
    int leading_y = y >> (length-1);//0
    int leading_x_y = (x + y) >> (length-1);//1
    int x_y = x+y;


    int positive_overflow = ((~(leading_x|leading_y))&(~(leading_x^0x0)))&(overflow);//000000 if false, 11111 if true
    int negative_overflow = (leading_x&leading_y)&(overflow);

    return ((INT_MAX &positive_overflow)|(INT_MIN&negative_overflow))|((x+y)&(~negative_overflow)&(~positive_overflow));
}