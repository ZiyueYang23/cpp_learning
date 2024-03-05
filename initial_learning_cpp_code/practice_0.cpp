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

#if 0
#include <iostream>

using namespace std;

class MyClass
{
public:
    int num;
    MyClass()
    {
        // 这里给初始化的值
        num = 99;
        val = 98;
        cout << "MyClass" << endl;
    }
    MyClass(int n, int v = 3);   ///< 也可以使用参数缺省

private:
    int val;
};

// 注意此处从类调用构造函数
MyClass::MyClass(int n,int v)
{
    // 传值进去给初始值
    num = n;
    val = v;
    cout << "MyClass::MyClass()" << endl;
}
int main(void)
{
    MyClass learn_text_0;        ///< 这叫无参构造，注意此处不能加括号，尽管你括号里面不传值，想着调用那个 MyClass() 函数，结果是不会调用。(why?)
    learn_text_0.num = 100;

    // 参数缺省
    MyClass learn_text_1(1);   ///<这叫有参构造，后面加一个括号就直接把两个变量给完成初始化，是在对象创造完之后就会调用。
    cout << learn_text_1.num<< endl;

    // 也可以调用指针， new 一块堆区内存
    MyClass *p_my_class = new MyClass(8, 9);
    cout << p_my_class->num << endl;

    delete p_my_class;
}

#endif

#if 0
// 这是探究如何给类中的常量完成初始化的代码

#include <iostream>
#include <string>

using namespace std;

class WitStudent
{
public:
    string student_name_;
    const int kStudentId;
    const int kStudentNum;

public:
    // 基本语法就是 class(形参1，形参2):常量名(形参1)，常量名(形参2)，常量名(0（也可以直接给值）)。
    WitStudent(int student_num) : kStudentNum(student_num), kStudentId(0)
    {
        cout << kStudentNum << endl
             << kStudentId << endl;
    }
};

int main(void)
{
    // 由于此处没有“低保”了，调用构造函数就必须要传值进去。
    WitStudent z_y(1);

    z_y.student_name_ = "z_y";
    cout << z_y.student_name_ << endl;

    return 0;
}

#endif

#if 0
// 这是探究如何给类中的常量完成初始化的代码

#include <iostream>
#include <string>

using namespace std;

class WitStudent
{
public:
    string student_name_;
    const int kStudentId;
    const int kStudentNum;

public:
    WitStudent(int student_num);
};

// 基本语法就是 class(形参1，形参2):常量名(形参1)，常量名(形参2)，常量名(0（也可以直接给值）)。
WitStudent::WitStudent(int student_num) : kStudentNum(student_num), kStudentId(0)
{
    cout << kStudentNum << endl
         << kStudentId << endl;
}

int main(void)
{
    // 由于此处没有“低保”了，调用构造函数就必须要传值进去。
    WitStudent z_y(1);

    z_y.student_name_ = "z_y";
    cout << z_y.student_name_ << endl;

    return 0;
}

#endif

#if 0
// 这是学习析构函数的代码

#include <iostream>
#include <string>

using namespace std;

class WitStudent
{
public:
    string wit_student_name_;
    const int kWitStudentNum;
    const int kWitStudentId;

public:
    // 构造函数声明
    WitStudent(int wit_student_num, int flag);
    // 析构函数声明
    ~WitStudent();
};

// 构造函数定义
WitStudent::WitStudent(int wit_student_num, int flag) : kWitStudentNum(wit_student_num), kWitStudentId(0)
{
    cout << "WitStudent" << flag << endl;
}

WitStudent::~WitStudent()
{
    cout << "~WitStudent" << endl;
}

int main(void)
{
    cout << "flag~~~~~" << endl;
    // 这里多传一个flag进去看先后，这是栈区对象
    WitStudent z_y(1, 1);
    cout << "flag~~~~~" << endl;

    cout << "flag~~~~~" << endl;
    // 这是堆区对象
    WitStudent *p_just_name = new WitStudent(9, 2);
    cout << "flag~~~~~" << endl;
    p_just_name->wit_student_name_ = "m_t";

    // 此处结束堆区对象的生命周期
    delete p_just_name;
    cout << "flag~~~~~" << endl;

    // 请注意时对象的生命周期结束在调用析构函数，而不是因为调用析构函数对象才结束周期的。
    return 0;
}

#endif

#if 0
// 这是探究构造函数的代码

#include <iostream>
#include <string>

using namespace std;

class Monster
{
public:
    string monster_name_;
    int monster_hp_;
    double monster_speed_;

public:
    Monster();                                                     ///< 无参构造函数
    Monster(string m_name, int m_hp = 100, double m_speed = 10.1); ///< 有参并且参数缺省构造函数
    ~Monster();                                                    ///< 析构函数
    Monster(Monster &obj);                                         ///< 拷贝构造函数
    Monster(Monster &obj, int m_hp);                               ///< 拷贝构造函数
};

void TextFun1(Monster obj);
Monster TextFun2();

// 无参构造
Monster::Monster()
{
    monster_name_ = "无名氏";
    monster_hp_ = 99;
    monster_speed_ = 10.0;

    cout << "无参构造" << endl;
}
// 有参构造
Monster::Monster(string m_name, int m_hp, double m_speed)
{
    monster_name_ = m_name;
    monster_hp_ = m_hp;
    monster_speed_ = m_speed;

    cout << "有参构造函数" << endl;
}
// 析构函数
Monster::~Monster()
{
    cout << "析构函数" << endl;
}
// 拷贝构造函数1号
Monster::Monster(Monster &obj)
{
    monster_name_ = obj.monster_name_;
    monster_hp_ = obj.monster_hp_;
    monster_speed_ = obj.monster_speed_;

    cout << "拷贝构造函数1号" << endl;
}
// 拷贝构造函数2号
Monster::Monster(Monster &obj, int m_hp)
{
    monster_name_ = obj.monster_name_;
    monster_hp_ = m_hp;
    monster_speed_ = obj.monster_speed_;

    cout << "拷贝构造函数2号" << endl;
}

void TextFun1(Monster obj)
{

    cout << "flag" << endl;
}
Monster TextFun2()
{
    Monster obj;
    return obj;
}

int main(void)
{
    Monster m0;
    TextFun1(m0);

    TextFun2();
    // 这里gcc不给过，在vs里面可以
    // Monster monster = TextFun2();

    return 0;
}

#endif

#if 0
// 这是探究 this 指针
// 初版本

#include <iostream>

using namespace std;

class MyClass
{
    // 默认private
    int num;

public:
    void SetNum(int n)
    {
        num = n;
    }
    int Print()
    {
        return num;
    }
};

int main(void)
{
    MyClass c;
    c.SetNum(1);
    cout << c.Print() << endl;
    return 0;
}
#endif

#if 0
// 这是探究 this 指针
// 引出this

#include <iostream>

using namespace std;

class MyClass
{
    // 默认private
    int num;

public:
    // 如果我把形参的名字也给成num会如何呢?
    // 其实每一次系统都会默认给你类指针this不需要自己加。
    // void SetNum(MyClass *this, num)
    void SetNum(int num)
    {
        // 有趣的是下面这种直接num=num，输出结果为0(why?)
        // num = num;
        this->num = num;
    }
    int Print()
    {
        this->num = 0;
        cout << num << endl;
        this->SetNum(3);
        (*this).SetNum(4);
        cout << num << endl;

        // 这里的返回值也不单单是num而应该是this->num,只不过一般把他们省略。
        return num;
    }
};

int main(void)
{
    MyClass c;
    c.SetNum(2);
    cout << c.Print() << endl;
    return 0;
}
#endif

#if 0
// 这是探究静态数据成员

#include <iostream>

using namespace std;
class MyClass
{
public:
    MyClass();
    ~MyClass();
    static int num;
};

// 这是正确给初始值的方式，在类的外面。
int MyClass::num = 0;

MyClass::MyClass()
{
    // error 此时num是静态的数据成员，属于公有的。
    // num = 0;

    //  常用方式是这样的给一个++，就可以知道创建了多少个对象。
    num++;
}

MyClass::~MyClass()
{
}

int main()
{
    MyClass obj_1;
    cout << "obj_1.num=" << obj_1.num << endl;

    // 可以通过对象访问到num，并且由此可以验证num是共有的，并不属于任何一个对象。
    obj_1.num = 1;

    MyClass obj_2;
    cout << "obj_2.num=" << obj_2.num << endl;

    // 尝试输出看看对象内部占几个字节结果是只占一个，由此可见num不在obj_1之中。
    cout << "sizeof(obj_1)=" << sizeof(obj_1) << endl;
    // 那为何类也是一个字节呢？这样的测量方式是错误的，sizeof不能直接测量类的大小。
    cout << "sizeof(MyClass)=" << sizeof(MyClass) << endl;

    return 0;
}

#endif

#if 0
// 这是探究静态数据成员

#include <iostream>

using namespace std;
class MyClass
{
public:
    MyClass();
    ~MyClass();
    int i;
    static int num;
    // 可内可外
    static void TextFun1()
    {
        // error 不可在静态成员函数中用成员数据。
        // i = 0;
        cout << "TextFun1()" << endl;
    }
    static void TextFun2();
    void Text()
    {
        i = 0;
    }
};

// 这是正确给初始值的方式，在类的外面。
int MyClass::num = 0;

// 静态成员函数定义
void MyClass::TextFun2()
{
    // error 这也是不可
    // this->i = 0;

    // error 调用非静态成员函数也不可，是为了防止你绕弯子去动成员变量的值。
    // Text();
    cout << "TextFun2()" << endl;
}

int main()
{
    // 注意这是在对象创建之前就可以通过类名调用静态成员函数
    // 这也可以解释为何在静态成员函数中不能存在类的成员变量，因为连对象都没创建出来。
    MyClass::num = 0;
    MyClass::TextFun1();
    MyClass::TextFun2();

    MyClass obj_1;
    (&obj_1)->TextFun2();

    return 0;
}

#endif