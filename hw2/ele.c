#define R 3
#define S 19
#define T 2

int A[R][S][T];

int
ele (long i, long j, long k)
{
  return A[R - i][1 - j][k - 1];
}
//---------------------------------------------//
//from the machine code ele.s we were able to deduce the values of R,S,T
// we are able to do this through extending the equation 3.1 to a 3 dimensional array.
//this is done as follows:
// &a[i][j][k] = &a + sizeof(int)*(k +T*j + T*S*k)
// this can be deduced by looking at the 3-d representation of the matrix
// and comparing it to the pattern with which the bytes are mapped out
// as incrementing the first column will skip TS elements, the index of the first column
// must be multiplied by this value. from there is is essentially, the same as a 2 d array, so accounting for 
// our i*T*S term will suffice for modifying the equation.
//
//note that the constants for R,S,T can be found through examining the machine code
//we notice the program starts by calculating 3-i, as the first index corresponds to A-i, we know A must be 3.
//The program then procedes to multiply this index number by 38 (using lea instructions),
// so TS is a 38. the program then, through the use of lea and subq instructions, calculates the second index,
//multiplies it by 2, and adds the calculated third index to the sum. The final sum is multiplied by 4 (the size of int) and added to 
//some constant value. This suggests the T is 2, and by our previous information that S is 19. 
//Note that this can also be found through testing trial inputs. If you ensure that one index remains at zero and 
//examine the effect setting each index to 1 with all the others zero, you can deduce the same 
//values for our constants R,S, and T.
//---------------------------------------------//
