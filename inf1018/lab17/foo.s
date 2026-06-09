
.text
.global foo

foo:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movsd %xmm0, -8(%rbp)
    movl %edi, -16(%rbp)

    movl -16(%rbp), %eax
    negl %eax
    cvtsi2sd %eax, %xmm1
    movsd -8(%rbp), %xmm0
    mulsd %xmm1, %xmm0
    movq %xmm0, %rax

    leave
    ret