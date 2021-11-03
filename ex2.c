//Implement a C function called ex2 such that it achieves 
//the same functionality as the machine code of objs/ex2_sol.o
//Note: you need to figure out ex2()'s function signature yourself; 
//the signature is not void ex2()
  
#include <assert.h>

/*

 Text Memory:                         Disassembly:                  My Thought Process:
 ---------------------------------------------------------------------------------------
  0: ba 00 00 00 00                   movl    $0, %edx              Move int 0 to edx
  5: b8 00 00 00 00                   movl    $0, %eax              Move int 0 to eax
  a: eb 04                            jmp     4 <ex2+0x10>          Jump to 0x10
  c: 48 83 c2 01                      addq    $1, %rdx              Increment arg3
 10: 48 39 f2                         cmpq    %rsi, %rdx            ----
 13: 7d 0f                            jge     15 <ex2+0x24>         If arg2 > arg3, jump to 0x24 ; this is the same as arg3 <= arg2
 15: 8b 0c 97                         movl    (%rdi,%rdx,4), %ecx   arg4 = value in address (arg1 + arg3 * 4)
 18: 85 c9                            testl   %ecx, %ecx            ----
 1a: 7e f0                            jle     -16 <ex2+0xc>         if ecx <= 0 jump to 0xc
 1c: 48 63 c9                         movslq  %ecx, %rcx            set arg4 to value in ecx, and convert from 32 to 64 bit
 1f: 48 01 c8                         addq    %rcx, %rax            Add arg4 to ret val
 22: eb e8                            jmp     -24 <ex2+0xc>         Jump to 0xc
 24: f3 c3                            rep             retq          Return 8 bytes (and avoid branch problem)

*/

/*
// This was my first attempt at reverse engineering the disassembly
long ex2(long arg1, long arg2)
{
    long rdx = 0;
    long rax = 0;
    while(true) {
        if(arg2 > rdx) break;
        
        int rcx = *(int*)(arg1 + rdx * 4); // actually ecx, is arg1 pointer to array? each elem is 4 bytes?
        
        if(rcx > 0) rax += rcx;
        
        rdx++; // This comes last since it's skipped the first time
    }
    return rax;
}
*/

// This is my final attempt
// It takes an int array pointer and the length as input and returns the sum of all the values greater than 0
int ex2(int* array, int length)
{
    int sum = 0;
    for(int i = 0; i < length; i++) {
        int value = array[i];
        if(value > 0) sum += value;
    }
    return sum;
}

