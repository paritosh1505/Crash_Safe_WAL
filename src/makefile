#compiler used
CXX = g++

#Compiler flag
CXXFLAG= -std=c++17 -Werror -Wall -Wextra -o

#File name to compile
CXXFILENAME = main.cpp file.cpp

#Target File
TARGET= output

# the default 'all' target
all: $(TARGET)

$(TARGET): $(CXXFILENAME) 
		$(CXX) $(CXXFLAG) $(TARGET) $(CXXFILENAME)

clean:
	@rm -rf $(TARGET)
