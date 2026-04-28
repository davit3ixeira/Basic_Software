  .data
  s1: .string "ls -ls"

  .text
  .globl main
  main:
  /* prologo */
    pushq %rbp
    movq  %rsp, %rbp

  movq $1, %rbi  

  call system

  movl $0, %eax    

  /* finalizacao */
    leave
    ret