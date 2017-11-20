#include<iostream>
#include<exception>
#include<stdexcept>

using namespace std;

template<typename DT> class List;
template<typename DT>
class ListNode
{
private:
    friend class List<DT>;
    ListNode(const DT &data, ListNode *priorPtr, ListNode *nextPtr ) : Item(data), prior(priorPtr), next(nextPtr){};
    DT Item;
    ListNode *prior, *next;
};	

template<typename DT>
class List
{
private:
	ListNode<DT> *Cursor;
    ListNode<DT> *Head;
public:
    List() : Head(nullptr), Cursor(nullptr){};
    ~List();
    void insert(const DT &newDataItem ); //throw ( bad_alloc )
    bool isEmpty() const { return Head == nullptr; }
    void gotoBeginning(); //throw ( logic_error )
    void gotoEnd(); //throw ( logic_error )
    void gotoNext();
    void gotoPrior();
    DT getCursor() const {return Cursor->Item;}
    ListNode<DT> * getPtrC(){ return Cursor; }
    void remove(); //throw ( logic_error )
    void replace( const DT &newDataItem ){ Cursor->Item = newDataItem; } //throw ( logic_error )
    void clear();
    void showStructure () const;
    void Show() { cout << Cursor->Item << endl;}
};

template<typename DT>
List<DT>::~List()
{
    clear();
}

template<typename DT>
void List<DT>::insert(const DT &newDataItem )
{
    if(Head == nullptr)
    {
		Head = new ListNode<DT>(newDataItem, Head, Head);
    }
    else
    {
        ListNode<DT> *temp = new ListNode<DT>(newDataItem, Cursor, Head);
        Cursor->next = temp;
        Cursor = temp;
        Head -> prior = Cursor;
    }
}

template<typename DT>
void List<DT>::gotoBeginning()
{
    try
	{
		if(Head!=nullptr)
		{
            Cursor = Head;
        }
		else
		{
			string msg = "gotoBeginning message: Lista jest pusta!\n";
			throw msg;
		}
	}
	catch(string& msg)
	{
		std::cout << msg;
	}
}	

template<typename DT>
void List<DT>::gotoEnd()
{
    try
	{
		if(Head!=nullptr)
		{
            for(Cursor = Head; Cursor->next!=Head; Cursor = Cursor->next);
        }
		else
		{
			string msg = "gotoend() message: Lista jest pusta!\n";
			throw msg;
		}
	}
	catch(string& msg)
	{
		std::cout << msg;
	}
}

template<typename DT>
void List<DT>::gotoNext()
{
   try
   {
		if(Cursor!=nullptr)
		{
           Cursor = Cursor->next;
        }
		else
		{
			throw logic_error("gotoNext message: Kursor nie pokazuje na nic ");
        }
    }
    catch(logic_error &logic)
    {
        cout << logic.what() << endl;
    }
}

template<typename DT>
void List<DT>::gotoPrior()
{
    try
	{
		if(Cursor!=nullptr)
		{
           Cursor = Cursor->prior;
        }
		else
		{
            throw logic_error("gotoPrior message: Brak elementu poprzedniego!\n");
        }
    }
    catch(logic_error &le)
    {
        cout << le.what() << endl;
    }
}

template<typename DT>
void List<DT>::remove()
{
	int x=0;
    if(Cursor == Head) x=1;
    ListNode<DT> *temp = Cursor->prior;
    temp->next = Cursor->next;
    temp = Cursor->next;
    temp->prior = Cursor->prior;
    temp = Cursor->prior;
    delete Cursor;
    Cursor = temp;
    if(x==1)
        Head = Cursor;
    cout << "Usuniêto\n" << "Wskazywany element:" << getCursor() << endl;
}

template<typename DT>
void List<DT>::clear()
{
    try{
        if(Head == nullptr)
		{
            throw logic_error("clear message: Lista pusta. Nie ma czego wyczyscic!\n");
        }
        auto cursor = Head->next;
        while(cursor != Head)
		{
            auto temp = cursor->next;
            delete cursor;
            cursor = temp;
        }
        delete cursor;
    }
    catch(logic_error &logic)
    {
        cout << logic.what() << endl;
    }
}

template<typename DT>
void List<DT>::showStructure() const
{
    if(isEmpty())
	{
        cout << "showStructure message: Lista pusta!\n";
        return;
    }
    auto cursor = Head;
    do
    {
        cout << cursor->Item << " ";
        cursor = cursor->next;
    }
    while(cursor != Head);
    cout << endl;
}

class Puzzle
{
private:
	List<char> solution; // rozwi¹zanie  puzzli
	List<char> puzzle; //  konfiguracja liter
	int dlugosc;
public:
	Puzzle( string &answ, string &init ); // Konstruuje puzzle
	void shiftLeft();
	void swapEnds();
	void display();
	bool isSolved();
	void reverse();
};

Puzzle::Puzzle(string &answ, string &init)
{
    dlugosc = answ.length();
    int i=0;
    while(i<dlugosc)
    {
        solution.insert(char(answ[i]));
        puzzle.insert(char(init[i]));
        i++;
    }
        solution.gotoBeginning();
        puzzle.gotoBeginning();
}

void Puzzle::reverse()
{
    for(int i=0; i<dlugosc/2; i++)
    {
        int k=0;
        while(k++<i)
        {
            puzzle.gotoNext();
        }
        char temp = puzzle.getCursor();
        puzzle.gotoEnd();
        k=0;
        while(k++<i)
        {
            puzzle.gotoPrior();
        }
        char temp2 = puzzle.getCursor();
        puzzle.replace(temp);
        puzzle.gotoBeginning();
        k=0;
        while(k++<i)
        {
            puzzle.gotoNext();
        }
        puzzle.replace(temp2);
        puzzle.gotoBeginning();
    }
}

void Puzzle::shiftLeft()
{
    int x,i=1;
    cout << "Ktory element chcesz przesunac w lewo?\n";
    cin >> x;
    while(i++ < x)
	{
	   puzzle.gotoNext();    
	}
    char temp = puzzle.getCursor();  
    puzzle.gotoPrior();              
    char temp2 = puzzle.getCursor(); 
    puzzle.replace(temp);           
    puzzle.gotoNext();              
    puzzle.replace(temp2);         
}

void Puzzle::swapEnds()
{
    puzzle.gotoBeginning();           
    char first = puzzle.getCursor();  
    puzzle.gotoEnd();                   
    char last = puzzle.getCursor();    
    puzzle.replace(first);             
    puzzle.gotoBeginning();             
    puzzle.replace(last);               
}

bool Puzzle::isSolved()
{
    puzzle.gotoEnd();
    auto end = puzzle.getPtrC();      
    puzzle.gotoBeginning();
    auto cursor1 = puzzle.getPtrC();   
    auto cursor2 = solution.getPtrC(); 
    while(cursor1 != end) // petla przestaje dzialac kiedy porownywane wartosci sa od siebie rozne - funkcja zwraca false. 
							//Jesli petla przejdzie przez cala liste - funkcja zwroci true
    {
        if(puzzle.getCursor() != solution.getCursor())
		{
            puzzle.gotoBeginning();
            solution.gotoBeginning();
            return false;
        }
        solution.gotoNext();
        puzzle.gotoNext();
        cursor1 = puzzle.getPtrC();
    }
    cout << "Wygrales!\n";
    return true;
}

void Puzzle::display()
{
    puzzle.showStructure();
}


using namespace std;
int main()
{
    string answ, init;
    cout<<"Podaj lancuch bedacy odpowiedzia: "<<endl;
    cin>>answ;
    cout<<"Podaj lancuch pomieszany: "<<endl;
    cin>>init;
    cout<<"dziala"<<endl;
    Puzzle Gra(answ,init);
    cout<< "Zmieniony lancuch: \n"<<endl;
    Gra.display();
    int x;
    while(!Gra.isSolved())
    {
        cout<<"Wybierz opcjê:\n\n 1. reverse \n 2. Shift left\n 3. Swap Ends\n 4. Display\n 5.Quit"<<endl;
        cin>>x;
        switch(x)
        {
        case 1:
            Gra.reverse();
            break;
        case 2:
            Gra.shiftLeft();
            break;
        case 3:
            Gra.swapEnds();
            break;
        case 4:
            Gra.display();
            break;
        default:
            cout<<"ZAKONCZ"<<endl;
            return 0;
        }
        Gra.display();
    }
    return 0;
}

