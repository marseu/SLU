#include "wektor.hpp"
#include <iostream>

using namespace std;

    Wektor::Wektor(int vectorSize, int number)
	{
        if(vectorSize < 1) 
		{
            this->vectorSize = 0;
            numbers = NULL;
        }
        numbers = new int [vectorSize];
        if(numbers == NULL) 
		{
            this->vectorSize = 0;
            throw "\nBlad konstruktora wektorow\n";
        } 
		else 
		{
            this->vectorSize = vectorSize;
            for ( int i = 0; i < vectorSize; i++ )
            {
                numbers[i] = number;
            }
        }
    }

    Wektor::Wektor(const Wektor & B) 
	{
        if(B.vectorSize < 1 || B.numbers == NULL ) 
		{
            delete [] numbers;
            vectorSize = 0;
            numbers = NULL;
        } 
		else 
		{
            numbers = new int[B.vectorSize];
            if ( numbers == NULL ) 
			{
                vectorSize = 0;
                throw "\nBlad konstruktora kopiujacego wektorow\n";
            } 
			else 
			{
                vectorSize = B.vectorSize;
                for ( int i = 0; i < vectorSize; i++ )
                {
                    numbers[i] = B.numbers[i];
                }
            }
        }
    }

    Wektor::~Wektor() 
	{
        delete [] numbers;
        vectorSize = 0;
    }

    int Wektor::getNumber(int position) 
	{
        return numbers[position];
    }

    int* Wektor::getVector() 
	{
        return numbers;
    }

    int Wektor::getVectorSize() 
	{
        return vectorSize;
    }

    void Wektor::setNumber(int number, int position) 
	{
        numbers[position] = number;
    }

    void Wektor::setVector(int position) 
	{
        for (int i = 0; i < vectorSize; i++)
        {
            numbers[i] = position;
        }
    }

    void Wektor::reset() 
	{
        for(int i = 0; i < vectorSize; i++)
        {
			numbers[i] = 0;
		}
    }

    void Wektor::show() 
	{
        for(int i = 0; i < vectorSize; i++)
            cout << numbers[i] << endl;
    }

    Wektor Wektor::operator!() 
	{
        (*this) = (*this) - 2*(*this);
        return (*this);
    }

    Wektor Wektor::operator+(const Wektor & B) const 
	{
        if( vectorSize < 1 || B.vectorSize < 1 || numbers == NULL || B.numbers == NULL) 
		{
            throw "\nBlad operatora + wektorow (zly wymiar)\n";
        }
        if( vectorSize != B.vectorSize) 
		{
            throw "\nBlad operatora + wektorow (rozne wymiary)\n";
        }
        Wektor result((*this).vectorSize);
        if ( result.numbers == NULL ) 
		{
            result.vectorSize = 0;
            throw "\nBlad operatora + wektorow (nie udalo sie utowrzyc wektora)\n";
        }
        for ( int i = 0; i < (*this).vectorSize; i++)
        {
            result.numbers[i] = (*this).numbers[i] + B.numbers[i];
        }
        return result;
    }

    Wektor Wektor::operator-(const Wektor & B) const 
	{
        if( vectorSize < 1 || B.vectorSize < 1 || numbers == NULL || B.numbers == NULL) 
		{
            throw "\nBlad operatora - wektorow (zly wymiar)\n";
        }
        if( vectorSize != B.vectorSize) 
		{
            throw "\nBlad operatora - wektorow (rozne wymiary)\n";
        }
        Wektor result((*this).vectorSize);
        if ( result.numbers == NULL ) 
		{
            result.vectorSize = 0;
            throw "\nBlad operatora - wektorow (nie udalo sie utowrzyc wektora)\n";
        }
        for ( int i = 0; i < (*this).vectorSize; i++)
        {
            result.numbers[i] = (*this).numbers[i] - B.numbers[i];
        }
        return result;
    }

    Wektor Wektor::operator*(const int number) const 
	{
        Wektor result((*this).vectorSize);
        if ( result.numbers == NULL ) 
		{
            result.vectorSize = 0;
            throw "\nBlad operatora * wektorow (Wektor*int) (nie udalo sie utowrzyc wektora)\n";
        }
        for ( int i = 0; i < (*this).vectorSize; i++ )
        {
            result.numbers[i] = (*this).numbers[i] * number;
        }
        return result;
    }

    Wektor Wektor::operator/(const int number) const 
	{
        Wektor result((*this).vectorSize);
        if ( result.numbers == NULL ) 
		{
            result.vectorSize = 0;
            throw "\nBlad operatora / wektorow (nie udalo sie utowrzyc wektora)\n";
        }
        for ( int i = 0; i < (*this).vectorSize; i++ )
        {
            result.numbers[i] = (*this).numbers[i] / number;
        }
        return result;
    }

    int Wektor::operator*(const Wektor & B) 
	{
        if( this == NULL || &B == NULL || B.vectorSize < 1 || vectorSize < 1 || B.numbers == NULL || numbers == NULL )
        {
            return 0;
        }
        int result = 0, minimum = vectorSize > B.vectorSize ? B.vectorSize : vectorSize;
        for ( int i = 0; i < minimum; i++ ) {
            result += numbers[i]*B.numbers[i];
        }
        return result;
    }

    Wektor & Wektor::operator=(const Wektor & B) 
	{
        if(this == NULL)
        {
            throw "\nBlad operatora = wektorow (Drugi wektor jest 0)\n";
        }
        if (this == &B)
        {
            return *this;
        }
        delete [] numbers;
        vectorSize = 0;
        numbers = new int[B.vectorSize];
        if ( numbers == NULL ) 
		{
            vectorSize = 0;
            throw "\nBlad operatora = wektorow (nie udalo sie utowrzyc wektora)\n";
        }
        vectorSize = B.vectorSize;
        for (int i = 0; i < B.vectorSize; i++)
        {
            numbers[i] = B.numbers[i];
        }
        return *this;
    }

    bool Wektor::operator==(const Wektor & B) const 
	{
        if( this == NULL || this->numbers == NULL || B.numbers == NULL || this->vectorSize < 1 || vectorSize < 1 || this->vectorSize < 1 )
            throw "\nBlad operatora == wektorow\n";
        if( this == &B )
            return true;
        if ( (*this).vectorSize != B.vectorSize )
            return false;
        for ( int i = 0; i < (*this).vectorSize; i++ )
        {
            if ( (*this).numbers[i] != B.numbers[i] )
            {
                return false;
            }
        }
        return true;
    }

    bool Wektor::operator!=(const Wektor & B) const 
	{
        if( this == NULL || this->numbers == NULL || B.numbers == NULL || this->vectorSize < 1 || vectorSize < 1 || this->vectorSize < 1 )
            throw "\nBlad operatora != wektorow\n";
        if( this == &B )
            return false;
        if ( (*this).vectorSize != B.vectorSize )
            return true;
        for ( int i = 0; i < (*this).vectorSize; i++ )
        {
            if ( (*this).numbers[i] != B.numbers[i] )
            {
                return true;
            }
        }
        return false;
    }

    Wektor operator*(const int number, const Wektor & B) 
	{
        if( &B == NULL || B.numbers == NULL || B.vectorSize < 1 )
            throw "\nBlad operatora * (int*Wektor) wektorow\n";
        Wektor result(B.vectorSize);
        if ( result.numbers == NULL ) {
            result.vectorSize = 0;
            throw "\nBlad operatora * (int*Wektor) wektorow (nie udalo sie utowrzyc wektora)\n";
        }
        for (int i = 0; i < B.vectorSize; i++ )
            result.numbers[i] = B.numbers[i] * number;
        return result;
    }

    void Wektor::operator+=(const Wektor & B) {
        (*this) = (*this) + B;
    }

    void Wektor::operator-=(const Wektor & B) {
        (*this) = (*this) - B;
    }

    void Wektor::operator*=(const int number) {
        (*this) = (*this) * number;
    }

    void Wektor::operator/=(const int number) {
        (*this) = (*this) / number;
    }

    int Wektor::operator[](int i) const 
	{
        if( this->numbers == NULL || this == NULL || this->vectorSize < 1 )
            throw "\nBlad operatora [] wektorow 1.1\n";
        if ( i >= (*this).vectorSize || i < 0)
            throw "\nBlad operatora [] wektorow 1.2\n";
        return (*this).numbers[i];
    }
    /*
    int & Wektor::operator[](size_t index) {
        if ( index >= 0 && index < (size_t) vectorSize)
            return numbers[(size_t)index];
        else
            throw "\nNiepowodzenie operatora [] dla wektora\n";
    }
    */
    const int & Wektor::operator[](size_t index) const 
	{
        if( this->numbers == NULL || this == NULL || this->vectorSize < 1 )
            throw "\nBlad operatora [] wektorow 2.1\n";
        if(index >= 0 && index < (size_t) vectorSize)
            return numbers[(size_t)index];
        throw "\nBlad operatora [] wektorow 2.2\n";
    }

    ostream & operator<<( ostream & os, Wektor & B ) 
	{
        if( B.numbers == NULL || &B == NULL || B.vectorSize < 1 )
            throw "\nBlad operatora << wektorow\n";
        os << '[';
        for ( int i = 0 ; i < B.vectorSize-1 ; i++ )
            os << B.numbers[i] << ',' << ' ';
        os << B.numbers[ B.vectorSize-1 ] <<']';
        return os;
    }

    istream & operator>>( istream & is, Wektor & B ) 
	{
        if( B.numbers == NULL || &B == NULL || B.vectorSize < 1 )
            throw "\nBlad operatora >> wektorow\n";
        int* pointer;
        pointer = new int[B.getVectorSize()];
        for ( int i = 0; i < B.getVectorSize(); i++ )
            cin >> pointer[i];
        for ( int i = 0; i < B.getVectorSize(); i++ )
            B.setNumber(pointer[i], i);
        delete [] pointer;
        return is;
    }
