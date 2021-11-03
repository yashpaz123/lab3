//Implement a C function called ex3 such that it achieves 
//the same functionality as the machine code of objs/ex3_sol.o
//Note: you need to figure out ex3()'s function signature yourself; 
//the signature is not void ex3()
  
#include <assert.h>

/*

  0: b8 00 00 00 00                   movl    $0, %eax              rax = 0
  5: eb 04                            jmp     4 <ex3+0xb>           Jump to 0xb
  7: 48 83 c0 01                      addq    $1, %rax              rax++
  b: 80 3c 07 00                      cmpb    $0, (%rdi,%rax)       ----
  f: 75 f6                            jne     -10 <ex3+0x7>         jump to 0x7 if byte at (arg1 + rax) != 0
 
 11: ba 00 00 00 00                   movl    $0, %edx              rdx = 0
 16: eb 0c                            jmp     12 <ex3+0x24>         jump to 0x24
 18: 4c 8d 04 10                      leaq    (%rax,%rdx), %r8      r8 = byte at (rax + rdx)
 1c: 42 88 0c 07                      movb    %cl, (%rdi,%r8)       set byte at (rdi + r8) to cl (same as ecx)
 20: 48 83 c2 01                      addq    $1, %rdx              rdx++
 24: 0f b6 0c 16                      movzbl  (%rsi,%rdx), %ecx     ecx = byte at (rsi + rdx) ;;;;; why is this instruction over here? Makes reading it a bit challenging...
 28: 84 c9                            testb   %cl, %cl              ----
 2a: 75 ec                            jne     -20 <ex3+0x18>        jump to 0x18 if cl != 0
 
 2c: 48 01 d0                         addq    %rdx, %rax            rax += rdx
 2f: c6 04 07 00                      movb    $0, (%rdi,%rax)       set byte at (rdi + rax) to 0
 33: c3                               retq

*/

/*
// First attempt
void ex3(char* str1, char* str2)
{
    int var1 = 0;
    while(str1[var1] != 0) {
        var1++;
    }
    
    int var2 = 0;
    while(str2[var2] != 0) {
        str1[var1 + var2] = str2[var2];
        var2++;
    }
    
    str1[var1 + var2] = 0;
    return;
}
*/

#include <string.h>

// Better version...
// It's possible strlen was actually used through function inlining
// str1 and str2 must not be string literals
// str1 and str2 must be contiguous
void ex3(char* str1, char* str2)
{
    int len = strlen(str1);
    int i = 0;
    for(; str2[i] != '\0'; i++) {
        str1[len + i] = str2[i]; // This is unsafe if str1 and str2 aren't contiguous
    }
    str1[len + i] = '\0';
    return;
}

