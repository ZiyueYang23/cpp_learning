#if 1
// 这是研究vector容器的演示代码

#include <iostream>
// 翻译为向量，在cpp中被称为容器，因为它可以装许多类型的数据
#include <vector>
//  格式化输出 流操作算子
#include <iomanip>
// 算法 algorithm 用sort的时候会用到
#include <algorithm>

// 比较大小函数，小到大
inline bool Compare1(int a, int b);
// 大到小
inline bool Compare2(int a, int b);

int main(void)
{
    // 六个元素，均赋值为1.
    std::vector<int> my_vector(6, 1);
    // for的新标准，c++ 11，前面是类型，后跟名字，再:接要循环的对象。
    for (auto my_vector_e : my_vector)
    {
        std::cout << my_vector_e << std::endl;
    }
    // 清除容器中所有的元素，不单单是把值归0，是直接释放
    my_vector.clear();

    std::cout << "*****" << std::endl;

    // 尾部插入
    my_vector.push_back(0);
    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.push_back(3);
    my_vector.push_back(4);

    for (auto my_vector_e : my_vector)
    {
        std::cout << my_vector_e << std::endl;
    }
    // 这是容量，是一个容器的直接大小
    std::cout << "my_vector.capacity() =" << my_vector.capacity() << std::endl;
    // size 就是具体有几个元素
    std::cout << "my_vector.size() =" << my_vector.size() << std::endl;

    // 尾部删除
    my_vector.pop_back();

    std::cout << "my_vector.size() =" << my_vector.size() << std::endl;
    // 调用algorithm算法库中的sort应该是快排的函数，三个指针，首地址，尾地址，比较函数的地址
    // 小到大排序
    sort(my_vector.begin(), my_vector.end(), Compare1);

    std::cout << "*******" << std::endl;
    for (auto i : my_vector)
    {
        std::cout << i << std::endl;
    }
    // 大到小排序
    sort(my_vector.begin(), my_vector.end(), Compare2);

    std::cout << "*******" << std::endl;

    for (auto i : my_vector)
    {
        std::cout << i << std::endl;
    }

    std::cout << "my_vector.at(0)=" << my_vector.at(0) << std::endl;

    // 二维vector
    std::vector<std::vector<int>> obj(5, std::vector<int>(6));
    for (int i = 0; i < obj.size(); i++)
    {
        for (int j = 0; j < obj[i].size(); j++)
        {
            // 按照索引顺序对应赋值。
            obj[i][j] = 6 * i + j;
            // 默认右对齐以及十进制
            // 这里用了左对齐，以及设置宽度函数
            std::cout << std::left << std::setw(4) << obj[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

// 小于就是小到大
inline bool Compare1(int a, int b)
{
    return a < b;
}
// 大于就是大到小
inline bool Compare2(int a, int b)
{
    return a > b;
}

#endif

