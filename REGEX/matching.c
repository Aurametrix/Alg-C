switch (x) {
case 0: std::cout << "got zero"; break;
case 1: std::cout << "got one"; break;
default: std::cout << "don't care";
}

if (s == "foo") {
std::cout << "got foo";
} else if (s == "bar") {
std::cout << "got bar";
} else {
std::cout << "don't care";
}

auto&& [x, y] = p;
if (x == 0 && y == 0) {
std::cout << "on origin";
} else if (x == 0) {
std::cout << "on y-axis";
} else if (y == 0) {
std::cout << "on x-axis";
} else {
std::cout << x << ',' << y;
}
