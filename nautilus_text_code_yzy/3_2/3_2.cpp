// 三.2
#include <iostream>
#include <algorithm>
#include <set>
// #include <greater>
using namespace std;

int main(void)
{
    set<int,greater<int>> s;

    for (int i = 0; i < 10;i++)
    {
        int temp = 0;
        cin >> temp;
        s.emplace(temp);
    }
    for (auto i:s)
    {
        cout << i;
    }
    return 0;
}