#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

void err_msg(char *msg);
void Stat(const char *filename, struct stat *buf);

int main(int argc, char **argv) {
  struct stat meta_data;
  char *type, *readok;

  Stat(argv[1], &meta_data);
  if (S_ISREG(meta_data.st_mode))
    type = "regular";
  else if (S_ISDIR(meta_data.st_mode))
    type = "directory";
  else
    type = "other";

  if ((meta_data.st_mode & S_IRUSR))
    readok = "yes";
  else
    readok = "no";

  printf("type: %s, read: %s\n", type, readok);

  return 0;
}

void err_msg(char *msg) {
  fprintf(stderr, "err: %s\n", msg);
}

void Stat(const char *filename, struct stat *buf) {
  if (stat(filename, buf) < 0) {
    err_msg("Stat erorr");
  }
}
