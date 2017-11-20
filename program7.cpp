#include<iostream>
#include<iterator>
#include<queue>
#include<vector>

using namespace std;

template <typename Iter>
void wypisuj_na_cout(Iter it, int n)
{
	cout<<"Wypisanie po otrzymaniu iteratora na element. Liczba elementow: "<< n+1 <<"\n"<<endl;
	for(int i = 0 ; i<=n ; i++, it++)
	{
    	cout<<*it<<endl;
    }
	cout<<"\n\n";
}

template <typename Container>
void wypisuj_na_cout(const Container &c)
{
	cout<<"Wypisanie po otrzymaniu kontenera danych:\n"<<endl;
	typename Container::const_iterator pt;
	for(pt =c.begin(); pt!=c.end(); pt++)
    cout << *pt << endl;
	cout<<"\n\n";
}

template <typename Iter>
void wypisuj_na_cout(Iter begin, Iter end)
{
	cout<< "Wypisanie po otrzymaniu iteratorow na begin i end:\n" << endl;
	for(Iter pt = begin; pt!=end; pt++)
	{
    	cout<<*pt<<endl;
    }
	cout<<"\n\n";
}

template<typename T>
class oprocz_pierwszego
{
	public:
		bool operator() (T n)
		{
			if(n>1) return true;
			else return false;
		}
};

template<typename T>
class tylko_parzyste
{
public:
	bool operator() (T n) 
	{
		if(n%2 == 0) return true;
		else return false;
	}
};

template<typename Iter>
class wstaw_jeden
{
public:
	void operator() (Iter it)
	{
		cout<<"Za element podstawiam jeden!"<<endl;
		*it=1;
	}
};

template <typename Iter, typename Cond, typename Oper>
void zrealizuj_dla_spelniajacych(Iter poczatek, Iter za_koncem, Cond warunek, Oper czynnosc)
{
    cout<<"\t\t realizuje tylko dla spelniajacych\n\n"<<endl;
    while(poczatek!=za_koncem)
    {
		if(warunek(*poczatek))
        {
			cout<<*poczatek<<" : ";
			czynnosc(poczatek);
        }
        poczatek++;
    }
}

int main()
{
	oprocz_pierwszego<int> funktor_warunku;
	tylko_parzyste<int> funktor_warunku2;
	wstaw_jeden<vector<int>::iterator> funktor_operacji;
	const int MAX = 10;
	vector<int> wektor;
	for(int i=0;i<MAX;i++)
	{
		wektor.push_back(i);
	}
	vector<int>::iterator It = wektor.begin();
	int n = wektor.size();
	cout<<"Rozmiar wektora:    "<< n <<"\n"<<endl;
	wypisuj_na_cout(wektor.begin(), wektor.end());
	wypisuj_na_cout(It,4);
	zrealizuj_dla_spelniajacych(wektor.begin(),wektor.end(),funktor_warunku,funktor_operacji);
	wypisuj_na_cout(wektor.begin(), wektor.end());
	vector<int> wektor2;
	for(int i=0;i<MAX;i++)
	{
        wektor2.push_back(i);
	}
	int n2 = wektor2.size();
	zrealizuj_dla_spelniajacych(wektor2.begin(),wektor2.end(),funktor_warunku2,funktor_operacji);
	wypisuj_na_cout(wektor2.begin(), wektor2.end());
	return 0;
}
