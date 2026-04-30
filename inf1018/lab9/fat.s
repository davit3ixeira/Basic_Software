
.text
.globl fat

fat:
    pushq %rbp
    movq %rsp, %rbp

    subq $8, %rsp
    movl %edi, -4(%rbp)

    cmpl $0, %edi
    jne l1

    movl $1, %eax
    jmp l2

l1:
    movl -4(%rbp), %edi

    subl $1, %edi

    call fat

    movl -4(%rbp), %edx

    imull %edx, %eax

l2:
    leave
    ret
