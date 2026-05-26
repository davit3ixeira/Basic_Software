.text
.globl foo

foo:
    cvtss2sd %xmm1, %xmm2
    movsd %xmm0, %xmm3
    addsd %xmm2, %xmm3
    movsd %xmm0, %xmm4
    subsd %xmm2, %xmm4
    mulsd %xmm4, %xmm3
    cvtsd2ss %xmm3, %xmm0
    ret