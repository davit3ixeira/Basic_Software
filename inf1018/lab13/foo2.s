.text
.global foo2

foo2:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    
    movl %edi, -4(%rbp)
    movl -4(%rbp), %edi    
    call add

    leave
    ret