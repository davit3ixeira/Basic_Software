/*
#include <stdio.h>

int nums[4] = {65, -105, 111, 34};

int main (void) {
  int i;
  int s = 0;

  for (i=0;i<4;i++)
    s = s+nums[i];

  printf ("soma = %d\n", s);

  return 0;
}
*/

.data
nums: .int 65, -105, 111, 34
Sf: .string "soma = %d\n"

.text
.globl main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq %rbp
  movq %rsp, %rbp
  subq $16, %rsp
  movq %rbx, -8(%rbp) /* guarda rbx */
  movq %r12, -16(%rbp) /* guarda r12 */
/********************************************************/

  movl $0, %r12d
  movl $0, %edx

L1:
  cmpl $4, %r12d
  jge L2

  movq $nums, %rbx
  movslq %r12d, %rdi
  imulq $4, %rdi
  addq %rdi, %rbx

  movl (%rbx), %ecx
  addl %ecx, %edx

  addl $1, %r12d
  jmp L1

L2:
/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)        */
  movq $Sf, %rdi
  movl %edx, %esi
  movl $0, %eax
  call printf
/*************************************************************/

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq $0, %rax
  movq -16(%rbp), %r12
  movq -8(%rbp), %rbx
  leave
  ret
/***************************************************************/