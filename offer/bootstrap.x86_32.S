#include <xen/arch-x86_32.h>

.section __xen_guest
    .ascii  "GUEST_OS=OFFER"
    .ascii  ",XEN_VER=xen-3.0"
    .ascii  ",VIRT_BASE=0x0"
    .ascii  ",ELF_PADDR_OFFSET=0x0"
    .ascii  ",HYPERCALL_PAGE=0x2"
    .ascii  ",PAE=yes"
    .ascii  ",LOADER=generic"
    .byte   0

.text

.global _start, shared_info, hypercall_page, shared_page

_start:
    cld
    lss     stack_start, %esp
    push    %esi
    call    start_kernel

stack_start:
    .long stack+8192, FLAT_KERNEL_SS

    .org 0x1000
shared_page:
    .org 0x2000
hypercall_page:
    .org 0x3000

ES          = 0x20
ORIG_EAX    = 0x24
EIP         = 0x28
CS          = 0x2C
