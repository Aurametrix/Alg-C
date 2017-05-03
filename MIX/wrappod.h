namespace clif_example {
namespace wrappod {

struct MyClass {
  int a;       // Available in Python as an int value
  float f;     // Available in Python as a float value
  string s;    // Available in Python as a bytes object

  std::vector<int> v;    // Available in Python as a list of int values via
                         // getter and setter methods.
  std::pair<int, int> p; // Available in Python as a 2-tuple

  double d; // Not available in wrapped Python.
};

}  // namespace wrappod
}  // namespace clif_example
