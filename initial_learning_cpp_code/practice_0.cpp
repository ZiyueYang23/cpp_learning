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

#if 0
// 这是单例模式
#include <iostream>

using namespace std;

class SingleInstance
{
private:
    SingleInstance();
    SingleInstance(const SingleInstance &obj);
    static SingleInstance *p_single_instance;

public:
    static SingleInstance *GetSingleInstance();
    ~SingleInstance();
    int num_;
};
SingleInstance *SingleInstance::p_single_instance = NULL;
SingleInstance *SingleInstance::GetSingleInstance()
{
    if (p_single_instance == NULL)
    {
        p_single_instance = new SingleInstance;
    }

    return p_single_instance;
}

SingleInstance::SingleInstance()
{
    num_ = 0;
}

SingleInstance::~SingleInstance()
{
}

int main(void)
{
    // 显示不可访问
    // SingleInstance a;

    // 输出三个地址都是一样的

    SingleInstance *p_single_class_1 = SingleInstance::GetSingleInstance();
    cout << hex << p_single_class_1 << endl;
    cout << p_single_class_1->num_ << endl;
    SingleInstance *p_single_class_2 = SingleInstance::GetSingleInstance();
    cout << hex << p_single_class_2 << endl;
    p_single_class_1->num_ = 15;
    SingleInstance *p_single_class_3 = SingleInstance::GetSingleInstance();
    cout << hex << p_single_class_3 << endl;
    cout << p_single_class_1->num_ << endl;

    return 0;
}

#endif

#if 0
// 这是探究常量数据成员的代码

#include <iostream>

using namespace std;

class TextConstData
{
public:
    TextConstData();
    TextConstData(int v, int n = 0);
    int num;
    const int val=0;
};

TextConstData::TextConstData()
{
}
TextConstData::TextConstData(int v, int n) : val(v), num(n)
{
}

int main(void)
{
    TextConstData text_const_data;
    cout << "text_const_data.num=" << text_const_data.num << ",text_const_data.val=" << text_const_data.val << endl;

    text_const_data.num = 100;
    cout << "text_const_data.num=" << text_const_data.num << ",text_const_data.val=" << text_const_data.val << endl;

    return 0;
}

#endif

#if 0
// 这是探究常量成员函数以及常量对象的代码演示

#include <iostream>

using namespace std;

class TextConst
{
private:
    /* data */
public:
    int num;
    const int val;
    static int temp;

public:
    TextConst(int v);
    ~TextConst();
    void TextFun1();
    void TextFun2() const;
};
int TextConst::temp = 888;

TextConst::TextConst(int v) : val(v)
{
    num = 0;
}
TextConst::~TextConst()
{
}
void TextConst::TextFun1()
{
    num = 999;
    cout << "TextFun1.num=" << num << endl;
    cout << "TextFun1.val=" << val << endl;
    cout << "TextFun1.temp=" << temp << endl;

}

void TextConst::TextFun2() const
{
    // error 在常量函数中不可以进行修改内部成员变量的值
    // num = 999;
    // 当然输出这些都是没问题的
    cout << "TextFun2.num=" << num << endl;
    cout << "TextFun2.val=" << val << endl;
    // 注意到，静态成员变量是可以进行修改的。
    temp = 777;
    cout << "TextFun2.temp=" << temp << endl;
}

int main(void)
{
    TextConst text_const_1(555);
    text_const_1.TextFun1();
    text_const_1.TextFun2();

    const TextConst text_const_2(333);

    // error 常对象不能修改值
    // text_const_2.num = 0;

    // 如同常函数一样可以对静态变量修改
    text_const_2.temp = 0;

    // error 常对象还需要注意的一点就是不能调用普通的成员函数为何？？
    // 是因为如果调用成员函数你就可能间接的进行修改值，所以直接禁止使用普通成员函数。
    // text_const_2.TextFun1();

    // 调用常成员函数自然是没有问题，因为常函数本身就不能修改值自然就可以使用。
    text_const_2.TextFun2();
    return 0;
}

#endif

#if 0

#include <iostream>

using namespace std;

class TextFriend
{
private:
    int num_;
    // 位置可以在任何地方
    friend TextFriend TextFriendFun1(TextFriend obj);

public:
    int val_;
    TextFriend();
};

TextFriend TextFriendFun1(TextFriend obj)
{
    // error 注意这个地方由于num是属于私有的没有权限访问
    //  obj.num_ = 0;

    // 这个地方不加friend 也可以进行对公有变量的修改。
    obj.val_ = 1;   ///<但是需要注意，传进去改值是可以但是传不出去

    // 这里就是打破了封装可以修改里面的值
    obj.num_ = 1;
    cout << "TextFriend.num_=" << obj.num_ << endl;

    return obj;
}
TextFriend::TextFriend()
{
}

int main(void)
{
    TextFriend text_friend_1;
    text_friend_1 = TextFriendFun1(text_friend_1);
    cout << text_friend_1.val_ << endl;
    return 0;
}

#endif
#if 0
// 这是对友元函数的学习代码

#include <iostream>

using namespace std;

class TextFriendFun
{
private:
    int num_;
    
    // 位置可以在任何地方
    friend void TextFriendFunFun1(TextFriendFun& obj);

public:
    int val_;
    TextFriendFun();
};

void TextFriendFunFun1(TextFriendFun& obj)
{
    // error 注意这个地方由于num是属于私有的没有权限访问
    //  obj.num_ = 0;

    // 这个地方不加friend 也可以进行对公有变量的修改。
    obj.val_ = 1;   ///<但是需要注意，传进去改值,如果没加上&是传不出去的，里面改了外面没动。

    // 这里就是打破了封装可以修改里面的值
    obj.num_ = 1;
    cout << "TextFriendFun.num_=" << obj.num_ << endl;

}
TextFriendFun::TextFriendFun()
{
    num_ = 0;
}

int main(void)
{
    TextFriendFun text_friend_1;
    TextFriendFunFun1(text_friend_1);
    cout << text_friend_1.val_ << endl;

    return 0;
}

#endif

#if 0
// 这是探究友元类的演示代码

#include <iostream>

using namespace std;

class TextFriendClass1
{
private:
    int num;

public:
    friend class TextFriendClass2;
};

class TextFriendClass2
{
public:
    void TextFun(TextFriendClass1 &obj)
    {
        // 友元类，就打破了类的封装。
        obj.num = 1;
    }
};

int main(void)
{
    return 0;
}

#endif

#if 0
// 这是探究继承与派生的代码

#include <iostream>

using namespace std;

class ClassFather
{
private:
    int pri_;

public:
    int pub_;
    ClassFather(ClassFather &obj);
    ClassFather();

protected:
};

class ClassSon : public ClassFather
{
private:
public:
    int num_;
    ClassSon();
    ClassSon(ClassSon &obj);

protected:
};

int main(void)
{
    ClassFather class_father_1;
    ClassSon class_son_1;

    cout << "sizeof(class_father_1)=" << sizeof(class_father_1) << endl;
    cout << "sizeof(class_son_1)=" << sizeof(class_son_1) << endl;
    // 输出结果：
    // sizeof(class_father_1)=8，父类中两个int型变量，占用八个字节。
    // sizeof(class_son_1)=12，子类中只有一个int型变量却占用了十二个字节。由此可见，子类继承了父类的所有数据，尽管有些数据不能访问

    // 可以访问父类的public
    class_son_1.pub_ = 1;
    // 此时显示的是class_father_1.pub_=0;也就是子类继承有了新的数据
    cout << "class_father_1.pub_=" << class_father_1.pub_ << endl;

    return 0;
}


// ClassFather

ClassFather::ClassFather()
{

}
ClassFather::ClassFather(ClassFather &obj)
{
    cout << "拷贝构造函数" << endl;
}

// ClassSon

ClassSon::ClassSon()
{
    num_ = 0;
    // 在认爸爸之后就可以使用爸爸里面的数据，注意权限
    pub_ = 0;
    // error 不可访问，但是否存在？可以通过sizeof来检测一下
    // pri_ = 0;
}

ClassSon::ClassSon(ClassSon &obj)
{
    cout << "拷贝构造函数" << endl;
}

#endif

#if 0
// 这是探究父子类成员重名时的优先级的演示代码

#include <iostream>

using namespace std;

class ClassFather1
{
public:
    ClassFather1(/* args */);
    int num_;
};

class ClassFather2
{
public:
    ClassFather2(/* args */);
    int num_;
};

class ClassSon : public ClassFather1, public ClassFather2
{
public:
    ClassSon(/* args */);
    int num_;
};

int main(void)
{
    ClassSon class_son;
    // 输出结果是class_son.num_=99，也就是说优先的为子类的成员
    cout << "class_son.num_=" << class_son.num_ << endl;
    // class_son.ClassFather1::num_=1
    cout << "class_son.ClassFather1::num_=" << class_son.ClassFather1::num_ << endl;
    // class_son.ClassFather2::num_=2
    cout << "class_son.ClassFather2::num_=" << class_son.ClassFather2::num_ << endl;

    return 0;
}

// ClassFather1
ClassFather1::ClassFather1(/* args */)
{
    num_ = 1;
}

// ClassFather2
ClassFather2::ClassFather2(/* args */)
{
    num_ = 2;
}

// ClassSon
ClassSon::ClassSon(/* args */)
{
    num_ = 99;
}

#endif

#if 0
// 这是研究父类与子类创建的过程的代码示例

#include <iostream>

using namespace std;

class ClassFather1
{
public:
    int val_;
    ClassFather1();
    ~ClassFather1();
};

class ClassSon1 : public ClassFather1
{
public:
    int num_;
    ClassSon1();
    ~ClassSon1();
};

int main(void)
{
    // 此处并没有定义父类对象
    ClassSon1 class_song_1;
    // 而且也没有使用父类成员变量
    cout << class_song_1.num_ << endl;
    // 结果是完成父类的构造。
}

// ClassFather
ClassFather1::ClassFather1()
{
    val_ = 1;
    cout << "父类构造" << endl;
}
ClassFather1::~ClassFather1()
{
    cout << "父类析构" << endl;
}

// ClassSon1
ClassSon1::ClassSon1()
{
    num_ = 2;
    cout << "子类构造" << endl;

}
ClassSon1 ::~ClassSon1()
{
    cout << "子类析构" << endl;
}

/* 
输出结果:

父类构造  
子类构造
2
子类析构
父类析构
*/

#endif

#if 0
// 这是探究子类对象如何对父类中继承的const变量进行初始化的演示代码

#include <iostream>

using namespace std;

class ClassFather2
{
public:
    int val_;
    ClassFather2(int n);
    ClassFather2();
    ~ClassFather2();
    const int kNum_;
};

class ClassSon2 : public ClassFather2
{
public:
    int num_;
    ClassSon2(int n);
    ClassSon2();
    ~ClassSon2();
};

int main(void)
{
    ClassSon2 class_son_2;
    cout << "class_son_2.val_=" << class_son_2.val_ << endl
         << "class_son_2.num_=" << class_son_2.num_ << endl
         << "class_son_2.kNum_=" << class_son_2.kNum_ << endl;
}

// ClassFather2
ClassFather2::ClassFather2(int n) : kNum_(n)
{

    val_ = 1;
    cout << "父类有参构造" << endl;
}
ClassFather2 ::ClassFather2() : kNum_(9)
{
    cout << "父类构造" << endl;
}
ClassFather2::~ClassFather2()
{
    cout << "父类析构" << endl;
}

// ClassSon2
// 直接调用父类构造函数，语法就是: 父类构造函数名（）
ClassSon2::ClassSon2(int n) : ClassFather2(n)
{
    num_ = 2;
    val_ = 3;
    // error 那么改如何完成子类继承的const常量的初始化呢？
    cout << "子类有参构造" << endl;
}
ClassSon2 ::ClassSon2()
{
    cout << "子类构造" << endl;
}
ClassSon2 ::~ClassSon2()
{
    cout << "子类析构" << endl;
}

// ClassSon2 ::ClassSon2() : ClassFather2(7)
// {
//     cout << "子类构造" << endl;
// }
#endif

#if 0
// 这是研究菱形继承演示代码

#include <iostream>

using namespace std;

class GrandClass
{
public:
    int grand_num_ = 9;
};
class FatherClass1 : public GrandClass
{
public:
    int father_1_num_;
};
class FatherClass2 : public GrandClass
{
public:
    int father_2_num_;
};
class SonClass2 : public FatherClass1, public FatherClass2
{
public:
    int son_num_;
};

int main(void)
{
    SonClass2 son_class_0;
    son_class_0.son_num_;
    son_class_0.father_1_num_;
    son_class_0.father_2_num_;
    // error 不知道放到那一块内存。
    // son_class_0.grand_num_;

    // 输出结果都是9，也就说明他们是重复的造成了内存的浪费。
    cout << "son_class_0.FatherClass1::grand_num_=" << son_class_0.FatherClass1::grand_num_ << endl;
    cout << "son_class_0.FatherClass2::grand_num_=" << son_class_0.FatherClass2::grand_num_ << endl;


    cout << "sizeof(GrandClass)=" << sizeof(GrandClass) << endl;
    cout << "sizeof(FatherClass1)=" << sizeof(FatherClass1) << endl;
    cout << "sizeof(FatherClass2)=" << sizeof(FatherClass2) << endl;
    cout << "sizeof(SonClass2)=" << sizeof(SonClass2) << endl;

    /*
    print

    sizeof(GrandClass)=4
    sizeof(FatherClass1)=8
    sizeof(FatherClass2)=8
    sizeof(SonClass2)=20      ///<8+8+4=20,这里浪费了4个字节因为其根本上都是grand_num_
    */
}

#endif

#if 0
// 这是研究菱形继承中虚继承的演示代码

#include <iostream>

using namespace std;

class GrandClass
{
public:
    int grand_num_ = 9;
};
class FatherClass1 : virtual public GrandClass
{
public:
    int father_1_num_;
};
class FatherClass2 : virtual public GrandClass
{
public:
    int father_2_num_;
};
class SonClass2 : public FatherClass1, public FatherClass2
{
public:
    int son_num_;
};

int main(void)
{
    SonClass2 son_class_0;
    son_class_0.son_num_;
    // son_class_0.father_1_num_;
    // son_class_0.father_2_num_;
    // right 用来虚继承就可以使用了
    son_class_0.grand_num_;

    // 输出结果都是9，也就说明他们是重复的造成了内存的浪费。
    cout << "son_class_0.FatherClass1::grand_num_=" << son_class_0.FatherClass1::grand_num_ << endl;
    cout << "son_class_0.FatherClass2::grand_num_=" << son_class_0.FatherClass2::grand_num_ << endl;


    cout << "sizeof(GrandClass)=" << sizeof(GrandClass) << endl;
    cout << "sizeof(FatherClass1)=" << sizeof(FatherClass1) << endl;
    cout << "sizeof(FatherClass2)=" << sizeof(FatherClass2) << endl;
    cout << "sizeof(SonClass2)=" << sizeof(SonClass2) << endl;

    /*
    print

    sizeof(GrandClass)=4
    sizeof(FatherClass1)=16
    sizeof(FatherClass2)=16 ///<原来是8字节现在变成了16字节？？why？
    sizeof(SonClass2)=40    ///<16+16+4+4???这里是怎么算的不太清楚
    */
}

#endif
#if 0
// 这是实现多态的演示代码

#include <iostream>
using namespace std;

class FatherClass3
{
public:
    virtual void TextFunction3();
};

class SonClass3 : public FatherClass3
{
public:
    void TextFunction3();
};
class SonClass4 : public FatherClass3
{
public:
    void TextFunction3();
};

int main(void)
{
    FatherClass3 father_class_3;

    SonClass3 son_class_3;

    SonClass4 son_class_4;

    FatherClass3 *p_father_class_3;
    
    p_father_class_3 = &father_class_3;
    p_father_class_3->TextFunction3();

    p_father_class_3 = &son_class_3;
    p_father_class_3->TextFunction3();

    p_father_class_3 = &son_class_4;
    p_father_class_3->TextFunction3();
    return 0;
}

// FatherClass3
void FatherClass3::TextFunction3()
{
    cout << "FatherClass3.TextFunction3()" << endl;
}

// SonClass3
void SonClass3::TextFunction3()
{
    cout << "SonClass3.TextFunction3()" << endl;
}
// SonClass4
void SonClass4::TextFunction3()
{
    cout << "SonClass4.TextFunction3()" << endl;
}

/*
输出结果

加上virtual:

FatherClass3.TextFunction3()
SonClass3.TextFunction3()
SonClass4.TextFunction3()

如果什么都不变就只去掉virtual:
FatherClass3.TextFunction3()
FatherClass3.TextFunction3()
FatherClass3.TextFunction3()
*/

#endif

#if 0

#include <iostream>

using namespace std;

// 抽象类
class FatherClass4
{
public:
    virtual void TextFunc4() = 0;
};

class SonClass4 : public FatherClass4
{
public:
    void TextFunc4() final;
};

class GrandsonClass : public SonClass4
{
public:
    // error 这里就final了TextFunc4的虚函数继承，不能够再重写了
    // void TextFunc4();
};

int main(void)
{
    // error 此时父类已经是抽象类了，不能够再实例化对象
    // FatherClass4 a;

    SonClass4 son_class_4;
    son_class_4.TextFunc4();

    return 0;
}

// FatherClass4

// 纯虚函数
// void FatherClass4::TextFunc4()
// {
//     cout << "FatherClass4::TextFunc4()" << endl;
// }

// SonClass4

void SonClass4::TextFunc4()
{
    cout << "SonClass4::TextFunc4()" << endl;
}
#endif

#if 0
// 这是以复数类为例子研究运算符重载

#include <iostream>
using namespace std;


class MyComplex1
{
private:
    /* data */
    double real_;
    double imag_;

public:
    MyComplex1(double real = 0.0, double imag = 0.0);
    ~MyComplex1();

    void DisplayComplex() const;

    // // 初级版本-is loser
    // MyComplex1 operator+(MyComplex1 &obj);

    // 相对满足代码健壮性的版本
    MyComplex1 operator+(const MyComplex1 &obj) const;

    // 为何此处的返回值不能够是 MyComplex1 & ???
    MyComplex1 operator-(const MyComplex1 &obj) const;

    // 这里使用友元函数来使得在全局函数中也可以去访问到private数据。
    friend MyComplex1 operator*(const MyComplex1 &obj_1, const MyComplex1 &obj_2);
};

// 全局函数声明
MyComplex1 operator*(const MyComplex1 &obj_1, const MyComplex1 &obj_2);

int main(void)
{
    MyComplex1 my_complex_obj_1(-3, 5);
    my_complex_obj_1.DisplayComplex();

    MyComplex1 my_complex_obj_2(4, -3);
    my_complex_obj_2.DisplayComplex();

    // 现在我想实现两个复数相加
    // error 没有这种加法运算符重载
    MyComplex1 my_complex_obj_3;
    my_complex_obj_3 = my_complex_obj_1 + my_complex_obj_2;
    my_complex_obj_3.DisplayComplex();
    my_complex_obj_3 = my_complex_obj_1.operator-(my_complex_obj_2);
    my_complex_obj_3.DisplayComplex();
    my_complex_obj_3 = operator*(my_complex_obj_1, my_complex_obj_2);
    my_complex_obj_3.DisplayComplex();
    my_complex_obj_3 = my_complex_obj_1 * my_complex_obj_2;
    my_complex_obj_3.DisplayComplex();

    // 注意到 = 这个运算符，直接就可以完成两个对象相等
    // 其实这是我们吃到的一个新的低保，叫赋值函数。
    // 现在类中存在四个低保，构造析构拷贝构造以及赋值函数。
    return 0;
}

// 完成全局函数定义
MyComplex1 operator*(const MyComplex1 &obj_1, const MyComplex1 &obj_2)
{
    return MyComplex1((obj_1.real_ * obj_2.real_) - (obj_1.imag_ * obj_2.imag_), (obj_1.real_ * obj_2.imag_) + (obj_1.imag_ * obj_2.real_));
}

// MyComplex1
MyComplex1::MyComplex1(double real, double imag)
    : real_(real), imag_(imag)
{
}

MyComplex1::~MyComplex1()
{
}

// // 初级版本-loser版本
// MyComplex1 MyComplex1::operator+(MyComplex1 &obj)
// {
//     MyComplex1 obj_temp;

//     obj_temp.real_ = this->real_ + obj.real_;
//     obj_temp.imag_ = this->imag_ + obj.imag_;

//     return obj_temp;
// }

// 相对满足代码健壮性的版本
MyComplex1 MyComplex1::operator+(const MyComplex1 &obj) const
{
    // 直接用一个构造函数非常巧妙。
    return MyComplex1(this->real_ + obj.real_, this->imag_ + obj.imag_);
}

MyComplex1 MyComplex1::operator-(const MyComplex1 &obj) const
{
    return MyComplex1(this->real_ - obj.real_, this->imag_ - obj.imag_);
}

void MyComplex1::DisplayComplex() const
{
    cout << real_ << "+"
         << "(" << imag_ << ")"
         << "i" << endl;
}

#endif

#if 0
// 这是探究<< , >>运算符重载的代码演示

#include <iostream>
using namespace std;

class MyComplex2
{
private:
    double real_;
    double imag_;

public:
    MyComplex2(double real = 0.0, double imag = 0.0);

    // 友元函数，访问私有数据
    friend ostream &operator<<(ostream &out, MyComplex2 &obj);
    friend istream &operator>>(istream &in, MyComplex2 &obj);
};

// 全局函数<<,>>运算符重载声明
ostream &operator<<(ostream &out, MyComplex2 &obj);
istream &operator>>(istream &in, MyComplex2 &obj);

int main(void)
{
    MyComplex2 my_complex_2_0(3, 6);
    MyComplex2 my_complex_2_1(-1, 3);

    // error 这个地方我想实现直接打印出两个虚数，可是<<,>>这两个运算符并不认识类，需要重载
    // cout << my_complex_2_0 << my_complex_2_1 << endl;

    // 通过运算符重载可以实现想要达成的目的。
    cin >> my_complex_2_0 >> my_complex_2_1;
    cout << my_complex_2_0 << endl
         << my_complex_2_1 << endl;

    // 实际上是这样的,把cin >> my_complex_2_0运算完之后返回值为cin，继续调用重载函数，一个传进去cin，第二个再是my_complex_2_1
    operator>>((operator>>(cin, my_complex_2_0)), my_complex_2_1);
    // 有一点小瑕疵没法连在一起完成换行
    operator<<(cout, my_complex_2_0);
    cout << endl;
    operator<<(cout, my_complex_2_1);

    return 0;
}

// MyComplex2
MyComplex2::MyComplex2(double real, double imag)
    : real_(real), imag_(imag)
{
}

// >>,<<重载函数定义
ostream &operator<<(ostream &out, MyComplex2 &obj)
{
    out << obj.real_ << "+"
        << "(" << obj.imag_ << ")"
        << "i";
    return out;
}
istream &operator>>(istream &in, MyComplex2 &obj)
{
    in >> obj.real_ >> obj.imag_;
    return in;
}
#endif

#if 0

#include <iostream>

using namespace std;

class RMB
{
private:
    int Yuan_;
    int Jiao_;
    int Fen_;

public:
    RMB(int Yuan = 0, int Jiao = 0, int Fen = 0);
    ~RMB();

    operator double()
    {
        return (double)(Yuan_ + ((double)Jiao_ / 10) + ((double)Fen_ / 100));
    };
    void ShowRmb();
};

void RMB::ShowRmb()
{
    cout << this->Yuan_ << "元" << this->Jiao_ << "角" << this->Fen_ << "分" << endl;
}

RMB::RMB(int Yuan, int Jiao, int Fen)
    : Yuan_(Yuan), Jiao_(Jiao), Fen_(Fen)
{
}

RMB::~RMB()
{
}

int main(void)
{
    RMB rmb_0(5, 3, 6);
    RMB rmb_1(1);
    rmb_1.ShowRmb();
    rmb_0.ShowRmb();

    double temp;
    temp = rmb_0;

    cout << temp << endl;

    return 0;
}

#endif

#if 1
// 这是研究函数模板与类模板的演示代码（还需勤加练习）

#include <iostream>
#include <string>
using namespace std;

// template <class ClassType_1, class ClassType_2>
template <class ClassType_1 = int, class ClassType_2 = double>
class TextTypeClass
{
public:
    ClassType_1 var_1_;
    ClassType_2 var_2_;

    TextTypeClass(ClassType_1 var_1 = 0, ClassType_2 var_2 = 0.0)
        : var_1_(var_1), var_2_(var_2) {}
    void ShowData()
    {
        cout << "var_1=" << var_1_ << endl
             << "var_2=" << var_2_ << endl;
    }
};

template <class FatherTypeClass1, class FatherTypeClass2>
class FatherTypeClass
{
public:
    FatherTypeClass1 var_1_;
    FatherTypeClass2 var_2_;
};

// 普通做法
class SonClass : public FatherTypeClass<int, double>
{
public:
    int val_;
};
// 从这里开始顿悟，其实这玩意根据你想的加在函数or类前面，来充当临时类型，你再传参过去，有点temp的意思。
template <class SonTypeClass1, class SonTypeClass2>
class TypeSonClass : public FatherTypeClass<SonTypeClass1, SonTypeClass1>
{
public:
    SonTypeClass2 val_;
};

template <typename Type>
Type Add(Type num_1, Type num_2)
{
    return num_1 + num_2;
}

template <typename Type_1, typename Type_2>
void PrintText(Type_1 t_1, Type_2 t_2)
{
    cout << "t_1=" << t_1 << endl
         << "t_2=" << t_2 << endl;
}

void TextFunPrint_1(TextTypeClass<int, double> &obj)
{
    obj.ShowData();
}

template <typename FunType_1, typename FunType_2>
void TextFunPrint_2(TextTypeClass<FunType_1, FunType_2> &obj)
{
    obj.ShowData();
}

template <class ClassType>
void TextFunPrint_3(ClassType &obj)
{
    obj.ShowData();
}

int main(void)
{
    cout << Add(3, 4) << endl
         << Add<int>(3.2, 4) << endl
         << Add<double>(3.2, 4.3) << endl
         << Add(3.1, 4.1) << endl
         << Add<char>(67, 1) << endl;

    // error 我想弄一个运算符重载但是不知为何行不通，需要类。
    // cout << Add("Hello", ",cpp!") << endl;

    PrintText(1, 1);
    // PrintText<int, int>(1, 1);
    PrintText(1, 1.1);
    // PrintText<int, double>(1, 1.1);
    PrintText("Hello", "World!");
    PrintText<const char *, char>("Hello", 67);

    // error double,int 两种不同类型的变量传进去，会出现二义性
    // cout << Add(3.2, 4) << endl;

    TextTypeClass<> obj_1(3.2, 2.2);
    TextFunPrint_1(obj_1);

    TextTypeClass<char> obj_2(65, 2.2);
    TextFunPrint_2(obj_2);
    // 默认会给，隐式推导类型
    // TextFunPrint_2<char,double>(obj_2);
    // error
    // TextFunPrint_1(obj_2);

    TextTypeClass<char, float> obj_3(67, 2.2f);
    TextFunPrint_3(obj_3);
    // 实际上应该是这样的，隐式推导回帮助给出ClassType
    TextFunPrint_3<TextTypeClass<char, float>>(obj_3);

    TypeSonClass<int,double> obj_4;
    obj_4.var_1_ = 0;
    return 0;
}

#endif