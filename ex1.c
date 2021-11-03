//Implement a C function called ex1 such that it achieves 
//the same functionality as the machine code of objs/ex1_sol.o
//Note: you need to figure out ex1()'s function signature yourself; 
//the signature is not void ex1()
  
#include <assert.h>

/*
 
 Object file begins with header bytes "7F454C46 02010100 00000000 00000000 01003E00 01000000 00000000 00000000 00000000 00000000 08020000 00000000 00000000 40000000 00004000 0B000A00"
 
 Disassembly / my thought process:
  0: 48 01 f7                         addq    %rsi, %rdi        Add 2nd argument to 1st
  3: 48 39 d7                         cmpq    %rdx, %rdi        Compare 3rd arg to 1st
  6: 74 06                            je      6 <ex1+0xe>       If equal jump to 0xe
  8: b8 00 00 00 00                   movl    $0, %eax
  d: c3                               retq                      Return 0 if not equal
  e: b8 01 00 00 00                   movl    $1, %eax
 13: c3                               retq                      Return 1 if equal
 
 */

long ex1(long a, long b, long c)
{
    a += b;
    return c == a ? 1 : 0;
}
