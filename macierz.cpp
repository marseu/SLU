#include "macierz.hpp"
#include "wektor.hpp"

using namespace std;

    Macierz::Macierz(int matrixSize, int vectorSize, int number) {
        if ( matrixSize < 1 || vectorSize < 1 ) {
            this->matrixSize = 0;
            this->vectorSize = 0;
            matrix = NULL;
            throw "\nBlad konstruktora macierzy 1\n";
        }
        this->vectorSize = vectorSize;
        this->matrixSize = matrixSize;
        matrix = new Wektor * [matrixSize];
        if ( matrix == NULL ) {
            this->matrixSize = 0;
            this->vectorSize = 0;
            throw "\nBlad konstruktora macierzy 2\n";
        }
        for(int i = 0; i < matrixSize; i++) {
            *(matrix+i) = new Wektor(vectorSize, number);
            if (*(matrix+i) == NULL) {
                for ( int j = 0; j < i; j++)
                delete *(matrix + j);
                delete [] matrix;
                throw "\nBlad konstruktora macierzy 3\n";
            }
        }
    }

    Macierz::Macierz(const Macierz & B){
        if( B.matrixSize < 1 || B.vectorSize < 1 || B.matrix == NULL ) {
            matrixSize = 0;
            vectorSize = 0;
            matrix = NULL;
            return;
        }
        matrix = new Wektor * [B.matrixSize];
        if ( matrix == NULL ) {
            this->matrixSize = 0;
            this->vectorSize = 0;
            throw "\nBlad konstruktora kopiujacego macierzy 1\n";
        }
        matrixSize = B.matrixSize;
        vectorSize = B.vectorSize;
        for ( int i = 0; i < matrixSize; i++) {
            matrix[i] = new Wektor(vectorSize);
            if (*(matrix+i) == NULL) {
                for ( int j = 0; j < i; j++)
                delete *(matrix + j);
                throw "\nBlad konstruktora kopiujacego macierzy 2\n";
            }
            *(matrix[i]) = *(B.matrix[i]);
        }
    }

    Macierz::~Macierz() {
        for(int i = 0; i < matrixSize; i++) {
            delete *(matrix + i);
        }
        delete[] matrix;
        matrixSize = 0;
        vectorSize = 0;
    }

    int Macierz::getVectorSize() {
        return vectorSize;
    }

    int Macierz::getMatrixSize() {
        return matrixSize;
    }

    Wektor** Macierz::getMatirx() {
        return matrix;
    }

    Wektor Macierz::getVector(int Number) {
        return **(matrix + Number);
    }

    void Macierz::reset() {
        for(int i = 0; i < matrixSize; i++)
            (matrix[i])->reset();
    }

    void Macierz::show() {
        for(int i = 0; i < matrixSize; i++)
            (matrix[i])->show();
    }

    Macierz & Macierz::operator!() {
        (*this) = (*this) - 2*(*this);
        return (*this);
    }

    Macierz Macierz::operator+(const Macierz& B) const {
        if(matrixSize < 1 || B.matrixSize < 1 || vectorSize < 1 || B.vectorSize < 1 || matrix == NULL || B.matrix == NULL) {
            throw "\nBlad operatora + macierzy (zly wymiar)\n";
        }
        if(matrixSize != B.matrixSize || vectorSize != B.vectorSize) {
            throw "\nBlad operatora + macierzy (rozne wymiary)\n";
        }
        Macierz result(matrixSize, vectorSize);
        if ( result.matrix == NULL ) {
            result.matrixSize = 0;
            result.vectorSize = 0;
            throw "\nBlad operatora + macierzy (nie udalo sie utowrzyc macierzy)\n";
        }
        for(int i = 0; i < matrixSize; i++) {
            *(*(result.matrix + i)) = *(*(matrix+i)) + *(*(B.matrix + i));
        }
	return result;
    }


    Macierz Macierz::operator-(const Macierz& B) const {
        if(matrixSize < 1 || B.matrixSize < 1 || vectorSize < 1 || B.vectorSize < 1 || matrix == NULL || B.matrix == NULL) {
            throw "\nBlad operatora - macierzy (zly wymiar)\n";
        }
        if(matrixSize != B.matrixSize || vectorSize != B.vectorSize) {
            throw "\nBlad operatora - macierzy (rozne wymiary)\n";
        }
        Macierz result(matrixSize, vectorSize);
        if ( result.matrix == NULL ) {
            result.matrixSize = 0;
            result.vectorSize = 0;
            throw "\nBlad operatora - macierzy (nie udalo sie utowrzyc macierzy)\n";
        }
        for(int i = 0; i < matrixSize; i++) {
            *(*(result.matrix + i)) = *(*(matrix+i)) - *(*(B.matrix + i));
        }
	return result;
    }

    Macierz Macierz::operator*(const int number) const {
        Macierz result( (*this).matrixSize, (*this).vectorSize );
        if ( result.matrix == NULL ) {
            result.matrixSize = 0;
            result.vectorSize = 0;
            throw "\nBlad operatora * macierzy (nie udalo sie utowrzyc macierzy)\n";
        }
        for ( int i = 0; i < (*this).matrixSize; i++ )
            *(result.matrix[i]) = *(matrix[i]) * number;
        return result;
    }

    Macierz Macierz::operator/(const int number) const {
        Macierz result( (*this).matrixSize, (*this).vectorSize );
        if ( result.matrix == NULL ) {
            result.matrixSize = 0;
            result.vectorSize = 0;
            throw "\nBlad operatora / macierzy (nie udalo sie utowrzyc macierzy)\n";
        }
        for (int i = 0; i < (*this).matrixSize; i++ )
            *(result.matrix[i]) = *(matrix[i]) / number;
        return result;
    }

    Macierz & Macierz::operator=(const Macierz & B) {
        if ( this == & B )
            return *this;
        if( B.matrixSize < 1 || B.vectorSize < 1 || B.matrix == NULL ) {
                matrixSize = 0;
                vectorSize = 0;
                matrix = NULL;
                throw "\nBlad operatora = macierzy (zly wymiar)\n";
            }
        for(int i = 0; i < matrixSize; i++) {
            delete *(matrix + i);
        }
        delete[] matrix;
            matrixSize = 0;
            vectorSize = 0;
            matrix = new Wektor * [B.matrixSize];
            if ( matrix == NULL ) {
                this->matrixSize = 0;
                this->vectorSize = 0;
                throw "\nBlad operatora = macierzy (nie udalo sie utowrzyc macierzy)\n";
            }
            matrixSize = B.matrixSize;
            vectorSize = B.vectorSize;
            for ( int i = 0; i < matrixSize; i++) {
                matrix[i] = new Wektor(vectorSize);
                if (*(matrix+i) == NULL) {
                    for ( int j = 0; j < i; j++)
                    delete *(matrix + j);
                    throw "\nBlad operatora = macierzy (nie udalo sie utowrzyc wektora)\n";
                }
                *(matrix[i]) = *(B.matrix[i]);
            }
        return *this;
    }

    Macierz Macierz::operator*(Macierz &B) const {
        int m = 0;
        int n = 0;
        if( this == NULL || &B == NULL || B.matrixSize < 1 || matrixSize < 1 || B.vectorSize < 1 || vectorSize < 1 || B.matrix == NULL || matrix == NULL ) {
                throw "\nBlad operatora * (Macierz*Macierz) macierzy (zly wymiar)\n";
            }
        if ( vectorSize !=  B.matrixSize )
            throw "\nBlad operatora * (Macierz*Macierz) macierzy (niedozwolone dzialanie)\n";
        Macierz result( matrixSize, B.vectorSize, 0 );
        if ( result.matrix == NULL ) {
            result.vectorSize = 0;
            result.matrixSize = 0;
            throw "\nBlad operatora / macierzy (nie udalo sie utowrzyc macierzy)\n";
        }
        for ( int i = 0; i < matrixSize; i++ ) {
            for ( int j = 0; j < B.vectorSize; j++ ) {
                for ( int k = 0; k < vectorSize; k++ ) {
                    m = ((*this).matrix[i])->getNumber(k) * (B.matrix[k])->getNumber(j);
                    n = (result.matrix[i])->getNumber(j);
                    (result.matrix[i])->setNumber( m + n , j );
                }
            }
        }
        return result;
    }

    bool Macierz::operator==(const Macierz & B) const {
        if ( (*this).matrixSize != B.matrixSize || (*this).vectorSize != B.vectorSize ) return false;
        for ( int i = 0; i < (*this).matrixSize; i++ )
            if ( (*((*this).matrix[i]) == *(B.matrix[i])) == 0 ) return false;
        return true;
    }

    bool Macierz::operator!=(const Macierz & B) const {
        if ( (*this).matrixSize != B.matrixSize || (*this).vectorSize != B.vectorSize ) return true;
        for ( int i = 0; i < (*this).matrixSize; i++ )
            if ( *((*this).matrix[i]) != *(B.matrix[i]) ) return true;
        return false;
    }

    Macierz & Macierz::operator+=(const Macierz & B) {
            (*this) = (*this) + B;
            return (*this);
    }

    Macierz & Macierz::operator-=(const Macierz & B) {
        (*this) = (*this) - B;
        return (*this);
    }

    Macierz & Macierz::operator*=(const int number) {
        (*this) = (*this) * number;
        return (*this);
    }

    Macierz & Macierz::operator/=(const int number) {
        (*this) = (*this) / number;
        return (*this);
    }

    Wektor& Macierz::operator[] (size_t index) {
        if(index >= 0 && index < (size_t)matrixSize && matrix != NULL) {
            return (*matrix)[index];
        }
        throw "\nBlad operatora [] macierzy 1\n";
    }

    const Wektor& Macierz::operator[] (size_t index) const {
        if(index >= 0 && index < (size_t)matrixSize && matrix != NULL) {
            return (*matrix)[index];
        }
        throw "\nBlad operatora [] macierzy 2\n";
    }



    int Macierz::operator()(const int vectorS, const int matrixS)
    {
        if ( vectorS < 0 || matrixS < 0 || vectorS > matrixSize || matrixS > vectorSize)
            throw "\nBlad operatora () macierzy \n";
        return (*(*(matrix + matrixS)))[vectorS];
    }

    Macierz operator*(const int number, const Macierz & B) {
        Macierz result( B.matrixSize, B.vectorSize );
        if ( result.matrix == NULL ) {
            result.matrixSize = 0;
            result.vectorSize = 0;
            throw "\nBlad operatora * macierzy (nie udalo sie utowrzyc macierzy)\n";
        }
        for ( int i = 0; i < B.matrixSize; i++ )
            *(result.matrix[i]) = *(B.matrix[i]) * number;
        return result;
    }

    Macierz operator/(const int number, const Macierz & B) {
        Macierz result( B.matrixSize, B.vectorSize );
        if ( result.matrix == NULL ) {
            result.matrixSize = 0;
            result.vectorSize = 0;
            throw "\nBlad operatora / macierzy (nie udalo sie utowrzyc macierzy)\n";
        }
        for ( int i = 0; i < B.matrixSize; i++ )
            *(result.matrix[i]) = *(B.matrix[i]) / number;
        return result;
    }

    ostream & operator<<(ostream & os, const Macierz & B) {
        if (B.matrix == NULL)
            throw "\nBlad operatora << macierzy\n";
        for (int i = 0; i < B.matrixSize; i++) {
                if ( i < B.matrixSize ) {
            cout << (*(*(B.matrix + i)));
            cout << endl;
                }
    }
    return os;
}
/*
    ostream & operator<<(ostream & os, const Macierz & B) {
        for (int i = 0; i < B.matrixSize; i++) {
            cout << '[';
            for (int j = 0; j < B.vectorSize - 1; j++) {
                cout << (*(*(B.matrix + i)))[j] << ',' << ' ';
            }
            cout << (*(*(B.matrix + i)))[B.vectorSize - 1] << ']' << endl;
    }
    return os;
}
*/
    istream & operator>>(istream & is, const Macierz & B) {
        if (B.matrix == NULL)
            throw "\nBlad operatora >> macierzy\n";
    for (int i = 0; i < B.matrixSize; i++)
        cin >> *(*(B.matrix + i));
    return is;
    }
