//Implement a C function called ex5 such that it achieves 
//the same functionality as the machine code of objs/ex5_sol.o
//Note: you need to figure out ex5()'s function signature yourself; 
//the signature is not void ex5(node *n). However, as a hint, 
//ex5 does take node * as an argument.

/*

  0: 48 85 ff                         testq    %rdi, %rdi       ----
  3: 74 20                            je       32 <ex5+0x25>    Jump to 0x25 if arg == 0
 
 START loop section
 
  5: 48 8b 47 08                      movq     8(%rdi), %rax    rax = value in addr (arg + 8) ; node arg->next
  9: 48 85 c0                         testq    %rax, %rax       ----
  c: 74 11                            je       17 <ex5+0x1f>    jump to 0x1f if rax == 0
 
  e: 48 8b 17                         movq     (%rdi), %rdx     rdx = *arg ; node arg->value
 11: 48 89 c7                         movq     %rax, %rdi       arg = rax
 14: 48 3b 10                         cmpq     (%rax), %rdx     ----
 17: 7e ec                            jle      -20 <ex5+0x5>    Jump to 0x5 if rdx <= *rax ; node rax->value
 
 END loop section
 
 19: b8 00 00 00 00                   movl     $0, %eax         ----
 1e: c3                               retq                      return 0
 1f: b8 01 00 00 00                   movl     $1, %eax         ----
 24: c3                               retq                      return 1
 25: b8 01 00 00 00                   movl     $1, %eax         ----
 2a: c3                               retq                      return 1

*/
 
#include <assert.h>
#include "ex5.h"

int ex5(node* curr)
{
    node* next;
    long currValue;
    if(curr == 0) return 1;
    do {
        next = curr->next;
        if(next == 0) return 1;
        currValue = curr->value;
        curr = next;
    } while(currValue <= next->value);
    return 0;
}
