.text
.globl foo3

foo3:
    pushq %rbp
    movq %rsp, %rbp
    pushq %r12
    pushq %r13
    pushq %r14
    subq $8, %rsp
    movq %rdi, %r12
    movl %esi, %r13d
    movl $0, %r14d
    pxor %xmm0, %xmm0
    movsd %xmm0, -32(%rbp)

L_cond:
    cmpl %r13d, %r14d
    jge L_end
    movsd (%r12), %xmm0
    call sin
    addsd -32(%rbp), %xmm0
    movsd %xmm0, -32(%rbp)
    addq $8, %r12
    addl $1, %r14d
    jmp L_cond

L_end:
    movsd -32(%rbp), %xmm0
    addq $8, %rsp
    popq %r14
    popq %r13
    popq %r12
    leave
    ret