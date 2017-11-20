#ifndef MACIERZ
 #define MACIERZ

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "wektor.hpp"

using namespace std;

class Macierz {

private:
  int matrixSize;
  int vectorSize;
  Wektor** matrix;

public:
    Macierz(int matrixSize = 2, int vectorSize = 2, int number = 0);
    Macierz(const Macierz & B);
    virtual ~Macierz();

    int getVectorSize();
    int getMatrixSize();
    Wektor** getMatirx();
    Wektor getVector(int Number);
    void reset();
    void show();

    Macierz & operator!();
    Macierz operator+(const Macierz & B) const;
    Macierz operator-(const Macierz & B) const;
    Macierz operator*(const int number) const;
    Macierz operator/(const int number) const;
    Macierz & operator=(const Macierz & B);
    Macierz operator*(Macierz &B) const;

    bool operator==(const Macierz & B) const;
    bool operator!=(const Macierz & B) const;

    Macierz & operator+=( const Macierz & B);
    Macierz & operator-=(const Macierz & B);
    Macierz & operator*=(const int number);
    Macierz & operator/=(const int number);

    int operator()(const int vectorS, const int matrixS);
	Wektor& operator[] (size_t index);
	const Wektor& operator[] (size_t index) const;

    friend Macierz operator*(const int number, const Macierz & B);
    friend Macierz operator/(const int number, const Macierz & B);
    friend ostream & operator<<(ostream & os, const Macierz & B);
    friend istream & operator>>(istream & is, const Macierz & B);
};

#endif
