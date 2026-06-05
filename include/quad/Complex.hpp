#pragma once 
#include <iostream>
#include <cmath>
#include <stdexcept>

namespace quad{
template <class T>
class Complex{
private:
    T realPart;
    T imaginaryPart;
public:
    Complex():realPart(0),imaginaryPart(0){}
    Complex(T r):realPart(r),imaginaryPart(0){}
    Complex(T r, T i):realPart(r),imaginaryPart(i){}
    
    friend T real(const Complex& c){
        return c.realPart;
    }
    friend T imaginary(const Complex& c){
        return c.imaginaryPart;
    }
    auto operator+(const Complex& c) const{
        return Complex(real(c)+realPart,imaginary(c)+imaginaryPart);
    }
    auto operator+(T n) const{
        return Complex(realPart+n,imaginaryPart);
    }
    friend auto operator+(T n, const Complex& c){
        return Complex(n+real(c),imaginary(c));
    }
    auto operator-(const Complex& c) const{
        return Complex(realPart-real(c),imaginaryPart-imaginary(c));
    }
    auto operator-(T n) const{
        return Complex(realPart-n,imaginaryPart);
    }
    friend auto operator-(T n, const Complex& c){
        return Complex(n-real(c),-imaginary(c));
    }
    auto operator-() const{
        return Complex(-realPart,-imaginaryPart);
    }
    auto operator*(const Complex& c) const{
        return Complex(realPart*real(c)-imaginaryPart*imaginary(c),real(c)*imaginaryPart+realPart*imaginary(c));
    }
    auto operator*(T n) const{
        return Complex(realPart*n,imaginaryPart*n);
    }
    friend auto operator*(T n, const Complex& c){
        return Complex(n*real(c),n*imaginary(c));
    }
    friend Complex conjugate(const Complex& c){
        return Complex(c.realPart,-c.imaginaryPart);
    }
    friend auto norm(const Complex& c){
        return (c.realPart*c.realPart+c.imaginaryPart*c.imaginaryPart);
    }
    friend auto modulo(const Complex& c){
        return std::sqrt(norm(c));
    }
        auto operator/(T n) const{
        if (n==0){
                throw std::runtime_error("Division by zero error");
        }
        return Complex(realPart/n,imaginaryPart/n);
    }
    friend Complex inv(const Complex& c){
        if (modulo(c)==0){
                throw std::runtime_error("Modulo should not be zero error");
        }
        return conjugate(c)/(norm(c));
    }
    auto operator/(const Complex& c) const{
        if (c==0){
                throw std::runtime_error("Division by zero error");
        }
        return ((*this)*conjugate(c))/(norm(c));
    }
    friend auto operator/(T n, const Complex& c){
        if (c==0){
                throw std::runtime_error("Division by zero error");
        }
        return (n*conjugate(c))/(norm(c));
    }
    bool operator==(const Complex& c) const{
        return (realPart==real(c)&&imaginaryPart==imaginary(c));
    }
    bool operator!=(const Complex& c) const{
        return !(*this==c);
    }
    Complex& operator+=(const Complex& c){
        realPart+=real(c);
        imaginaryPart+=imaginary(c);
        return (*this);
    }
    Complex& operator-=(const Complex& c){
        realPart-=real(c);
        imaginaryPart-=imaginary(c);
        return (*this);
    }
    Complex& operator*=(const Complex& c){
        T i=realPart*imaginary(c)+imaginaryPart*real(c);
        T r=realPart*real(c)-imaginaryPart*imaginary(c);
        imaginaryPart=i;
        realPart=r;
        return (*this);
    }
    Complex& operator/=(const Complex& c){
        if (c==0){
            throw std::runtime_error("Division by zero error");
        }
        T i=(T)(imaginaryPart*real(c)-realPart*imaginary(c))/(norm(c));
        T r=(T)(realPart*real(c)+imaginaryPart*imaginary(c))/(norm(c));
        realPart=r;
        imaginaryPart=i;
        return (*this);
    }
    friend std::istream& operator>>(std::istream& in, Complex& c){
        T r,i;
        in>>r>>i;
        c.realPart=r;
        c.imaginaryPart=i;
        return in;
    }
        friend std::ostream& operator<<(std::ostream& out, const Complex& c){
        out<<c.realPart;
        if (c.imaginaryPart>=0){
            out<<"+"<<c.imaginaryPart<<"i";
        }
        else{
            out<<c.imaginaryPart<<"i";
        }
        return out;
    }
};

}