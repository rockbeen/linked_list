#include <iostream>
template <class T>
struct item
{
    T data;
    item* next;

    item<T>(T data = T(), item<T> *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};
template <class T>
class List
{
    private:
        item<T>* first;
        int size;
        void swap(List<T>& src);
    public:

        List(){
            first=nullptr;
            size=0;
        }
        ~List();
        List(const List & );
        bool is_empty();
        void add_item(T );
        void display();
        void swap_list();
        void delete_item();
        void remove(T);
        item<T> read_item();
        List<T>& operator=(const List<T>& );
        template <class L> friend void swapList(List<L>& left,List<L>& right);
    };
