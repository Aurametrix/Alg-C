### Algorithms in C/C++
=====


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

+ [3D real time physics simulation library](https://github.com/bepu/bepuphysics2)

+ [Blaze](https://bitbucket.org/blaze-lib/blaze/src/master/) -  high-performance C++ math library 
+ [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) - C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms
+ [STX](https://lamarrr.github.io/STX/) - collection of libraries and utilities designed to make working with C++ easier and less error-prone; [source code](https://github.com/lamarrr/stx)

### Language used in unity
+ [Learn Unity](https://learn.unity.com/)

===

+ [compile C#/C++ faster](https://github.com/Microsoft/FASTER)
+ [Compiler Explorer](https://godbolt.org/)
+ [C compiler that used Excel](https://github.com/mrthefakeperson/Excel-Virtual-Machine)
+ [awk to C compiler](https://github.com/nokia/awkcc)
+ [xmake](https://github.com/xmake-io/xmake) - build utility
+ [virtual machine that runs C in the browser](https://vasyop.github.io/miniC-hosting)
+ [Single Instruction C compiler](https://github.com/xoreaxeaxeax/movfuscator)
+ [High Performance Garbage Collector](https://v8.dev/blog/high-performance-cpp-gc)
+ [C++ for Android and iOS development](https://github.com/ashampoosystems/boden)
+ [Intro to pointers](https://www.brainstobytes.com/a-gentle-introduction-to-pointers-in-c/)
+ [Implementing a class with a void *](http://web.eecs.utk.edu/~jplank/plank/classes/cs140/Notes/Running_Times/voidstar.html)
+ [Obfuscation tricks](https://github.com/ColinIanKing/christmas-obfuscated-C/blob/master/tricks/obfuscation-tricks.txt)
+ [Defining C macros](https://bowero.nl/blog/2020/10/25/defining-c-macros-the-right-way/)
+ [Cling](https://root.cern/cling/) - an interactive C++ interpreter,

===
Creating dynamically sized arrays at run-time is done using std::vector<T>

//sizeof(i) returns the amount of memory (in bytes) for the variable or type i
//sizeof an array is the distance between elements of that array	


+ [Box2D](https://github.com/erincatto/Box2D/commits/master) -  2D physics engine for games
+  [script video games](https://github.com/ArkScript-lang/Ark)
+ [NasNas](https://github.com/Madour/NasNas) - C++ game framework
+ [Liquid Fun](http://google.github.io/liquidfun/) - 2D rigid-body and fluid simulation libraries based on Box2D


[Standard C++ Library reference](http://www.cplusplus.com/reference/iostream/cout/)
    
[Castor](https://github.com/leprojetcastor/castor) - C++ library to code a la Matlab
    
[Libraries for server applications](https://github.com/facebook/folly) from MEta/FB   

[building a website with C++](https://blog.sourcerer.io/building-a-website-with-c-db942c801aee)

    [c++ web toolkit](https://www.webtoolkit.eu/wt/)
    
    [A little Web Server in C](https://github.com/robdelacruz/lkwebserver)

* Essential C (http://cslibrary.stanford.edu/101/)
Explains the basic features of the C programming language.
* Pointers and Memory (http://cslibrary.stanford.edu/102/)
Explains how pointers and memory work in C and other languages. Starts
with the very basics, and extends through advanced topics such as
reference parameters and heap management.
    
(Hunting a memory leak](https://medium.com/zendesk-engineering/hunting-down-a-c-memory-leak-in-a-go-program-2d08b24b617d
    )

unrecognized command line option "-std=gnu++0x"
GCC 4.2 is ancient, but Apple don't ship a newer version.

You can either install a modern GCC from somewhere like Mac Ports 
(which is probably simpler and quicker) or build it yourself following the instructions 
at http://gcc.gnu.org/wiki/InstallingGCC
brew tap homebrew/versions && brew install gcc48


Basic Data Structures:
1. [STACKS](HASH/stack.cpp)
        [Hashing for strings](http://0x80.pl/notesen/2023-04-30-lookup-in-strings.html)
2. [QUEUES](HASH/queue.c%2B%2B)
3. LINKED LISTS
    * [Linked List Basics](http://cslibrary.stanford.edu/103/)
    * [Linked List problems](http://cslibrary.stanford.edu/105/LinkedListProblems.pdf)

4. BINARY TREES
    * Binary Tree basics (http://cslibrary.stanford.edu/110/)
    * The Great Tree List Problem (http://cslibrary.stanford.edu/109/)

 [Lock-free data structures](https://github.com/DNedic/lockfree)

 [Structures in C: From Basics to Memory Alignment](https://abstractexpr.com/2023/06/29/structures-in-c-from-basics-to-memory-alignment/)

#### [SORT](https://github.com/Aurametrix/Alg-C/tree/master/SORT)

------

| Sort       			                                                | Worst Case    | Average Case   	| Best Caase        | 
| -------------			 |:-------------: |:-------------:													| -----:		    |
|  [Bogo](https://en.wikipedia.org/wiki/Bogosort)   					| O((n+1)!)	|O((n+1)!)		  	 | O(n)					|
|  [Bubble](https://en.wikipedia.org/wiki/Bubble_sort)   				| O(n<sup>2</sup>)|	O(n<sup>2</sup>) | O(n)				|
|  [Cocktail Shaker](https://en.wikipedia.org/wiki/Cocktail_shaker_sort)| O(n<sup>2</sup>) |O(n<sup>2</sup>)		| O(n)		|
|  [Selection](https://en.wikipedia.org/wiki/Selection_sort)   			| O(n<sup>2</sup>) |O(n<sup>2</sup>) | O(n<sup>2</sup>)	|
|  [Gnome](https://en.wikipedia.org/wiki/Gnome_sort)   				    | O(n<sup>2</sup>)|	O(n<sup>2</sup>) |  O(n<sup>2</sup>)|
|  [Comb](https://en.wikipedia.org/wiki/Comb_sort)   					| O(n<sup>2</sup>) |O(nlogn) |O(nlogn)              	|
|  [Insertion](https://en.wikipedia.org/wiki/Insertion_sort)   			| O(n<sup>2</sup>)|	O(n<sup>2</sup>) |O(n)				|
|  [Shell](https://en.wikipedia.org/wiki/Shellsort)   					| O(n(log(n))<sup>2</sup>) | O(n(log(n))<sup>2</sup>)|O(nlogn)	|
|  [Merge Sort](https://en.wikipedia.org/wiki/Merge_sort)  				| O(nlogn)	| O(nlogn)		 |O(nlogn)		            |				
|  [Quick Sort](https://en.wikipedia.org/wiki/Quicksort)  		 		| O(n<sup>2</sup>)| 	O(nlogn)	|O(nlogn)	    	|
|  [Heap Sort](https://en.wikipedia.org/wiki/Heapsort)  		 		| O(nlogn)|	 O(nlogn)			 |O(nlogn)	        	|

+ [Sorting functions implemented in C as std qsort() format](https://github.com/p1v0t/Sort)
 



* [C++ cheet sheet](https://github.com/jwasham/coding-interview-university/blob/master/extras/cheat%20sheets/Cpp_reference.pdf)
* [Reference](http://en.cppreference.com/w/)
* [Coding Interview University](https://github.com/jwasham/coding-interview-university/blob/master/programming-language-resources.md)

### What not to do: 
+use malloc to dynamically allocate memory, and free to deallocate it. 
+malloc takes a count of bytes and returns a void pointer

+[coding guidelines](https://howardhinnant.github.io/coding_guidelines.html)

* Stroustrup's ["The C++ Programming Language" ](http://www.stroustrup.com/4th.html) 
* [C++ video lectures](https://www.youtube.com/user/BoQianTheProgrammer/playlists)
* [Teach yourself programming](http://norvig.com/21-days.html)
* [Recommendations about coding in C++](https://software.intel.com/en-us/articles/the-ultimate-question-of-programming-refactoring-and-everything): pay attention
* [C++ Coding Standards](http://www.informit.com/articles/article.aspx?p=373339)
* [Circle](https://www.circle-lang.org/) - the C++ automation language


##### Best ways to learn modern C

- Tour of C++ (http://www.stroustrup.com/Tour.html)
- Principles and Practice Using C++ (http://www.stroustrup.com/programming.html)

- From Mathematics to Generic Programming (http://www.fm2gp.com/)

- The Scott Meyers books

-  Some of the Bjarne Stroustrup videos: "Learning and Teaching Modern C++" - https://www.youtube.com/watch?v=fX2W3nNjJIo

-  Some of the Herb Sutter videos: "Writing Good C++14... By Default" - https://www.youtube.com/watch?v=hEx5DNLWGgA

- "Back to the Basics! Essentials of Modern C++ Style" - https://www.youtube.com/watch?v=xnqTKD8uD64

- Some of the Kate Gregory videos,"Stop Teaching C" - https://www.youtube.com/watch?v=YnWhqhNdYyk

- "10 Core Guidelines You Need to Start Using Now" - https://www.youtube.com/watch?v=XkDEzfpdcSg

- "It's Complicated" - https://www.youtube.com/watch?v=tTexD26jIN4

- [CPP Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)

- [free open-source books](https://www.ossblog.org/master-c-programming-with-open-source-books/)

- [Google's C++ class](https://developers.google.com/edu/c++/)
    
- [Top secure coding practices](https://www.incredibuild.com/blog/top-10-secure-c-coding-practices)    

- [So you think you know C?](https://wordsandbuttons.online/so_you_think_you_know_c.html)

##### misc / interesting

* [C++ UI libraries](https://philippegroarke.com/posts/2018/c++_ui_solutions/)
* [C++ implementation of the I2P anonymous network](https://github.com/monero-project/kovri)
* [C++20 concepts](https://thecodepad.com/cpp/c20-concepts-the-definitive-guide/)
* [C3](https://news.ycombinator.com/item?id=32005678)
* [Checked C](https://github.com/microsoft/checkedc) - adds static and dynamic checking to C to detect or prevent common programming errors such as buffer overruns and out-of-bounds memory accesses
* [c & memory safety](https://gavinhoward.com/2023/02/why-i-use-c-when-i-believe-in-memory-safety/)
* [runewordCalculator](https://github.com/downIoads/cpp_diablo2r_runewordCalculator) - for Diablo gamers
* [myth & reality](https://www.lelanthran.com/chap9/content.html)

* [Mildly interesting quirks of C](https://gist.github.com/fay59/5ccbe684e6e56a7df8815c3486568f01)
* [CUDA-accelerated raytracer](https://github.com/maxilevi/raytracer)



[Open source physics simulator for robotics](https://deepmind.com/blog/announcements/mujoco)
    + [C API](https://mujoco.org/download)
    + https://deepmind.com/blog/announcements/mujoco

* [C++ implementation of a secure messaging protocol](https://github.com/equalitie/np1sec)

* [CADseer](https://gitlab.com/blobfish/cadseer/-/releases) - CAD desktop app
* [Secure cache](https://github.com/rongarret/scache)

* [Beej's Guide to C Programming](http://beej.us/guide/bgc/)

* [Floating point library](https://github.com/oprecomp/FloatX)

* [Asynchronous programming in C#](https://github.com/davidfowl/AspNetCoreDiagnosticScenarios/blob/master/AsyncGuidance.md)

* [libgrapheme](https://libs.suckless.org/libgrapheme/) - utilities for properly handling strings
    

* [A Tutorial on Pointers and Arrays in C:] (http://home.netcom.com/%7Etjensen/ptr/pointers.htm)
* [Learn C++ for embedded code](https://luckyresistor.me/knowledge/learn-cpp/)
* [Embedded template library](https://www.etlcpp.com/)

* [mle](https://github.com/adsr/mle) - small, flexible, terminal-based text editor

* [Right-left Rule:] (http://ieng9.ucsd.edu/~cs30x/rt_lt.rule.html)
* [Zstandard, real time compression](https://github.com/facebook/zstd)
see also [Zstd before FB](https://github.com/luben/zstd-jni)
* [Parcing C in Tcl](https://wiki.tcl-lang.org/page/Parsing+C+Types)

* [C and C++ refactoring tips](https://software.intel.com/content/www/us/en/develop/articles/the-ultimate-question-of-programming-refactoring-and-everything.html)

* [Microsoft Build Accelerator](https://news.ycombinator.com/item?id=19791515)
* [Alternative Operator Representations](https://en.cppreference.com/w/cpp/language/operator_alternative)

* [Understanding the C/C++ memory model](https://davmac.wordpress.com/2018/01/28/understanding-the-c-c-memory-model/)

* [Near-duplicate features of C++](https://www.nayuki.io/page/near-duplicate-features-of-cplusplus)

* [Some obscure C features](https://multun.net/obscure-c-features.html)

* [Linux driver for the Xbox One wireless dongle](https://github.com/medusalix/xow)

* [lager](https://sinusoid.es/lager/), a C++ library to assist value-oriented design by implementing the unidirectional data-flow architecture; [github](https://github.com/arximboldi/lager)

* [Math parser](https://github.com/ArashPartow/math-parser-benchmark-project)

* [Google's robots.rxt parser](https://github.com/google/robotstxt)

* [Algorithm visualizer](https://algorithm-visualizer.org/)
* [C-Sharp Syntax Rewriter Tool](https://github.com/ShiftLeftSecurity/SharpSyntaxRewriter)
* [C++ pandas alternative](https://github.com/hosseinmoein/DataFrame)
* [Autodiff in C++](https://tbz533.blogspot.com/2021/01/spin-your-own-autodiff-in-c.html)

* [MS application inspector](https://github.com/Microsoft/ApplicationInspector)

+ [TOML++](https://marzer.github.io/tomlplusplus/) - parser and serializer

+ [Virtual CPU](http://megalomaniacbore.blogspot.com/2014/04/virtual-cpu-in-c-4001-cpu.html)
    
+ [Template engine for modern C++](https://github.com/pantor/inja)    

+ [Circle](https://github.com/seanbaxter/circle) - C++ compiler

+ [writing games](https://benpaulhanna.com/writing-a-game-in-c-parsing-s-expressions.html)

+ [Anomaly detection in graphs](https://github.com/bhatiasiddharth/MIDAS)

+ [Modern C++](https://docs.microsoft.com/en-us/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=vs-2019)
    
+ [C'](https://github.com/pfusik/cito/blob/master/ci.md)

+ [Inline and sideline approaches for low-cost memory safety in C](https://www.cl.cam.ac.uk/techreports/UCAM-CL-TR-954.html)

+ [Test anything in C++ ](http://testanything.org/testing-with-tap/c-plus-plus.html)

+ [Find partners for software projects](https://redsand.io/)

+ [Orca](https://git.sr.ht/~rabbits/orca) - audio-visual live coding

+ [PlotJuggler](https://github.com/facontidavide/PlotJuggler) - time seeries visualization
+ [Implot](https://github.com/epezent/implot) - GPU plotting library

+ [mini-Dog](https://github.com/XRobots/miniDogV2)
+ [Maco](https://github.com/chjj/mako) - full bitcoin implementation

+ [Terminal File Manager](https://github.com/jarun/nnn); see also [vifm](https://github.com/vifm/vifm)

+ [olive](https://tsoding.org/olive.c/) - graphics lib with no dependencies
    
+ [Fast Server for Python written in C](https://github.com/jamesroberts/fastwsgi)

+ [Fast note-raking app](https://github.com/nuttyartist/notes)

+ [C++ overtakes Java in popularity ](https://www.infoworld.com/article/3682141/c-plus-plus-overtakes-java-in-language-popularity-index.html): Dec 2022

+ [XHTTP:](https://github.com/cozis/xHTTP) - An HTTP server library in a single C file 

+ [NLP-based programming](https://twitter.com/matvelloso/status/1263193089310461952)
+ [	Run Llama 13B with a 6GB graphics card](https://gist.github.com/rain-1/8cc12b4b334052a21af8029aa9c4fafc)    
+ [A DOS JavaScript Canvas with sound written in C](https://github.com/SuperIlu/DOjS)
+ [Sabre C](https://github.com/garritfra/sabre)
+ [Little](http://www.little-lang.org/) - statically typed, C-like scripting language.
+ [Matplot++](https://github.com/alandefreitas/matplotplusplus)
+ [Cinder](https://libcinder.org/)  - a C++ library for programming with aesthetic intent
+ [darkhttpd](https://unix4lyfe.org/darkhttpd/) - an http server in a single .c file
+ [Rust vs C/C++](http://cliffle.com/blog/prefer-rust/)
+ [Embracing Modern C++ safely](https://www.cppstories.com/2022/embracing-modern-cpp-book/)
+ [Miraclecast](https://github.com/albfan/miraclecast) - Wifi-Display
+ [C++23](http://modernescpp.com/index.php/c-23-the-next-c-standard)
+ [Apple Open Source projects](https://opensource.apple.com/)

### Raspberry Pi
https://github.com/hoglet67/RGBtoHDMI
https://stardot.org.uk/forums/viewtopic.php?f=3&t=14430
https://joetruncale.medium.com/thermos-d089e1c4974b
https://github.com/gerrito333/mousehunter-edge/blob/master/README.md
https://www.skyatnightmagazine.com/advice/diy/raspberry-pi-meteor-detector/
https://magpi.raspberrypi.org/articles/build-a-magic-mirror
https://tinypilotkvm.com

[You can't buy a Raspberry Pi right now](https://www.jeffgeerling.com/blog/2022/you-cant-buy-raspberry-pi-right-now) - Oct 3, 2022
