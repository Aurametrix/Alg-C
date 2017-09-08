struct S0 {
  int f0;
  int f1;
  int f2;
  int f3;
};

int f1(struct S0 p) {
    return p.f0;
}



PR tree-optimization/63387
gcc/
	* match.pd ((x unord x) | (y unord y) -> (x unord y),
	(x unord x) | (x unord y) -> (x unord y)): New simplifications.
gcc/testsuite/
	* gcc.dg/pr63387.c: New testcase.
