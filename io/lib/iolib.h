#ifndef __IOLIB_H__
#define __IOLIB_H__

#include <stdio.h>
#include <unistd.h>

#define IO_BUFSIZE 8192

typedef struct {
  int io_fd;
  int cnt;
  char *io_bufptr;
  char io_buf[IO_BUFSIZE];
} io_t;

void io_readinitb(io_t *rp, int fd);
ssize_t io_readlineb(io_t *rp, void *usrbuf, size_t n);
ssize_t io_readnb(io_t *rp, void *usrbuf, size_t n);

#endif
