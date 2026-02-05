#include "file.h"
#include <unistd.h>


FileDescriptor::FileDescriptor(int fd) noexcept:fdval(fd){};


FileDescriptor::FileDescriptor(FileDescriptor&& otherfd) noexcept:fdval(otherfd.fdval){
    otherfd.fdval=-1;
}
FileDescriptor& FileDescriptor::operator=(FileDescriptor&& otherfd) noexcept{
    if(this!=&otherfd){
        if(this->valid()){
            close(this->fdval);
        }
       this->fdval = otherfd.fdval;
       otherfd.fdval=-1;
    }
    return *this;
    
}
int FileDescriptor::get() const noexcept{
    return fdval;
}
bool FileDescriptor::valid() const noexcept{
    if(this->fdval>=0)
    return true;
    else
    return false;

}
FileDescriptor::~FileDescriptor(){
    if(valid())
    close(this->fdval);
}

