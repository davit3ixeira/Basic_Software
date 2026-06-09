.global pack1

pack1:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    pushq %rbx
    pushq %r12
    pushq %r13

    movq %rdi, %rbx
    movl %esi, %r12d
    xorl %r13d, %r13d

    xorpd %xmm0, %xmm0
    movsd %xmm0, -8(%rbp)   # acc = 0.0

.loop1:
    cmpl %r12d, %r13d
    jge .done1

    movl %r13d, %eax
    imull $8, %eax
    movslq %eax, %rax

    cvtss2sd 4(%rbx, %rax), %xmm0
    movl 0(%rbx, %rax), %edi

    call foo

    addsd -8(%rbp), %xmm0
    movsd %xmm0, -8(%rbp)

    incl %r13d
    jmp .loop1

.done1:
    movsd -8(%rbp), %xmm0
    popq %r13
    popq %r12
    popq %rbx
    leave
    ret