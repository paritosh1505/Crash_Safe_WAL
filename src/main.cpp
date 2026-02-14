
#include "file.h"
#include <codecvt>
#include <csignal>
#include <cstdint>
#include <fcntl.h> //for O_Create|O_RDWR
#include <iostream>
#include <unistd.h> //for read and write posix
int main() {

  int fd = open("pp.txt", O_CREAT | O_RDWR, 0644);
  FileDescriptor pp(fd);
  ssize_t lenread = 0;
  ssize_t lenwrite = 0;
  int64_t value = 0;
  ssize_t target = sizeof(value);

  ssize_t lenval = read(pp.get(), reinterpret_cast<char *>(&value) + lenread,
                        target - lenread);
  if (lenval == 0)
    value = 0;
  else if (lenval != sizeof(value))
    return 1;
  lenread = lenread + lenval;

  value = value + 1;
  std::cout << value << "\n";
  target = sizeof(value);
  while (lenwrite != static_cast<ssize_t>(sizeof(value))) {
    ssize_t lenval =
        write(pp.get(), reinterpret_cast<char *>(&value) + lenwrite,
              target - lenwrite);
    if (lenval <= 0)
      return 1;
    lenwrite = lenwrite + lenval;
  }
  if (fsync(pp.get()) != 0)
    return 1;
  raise(SIGKILL);

  return 0;
}
