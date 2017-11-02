#include <stdlib.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

char* readable_filesz(double size, char *readablesz) {
    int i = 0;
    const char* units[] = {"bytes", "kilobytes", "megabytes", "gigabytes", "terabytes"};
    while (size > 1024) {
        size /= 1024;
        i++;
    }
    sprintf(readablesz, "%.*f %s", i, size, units[i]);
    return readablesz;
}

int main() {
  struct stat statbuffer;
  char readablesz[10];
  stat("kevinsstat.c", &statbuffer);
  printf("File Size: %lld\n", statbuffer.st_size);
  printf("More Readable File Size: %s\n", readable_filesz(statbuffer.st_size, readablesz));
  printf("Mode: %d\n", statbuffer.st_mode);
  printf("Access time: %s\n", ctime(&statbuffer.st_atime));
}
