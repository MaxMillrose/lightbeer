#ifndef FUZZ_WRAPFD_H
#define FUZZ_WRAPFD_H

#include "buffer.h"

enum wrapfd_mode {
    UNUSED = 0,
    COMMONBUF, // using the common buffer
    DUMMY, // reads return fixed output, of random length
};

// buf is a common buffer read by all wrapped FDs. doesn't take ownership of buf
void wrapfd_setup(buffer *buf);
void wrapfd_setseed(uint32_t seed);
int wrapfd_new_fuzzinput();
int wrapfd_new_dummy();

// called via #defines for read/write/select
int wrapfd_read(int fd, void *out, size_t count);
int wrapfd_write(int fd, const void* in, size_t count);
int wrapfd_select(int nfds, fd_set *readfds, fd_set *writefds, 
    fd_set *exceptfds, struct timeval *timeout);
int wrapfd_close(int fd);

#endif // FUZZ_WRAPFD_H
