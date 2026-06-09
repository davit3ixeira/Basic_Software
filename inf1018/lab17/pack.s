
.text
.global pack

pack:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    xorpd %xmm0, %xmm0
    movsd %xmm0, -8(%rbp)

    pushq %rbx
    movq %rdi, %rbx

.loop:
    testq %rbx, %rbx
    je .done

    movsd 8(%rbx), %xmm0
    movl 0(%rbx), %edi

    call foo

    addsd -8(%rbp), %xmm0
    movsd %xmm0, -8(%rbp)

    movq 16(%rbx), %rbx
    jmp .loop

.done:
    movsd -8(%rbp), %xmm0
    popq %rbx
    leave
    ret