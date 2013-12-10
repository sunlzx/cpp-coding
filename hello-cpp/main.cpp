#include <iostream>
#include <string>
#include <user.h>
#include <vector>
#include <algorithm>

#include "utility.h"
#include "mytest.h"

using namespace std;

void test_vector()
{
    vector<int> ids;
    int i;
    for(i = 0; i < 100; i++)
    {
        ids.push_back(i);
    }
    //
    cout <<  "size:" << ids.size() << endl;

    vector<int>::iterator iter1 = ids.begin();
    while(iter1 != ids.end()) {
        cout << *iter1 << " ";
        iter1 ++;
    }
    cout << endl;

    cout << "for" << endl;

    for(i =0; i < ids.size(); i++) {
        cout << ids[i] << " ";
    }
    cout << endl;

    //    vector<int>::iterator iter1 = v.begin();
    //     while( iter1 != v.end() && *iter1 % 2 != 0 ) {
    //       iter1++;
    //     }

}

void t_reference()
{
    int a ;
    int &b = a;    //b和a实际上是同一变量

    b = 100;       //b赋值为100，也就是a赋值为100
    cout << a << endl;

    //a的地址和b的地址应该是完全一样
    cout << &a << endl;
    cout << &b << endl;

    //-------▼下面代码有错，注释后才能运行▼-----------
//    int x[] = {12,15,20} ;
//    int &y = x;    //错误：数组、指针不能被引用

//    int x1;
//    int &y1;    //错误：引用时必须初始化
//    y1 = x1;
    //-------▲上面代码有错，注释后才能运行▲-----------
}


/**
 * @brief main
 * @return
 */
int main()
{
    cout << "Hello World!" << endl;

    //    test_template::test_template();
    //    test_class::test_class();
    //    test_class::test_static_class();
    //    test_struct::test_struct();

    //    mytest1::test_sizeof();
    //    mytest1::test_exec_cmd();
    //    mytest1::test_convert();
    //    mytest1::test_algorithm();

    //    test_vector();
    t_reference();

    return 0;
}

