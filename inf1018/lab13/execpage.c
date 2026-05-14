#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#define PAGE_START(P) ((intptr_t)(P)&~(pagesize-1))
#define PAGE_END(P) (((intptr_t)(P)+pagesize-1)&~(pagesize-1))

int execpage(void *ptr, size_t len) {
    int ret;
    const long pagesize = sysconf(_SC_PAGE_SIZE);
    if (pagesize == -1) return -1;

    ret = mprotect((void *)PAGE_START(ptr),
         PAGE_END((intptr_t)ptr + len) - PAGE_START(ptr),
         PROT_READ | PROT_WRITE | PROT_EXEC);
    if (ret == -1) return -1;
    return 0;
}
#undef PAGE_START
#undef PAGE_END

int add (int x){
    return x + 1;
}

typedef int (*funcp) (int x);

int main(){

    unsigned char codigo[] = {0x55, 0x48, 0x89, 0xe5, 0x48, 0x83, 0xec, 0x10, 0x89, 0x7d, 0xfc, 0x83, 0x45, 0xfc, 0x01, 0x8b, 0x45, 0xfc, 0xc9, 0xc3};

    execpage(codigo, sizeof(codigo));

    unsigned char *end_proxima_inst = &codigo[9];

    int deslocamento = (int)((intptr_t)add - (intptr_t)end_proxima_inst);

    int *patch = (int *)&codigo[5];
    *patch = deslocamento;

    return 0;
}