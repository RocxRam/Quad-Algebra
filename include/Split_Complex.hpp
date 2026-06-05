#pragma once 
#include <iostream>
#include <cmath>
#include <stdexcept>

namespace quad{
template <class T>
class Split_Complex{
private:
    T realPart;
    T hyperbolicPart;
public:
    Split_Complex():realPart(0),hyperbolicPart(0){}
    Split_Complex(T r):realPart(r),hyperbolicPart(0){}
    Split_Complex(T r, T h):realPart(r),hyperbolicPart(h){}

    friend T real(const Split_Complex& c){
        return c.realPart;
    }
    friend T hyperbolic(const Split_Complex& c){
        return c.hyperbolicPart;
    }
    auto operator+(const Split_Complex& c) const{
        return Split_Complex(real(c)+realPart,hyperbolic(c)+hyperbolicPart);
    }
    auto operator+(T n) const{
        return Split_Complex(realPart+n,hyperbolicPart);
    }
    friend auto operator+(T n, const Split_Complex& c){
        return Split_Complex(n+real(c),hyperbolic(c));
    }
    auto operator-(const Split_Complex& c) const{
        return Split_Complex(realPart-real(c),hyperbolicPart-hyperbolic(c));
    }
    auto operator-(T n) const{
        return Split_Complex(realPart-n,hyperbolicPart);
    }
    friend auto operator-(T n, const Split_Complex& c){
        return Split_Complex(n-real(c),-hyperbolic(c));
    }
    auto operator-() const{
        return Split_Complex(-realPart,-hyperbolicPart);
    }
    auto operator*(const Split_Complex& c) const{
        return Split_Complex(realPart*real(c)+hyperbolicPart*hyperbolic(c),real(c)*hyperbolicPart+realPart*hyperbolic(c));
    }
    auto operator*(T n) const{
        return Split_Complex(realPart*n,hyperbolicPart*n);
    }
    friend auto operator*(T n, const Split_Complex& c){
        return Split_Complex(n*real(c),n*hyperbolic(c));
    }
    friend Split_Complex conjugate(const Split_Complex& c){
        return Split_Complex(c.realPart,-c.hyperbolicPart);
    }
    friend auto norm(const Split_Complex& c){
        return (c.realPart*c.realPart-c.hyperbolicPart*c.hyperbolicPart);
    }
    friend auto modulo(const Split_Complex& c){  
        return std::sqrt(std::abs(norm(c)));
    }
    auto operator/(T n) const{
        if (n==0){
            throw std::runtime_error("Division by zero error");
        }
        return Split_Complex(realPart/n,hyperbolicPart/n);
    }
    friend Split_Complex inv(const Split_Complex& c){
        if (norm(c)==0){
            throw std::runtime_error("Norm should not be zero error");
        }
        return conjugate(c)/(norm(c));
    }
    auto operator/(const Split_Complex& c) const{
        if (norm(c)==0){
            throw std::runtime_error("Norm should not be zero error");
        }
        return ((*this)*conjugate(c))/(norm(c));
    }
    friend auto operator/(T n, const Split_Complex& c){
        if (norm(c)==0){
            throw std::runtime_error("Norm should not be zero error");
        }
        return (n*conjugate(c))/(norm(c));
    }
    bool operator==(const Split_Complex& c) const{
        return (realPart==real(c)&&hyperbolicPart==hyperbolic(c));
    }
    bool operator!=(const Split_Complex& c) const{
        return !(*this==c);
    }
    Split_Complex& operator+=(const Split_Complex& c){
        realPart+=real(c);
        hyperbolicPart+=hyperbolic(c);
        return (*this);
    }
    Split_Complex& operator-=(const Split_Complex& c){
        realPart-=real(c);
        hyperbolicPart-=hyperbolic(c);
        return (*this);
    }
    Split_Complex& operator*=(const Split_Complex& c){
        T j=realPart*hyperbolic(c)+hyperbolicPart*real(c);
        T r=realPart*real(c)+hyperbolicPart*hyperbolic(c);
        hyperbolicPart=j;
        realPart=r;
        return (*this);
    }
    Split_Complex& operator/=(const Split_Complex& c){
        if (norm(c)==0){
            throw std::runtime_error("Norm should not be zero error");
        }
        T j=(T)(hyperbolicPart*real(c)-realPart*hyperbolic(c))/(norm(c));
        T r=(T)(realPart*real(c)+hyperbolicPart*hyperbolic(c))/(norm(c));
        realPart=r;
        hyperbolicPart=j;
        return (*this);
    }
    friend std::istream& operator>>(std::istream& in, Split_Complex& c){
        T r,j;
        in>>r>>j;
        c.realPart=r;
        c.hyperbolicPart=j;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Split_Complex& c){
        out<<c.realPart;
        if (c.hyperbolicPart>=0){
            out<<"+"<<c.hyperbolicPart<<"j";
        }
        else{
            out<<c.hyperbolicPart<<"j";
        }
        return out;
    }
};
}