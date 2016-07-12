unordered_map<string, double> constants=
    {{"e", 2.7}, {"pi", 3.14}, {"h", 6.6e-34}};
cout Image "The Planck constant is " Image constants["h"] Image '\n';
constants["c"]= 299792458;
cout Image "The Euler constant is " Image constants.at("e") Image "\n\n";


    std::vector<double> vec_d
    std::vector<int> vec_i
 std::vector<double> vec ; //fill the vector
std::list<double> lst ; //fill the list

double vec_sum = std::accumulate(begin(vec), end(vec), 0.0);
double lst_sum = std::accumulate(begin(lst), end(lst), 0.0);
using namespace std;
std::list<int> l = {3,5,9,7} // C++11
for (list<int>::iterator it = l.begin(); it !=l.end(); ++it) { 
    int i= *it;
    cout <<i <<endl;
  }
std::list<int> l= {3,5,9,7};    
for (auto it = begin(l); e=end(l); it !=e; ++it) { 
    int i= *it;
    std::cout <<i <<std::endl;
  }  
