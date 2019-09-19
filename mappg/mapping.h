#ifndef _OFFERING_H_
#define _OFFERING_H_

grant_handle_t map(
    domid_t next,
    unsigned int entry,
    void *shared_page,
    grant_handle_t *handle);

#endif