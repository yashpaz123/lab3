//Implement a C function called ex4 such that it achieves 
//the same functionality as the machine code of objs/ex4_sol.o
//Note: you need to figure out ex4()'s function signature yourself; 
//the signature is not void ex4()
  
#include <assert.h>

/*

The values bounce across registers very frequently to preserve important values such as return value and argument/param
 
  0: 55                               pushq   %rbp                  push rbp ; save for later, because we're using the register
  1: 53                               pushq   %rbx                  push rbx ; ^^^
  2: 48 83 ec 08                      subq    $8, %rsp              rsp -= 8
  6: 48 89 fb                         movq    %rdi, %rbx            rbx = arg1 ; save for later
  9: 48 83 ff 01                      cmpq    $1, %rdi              ----
  d: 7f 0a                            jg      10 <ex4+0x19>         jump to 0x19 if arg1 > 1
  f: 48 89 d8                         movq    %rbx, %rax            rax = rbx ; save for later
 12: 48 83 c4 08                      addq    $8, %rsp              rsp += 8
 16: 5b                               popq    %rbx                  pop 8 bytes save in rbx
 17: 5d                               popq    %rbp                  ' ' ' ' ' ' save in rbp
 18: c3                               retq                          return rbx ; because rax = rbx
 
                                                                    Run instructions below if 1 > arg1
 
 19: 48 8d 7f ff                      leaq    -1(%rdi), %rdi        ----
 1d: e8 00 00 00 00                   callq   0 <ex4+0x22>          call recursive with arg (rdi - 1)
 22: 48 89 c5                         movq    %rax, %rbp
 25: 48 8d 7b fe                      leaq    -2(%rbx), %rdi        ----
 29: e8 00 00 00 00                   callq   0 <ex4+0x2e>          call recursive with arg (rdi - 2)
 2e: 48 8d 5c 05 00                   leaq    (%rbp,%rax), %rbx     this also sets arg1 to the
 33: eb da                            jmp     -38 <ex4+0xf>         jump to 0xf

*/

// Yes!!! I knew the fibonacci sequence would be one of the labs
long ex4(long arg)
{
  if(arg > 1) {
    long var = ex4(arg - 1);
    arg = ex4(arg - 2);
    arg += var;
  }
  return arg;
}

