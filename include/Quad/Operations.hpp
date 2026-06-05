#pragma once
#include <iostream>
#include <cmath>
#include "Complex.hpp"
#include "Split_Complex.hpp"
#include "Dual.hpp"

namespace quad{
template <class T>
Complex<T> exp(const Complex<T>& c){
    T r=std::exp(real(c));
    return Complex<T>(r*std::cos(imaginary(c)), r*std::sin(imaginary(c)));
}

template <class T>
Split_Complex<T> exp(const Split_Complex<T>& c){
    T r=std::exp(real(c));
    return Split_Complex<T>(r*std::cosh(hyperbolic(c)), r*std::sinh(hyperbolic(c)));
}

template <class T>
Dual<T> exp(const Dual<T>& c){
    T r=std::exp(real(c));
    return Dual<T>(r,dual(c)*r);
}

template <class T>
Complex<T> log(const Complex<T>& c){
    if (norm(c)<=0){
        throw std::runtime_error("Norm should be positive error");
    }
    return Complex<T>(std::log(modulo(c)), std::atan2(imaginary(c),real(c)));
}

template <class T>
Split_Complex<T> log(const Split_Complex<T>& c){
    if (norm(c)<=0){
        throw std::runtime_error("Norm should be positive error");
    }
    return Split_Complex<T>(0.5*std::log(norm(c)), std::atanh(hyperbolic(c)/real(c)));
}

template <class T>
Dual<T> log(const Dual<T>& c){
    if (real(c)<=0){
        throw std::runtime_error("Real part should be positive error");
    }
    return Dual<T>(std::log(real(c)),dual(c)/real(c));
}

template <class T>
Complex<T> pow(const Complex<T>& c,const Complex<T> &n){
    if (n==0){
        return Complex<T>(1,0);
    }
    Complex<T> result=exp(log(c)*n);
    return result;
}

template <class T>
Split_Complex<T> pow(const Split_Complex<T>& c, const Split_Complex<T> &n){
    if (n==0){
        return Split_Complex<T>(1,0);
    }
    Split_Complex<T> result=exp(log(c)*n);
    return result;
}

template <class T>
Dual<T> pow(const Dual<T>& c, const Dual<T> &n){
    if (n==0){
        return Dual<T>(1,0);
    }
    Dual<T> result=exp(log(c)*n);
    return result;
}

template <class T>
Complex<T> pow(const Complex<T>& c,const T &n){
    if (n==0){
        return Complex<T>(1,0);
    }
    Complex<T> result=exp(log(c)*n);
    return result;
}

template <class T>
Split_Complex<T> pow(const Split_Complex<T>& c, T &n){
    if (n==0){
        return Split_Complex<T>(1,0);
    }
    Split_Complex<T> result=exp(log(c)*n);
    return result;
}

template <class T>
Dual<T> pow(const Dual<T>& c, T &n){
    if (n==0){
        return Dual<T>(1,0);
    }
    Dual<T> result=exp(log(c)*n);
    return result;
}

template <class T>
Complex<T> sqrt(const Complex<T>& c){
    return exp(log(c)/2.0);
}

template <class T>
Split_Complex<T> sqrt(const Split_Complex<T>& c){
    return exp(log(c)/2.0);
}

template <class T>
Dual<T> sqrt(const Dual<T>& c){
    if (real(c)<=0){
        throw std::runtime_error("Real part should be positive error");
    }
    return exp(log(c)/2.0);
}

template <class T>
Complex<T> sin(const Complex<T>& c){
    T r=real(c);
    T i=imaginary(c);
    return Complex<T>(std::sin(r)*std::cosh(i), std::cos(r)*std::sinh(i));
}

template <class T>
Split_Complex<T> sin(const Split_Complex<T>& c){
    T r=real(c);
    T h=hyperbolic(c);
    return Split_Complex<T>(std::sin(r)*std::cos(h), std::cos(r)*std::sin(h));
}

template <class T>
Dual<T> sin(const Dual<T>& c){
    return Dual<T>(std::sin(real(c)), std::cos(real(c))*dual(c));
}

template <class T>
Complex<T> cos(const Complex<T>& c){
    T r=real(c);
    T i=imaginary(c);
    return Complex<T>(std::cos(r)*std::cosh(i), -std::sin(r)*std::sinh(i));
}

template <class T>
Split_Complex<T> cos(const Split_Complex<T>& c){
    T r=real(c);
    T h=hyperbolic(c);
    return Split_Complex<T>(std::cos(r)*std::cos(h), -std::sin(r)*std::sin(h));
}

template <class T>
Dual<T> cos(const Dual<T>& c){
    return Dual<T>(std::cos(real(c)),-std::sin(real(c))*dual(c));
}

template <class T>
Complex<T> tan(const Complex<T>& c){
    return sin(c)/cos(c);
}

template <class T>
Split_Complex<T> tan(const Split_Complex<T>& c){
    return sin(c)/cos(c);
}

template <class T>
Dual<T> tan(const Dual<T>& c){
    return sin(c)/cos(c);
}

template <class T>
Complex<T> cot(const Complex<T>& c){
    return cos(c)/sin(c);
}

template <class T>
Split_Complex<T> cot(const Split_Complex<T>& c){
    return cos(c)/sin(c);
}

template <class T>
Dual<T> cot(const Dual<T>& c){
    return cos(c)/sin(c);
}

template <class T>
Complex<T> sec(const Complex<T>& c){
    return Complex<T>(1,0)/cos(c);
}

template <class T>
Split_Complex<T> sec(const Split_Complex<T>& c){
    return Split_Complex<T>(1,0)/cos(c);
}

template <class T>
Dual<T> sec(const Dual<T>& c){
    return Dual<T>(1,0)/cos(c);
}

template <class T>
Complex<T> csc(const Complex<T>& c){
    return Complex<T>(1,0)/sin(c);
}

template <class T>
Split_Complex<T> csc(const Split_Complex<T>& c){
    return Split_Complex<T>(1,0)/sin(c);
}

template <class T>
Dual<T> csc(const Dual<T>& c){
    return Dual<T>(1,0)/sin(c);
}

template <class T>
Complex<T> asin(const Complex<T>& c){
    const Complex<T> i(0,1);
    return -i*log(i*c+sqrt(1-c*c));
}

template <class T>
Split_Complex<T> asin(const Split_Complex<T>& c){
    const Split_Complex<T> j(0,1);
    return -j*log(j*c+sqrt(1-c*c));
}

template <class T>
Dual<T> asin(const Dual<T>& c){
    return std::asin(real(c))+std::cos(real(c))*dual(c)/std::sqrt(1-real(c)*real(c));
}

template <class T>
Complex<T> acos(const Complex<T>& c){
    const Complex<T> i(0,1);
    return -i*log(c+sqrt(c*c-1));
}

template <class T>
Split_Complex<T> acos(const Split_Complex<T>& c){
    const Split_Complex<T> j(0,1);
    return -j*log(c+sqrt(c*c-1));
}

template <class T>
Dual<T> acos(const Dual<T>& c){
    return std::acos(real(c))-std::sin(real(c))*dual(c)/std::sqrt(1-real(c)*real(c));
}

template <class T>
Complex<T> atan(const Complex<T>& c){
    const Complex<T> i(0,1);
    return (i/2.0)*(log(1-i*c)-log(1+i*c));
}

template <class T>
Split_Complex<T> atan(const Split_Complex<T>& c){
    const Split_Complex<T> j(0,1);
    return (j/2.0)*(log(1-j*c)-log(1+j*c));
}

template <class T>
Dual<T> atan(const Dual<T>& c){
    return std::atan(real(c))+dual(c)/(1+real(c)*real(c));
}

template <class T>
Complex<T> atan2(const Complex<T>& y, const Complex<T>& x){
    return atan(y/x);
}

template <class T>
Split_Complex<T> atan2(const Split_Complex<T>& y, const Split_Complex<T>& x){
    return atan(y/x);
}

template <class T>
Dual<T> atan2(const Dual<T>& y, const Dual<T>& x){
    return atan(y/x);
}

template <class T>
Complex<T> sinh(const Complex<T>& c){
    const Complex<T> i(0,1);
    return (exp(c)-exp(-c))/2.0;
}

template <class T>
Split_Complex<T> sinh(const Split_Complex<T>& c){
    const Split_Complex<T> j(0,1);
    return (exp(c)-exp(-c))/2.0;
}

template <class T>
Dual<T> sinh(const Dual<T>& c){
    return Dual<T>(std::sinh(real(c)), std::cosh(real(c))*dual(c));
}

template <class T>
Complex<T> cosh(const Complex<T>& c){
    const Complex<T> i(0,1);
    return (exp(c)+exp(-c))/2.0;
}

template <class T>
Split_Complex<T> cosh(const Split_Complex<T>& c){
    const Split_Complex<T> j(0,1);
    return (exp(c)+exp(-c))/2.0;
}

template <class T>
Dual<T> cosh(const Dual<T>& c){
    return Dual<T>(std::cosh(real(c)), std::sinh(real(c))*dual(c));
}

template <class T>
Complex<T> tanh(const Complex<T>& c){
    return sinh(c)/cosh(c);
}

template <class T>
Split_Complex<T> tanh(const Split_Complex<T>& c){
    return sinh(c)/cosh(c);
}

template <class T>
Dual<T> tanh(const Dual<T>& c){
    return sinh(c)/cosh(c);
}

template <class T>
Complex<T> coth(const Complex<T>& c){
    return cosh(c)/sinh(c);
}

template <class T>
Split_Complex<T> coth(const Split_Complex<T>& c){
    return cosh(c)/sinh(c);
}

template <class T>
Dual<T> coth(const Dual<T>& c){
    return cosh(c)/sinh(c);
}

template <class T>
Complex<T> sech(const Complex<T>& c){
    return Complex<T>(1,0)/cosh(c);
}

template <class T>
Split_Complex<T> sech(const Split_Complex<T>& c){
    return Split_Complex<T>(1,0)/cosh(c);
}

template <class T>
Dual<T> sech(const Dual<T>& c){
    return Dual<T>(1,0)/cosh(c);
}

template <class T>
Complex<T> csch(const Complex<T>& c){
    return Complex<T>(1,0)/sinh(c);
}

template <class T>
Split_Complex<T> csch(const Split_Complex<T>& c){
    return Split_Complex<T>(1,0)/sinh(c);
}

template <class T>
Dual<T> csch(const Dual<T>& c){
    return Dual<T>(1,0)/sinh(c);
}

template <class T>
Complex<T> asinh(const Complex<T>& c){
    const Complex<T> i(0,1);
    return log(c+sqrt(c*c+1));
}

template <class T>
Split_Complex<T> asinh(const Split_Complex<T>& c){
    const Split_Complex<T> j(0,1);
    return log(c+sqrt(c*c+1));
}

template <class T>
Dual<T> asinh(const Dual<T>& c){
    return std::asinh(real(c))+dual(c)/std::sqrt(real(c)*real(c)+1);
}

template <class T>
Complex<T> acosh(const Complex<T>& c){
    const Complex<T> i(0,1);
    return log(c+sqrt(c*c-1));
}

template <class T>
Split_Complex<T> acosh(const Split_Complex<T>& c){
    const Split_Complex<T> j(0,1);
    return log(c+sqrt(c*c-1));
}

template <class T>
Dual<T> acosh(const Dual<T>& c){
    return std::acosh(real(c))+dual(c)/std::sqrt(real(c)*real(c)-1);
}

template <class T>
Complex<T> atanh(const Complex<T>& c){
    const Complex<T> i(0,1);
    return (log(1+c)-log(1-c))/2.0;
}

template <class T>
Split_Complex<T> atanh(const Split_Complex<T>& c){
    const Split_Complex<T> j(0,1);
    return (log(1+c)-log(1-c))/2.0;
}

template <class T>
Dual<T> atanh(const Dual<T>& c){
    return atanh(real(c))+dual(c)/(1-real(c)*real(c));
}

}



