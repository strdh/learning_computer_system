#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

void err_msg(char *msg);
DIR *Opendir(const char *name);
int Closedir(DIR *dirp);

int main(int argc, char **argv) {
  if (argc != 2) {
    err_msg("Usage: program_name dir_name");
    exit(1);
  }

  DIR *streamp;
  struct dirent *dep;

  streamp = Opendir(argv[1]);

  errno = 0;
  while ((dep = readdir(streamp)) != NULL) {
    printf("---- : %s\n", dep->d_name);
  }

  if (errno != 0) {
    err_msg("readdir error");
    exit(1);
  }

  Closedir(streamp);
  return 0;
}

void err_msg(char *msg) {
  fprintf(stderr, "err: %s\n", msg);
}

DIR *Opendir(const char *name) {
  DIR *dirp = opendir(name);

  if (!dirp) {
    err_msg("opendir error");
    exit(1);
  }
  return dirp;
}

int Closedir(DIR *dirp) {
  int rc;

  if ((rc = closedir(dirp)) < 0) {
    err_msg("closedir error");
    exit(1);
  }
  return rc;
}
