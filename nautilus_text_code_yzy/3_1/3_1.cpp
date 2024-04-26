// 水仙花数
// 三.1
#include <iostream>
int main(void)
{
    int num(0);
    int sum(0);
    std::cin >> num;
    int tmp = num;
    while (num != 0)
    {
        int temp = num % 10;
        sum += (temp * temp * temp);
        num = num / 10;
    }

    if (tmp == sum)
    {
        std::cout << "yes";
    }
    return 0;
}