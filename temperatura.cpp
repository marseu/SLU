#include<iostream>
using namespace std; 

class Temperatura
{
private:
	double temp; // w kelwinach
public:
	Temperatura(double temp = 0);
	void ustawKelwiny(double t);
	void ustawCelcjusze(double t);
	double pokazKelwiny();
	double pokazCelcjusze();
	Temperatura operator+(const Temperatura& t);
	Temperatura operator=(const Temperatura& t);
	friend ostream &operator<<(ostream& os, const Temperatura& t);
};

Temperatura::Temperatura(double t)
{
	temp = t;
}

void Temperatura::ustawKelwiny(double t)
{
	temp = t;
}

void Temperatura::ustawCelcjusze(double t) 
{
	temp = t+273;
}

double Temperatura::pokazKelwiny()
{
	return temp;
}

double Temperatura::pokazCelcjusze()
{
	return temp - 273;
}

Temperatura Temperatura::operator+(const Temperatura& t) 
{
	Temperatura result;
	result.temp = this->temp + t.temp;
	return result;
}

Temperatura Temperatura::operator=(const Temperatura& t)
{
	if(this!=&t)
	{
		temp = t.temp;
	}
	return *this; 
}

ostream &operator<<(ostream& os, const Temperatura& t)
{
	os << t.temp;
	return os;
}


int main()
{
    Temperatura pierwsza;
    Temperatura druga(373);
    pierwsza.ustawKelwiny(10);
    cout << "Pierwsza C: " << pierwsza.pokazCelcjusze() << " K: " << pierwsza.pokazKelwiny() << endl;
    cout << "druga C: " << druga.pokazCelcjusze() << " K: " << druga.pokazKelwiny() << endl;
    Temperatura wynik = pierwsza + druga;
    cout << "pierwsza + druga C: " << wynik.pokazCelcjusze() << " K: " << wynik.pokazKelwiny() << endl;
    pierwsza = druga; 
    cout << "Pierwsza C: " << pierwsza.pokazCelcjusze() << " K: " << pierwsza.pokazKelwiny() << endl;
    cout << "druga C: " << druga.pokazCelcjusze() << " K: " << druga.pokazKelwiny() << endl;
 
    cout << wynik;
    return 0;
}



