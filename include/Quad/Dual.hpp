#pragma once

#include <iostream>
#include <stdexcept>

namespace quad{
template <class T>
class Dual{
private:
    T realPart;
    T dualPart;
public:
    Dual(): realPart(0), dualPart(0){}
    Dual(T r): realPart(r), dualPart(0){}
    Dual(T r, T d): realPart(r), dualPart(d){}

    friend T real(const Dual& d){
        return d.realPart;
    }

    friend T dual(const Dual& d){
        return d.dualPart;
    }

    auto operator+(const Dual& n) const {
        return Dual(realPart + real(n), dualPart + dual(n));
    }

    auto operator+(T n) const {
        return Dual(realPart + n, dualPart);
    }

    friend auto operator+(T n, const Dual& d1){
        return Dual(n + real(d1), dual(d1));
    }

    auto operator-(const Dual& n) const{
        return Dual(realPart - real(n), dualPart - dual(n));
    }

    auto operator-(T n) const {
        return Dual(realPart - n, dualPart);
    }

    friend auto operator-(T n, const Dual& d1){
        return Dual(n - real(d1), -dual(d1));
    }

    auto operator-() const {
        return Dual(-realPart, -dualPart);
    }

    auto operator*(const Dual& n) const{
        return Dual(realPart * real(n), realPart * dual(n) + dualPart * real(n));
    }

    auto operator*(T n) const {
        return Dual(realPart * n, dualPart * n);
    }

    friend auto operator*(T n, const Dual& d1){
        return Dual(n * real(d1), n * dual(d1));
    }

    auto operator/(const Dual& n) const{
        if (real(n) == 0){
            throw std::runtime_error("Division by zero error");
        }
        return Dual(
            realPart / real(n),
            (dualPart * real(n) - realPart * dual(n)) / (real(n) * real(n))
        );
    }

    auto operator/(T n) const {
        if (n == 0){
            throw std::runtime_error("Division by zero error");
        }
        return Dual(realPart / n, dualPart / n);
    }

    friend auto operator/(T n, const Dual& d1){
        if (real(d1) == 0){
            throw std::runtime_error("Division by zero error");
        }
        return Dual(
            n / real(d1),
            -(dual(d1) * n) / (real(d1) * real(d1))
        );
    }

    friend Dual conjugate(const Dual& d){
        return Dual(d.realPart, -d.dualPart);
    }

    friend auto norm(const Dual& d){
        return (d.realPart*d.realPart);
    }

    friend auto modulo(const Dual& d){
        return d.realPart>=0?d.realPart:-d.realPart;
    }

    bool operator==(const Dual& n) const{
        return realPart == real(n) && dualPart == dual(n);
    }

    bool operator!=(const Dual& n) const{
        return !(*this == n);
    }

    Dual& operator+=(const Dual& n){
        realPart += real(n);
        dualPart += dual(n);
        return *this;
    }

    Dual& operator-=(const Dual& n){
        realPart -= real(n);
        dualPart -= dual(n);
        return *this;
    }

    Dual& operator*=(const Dual& n){
        T r = realPart * real(n);
        T d = realPart * dual(n) + dualPart * real(n);
        realPart = r;
        dualPart = d;
        return *this;
    }

    Dual& operator/=(const Dual& n){
        if (real(n) == 0){
            throw std::runtime_error("Division by zero error");
        }
        T r = realPart / real(n);
        T d = (dualPart * real(n) - realPart * dual(n)) / (real(n) * real(n));
        realPart = r;
        dualPart = d;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Dual& n){
        out << real(n);
        if (dual(n) >= 0){
            out << "+" << dual(n) << "e";
        } else {
            out << dual(n) << "e";
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Dual& n){
        in >> n.realPart >> n.dualPart;
        return in;
    }
};
}
