#pragma once

class FileDescriptor{
    private:
    int fdval;
    public:
    explicit FileDescriptor(int otherfdval) noexcept;

    FileDescriptor(const FileDescriptor&)=delete;
    FileDescriptor& operator=(const FileDescriptor&)=delete;
    
    FileDescriptor (FileDescriptor&&) noexcept;
    FileDescriptor& operator=(FileDescriptor&&) noexcept;

    int get() const noexcept;
    bool valid() const noexcept;

    ~FileDescriptor();
};