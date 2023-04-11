#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h> // Include stdlib.h for exit function
#include <unistd.h>

int Open(const char *pathname, int flags, mode_t mode);
void Close(int fd);
void unix_error(char *msg); // Declare the unix_error function

int main() {
  int fd1, fd2;

  fd1 = Open("foo.txt", O_RDONLY, 0);
  Close(fd1); // Close the opened file descriptor
  fd2 = Open("baz.txt", O_RDONLY, 0);
  Close(fd2);
  printf("fd2 = %d\n", fd2);
  return 0;
}

int Open(const char *pathname, int flags, mode_t mode) {
  int rc;
  if ((rc = open(pathname, flags, mode)) < 0) {
    unix_error("Open error");
    exit(1); // Exit the program in case of an error
  }
  return rc;
}

void Close(int fd) {
  int rc;
  if ((rc = close(fd)) < 0) {
    unix_error("Close error");
    exit(1); // Exit the program in case of an error
  }
}

void unix_error(char *msg) {
  fprintf(stderr, "%s\n", msg);
}
