std::cout << "creating" << std::endl;
std::ofstream f("/path/to/file");
DEFER ( [&]() { std::cout << "closing" << std::endl;
                f.close(); } );
std::cout << "writing" << std::endl;
f << "hello defer" << std::endl;
