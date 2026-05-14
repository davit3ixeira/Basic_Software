.text
.global foo

foo:
  pushq %rbp
  movq %rsp, %rbp
  subq $16, %rsp

  movl %edi, -4(%rbp)
  addl $1, -4(%rbp)
  movl -4(%rbp), %eax

  leave
  ret