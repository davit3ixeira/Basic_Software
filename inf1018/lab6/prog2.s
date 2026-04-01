.data
nums:  .int  10, -21, -30, 45
Sf:  .string "%d\n"

.text
.globl  main
main:

/********************************************************/
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/********************************************************/

  movl  $0, %ebx  /* ebx = 0; */
  movq  $nums, %r12  /* r12 = &nums */

L1:
  cmpl  $4, %ebx  /* if (ebx == 4) ? */
  je  L2          /* goto L2 */

  cmpl  $4, %ebx

  movl  (%r12), %eax    /* eax = *p */

  testl $1, %eax
  jne  L3

/*************************************************************/
  movq    $Sf, %rdi
  movl    (%r12), %esi
  call    printf
/*************************************************************/

L3:
  addl  $1, %ebx  /* ebx += 1; */
  addq  $4, %r12  /* r12 += 4; */

  jmp  L1         /* goto L1; */

L2:
/***************************************************************/
  movq  $0, %rax
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret
/***************************************************************/