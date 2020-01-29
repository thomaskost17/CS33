/* 
 * CS:APP Data Lab 
 * 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

/*
 * STEP 2: Modify the following functions according the coding rules.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* 
 * specialBits - return bit pattern 0xffca3fff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 3
 *   Rating: 1
 */
int specialBits(void) {
     int specialBits = (~0x00)^(0xD7 <<14);
    return specialBits;
}

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //only number whose compliment is one above it is Tmax  
    int negOneCheck = !((~0)^x);
    return !(((x+1)+x)^~0)&(!negOneCheck);
}

/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
  int evenMask = ((0x55)<<24)|((0x55)<<16)|((0x55)<<8)|(0x55);//ones in all even indicies
  return (!(!(x&evenMask)));
}

/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {

  int byteRemoveMask = ~((0xFF)<<(n<<3)); //all ones except for the byte of interest
  x &= byteRemoveMask;//byte of interest now zeroes
  x = (x)|(c<<(n<<3));//move byte to right spot and replce the zeroes
  return x;
}

/* 
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x) {
  //positive will be identical to each other

  int sign = x>>31;//all 1 if neg, all 0 if positive
  int negativeMag = (x&(~(1<<31)));
  int negativeValue = (~negativeMag)+1;
  return (sign&negativeValue)|(~sign&negativeMag);
  
}

/* 
 * twosComp2SignMag - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: twosComp2SignMag(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int twosComp2SignMag(int x) {
    int sign = x>>31;//all 1 if neg, all 0 if positive
    int magnitude = ~x+1;//for neg
  return ((magnitude|(1<<31))&sign)|(x&(~sign));
}

/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x) {
    //return position of the highest index with a 1 (0-30 b/c positve and 31 not shown)
    //smear the first one bit to the right
    //declare variables
    int botOneBitsMask, botTwoBitsMask, botFourBistMask, botEightBitsMask,botSteenBitsMask, safetyMask;
    x |= (x>>1);
    x |= (x>>2);
    x |= (x>>4);
    x |= (x>>8);
    x |= (x>>16);
    x >>=1; //we dont care about the ones place bit
  
    botOneBitsMask = (0x55<<24)|(0x55<<16)|(0x55<<8)|0x55;//0101010101..
    botTwoBitsMask = (0x33<<24)|(0x33<<16)|(0x33<<8)|(0x33);//001100110011...
    botFourBistMask = (0x0f<<24)|(0x0f<<16)|(0x0f<<8)|(0x0f);//0000111100001111...
    botEightBitsMask = (0x00<<24)|(0xff<<16)|(0x00<<8)|(0xff);//0000000011111111...
    botSteenBitsMask = (0xff<<8)|(0xff);//00000000000000001111111111111111

    x = (x&botOneBitsMask) +((x>>1)&botOneBitsMask);//map ones and zeros to two bit segments denoting number of 1's
    x = (x&botTwoBitsMask) +((x>>2)&botTwoBitsMask);//do same thing but with 4 bit segments
    x = (x&botFourBistMask) + ((x>>4)&botFourBistMask);//with 8
    x = (x&botEightBitsMask) + ((x>>8)&botEightBitsMask);//with 16
    x = (x&botSteenBitsMask) + ((x>>16)&botSteenBitsMask);//for 32...will be sum of all ones

    safetyMask = 0x3f;//000...0111111, 31 is the max value so this ensures nothing is elsewhere
    return x&safetyMask;

}
