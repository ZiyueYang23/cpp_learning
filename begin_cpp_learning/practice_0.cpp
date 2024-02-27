#include <iostream>
#include <cmath>

using namespace std; // std也是一个命名空间使用这个就是方便后面的cout，cin等等不用再std::了

namespace Yangziyue
{
    int a = 9;
}

//@ using Yangziyue::a;
// 这也是一种表达方式

// void Swap(int &a, int &b);
void Swap(int &a, int &b);

// inline int Add(int a, int b);
// inline 这个叫内联函数，目的是提高效率，叫内联展开，即当遇到较为简单的函数时，编译器直接在编译时将Add函数展开
// 换成return的那个值即直接换成a+b，减少函数调用时浪费效率。c++一台追求性能的猛兽可见一斑
void AndOne(int a, int b);

int a = 1;

int main()
{

    int a = 8;
    int &b = a;

    b = 10;
    cout << a << endl; // b想当于a的别名，a就是b。
    // 应用

    int x = 10, y = 1;

    Swap(x, y); // 这里函数直接传x，y进去就行，然后在函数接收时&a，&b，引用此时a就是x，b就是y，修改a就是改x
    // 这玩意类似指针传地址进去，目的就是当实参所占内存很大时可以提高效率
    // 当你不想传进去的值修改时，同样可以加上const

    // cout << Add(x, y) << endl;

    AndOne(x, y);

    cout << Yangziyue::a << endl; // 命名空间，用于区别变量同名
    {
        int a = 3;
        cout << a << endl;
        cout << ::a << endl; // 这个地方是全局引用a
    }
    cin >> a;                           // 键盘输入
    cout << "hello world" << a << endl; // 屏幕输出

    return 0;
}

void Swap(int &a, int &b)
{
    cout << a << " " << b << endl;

    int temp = a;
    a = b; // 改为const之后这里会报错此时a也就是外面的x的值不能被修改。
    b = temp;

    cout << a << " " << b << endl;
}

// int Add(int a, int b)
// {
//     return a + b;
// }

// c++中传参进去再函数定义时可以对形参进行再次赋值，但必须要注意所赋值的变量必须在最右边
void AndOne(int a, int b = 1)
{
    cout << a + b << endl;
}

//@ 函数重载
//c++中允许函数重名，需要注意的是形参必须不同（个数，类型）
//！ 注意不能仅仅是返回值不同，编译器根据形参来判断你到底调用的是哪一个函数
