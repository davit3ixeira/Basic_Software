/*
#include <stdio.h>

int C = 1;

int main (void) {
  while (C < 11){
    C = C*C
    printf ("%d\n", C);
    C++;
  }
  return 0;
}
*/

.data
C:   .int 1
Sf:  .string "%d\n"
Sn:  .string "\n"

.text
.globl main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)    /* guarda rbx */
  movq    %r12, -16(%rbp)   /* guarda r12 */
/********************************************************/

L1:
  movl C(%rip), %eax
  cmpl $11, %eax
  jge L2

  imull %eax, %eax

/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)        */
  movq  $Sf, %rdi
  movl  %eax, %esi
  movl  $0, %eax
  call  printf
/*************************************************************/

  addl $1, C(%rip)
  jmp L1

L2:
/*************************************************************/
  movq  $Sn, %rdi
  movl  $0, %eax
  call  printf
/*************************************************************/

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq    $0, %rax
  movq    -16(%rbp), %r12
  movq    -8(%rbp), %rbx
  leave
  ret
/***************************************************************/