.text
.global bemboba

bemboba:
  pushq %rbp
  movq %rsp, %rbp
  subq $32, %rsp

  movl $0, -32(%rbp)
  movq -16(%rbp), %rax
  movq %rax, -24(%rbp)

  cmpl $4, -32(%rbp)
  jge fim

  movl %edi, %ebx
  movl %ebx, -24(%rbp)
  addl $1, -24(%rbp)
  addl $1, -32(%rbp)

fim:
  movq -16(%rbp), %rdi
  movl $4, %esi
  call addl

  leave
  ret