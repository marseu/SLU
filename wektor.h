#ifndef WEKTOR
 #define WEKTOR

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Wektor {

private:
    int *numbers;
    int vectorSize;

public:
    explicit Wektor(int vectorSize = 2, int number = 0);
    Wektor(const Wektor & B);
    ~Wektor();

    int getNumber(int position);
    int* getVector();
    int getVectorSize();
    void setNumber(int number, int position);
    void setVector(int position);
    void reset();
    void show();

    Wektor operator!();
    Wektor operator+(const Wektor & B) const;
    Wektor operator-(const Wektor & B) const;
    Wektor operator*(const int number) const;
    Wektor operator/(const int number) const;
    Wektor & operator=(const Wektor & B);
    int operator*(const Wektor & B);

    bool operator==(const Wektor & B) const;
    bool operator!=(const Wektor & B) const;
    void operator+=(const Wektor & B);
    void operator-=(const Wektor & B);
    void operator*=(const int number);
    void operator/=(const int number);

    int operator[](int i) const;
//    int & operator[](size_t index);
    const int & operator[](size_t index) const;

    friend Wektor operator*(const int number, const Wektor & B);
    friend ostream & operator<<( ostream & os, Wektor & B );
    friend istream & operator>>( istream & s, Wektor & v );
};

#endif
