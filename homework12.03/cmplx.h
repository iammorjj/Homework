#ifndef CMPLX_H_INCLUDED
#define CMPLX_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class CmpxNum {
    int im, re;
public:
    CmpxNum(int r = 0, int i = 0): im(i), re(r) {}
    CmpxNum operator+(const CmpxNum& obj);
    CmpxNum operator-(const CmpxNum& obj);
    CmpxNum operator*(const CmpxNum& obj);
    friend int Im(const CmpxNum& obj) { return obj.im; }
    friend int Re(const CmpxNum& obj) { return obj.re; }
    friend double abs(const CmpxNum& obj) { return sqrt(obj.im*(obj.im) + obj.re*(obj.re)); }
    bool operator==(const CmpxNum& obj) { return (im == obj.im && re == obj.re); }
    bool operator!=(const CmpxNum& obj) { return (im != obj.im || re != obj.re); }
    friend ostream& operator<<(ostream& stream, const CmpxNum& obj);
    friend istream& operator>>(istream& stream, CmpxNum& obj);
};

istream& operator>>(istream& stream, CmpxNum& obj) {
    char i;
    stream >> obj.re >> obj.im >> i; // ЗАПИСЫВАТЬ В ВИДЕ ReImi ex: 0+0i
    return stream;
}
ostream& operator<<(ostream& stream, const CmpxNum& obj) {
    stream << obj.re;
    if(obj.im < 0) stream << obj.im << "i";
    else stream << "+" << obj.im << "i";
    return stream;
}
CmpxNum CmpxNum::operator+(const CmpxNum& obj) {
    CmpxNum temp;
    temp.im = im + obj.im;
    temp.re = re + obj.re;
    return temp;
}
CmpxNum CmpxNum::operator-(const CmpxNum& obj) {
    CmpxNum temp;
    temp.im = im - obj.im;
    temp.re = re - obj.re;
    return temp;
}
CmpxNum CmpxNum::operator*(const CmpxNum& obj) {
    CmpxNum temp;
    temp.im = im*(obj.im) - re*(obj.re);
    temp.re = im*(obj.re) + re*(obj.im);
    return temp;
}

#endif // CMPLX_H_INCLUDED
