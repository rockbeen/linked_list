#include <iostream>
using namespace std;
template <class T>
struct item
{
	T data;
	item* next;
	};
template <class T>
class list
{
	private:
		item<T>* first;
		int size()//the size
		{
			item<T>* current=first;
			int i=0;
			while(current!=NULL)
			{
				i++;
				current=current->next;
		
				}
			return i;
			}
	public:
		
		list()
		{first=NULL;}
		~list();
		list(const list & );//Default Constructor
		void add_item(T );
		void display();
		void delete_item_end();
		void show_size();
		void display_last();
		void deleting_equals(T d);
		list<T>& operator=(const list<T>& );
	};
template <class T>
void list<T>::add_item(T d)//add to top of list
{
	
	item<T>* newitem= new item<T>;
	newitem->data=d;
	newitem->next=first;
	first=newitem;
	
	}

template <class T>
void list<T>::delete_item_end()//deleting to end of list
{
	item<T>* current=first->next;
	delete first;
	first=current;
	
	}
template <class T>//display all elements on the screen
void list<T>::display()
{
	item<T>* current=first;
	while(current!=NULL)
	{
		cout<<current->data<<endl;
		current=current->next;
		}
	}
template <class T> 
void list<T>::display_last()//Reading the last element
{

	cout<<first->data<<endl;

	}
template <class T> 
list<T>::~list()//Destructor
{
    item<T>* current=first;
    item<T>* current2;
	while(current!=NULL)
	{
		current2=current->next;
		delete current;
		current=current2;
		
		}
   
}
template <class T> 
void list<T>::deleting_equals(T d)//Deleting all list items equal to the one passed
{
	item<T>* current=first;

	if (current->data==d)
	{
		current=first->next;
		delete first;
		first=current;
		
		}
	else
	{
		while(current!=NULL)
		{
			if (current->data==d)
				{
					bool button=true;
					item<T>* current2=first;
					while(button)
					{
						if((current2->next)==current)
						{
							current2->next=current->next;
							delete current;
							button=false;
							}
						if (current2->next!=NULL) current2=current2->next;
						}
					current=current2;
					}
			current=current->next;
			}
		}
   
}
template <class T> 
void list<T>::show_size()//Reading the size
{
	cout<<size()<<endl;	
	}
template <class T> 
list<T>::list(const list & other)//Copy Constructor
{
		first= other.first;
	}

template <class T>
list<T>& list<T>::operator=(const list<T>& other)//Copy assignment operator
{
    first =other.first;
    return *this;
}

 int main()
{
 return 0;
}

