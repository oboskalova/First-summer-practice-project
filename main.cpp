//#include "crtdynmem.h"
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#endif
#include <crtdbg.h>
#include "list.h"
#include <iostream>
using namespace std;


int main()
{

    setlocale(LC_ALL, "ru");

    {

        my_list arr;
        cin >> arr;
        try{
        cout << arr;
        }
        catch (const char *c)
        {
            cout<<c<<endl;
        }
       cout << "length=" << arr.length() << endl;
       cout << "count=" << arr.count_elem() << endl;
        cout << endl;
        try{
        arr.print_elem();
        }
        catch (const char *c)
        {
            cout<<c<<endl;
        }
double d=5;
arr.for_each(add_five);
        cout << endl;
        try{
        cout << "i=5     data=" << arr[5] << endl;// work
        cout << "i=4     data=" << arr[4] << endl;// work
        }
        catch (const char *c)
        {
            cout<<c<<endl;
        }

        system("pause");
    }
      _CrtDumpMemoryLeaks();


      _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
       _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );

    return 0;
}
