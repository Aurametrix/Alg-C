/ * MLE++ is a C++ class library for the estimation of econometric models
  * probit function is the quantile function associated with the standard normal distribution
  * /


#include "estimate.hpp" 
#include "probit.hpp"
int MleMain() { 
   Probit P("rprobit", "Y", "X1,X2,X3"); 
   P.SetOutFile("probit.out"); 
   P.SetHessMethod(ANALYTIC_H); 
   P.FindParms(); 
   return 0; 
}
