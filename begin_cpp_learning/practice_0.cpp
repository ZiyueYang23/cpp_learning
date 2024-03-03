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
// c++中允许函数重名，需要注意的是形参必须不同（个数，类型）
// ！ 注意不能仅仅是返回值类型不同，编译器根据形参来判断你到底调用的是哪一个函数

//@ 函数模板
// 前面提及到在c++中函数可以同名，但是例如遇到要写Add这个函数有时候是int类型，有时候是double类型的
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

// class是类，是概念
// object是对象是具体实物从属于某类
// c++中对象是由对象构成，对象与另外对象的关系是告诉对方what to do而不是how to do，就是你要干啥不是怎么做，怎么做是你的事情，我告诉你我只是传达指令，传递信息。所有对象都有类型，所有可以归类的对象都具有相应的特征。反过来几个对象都有同一特征我们把它归类
// 所有目录名文件用字母用小写_来链接
// 类的名字首字母都大写

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

#if 0
//命名空间注释代码
namespace my_namespace
{
    int number;
    double val;

    // 这里是在命名空间内部进行函数定义
    void Func_1()
    {
        cout << number << endl;
    }

    // 此处是声明，如果说我想拿到命名空间外面去定义函数该如何做呢
    void Func_2();

    // 同理还可以继续嵌套命名空间，但是注意不能在主函数里面进行定义命名空间

    // 注意最后是没有;的，与struct不同。
}

namespace my_namespace
{
    // 这里与上面的定义同属于my_namespace，可以分开定义
    char ch;
}

// 注意此时Func_2与内部并无关系，两个是不同的函数
void Func_2()
{
    cout << "hello world!" << endl;
}

// 如果在命名空间外要定义函数需要用::,此时定义的就是上述命名空间里的函数
void my_namespace::Func_2()
{
    cout << "hello world!" << endl;
}

#endif

#if 0
//new and delete

#include <iostream>

using namespace std;

int main(void)
{
    //第一种形式
    int *p_number_1 = new int;   ///< new返回值是一个地址
    *p_number_1 = 1;
    cout << *p_number_1 << endl;

    //第二种形式
    int *p_number_2 = new int(2);   ///<在定义时就完成初始化
    cout << *p_number_2 << endl;

    //第三种形式
    int *p_number_arr = new int[10];   ///<注意这个地方就不能在加（）给初始值了

    for (int i = 0; i < 10; i++)
    {
        p_number_arr[i] = i;
        cout << p_number_arr[i] << " ";
    }

    delete p_number_1;
    delete p_number_2;
    delete[] p_number_arr;   ///<这个地方注意批量删除时需要加delete[] ...，并且需要注意的时后面跟的必须是申请的首地址。

    return 0;
}

#endif

#if 0
#include <iostream>
#include <string>

using namespace std;

class People
{
public:
    string name_str_;
    int age_;

    // 此处去类外面完成函数定义
    void SpeakMyName();
    void SetWeight(int weight)
    {
        weight_kg_ = weight;
    }

private:
    int height_;
    int weight_kg_;

    void SpeakMyHeight()
    {
        cout << "My height is " << height_ << endl;
    }
};

// 注意此处需要加People，否则为全局函数。
void People::SpeakMyName()
{
    // 此处在类外部也可以用weight_kg_,函数体也算类里。
    cout << "My name is " << name_str_ << ",My weight is " << weight_kg_ << "kg." << endl;
}

int main(void)
{
    People z_y;
    z_y.name_str_ = "z_y";
    z_y.age_ = 18;
    // 此处只能通过加一个函数来动私有的变量
    z_y.SetWeight(70);
    z_y.SpeakMyName();

    // 也可以通过指针来使用
    People *p_z_y = &z_y;
    p_z_y->age_ = 19;
    p_z_y->SetWeight(65);

    return 0;
}

#endif


#if 0
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string text_str;
    char ch;

    // 可以直接等于
    text_str = "That is so coll";
    // 可以直接根据下表进行访问 
    ch = text_str[0];
    cout << ch << endl;
    // 这个是输出第几个值
    ch = text_str.at(1);
    cout << ch << endl;
    // 这个是计算长度
    cout << text_str.length();
    // 这个是帮忙清空字符串
    text_str.clear();
    // 这个是判断是否为空
    text_str.empty();


    return 0;
}

#endif


#if 1
#include <iostream>

using namespace std;

class MyClass
{
public:
    int num;
    MyClass()
    {
        cout << "MyClass" << endl;
    }
    MyClass(int n, int v);

private:
    int val;
};

// 注意此处从类调用构造函数
MyClass::MyClass(int n,int v)
{
    cout << "MyClass::MyClass()" << endl;
}
int main(void)
{
    MyClass learn_text_0;        ///< 这叫无参构造，注意此处不能加括号，尽管你括号里面不传值，想着调用那个 MyClass() 函数，结果是不会调用。(why?)
    MyClass learn_text_1(1,2);   ///<这叫有参构造，后面加一个括号就直接把两个变量给完成初始化，是在对象创造完之后就会调用。
}

#endif