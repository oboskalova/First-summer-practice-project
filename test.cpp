#include "test.h"
#include <iostream>
#include <cassert>

using namespace std;
int test::t_length(bool first)
{
    my_list ll;
    if (first)
    test_l(ll);
    return ll.length();

}

bool test::index(int i)
{
    my_list ll;
    test_l(ll);
    try
    {
        ll[i];
         return true;
     }
catch(char *c)
     {

    }
    return true;

}

