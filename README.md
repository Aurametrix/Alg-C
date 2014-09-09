Alg-C
=====

Algorithms in C/C++

gcc mycode.c

c++ mycode.c++

gcc mycode.cpp -lstdc++

If c++ file does not have the main function (declared in another file), instead of: 

c++ mycode.cpp

Try: 

g++ -c mycode.cpp
g++ -c codethathasmain.cpp
Link with
g++ -omy_program codethathasmain.o mycode.o


C#
Unlike C++, there are no object (.obj) files created as a result of invoking the C# compiler
Output files are created directly, so the C# compiler does not need a linker.

csc File.cs (=> File.exe)
csc /out:MyFile.exe File.cs (=> MyFile.exe)

to create dll (dynamically linked library):
csc /target:library File.cs



===
Creating dynamically sized arrays at run-time is done using std::vector<T>

//sizeof(i) returns the amount of memory (in bytes) for the variable or type i
//sizeof an array is the distance between elements of that array	

http://www.cplusplus.com/reference/iostream/cout/

unrecognized command line option "-std=gnu++0x"
GCC 4.2 is ancient, but Apple don't ship a newer version.

You can either install a modern GCC from somewhere like Mac Ports 
(which is probably simpler and quicker) or build it yourself following the instructions 
at http://gcc.gnu.org/wiki/InstallingGCC
brew tap homebrew/versions && brew install gcc48


Basic Data Structures:
1. STACKS
2. QUEUES
3. LINKED LISTS
4. BINARY TREES


What not to do: 
use malloc to dynamically allocate memory, and free to deallocate it. 
malloc takes a count of bytes and returns a void pointer
