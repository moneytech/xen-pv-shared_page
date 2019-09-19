#include <stdint.h>
#include <xen/xen.h>
#include <xen/grant_table.h>
#include "hypercall-x86_32.h"

grant_handle_t map(
    domid_t friend,
    unsigned int entry,
    void *shared_page,
    grant_handle_t *handle)
{
    // Set up the mapping oparation
    gnttab_map_grant_ref_t map_op;
    map_op.host_addr = (intptr_t) shared_page;
    map_op.flags = GNTMAP_host_map;
    map_op.ref = entry;
    map_op.dom = friend;
    // Perform the map
    HYPERVISOR_grant_table_op(GNTTABOP_map_grant_ref, &map_op, 1);
    // Check if worked
    if(map_op.status != GNTST_okay)
    {
        return -1;
    }
    else
    {
        // return the handle
        *handle = map_op.handle;
        return 0;
    }
}