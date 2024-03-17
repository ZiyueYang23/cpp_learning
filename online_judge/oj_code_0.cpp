// #include <iostream>
// int Find(int array[], int target);
// int main(void)
// {
//     const int kArrayNum = 10;
//     int array[kArrayNum]{-3, -1, 0, 5, 6, 9, 10, 17, 19, 66};
//     int target(0);

//     std::cout << "请输入你需要寻找到的值:>" << std::endl;
//     std::cin >> target;

//     int flag = Find(array, target);
//     if (flag != -1)
//     {
//         std::cout << "找到了，下标为" << flag << std::endl;
//     }
//     else
//     {
//         std::cout << "未找到" << std::endl;
//     }

//     return 0;
// }

// int Find(int array[], int target)
// {
//     int count = 0;
//     while (array != nullptr)
//     {
//         if (*array == target)
//         {
//             return count;
//         }
//         else
//         {
//             count++;
//             array++;
//         }
//     }

//     return -1;
// }

#include <iostream>

int Find(int array[], int target);
int kArraySize(10);
int main(void)
{
    int array[kArraySize]{-3, -1, 0, 1, 3, 4, 5, 6, 7, 10};
    int target(0);
    std::cout << "请输入你需要查找的值" << std::endl;
    std::cin >> target;

    int temp = Find(array, target);
    if (temp != -1)
    {
        std::cout << "找到了，下标为" << temp << std::endl;
    }
    else
    {
        std::cout << "没找到" << std::endl;
    }
}

int Find(int array[], int target)
{
    int left(0);
    int right(kArraySize);
    int temp = array[(left + right) / 2];

    // 二分法
    while ((right - left) != 1)
    {
        if (temp < target)
        {
            right = (right + left) / 2;
        }
        else if (temp > target)
        {
            left = (right + left) / 2;
        }
        else
        {
            temp = target;
            return (left + right) / 2;
        }
        
    }

    return -1;
}