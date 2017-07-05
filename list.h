#ifndef LIST_H
#define LIST_H
#pragma once
#include "math.h"
#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;
//константа необходимая для сравнения вещественных чисел
const double eps = 1e-5;
const int I=10;



class my_list
{
    struct node {
        double data;
        int position;
        node* next;
        node* prev;
    };
    int sz;
    double def;
    node* begin;
    node* end;

public :

    //конструктор по умолчанию
    my_list() : sz(0), def(0), begin(nullptr), end(nullptr) {};
    //конструктор копии
    my_list(const my_list &l)
    {
        copy_list(l.begin, l.end);
    }

    // МЕТОДЫ

    // получение длины массива
    int length()
    {
        return this->sz;
    }
    //получение количества не пустых элементов
    int count_elem();
    //вывод не пустых элементов массива
    std::ostream &print_elem(std::ostream &os = std::cout);
    //метод foreach, применяющий функцию обработки для всех не пустых элементов массива
    void for_each(void (*f)(double &));


    // ПЕРЕГРУЖЕННЫЕ ОПЕРАТОРЫ

    // оператор доступа к элементам
    double operator[](int i)
    {
        if (i<1 || i>this->sz)
            throw "öut of range";
        node *t = this->begin;
        while (t != nullptr)
        {
            if (i == t->position)
                return t->data;
            t = t->next;
        }

        return this->def;
    }

    //деструктор
    ~my_list()
    {
        delete_list();
    }
    //ввод в поток

    friend std::istream& operator>> (std::istream& is, my_list& l)
    {

        double a;
        cout << "enter a unique value " << endl;
        is>>l.def;// ввод уникального значения
        l.sz = 0;// инициализация размера массива
        l.begin = nullptr;
        l.end = nullptr;

        int i;
        cout << "Enter the actual size of the array"<<endl;
        is >> i;
        for (int j = 0; j<i; ++j)
        {
            cout << "enter the value of array element" << endl;
            is >> a;
            ++l.sz; // в любом случае увеличиваем размер массива

            if (abs(a - l.def)>eps)
            {// если введенное значение отлично от уникального
                if (l.end == nullptr) {
                    l.end = new node;
                    l.end->prev=l.end->next = nullptr;
                    l.begin = l.end;
                }
                else {
                   l.end->next = new node;
                    l.end->next->prev = l.end;
                    l.end = l.end->next;
                }
               l.end->data = a;
               l.end->position = l.sz;
                l.end->next = nullptr;

            }

        }
        return is;
    }


    // вывод в поток
    friend std::ostream &operator<< (std::ostream &os, my_list &l)
    {
        l.print_elem(os);
        return os;
    }

    friend void solve_task ( my_list& l)
    {
//формирование указанного массива
        double a;
        l.def=0;
        l.sz = 0;
       // l.begin = nullptr;
       // l.end = nullptr;

        for (int j = 0; j<I; ++j)
        {

            a=rand();
            ++l.sz; // в любом случае увеличиваем размер массива
            if (abs(a - l.def)>eps)
            {// если введенное значение отлично от уникального
                if (l.end == nullptr) {
                    l.end = new node;
                    l.end->prev=l.end->next = nullptr;
                    l.begin = l.end;
                }
                else {
                   l.end->next = new node;
                    l.end->next->prev = l.end;
                    l.end = l.end->next;
                }
               l.end->data = a;
               l.end->position = l.sz;
                l.end->next = nullptr;

            }

        }
   //массив сформирован

    }

    // запишем его в файл
   friend void toFile(char *nameFile, my_list &arr)
      {
       ofstream fout;
       fout.open(nameFile);
       if(!fout.is_open()) throw "error";
       node *p=arr.begin;
       int sz_arr=0; //отвечает за размер записанного в файл массива
       int count_def;//отвечает за количество уникальных значений между записанными числами
       while(arr.begin)
       {
           cout<< arr.begin->data<<endl;
           cout<< arr.begin->position<<endl;
           if( arr.begin->position!=sz_arr+1)//если позиция элемента из списка не равна размерности массива, то надо дописать недостающие
               //уникальные элементы.
           {
               count_def= arr.begin->position-sz_arr-1;
               for(int i=0; i<count_def; ++i)
               {
                   fout<<arr.def;
                   fout<<' ';
                   ++sz_arr;
               }

          }
           fout<< arr.begin->data;
           fout<<' ';
           ++sz_arr;
       arr.begin=arr.begin->next;

       }
       fout.close();
    arr.begin=p;
   }


   friend void test_l ( my_list& l)
   {
   //формирование указанного массива
   double a=-1;
   l.def=0;
   l.sz = 0;

   // l.begin = nullptr;
   // l.end = nullptr;

   for (int j = 1; j<6; ++j)
   {
   ++l.sz; // в любом случае увеличиваем размер массив

   if ( (j==1||j==3||j==5))
   { a+=2;

   // если введенное значение отлично от уникального
   if (l.end == nullptr) {
   l.end = new node;
   l.end->prev=l.end->next = nullptr;
   l.begin = l.end;
   }
   else {
   l.end->next = new node;
   l.end->next->prev = l.end;
   l.end = l.end->next;
   }

   l.end->position = l.sz;
   l.end->next = nullptr;
   l.end->data = a;
   }
   }

   }

private :
    //вспомогательные функции удаления и копирования списка для деструктора и конструктора
    void delete_list()
    {
        if (begin != nullptr)
        {
            while (begin->next != nullptr) {
                node *t = begin;
                begin = begin->next;
                delete t;
            }
            delete begin;
            begin = end = nullptr;

        }
    }
    void copy_list(const node * from_first, const node * from_last);
};

// для проверки foreach будеи мспользовать функцию, прибавляющую 5 к своему параметру
inline void add_five(double &a)
{
    a += 5;

}

#endif // LIST_H

