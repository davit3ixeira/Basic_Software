
.text 
.global foo

foo:
    push %rbp
    movq %rsp, %rbp

    subq $16, %rsp
    movl $0, -4(%rbp)
    movl $0, -8(%rbp)

l1:
    movl -4(%rbp), %eax

    cmpl %esi, %eax
    jge l3

    movl -4(%rbp), %eax

    imull $4, %eax

    movq %rdi, %rcx
    addq %rax, %rcx

    movl (%rcx), %edx

    addl %edx, -8(%rbp)

    movl $0, -8(%rbp)

l2:
    addl $1, -4(%rbp)

    jmp l1

l3:
    leave
    ret
