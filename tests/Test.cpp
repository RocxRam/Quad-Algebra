#include <iostream>
#include <cmath>
#include "Operations.hpp"
using namespace quad;

const double EPS = 1e-10;

template<class T>
bool approx(T a, T b){
    return std::abs(a - b) < EPS;
}

template<class T>
bool approxComplex(const Complex<T>& a, const Complex<T>& b){
    return approx(real(a), real(b)) && approx(imaginary(a), imaginary(b));
}

template<class T>
bool approxDual(const Dual<T>& a,const Dual<T>& b){
    return approx(real(a), real(b)) && approx(dual(a), dual(b));
}

template<class T>
bool approxSplit(const Split_Complex<T>& a, const Split_Complex<T>& b){
    return approx(real(a), real(b)) && approx(hyperbolic(a), hyperbolic(b));
}

int main(){
    std::cout << "========== COMPLEX ==========\n";
    Complex<double> c(1.2, 0.7);
    auto trigC =sin(c)*sin(c)+cos(c)*cos(c);
    auto hypC =cosh(c)*cosh(c)-sinh(c)*sinh(c);
    auto elogC =exp(log(c));
    std::cout<< "sin^2+cos^2=1 : "<< (approxComplex(trigC,Complex<double>(1,0))? "PASS" : "FAIL")<< '\n';
    std::cout<< "cosh^2-sinh^2=1 : "<< (approxComplex(hypC,Complex<double>(1,0))? "PASS" : "FAIL")<< '\n';
    std::cout<< "exp(log(z))=z : "<< (approxComplex(elogC,c)? "PASS" : "FAIL")<< '\n';

    std::cout << "\n========== DUAL ==========\n";
    Dual<double> d(1.2, 0.7);
    auto trigD =sin(d)*sin(d)+cos(d)*cos(d);
    auto hypD =cosh(d)*cosh(d)-sinh(d)*sinh(d);
    auto elogD =exp(log(d));
    std::cout<< "sin^2+cos^2=1 : "<< (approxDual(trigD,Dual<double>(1,0))? "PASS" : "FAIL")<< '\n';
    std::cout<< "cosh^2-sinh^2=1 : "<< (approxDual(hypD,Dual<double>(1,0))? "PASS" : "FAIL")<< '\n';
    std::cout<< "exp(log(z))=z : "<< (approxDual(elogD,d)? "PASS" : "FAIL")<< '\n';

    std::cout << "\n====== SPLIT COMPLEX ======\n";
    Split_Complex<double> s(1.2, 0.7);
    auto trigS =sin(s)*sin(s)+cos(s)*cos(s);
    auto hypS =cosh(s)*cosh(s)-sinh(s)*sinh(s);
    auto elogS =exp(log(s));
    std::cout<< "sin^2+cos^2=1 : "<< (approxSplit(trigS,Split_Complex<double>(1,0))? "PASS" : "FAIL")<< '\n';
    std::cout<< "cosh^2-sinh^2=1 : "<< (approxSplit(hypS,Split_Complex<double>(1,0))? "PASS" : "FAIL")<< '\n';
    std::cout<< "exp(log(z))=z : "<< (approxSplit(elogS,s)? "PASS" : "FAIL")<< '\n';
    return 0;
}