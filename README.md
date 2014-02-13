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
