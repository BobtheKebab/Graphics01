#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

  int fd = open("image.ppm", O_CREAT | O_WRONLY, 0644);
  char buff[50] = "P3\n500 500\n255\n";
  write(fd, buff, 50);

  int num = 0, count = 0;
  for(count; count < 500 * 500; count++) {
    if (num > 255) {
      num = 0;
    }
    sprintf(buff, "%d %d % d ", num, 0, num);
    write(fd, buff, 50);
    num++;
  }
  
  close(fd);
  
  return 0;
  
}
