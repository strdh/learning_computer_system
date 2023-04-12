#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

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
  
  printf("Device ID: %lu\n", (unsigned long) meta_data.st_dev);
  printf("Inode number: %lu\n", (unsigned long) meta_data.st_ino);
  printf("Number of hard links: %lu\n", (unsigned long) meta_data.st_nlink);
  printf("User ID of owner: %d\n", meta_data.st_uid);
  printf("Group ID of owner: %d\n", meta_data.st_gid);
  printf("Size of file: %lu KB\n", (unsigned long) (meta_data.st_size / 1024));
  printf("Block size for filesystem I/O: %lu bytes\n", meta_data.st_blksize);
  printf("Number of blocks allocated: %lu\n", (unsigned long) meta_data.st_blocks);
  char atime[20];
  strftime(atime, 20, "%Y-%m-%d %H:%M:%S", localtime(&meta_data.st_atime));
  printf("Time of last access: %s\n", atime);
  char mtime[20];
  strftime(mtime, 20, "%Y-%m-%d %H:%M:%S", localtime(&meta_data.st_mtime));
  printf("Time of last modification: %s\n", mtime);
  char ctime[20];
  strftime(ctime, 20, "%Y-%m-%d %H:%M:%S", localtime(&meta_data.st_ctime));
  printf("Time of last status change: %s\n", ctime);

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
