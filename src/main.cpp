
#include "file.h"
#include <utility>
#include <fcntl.h>
int main(){
  int fd = open("pp.txt",O_CREAT|O_RDWR,0644);
  FileDescriptor pp(fd);
  FileDescriptor jj (std::move(pp));
  return 0;  
}