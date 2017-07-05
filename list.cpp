#include "list.h"
#include <iostream>
#include <cmath>
#include <fstream>
//#include "crtdynmem.h"

using namespace std;


//получение количества не пустых элементов
int my_list::count_elem()
{
    int count = 0;
    if (begin != nullptr)
    {
        node *t = begin;
        while (t != nullptr) {
            ++count;
            t = t->next;

        }
    }
    return count;
}

//вывод не пустых элементов массива
std::ostream &my_list::print_elem(std::ostream &os)
{
   if (this->begin == nullptr)
        throw "this array is empty";
     node *t = this->begin;
    while (begin != nullptr) {
           os << begin->data << ' ';
           begin = begin->next;
       }
       os << endl;
       begin=t;
    return os;
}

//метод foreach, применяющий функцию обработки для всех не пустых элементов массива
void my_list::for_each(void (*f)(double &))
{
    node *t = this->begin;
    int s=0;
    int count_def;
    while (t->next != nullptr) {
        if(t->position!=s+1){
           count_def=t->position-(s+1);
           for(int i=0; i<count_def;++i){
               ++s;
               f(t->data);
           }
        }
        f(t->data);
        t = t->next;
        s++;
    }
}




// копирование списка (для консруктора копии)
void my_list::copy_list(const node * from_first, const node * from_last)
{
    begin = nullptr;
    end = nullptr;
    node **to = &begin;
    const node *from = from_first;
    while (from != from_last->next) {
        node *prev = *to;
        *to = new node;
        (*to)->prev = prev;
        (*to)->data = from->data;
        (*to)->position = from->position;
        to = &(*to)->next;
        from = from->next;
    }
    *to = nullptr;
    end = *to;
}


