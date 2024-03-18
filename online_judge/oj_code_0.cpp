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

// #include <iostream>

// int Find(int array[], int target);
// int kArraySize(10);
// int main(void)
// {
//     int array[kArraySize]{-3, -1, 0, 1, 3, 4, 5, 6, 7, 10};
//     int target(0);
//     std::cout << "请输入你需要查找的值" << std::endl;
//     std::cin >> target;

//     int temp = Find(array, target);
//     if (temp != -1)
//     {
//         std::cout << "找到了，下标为" << temp << std::endl;
//     }
//     else
//     {
//         std::cout << "没找到" << std::endl;
//     }
// }

// int Find(int array[], int target)
// {
//     int left(0);
//     int right(kArraySize);
//     int temp = array[(left + right) / 2];

//     // 二分法
//     while ((right - left) != 1)
//     {
//         if (temp < target)
//         {
//             right = (right + left) / 2;
//         }
//         else if (temp > target)
//         {
//             left = (right + left) / 2;
//         }
//         else
//         {
//             temp = target;
//             return (left + right) / 2;
//         }

//     }

//     return -1;
// }

// #include <iostream>

// int main()
// {
//     int num_1(6);
//     int num_2(7);

//     if (-3 ^ 1)
//     {
//         std::cout << "偶数" << std::endl;
//     }
//     else
//     {
//         std::cout << "奇数" << std::endl;
//     }
// }

// //@ 二分法实现
// #include <iostream>
// // 向量头文件
// #include <vector>
// // 二分法类——左闭右闭
// class Dichotomy
// {
// public:
//     // 具体实现二分法查找的函数声明
//     int Search(std::vector<int> &num, int target);
// };

// // 查找函数具体实现
// int Dichotomy::Search(std::vector<int> &num, int target)
// {
//     // 左值
//     int left(0);
//     // 右值
//     int right(num.size() - 1);
//     // 等号非常重要
//     while (left <= right)
//     {
//         // 精妙的地方，用右移位操作符代替相对复杂的除法算法，更为高效
//         int middle = left + ((right - left) >> 1);

//         if (target < num[middle])
//         {
//             // 满足左闭右闭
//             right = middle - 1;
//         }
//         else if (target > num[middle])
//         {
//             // 满足左闭右闭
//             left = middle + 1;
//         }
//         else
//         {
//             // 返回下标
//             return middle;
//         }
//     }
//     // 没找到
//     return -1;
// }

// int main(void)
// {
//     int array[]{-3, -1, 0, 1, 3, 4, 5, 6, 7, 10};
//     // 用数组完成初始化
//     std::vector<int> vector_array(array, array + 10);

//     // 实例化对象
//     Dichotomy text;

//     // 调用函数
//     int flag(text.Search(vector_array, 999));

//     if (flag >= 0)
//     {
//         std::cout << "下标为" << flag << std::endl;
//     }
//     else
//     {
//         std::cout << "没找到" << std::endl;
//     }

// }

//@ 搜索插入位置
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 你可以假设数组中无重复元素。
#include <iostream>
#include <vector>

class SearchOrInsert
{
public:
    int SearchOrInsert_function(std::vector<int> &a, int target);
};

int SearchOrInsert::SearchOrInsert_function(std::vector<int> &a, int target)
{
    for (int i = 0; i < a.size();i++)
    {
        // 这个地方非常巧妙，只要target小于或等于某一个元素的值直接返回索引
        if(target<=a[i])
        {
            return i;
        }
    }

    // target比所有的元素都大的时候就直接返回新增的函数
    return a.size();
}

int main(void)
{
    int array[]{1, 3, 5, 7};
    // 尾地址不会被包含
    std::vector<int> my_vector(array, array + 4);

    SearchOrInsert obj;
    std::cout << "obj.SearchOrInsert_function()=" << obj.SearchOrInsert_function(my_vector, 8);
}
