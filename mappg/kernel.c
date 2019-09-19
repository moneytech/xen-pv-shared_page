#include <stdint.h>
#include "/usr/lib/gcc/x86_64-redhat-linux/4.8.2/include/stddef.h"
#include <xen/xen.h>
#include <xen/grant_table.h>
#include "hypercall-x86_32.h"
#include "mapping.h"

#define DOMIDMOTO 1
#define GRANTENTRY 0

char stack[8192];
extern void * shared_page;
void start_kernel(start_info_t *si)
{
    grant_handle_t err, handle;
    HYPERVISOR_console_io(CONSOLEIO_write, 10, "Mapping.\n");
    err = map(DOMIDMOTO, GRANTENTRY, shared_page, &handle);
    if (err != 0)
    {
        HYPERVISOR_console_io(CONSOLEIO_write, 8, "failed.\n");
    }
    else
    {
        HYPERVISOR_console_io(CONSOLEIO_write, 9, "success.\n");
    }
    
    while(1);
}
