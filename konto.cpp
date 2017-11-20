
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class Konto
{
private:
	string depozytariusz;
	string numer;
	double saldo;

public:
	Konto();
	Konto(const Konto&);
	Konto(string dep, string nr, double sal);
	~Konto();
	void wyswietlDepozytariusz();
	void wyswietlNumer();
	void wyswietlSaldo();
	void wyswietlInformacje();
	void dodajKwote(double kwota);
	void wyplacKwote(double kwota);
	int zwrocSaldo();
	Konto operator+=(Konto & Konto2);
	Konto operator*=(double stopaProcentowa);
};

Konto::Konto(string dep, string nr, double sal)
{
	depozytariusz = dep;
	numer = nr;
	saldo = sal;
}

Konto::Konto(const Konto& K)
{
	depozytariusz = K.depozytariusz;
	numer = K.numer;
	saldo = K.saldo;
}

Konto::~Konto()
{
}

void Konto::wyswietlDepozytariusz()
{
	cout << "Depozytariusz: " << depozytariusz << "\n";
}

void Konto::wyswietlNumer()
{
	cout << "numer konta: " << numer << "\n";
}

void Konto::wyswietlSaldo()
{
	cout << "aktualne saldo: " << saldo << "\n";
}

void Konto::wyswietlInformacje()
{
	wyswietlDepozytariusz();
	wyswietlNumer();
	wyswietlSaldo();
}

void Konto::dodajKwote(double kwota)
{
	cout << "wplacam kwote: " << kwota << "\n";
	saldo += kwota;
}

void Konto::wyplacKwote(double kwota)
{
	if(saldo < kwota)
	{
		cout << "nie masz wystarczajaco srodkow \n";
	}
	cout << "wyplacam kwote: " << kwota << "\n";
	saldo -= kwota;
}

int Konto::zwrocSaldo()
{
	return saldo;
}

Konto Konto::operator+=(Konto & Konto2)
{
	this->saldo += Konto2.saldo;
	Konto2.saldo = 0;
	return *this;
}

Konto Konto::operator*=(double stopaProcentowa)
{
	this->saldo *= (1.0 + stopaProcentowa);
	return *this;
}

int main()
{
    Konto konto1("PKO", "12 3456 7890 1234 5678", 10000);
    konto1.wyswietlInformacje();
    konto1.dodajKwote(500);
    konto1.wyplacKwote(100);
    konto1.wyswietlSaldo();
    cout << "\n";
    Konto konto2("ING", "12345678887654321", 4012);
    konto2.wyswietlInformacje();
    konto1 += konto2;
    konto1.wyswietlSaldo();
    konto2.wyswietlSaldo();
    konto1 *= 0.12;
    konto1.wyswietlSaldo();
    return 0;
}

