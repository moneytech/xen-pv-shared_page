#include <stdint.h>
#include "/usr/lib/gcc/x86_64-redhat-linux/4.8.2/include/stddef.h"
#include <xen/xen.h>
#include <xen/grant_table.h>
#include "hypercall-x86_32.h"
#include "offering.h"

char stack[8192];

void start_kernel(start_info_t *si)
{
    HYPERVISOR_console_io(CONSOLEIO_write, 10, "Offering.\n");
    offer_page();
    while(1);
}
