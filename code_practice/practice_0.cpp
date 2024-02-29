#if 0
//cpp1
#include <iostream>

using namespace std;

int main()
{
    char a;
    int b;
    long c;
    double d;

    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(d) << endl;

    return 0;
}

#endif

#if 0
//cpp2
#include <iostream>

using namespace std;

int main()
{
    double a;
    cin >> a;

    int temp = 0;
    temp = (int)((int)(a * 10)) % 10;
    if (temp >= 5)
    {
        a++;
    }
    else if(temp<0&&(-temp)>5)
    {
        a--;
    }


    cout << (int)a << endl;
}

//这是我自己的方法有点冗杂
#endif

//@ 这个方法非常巧妙很好的利用了强转整数的界限
// ！ 四舍五入的好方法！！！
#if 0
#include <iostream>

using namespace std;

int main(void)
{
    double a;
    cin >> a;

    if (a > 0)
    {
        cout << (int)(a + 0.5);
    }
    else
    {
        cout << (int)(a - 0.5);
    }

    return 0;
}

#endif

#if 0
#include <iostream>

using namespace std;

int main(void)
{
    int a;
    int b;

    cin >> a >> b;

    cout << a + b << endl;

    return 0;
}

#endif

#if 0
#include <iostream>

using namespace std;

int main(void)
{
    int a;
    int b;
    int max;

    cin >> a >> b;

    max = a > b ? a : b;

    cout << max << endl;

    return 0;
}

#endif