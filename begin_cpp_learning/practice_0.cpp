#if 0

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

#endif


//@ 函数重载
//c++中允许函数重名，需要注意的是形参必须不同（个数，类型）
//！ 注意不能仅仅是返回值类型不同，编译器根据形参来判断你到底调用的是哪一个函数

//@ 函数模板
//前面提及到在c++中函数可以同名，但是例如遇到要写Add这个函数有时候是int类型，有时候是double类型的
#if 0
#include <iostream>
#include <string>

using namespace std;

int Add(int a, int b);
double Add(double a, double b);

int main(void)
{
    cout << Add(5, 3) << endl;
    cout << Add(5.4, 4.3) << endl;
    // cout << Add(5, 4.3) << endl;
    //！ error，此处有歧义编译器不知用哪一个函数需要强转
    // cout << Add("hello world!") << endl;
    //！ 这里就是如果你需要有很多类型但是函数功能相同的情况，就会出现很多重复并且影响代码维护
}

int Add(int a,int b)
{
    return a + b;
}
double Add(double a,double b)
{
    return a + b;
}
//上述代码就是展现弊端引出函数模板
#endif


#if 0
#include <iostream>
#include <string>

using namespace std;

template <typename T>
T Add(T a, T b)
{
    return a + b;
}

int main(void)
{
    cout << Add<int>(5, 4) << endl;
    cout << Add<double>(5.5, 4.5) << endl;
    cout << Add<string>("hellow ","world!") << endl;

    cout << Add(5, 3) << endl;
    cout << Add(5.5, 3.3) << endl;
    //@ 这里可知就算你不给出明确的类型编译器也会帮助你猜出类型，然后创造出对应类型的函数给你使用
    // cout << Add("hello ","world") << endl;
    //！但是需要注意字符串时编译器猜不出来。

}

#endif


//class是类，是概念
//object是对象是具体实物从属于某类
//c++中对象是由对象构成，对象与另外对象的关系是告诉对方what to do而不是how to do，就是你要干啥不是怎么做，怎么做是你的事情，我告诉你我只是传达指令，传递信息。所有对象都有类型，所有可以归类的对象都具有相应的特征。反过来几个对象都有同一特征我们把它归类
//所有目录名文件用字母用小写_来链接
//类的名字首字母都大写
//函数小驼峰，动词＋名词的形式



#if 0
//函数参数缺省代码片段
#include <iostream>

using namespace std;

void maxScore(int subject1, int subject2, int subject3 = 0);

int main(void)
{
    int subject1 = 0;
    int subject2 = 0;
    int subject3 = 0;

    cout<< "请输入三门课程的成绩:>";
    cin >> subject1 >> subject2 >> subject3;

    maxScore(subject1, subject2);
    maxScore(subject1, subject2,subject3);

    return 0;
}

void maxScore(int subject1, int subject2, int subject3)
{
    //！ 这里注意在函数声明时设置默认值，在函数定义时就直接写三个变量即可。
    int max = 0;
    max = subject1 > subject2 ? subject1 : subject2;
    max = max > subject3 ? max : subject3;

    cout << max << endl;
}

#endif

