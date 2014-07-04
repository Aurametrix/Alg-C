#include <iostream>
#include <iterator>
#include <vector>

int main()
        std::vector<int> a; // don't use C arrays...
        std::cout<<"Enter number sequence (end with Ctrl-d)"<<std::endl;
        std::copy(std::istream_iterator<int,char>(std::cin), // why use a self-written loop? This one is better...
                        std::istream_iterator<int,char>(), std::back_inserter(a));
        int j=0, key=0; // *always* initialize variables
        for (int i=1; i<a.size(); ++i) // use pre-increment to avoid unneccessary temorary object
        {
                key= a[i];
                j = i-1;
                while((j >= 0) && (a[j] > key))
                {
                        a[j+1] = a[j];
                        j -= 1;
                }
                a[j+1]=key;
        }
        std::cout<<"Sorted sequence:\n";
        std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, "\n")); // another loop avoided...
        std::cout<<std::flush;
}
