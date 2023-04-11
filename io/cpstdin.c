#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void err_msg(char *msg);
ssize_t Read(int fd, void *buf, size_t count);
ssize_t Write(int fd, const void *buf, size_t count);

int main() {
  char c;

  while (Read(STDIN_FILENO, &c, 1) != 0) {
    Write(STDOUT_FILENO, &c, 1);
  }
  return 0;
}

void err_msg(char *msg) {
  fprintf(stderr, "%s\n", msg);
}

ssize_t Read(int fd, void *buf, size_t count) {
  ssize_t rc;

  if ((rc = read(fd, buf, count)) < 0) {
    err_msg("Read error");
  }
  return rc;
}

ssize_t Write(int fd, const void *buf, size_t count) {
  ssize_t rc;

  if ((rc = write(fd, buf, count)) < 0) {
    err_msg("Write error");
  }
  return rc;
}
