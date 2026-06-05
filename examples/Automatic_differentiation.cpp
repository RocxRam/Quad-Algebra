#include "quad/Operations.hpp"
#include <iostream>
using namespace quad;

int main(){
    Dual<double> x(2.0,1.0);
    auto z=sin(x)*cos(x);
    std::cout<<"Derivative at x=2 is: "<<dual(z)<<std::endl;
    return 0;
}
