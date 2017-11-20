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
