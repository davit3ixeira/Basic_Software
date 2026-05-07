.data
    s1: .string "numero: "
    s2: .string "%d"

.text
.global novonum

novonum:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp          

    movq $s1, %rdi             
    call printf

    movq $s2, %rdi     
    leaq -4(%rbp), %rsi   
    movl $0, %eax           
    call scanf

    movl -4(%rbp), %eax

    leave
    ret