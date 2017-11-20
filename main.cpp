#include <iostream>
#include "wektor.hpp"
#include "macierz.hpp"
#include <stdlib.h>

using namespace std;

int main ( void ) {
    try{
        Macierz A;
        Macierz B(6,5,7);
        Macierz C(6,5,2);
        Macierz D(3,6,2);
        Macierz E(B+C);
        Macierz F(3,4);

        cout << "A=\n" << A << endl << endl;

        cout << "dodawanie A=B+C" << endl;
        A=B+C;
        cout << "A=\n" << A << endl << endl;

        cout << "odejmowanie A=B-C" << endl;
        A=B-C;
        cout << "A=\n" << A << endl << endl;

        cout << "wykrzyknik A= !A" << endl;
        A= !A;
        cout << "A=\n" << A << endl << endl;

        cout << "mnozenie A=B*5" << endl;
        A=B*5;
        cout << "A=\n" << A << endl << endl;

        cout << "dzielenie A=A/2" << endl;
        A=A/2;
        cout << "A=\n" << A << endl << endl;

        cout << "przypisanie A=B" << endl;
        A=B;
        cout << "A=\n" << A << endl << endl;

        cout << "porownanie A==A, A==B i A==C" << endl;
        bool a = A==A, b = A==B, c = A==C;
        cout << "A==A " << boolalpha << a << "\nA==B " << b << "\nA==C " << c << noboolalpha << endl << endl;

        cout << "porownanie A!=A, A!=B i A!=C" << endl;
        a = A!=A, b = A!=B, c = A!=C;
        cout << "A!=A " << boolalpha << a << "\nA!=B " << b << "\nA!=C " << c << noboolalpha << endl << endl;

        cout << "mnozenie A=5*B" << endl;
        A=5*B;
        cout << "A=\n" << A << endl << endl;

        cout << "dodawanie A+=B" << endl;
        A+=B;
        cout << "A=\n" << A << endl << endl;

        cout << "odejmowanie A-=B" << endl;
        A-=B;
        cout << "A=\n" << A << endl << endl;

        cout << "mnozenie A*=5" << endl;
        A*=5;
        cout << "A=\n" << A << endl << endl;

        cout << "mnozenie A=D*C" << endl;
        A=D*C;
        cout << "A=\n" << A << endl << endl;

        cout << "dzielenie A/=2" << endl;
        A/=2;
        cout << "A=\n" << A << endl << endl;

        cout << "wypisywanie A[0][1]" << endl;
        cout << "A= " << A[0][1] << endl << endl;

        cout << "wpisywanie cin >> A" << endl;
        cin >> A;
        cout << "A=\n" << A << endl << endl;

    }

    catch(const char * s) {
        cout << s << endl;
        cout << "Koniec programu " << endl;
        exit(EXIT_FAILURE);
    }

    catch(bad_alloc & B) {
        cout << B.what() << endl;
        cout << "Koniec programu " << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
