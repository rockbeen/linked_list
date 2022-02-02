/*
 * Copyright (c) 2017 Tecom LLC
 * All rights reserved
 *
 * Исключительное право (c) 2017 принадлежит ООО Теком
 * Все права защищены
 */

#include "list.hpp"


template <class T>
void List<T>::swap_list() {//expand the list
       if(is_empty()) return;

      item<T>* reversed_list = NULL;

      for ( item<T> *node = first, *next_node; node != NULL; node = next_node)
      {
        next_node = node->next;
        node->next = reversed_list;
        reversed_list = node;
      }

      first=reversed_list;

}
template <class T>
item<T> List<T>::read_item() {
    if(!is_empty()) return first->data;

}
template <class T>
bool List<T>::is_empty() {
    return first == nullptr;
}
template <class T>
void List<T>::add_item(T node)//adding an item to the end of the List
{

    item<T>* newitem= new item<T>;
    newitem->data=node;
    newitem->next=first;
    first=newitem;
    ++size;

    }

template <class T>
void List<T>::delete_item()//deleting to end of List
{
    if(is_empty()) return;
    item<T>* current=first->next;
    delete first;
    first=current;
    --size;

    }
template <class T>//display all elements on the screen
void List<T>::display()
{
    if(is_empty()) return;
    item<T>* current=first;
    while(current!=nullptr)
    {
        std::cout<<current->data<<std::endl;
        current=current->next;
        }
    }

template <class T>
List<T>::~List()//Destructor
{
        item<T>* currentNode = this->first;
        while (currentNode)
        {
            item<T>* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }


}
template <class T>
void List<T>:: remove(T val) {//deleting all elements equal to a certain one

    if (is_empty()) return;
    item<T>* currentNode = first;
    while(currentNode)
    {
        if (first->data == val) {
              item<T>* p = first;
              first = p->next;
              delete p;

        }
        else{


            item<T>* slow = first;
            item<T>* fast = first->next;
            while (fast && fast->data != val) {
                fast = fast->next;
                slow = slow->next;
            }
            if (!fast)  return;

            slow->next = fast->next;
            delete fast;
        }
     }
}
template <class T>
List<T>::List(const List& copy):size(0),first(nullptr)
  {
      item<T> * last = nullptr;
      for(item<T> * n = copy.first; n != nullptr; n = n->next)
      {
           item<T> * node = new item<T>(n->data);
           if(!first)
           {
               first = node;
           }
           else
           {
               last->next = node;
           }
           last = node;
           ++size;
      }
  }

template <class T>
List<T>& List<T>::operator=(const List<T>& other)//Copy assignment operator
{
    List(other).swap(*this);
    return *this;
}
template <class T>
void List<T>::swap(List<T>& other)
{
       std::swap(size, other.size);
       std::swap(first, other.first);
}

template <class T>
void swapList(List<T>& left,List<T>& right)
{
       item<T> *node=left.first;
       int size=left.size;
       left.first=right.first;
       left.size=right.size;
       right.first=node;
       right.size=size;



}



