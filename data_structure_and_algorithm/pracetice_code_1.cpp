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

// //@ 搜索插入位置
// // 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// // 你可以假设数组中无重复元素。
// #include <iostream>
// #include <vector>

// class SearchOrInsert
// {
// public:
//     int SearchOrInsert_function(std::vector<int> &a, int target);
// };

// int SearchOrInsert::SearchOrInsert_function(std::vector<int> &a, int target)
// {
//     for (int i = 0; i < a.size();i++)
//     {
//         // 这个地方非常巧妙，只要target小于或等于某一个元素的值直接返回索引
//         if(target<=a[i])
//         {
//             return i;
//         }
//     }

//     // target比所有的元素都大的时候就直接返回新增的函数
//     return a.size();
// }

// int main(void)
// {
//     int array[]{1, 3, 5, 7};
//     // 尾地址不会被包含
//     std::vector<int> my_vector(array, array + 4);

//     SearchOrInsert obj;
//     std::cout << "obj.SearchOrInsert_function()=" << obj.SearchOrInsert_function(my_vector, 8);
// }

// //@ 移除元素——暴力解法
// // 给你⼀个数组 nums 和⼀个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新⻓度。
// // 不要使⽤额外的数组空间，你必须仅使⽤ O(1) 额外空间并原地修改输⼊数组
// #include <iostream>
// #include <vector>

// class Solution
// {
// public:
//     // 函数声明
//     int RemoveElement(std::vector<int> &nums, int val);
// };
// // 函数定义
// int Solution::RemoveElement(std::vector<int> &nums, int val)
// {
//     // 获取数组长度
//     int size = nums.size();

//     for (int i(0); i < size; i++)
//     {
//         if (val == nums[i])
//         {
//             // 体会这里为何不直接用i，而是用j=i，因为进去第二个循环的时候会改i的值。
//             // 覆盖元素
//             for (int j = i; j < size; j++)
//             {
//                 // 用后面一个元素完成对前面找到的元素进行覆盖。
//                 nums[j] = nums[j + 1];
//             }
//             // i--，如果不减，将会造成新产生的数组，移过去的那个元素没有被检测是否相等。
//             i--;
//             // 覆盖了一个size减一。
//             size--;
//         }
//     }
//     return size;
// }

// int main(void)
// {
//     int array[]{1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 8, 8, 9};

//     std::vector<int> vec(array, array + 13);

//     // 实例化对象
//     Solution r_e;
//     // 输出size
//     std::cout << "r_e.RemoveElement()=" << r_e.RemoveElement(vec, 9);
// }

// //@ 移除元素-双指针-快慢指针法

// #include <iostream>
// #include <vector>

// class Solution
// {
// public:
//     int RemoveElement(std::vector<int> &vector, int val);
// };
// int Solution::RemoveElement(std::vector<int> &my_vector, int val)
// {
//     // 慢指针
//     int slow_index = 0;
//     // 数组长度
//     int size = my_vector.size();
//     // 快指针
//     for (int fast_index = 0; fast_index < size; fast_index++)
//     {
//         if (val != my_vector[fast_index])
//         {
//             my_vector[slow_index] = my_vector[fast_index];

//             // 慢指针还具有记录新数组长度的功能
//             slow_index++;
//         }
//     }

//     return slow_index;
// }

// int main(void)
// {
//     int array[]{1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 8, 8, 9};

//     std::vector<int> vec(array, array + 13);

//     // 实例化对象
//     Solution r_e;
//     // 输出size
//     std::cout << "r_e.RemoveElement()=" << r_e.RemoveElement(vec, 4);
// }
// // 注意到这种方法不会改变原来数组的元素的顺序

// //@ 双指针-相向双指针法

// #include <iostream>
// #include <vector>

// class Solution
// {
// public:
//     // 移除元素函数声明
//     int RemoveElement(std::vector<int> &v,int val);
// };
// // 移除元素函数定义
// int Solution::RemoveElement(std::vector<int> &v, int val)
// {
//     // 左指针,并且具有计数功能
//     int left_index(0);
//     // 右指针
//     int right_index(v.size()-1);

//     // 外层循环
//     while(left_index<=right_index)
//     {
//         // 内层循环左指针找相等,找到相等就停下等待右指针传值过来
//         while(left_index<=right_index&&val!=v[left_index])
//         {
//             // 不相等就自加,成为新数组的一员,使得左指针向右移动继续判断
//             left_index++;
//         }

//         // 内层循环,右指针找不相等的值传给左指针指到的与val相等的位置
//         while(right_index>=left_index&&val==v[right_index])
//         {
//             // 也因此会使得新数组元素的顺序改变
//             // 相等就自减,向左移动判断下一个
//             right_index--;
//         }
//         // 左边相等的被右边找到不相等的覆盖
//         if (left_index < right_index)
//         {
//             v[left_index] = v[right_index];

//             // 要指向下一块否则会重复判断
//             left_index++;
//             right_index--;
//         }
//     }

//     //返回新数组的长度
//     return left_index;
// }

// int main(void)
// {
//     int array[]{1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 8, 8, 9};

//     std::vector<int> vec(array, array + 13);

//     // 实例化对象
//     Solution r_e;
//     // 输出size
//     std::cout << "r_e.RemoveElement()=" << r_e.RemoveElement(vec, 9);
//     return 0;
// }

// //@ 有序数组的平方-暴力解法
// // 给你⼀个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <iomanip>

// class Solution
// {
// public:
//     void SortedSquares(std::vector<int> &v);
// };
// void Solution::SortedSquares(std::vector<int> &v)
// {
//     // 传统for循环
//     // for (int i = 0; i < v.size(); i++)
//     // {
//     //     v[i] *= v[i];
//     // }

//     // 传引用才能改值
//     // 更加简洁
//     for (auto &i : v)
//     {
//         i = i * i;
//     }

//     // 快速排序
//     std::sort(v.begin(), v.end());

// }

// int main(void)
// {
//     int array[]{-4, -3, -1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9};

//     std::vector<int> vec(array, array + 13);

//     // 实例化对象
//     Solution r_e;
//     // 输出size
//     r_e.SortedSquares(vec);

//     for (auto i : vec)
//     {
//         std::cout << std::left << std::setw(4) << i;
//     }

//     return 0;
// }

// //@ 有序数组平方——双指针法
// #include <iostream>
// #include <vector>
// // 流操作算子头文件
// #include <iomanip>

// class Solution
// {
// public:
//     // 函数声明
//     std::vector<int> &SortedSqures(const std::vector<int> &v, std::vector<int> &new_vector);
// };
// // 函数实现
// std::vector<int> &Solution::SortedSqures(const std::vector<int> &v, std::vector<int> &new_vector)
// {
//     // 左指针
//     int left_index = 0;
//     // 右指针
//     int righr_index = v.size() - 1;
//     // 新数组指针
//     int new_righr_index = v.size() - 1;

//     while (left_index <= righr_index)
//     {
//         // 左指针与右指针的值相比较，较大的一个赋给新数组的右指针
//         if (v[left_index] * v[left_index] >= v[righr_index] * v[righr_index])
//         {
//             // 给新数组从右侧即最大值开始填充
//             new_vector[new_righr_index] = v[left_index] * v[left_index];
//             // 左指针右移
//             left_index++;
//             // 新数组右指针左移
//             new_righr_index--;
//         }
//         else if (left_index <= righr_index && v[left_index] * v[left_index] < v[righr_index] * v[righr_index])
//         {
//             // 新数组填充
//             new_vector[new_righr_index] = v[righr_index] * v[righr_index];
//             // 右指针左移
//             righr_index--;
//             // 新数组右指针左移
//             new_righr_index--;
//         }
//     }
//     // 返回填充满的新数组
//     return new_vector;
// }

// int main()
// {
//     int array[]{-4, -3, -1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9};
//     // 承接有序数组的容器
//     std::vector<int> vec(array, array + 13);
//     // 开辟好等待填充的容器
//     std::vector<int> new_vector(vec.size(), 0);

//     // 实例化对象
//     Solution r_e;
//     // 输出size
//     r_e.SortedSqures(vec, new_vector);

//     for (auto i : new_vector)
//     {
//         // 输出新数组每一个元素
//         std::cout << std::left << std::setw(4) << i;
//     }

//     return 0;
// }

// //@ 长度最小的子数组
// // 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足子数组元素和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

// #include <iostream>
// #include <vector>
// #include <climits>
// // 断言，开发版本可以用但是在发布版本会被禁用，因此assert＋if是万全之策
// #include <cassert>
// class Solution
// {
// public:
//     int MinSubArray(const std::vector<int> &v, int val);
// };
// // 包装一个函数，后面也可以用，类里面的函数也不会显得冗余
// bool CheckInputArray(const std::vector<int>&v)
// {
//     if (v.empty())
//     {
//         std::cerr << "Error:Input array is empty!" << std::endl;
//         return false;
//     }

//     return true;
// }

// int Solution::MinSubArray(const std::vector<int> &v, int val)
// {
//     // empty 是向量自带的函数，如果为空返回真，因此这里要取反，空为假assert就会报错，&&后面的字符串会被送到标准错误流中。
//     // assert(!v.empty()&& "Input array is empty");

//     // 包装函数注意返回值，assert括号里面为假报错
//     assert(CheckInputArray(v) && "Input array is empty");

//     // // 万全之策，如果感觉冗余可以在封装一个函数
//     // if(v.empty())
//     // {
//     //     std::cerr << "Error:Input array is empty!" << std::endl;
//     //     return -1;
//     // }

//     // 慢指针，窗口起点
//     int slow_index(0);
//     // 子数组总和
//     int sum(0);
//     // 数组大小
//     int size = v.size();
//     // 最小长度
//     int min_array(INT_MAX); ///< INT_MAX是int类型的最大值，需要包含头文件<climits>

//     // 快指针，窗口终点，快指针遍历了整个数组
//     for (int fast_index(0); fast_index < size; fast_index++)
//     {
//         // 算子数组总和
//         sum += v[fast_index];
//         // 如果子数组总和到了val，现在快指针停止不动，由慢指针开始移动
//         while (sum >= val)
//         {
//             // 记录此时子数组长度并与上一个子数组长度相比较，哪一个更小，存入min_array
//             min_array = std::min(min_array, fast_index - slow_index + 1);
//             // 减掉头部移出的元素的值
//             sum -= v[slow_index];
//             // 让慢指针左移，左移起始位置，终止位置不动，达到减小子数组的目的
//             slow_index++;
//         }
//     }

//     // 如果最小子数组等于size本身长度就返回0
//     return (min_array == size) ? 0 : min_array;
// }

// int main(void)
// {
//     int array[]{-4, -3, -1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9};
//     // 承接有序数组的容器
//     std::vector<int> vec(array, array + 13);

//     // 实例化对象
//     Solution solution;
//     int target = 1000000;
//     int min_len = solution.MinSubArray(vec, target);

//     std::cout << "Minimum subarray length with sum at least " << target << " = " << min_len << std::endl;
// }
// // @ 螺旋矩阵

// #include <iostream>
// #include <vector>
// #include <iomanip>

// class Solution
// {
// public:
//     // 返回值为二维数组，因为是在函数体内部创建的二维数组需要往外面拷贝所以没有必要传引用
//     std::vector<std::vector<int>> generateMatrix(int n);
// };
// // 传进去n就是所需的n*n的矩阵的边长
// std::vector<std::vector<int>> Solution::generateMatrix(int n)
// {
//     // 创建一个二维数组
//     std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));

//     // 行
//     int row(0);
//     // 列
//     int col(0);
//     // 转几圈，很巧妙的用右移操作符实现/2的功能，并且性能更高
//     int times(n >> 1);
//     // 转了几圈
//     int count(0);
//     // 给每一个矩阵元素赋值，让其自加
//     int num(1);

//     // 只要圈数没转完就继续循环
//     while (count != times)
//     {
//         // 进来先圈数加1
//         count++;
//         // 上部分螺旋
//         while (col < n - count)
//         {
//             // 此时row不变，只有col变，向左移动，并且最后col是到达边界的，每一圈的右上角
//             res[row][col] = num++;
//             col++;
//         }
//         // 右部分螺旋
//         while (row < n - count)
//         {
//             // col不变，row变，向下移动，最后到右下角
//             res[row][col] = num++;
//             row++;
//         }
//         // 下部分螺旋
//         while (col >= count)
//         {
//             // 此时row不变，向左移动，最后到每一圈的左下角
//             res[row][col] = num++;
//             col--;
//         }

//         while (row >= count)
//         {
//             // 此时col不变，row变，向上移动，最终回到起点，左上角
//             res[row][col] = num++;
//             row--;
//         }
//         // 从起点左上角沿对角线方向移动，即进入下一圈
//         row++;
//         col++;

//         // 如果是n奇数，就会造成最中间的数没有完成赋值
//         // 这里也非常巧妙，用&1来判断奇偶并且奇数结果为1正好进入if语句，而偶数为0则跳过语句，性能更高
//         if (n & 1)
//         {
//             // 可以用n*n
//             // res[times][times] = n * n;

//             // 也可以用num赋值
//             res[times][times] = num;
//         }
//     }

//     return res;
// }
// int main(void)
// {
//     // 所需矩阵边长
//     int n = 8;

//     Solution solution;
//     std::vector<std::vector<int>> vec = solution.generateMatrix(n);

//     // 遍历输出矩阵
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             std::cout << std::setw(4) << std::left << vec[i][j];
//         }
//         std::cout << std::endl;
//     }
// }
// // 纯自己独立实现的，相当不错！

// //@ 移除元素

// #include <iostream>
// #include <cassert>
// // 创建LinkedList，
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     // 结构体中的默认构造函数
//     ListNode(int n = 0) : val(n), next(nullptr) {}
// };

// class Solution
// {
// public:
//     ListNode *RemoveElement(ListNode *p_head, int val);
// };

// ListNode *Solution::RemoveElement(ListNode *p_head, int target)
// {
//     // 断言括号里面的内容为真则不会触发，为假除法并输出错误信息。
//     assert(p_head != nullptr && "p_head should not be nullptr");
//     // 做一个虚拟头指针就可以完成统一对元素进行删除，否则如果头指针的val就是tatget就还需要判断并且进行修改。
//     ListNode *p_dummy_head = new ListNode(0);
//     // 插入头指针之前
//     p_dummy_head->next = p_head;
//     // 创建一个遍历指针
//     ListNode *cur = p_head;

//     // 再次保障cur非空，也就是head非空，当cur所指向的next为nullptr时循环结束
//     while (cur != nullptr && cur->next != nullptr)
//     {
//         // 检测下一个节点中的val是否等于target，这样才能动现在所指节点的next的值
//         if (cur->next->val == target)
//         {
//             // 临时指针记录要被删除的节点
//             ListNode *temp = cur->next;
//             // 精髓所在，cur所指向的节点的next储存下下个节点的地址
//             cur->next = cur->next->next;
//             // 如果不创建临时指针的话这块内存就无法被释放因为此时通过cur来指已经指不到这个节点，
//             delete temp;
//         }
//         else
//         {
//             // 如果不等于，就指向下一个节点
//             cur = cur->next;
//         }
//     }
//     // 移除虚拟头指针，因为此时原来的第一个节点是有可能被删除的
//     // 如果被原来第一个节点被删除掉，p_head就是野指针，那块内存被释放掉了，而p_head指向那里
//     // 此时把虚拟头指针所指向的下一个节点给p_head，此时p_head就不是野指针了。
//     p_head = p_dummy_head->next;
//     // 释放虚拟头指针
//     delete p_dummy_head;
//     // 返回头指针
//     return p_head;
// }

// int main(void)
// {
//     ListNode list_node;
//     Solution solution;
//     // 试了一下assert，感觉逻辑是反的有点奇怪，括号里面为假则会报错
//     solution.RemoveElement(list_node.next,0);
//     return 0;
// }

// //@ 设计链表- 第一版失败
// // get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// // addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
// // addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。

// #include <iostream>
// #include <cassert>
// struct LinkedNode
// {
//     int val;
//     LinkedNode *next;

//     LinkedNode(int v = 0) : val(v), next(nullptr) {}
// };

// class LinkedList
// {
// public:
//     int GetVal(LinkedNode *p_head, int index);
//     LinkedNode *AddAtHead(LinkedNode *p_head, int val);
//     void AddAtTail(LinkedNode *p_head, int val);
//     LinkedNode *AddAtIndex(LinkedNode *p_head, int index, int val);
//     void DeleteAtIndex(LinkedNode *p_head, int index);
// };
// int main()
// {
//     LinkedList myList;
//     LinkedNode *p_head = nullptr;

//     // 测试 AddAtHead
//     p_head = myList.AddAtHead(p_head, 1);
//     p_head = myList.AddAtHead(p_head, 2);

//     // 测试 GetVal
//     std::cout << "Value at index 1: " << myList.GetVal(p_head, 1) << std::endl;

//     // 测试 AddAtTail
//     myList.AddAtTail(p_head, 3);

//     // 测试 AddAtIndex
//     p_head = myList.AddAtIndex(p_head, 2, 4);

//     // 打印链表中所有节点的值
//     LinkedNode *current = p_head;
//     while (current != nullptr)
//     {
//         std::cout << current->val << " ";
//         current = current->next;
//     }
//     std::cout << std::endl;

//     // 测试 DeleteAtIndex
//     myList.DeleteAtIndex(p_head, 2);

//     // 再次打印链表中所有节点的值
//     current = p_head;
//     while (current != nullptr)
//     {
//         std::cout << current->val << " ";
//         current = current->next;
//     }
//     std::cout << std::endl;

//     return 0;
// }

// int LinkedList::GetVal(LinkedNode *p_head, int index)
// {
//     assert(p_head != nullptr);
//     int num(0);
//     while (p_head[num].next != nullptr)
//     {
//         if (num == index)
//         {
//             return p_head[index].val;
//         }
//         num++;
//     }

//     return -1;
// }

// LinkedNode *LinkedList::AddAtHead(LinkedNode *p_head, int val)
// {
//     LinkedNode *p_new_head = new LinkedNode(val);
//     p_new_head->next = p_head;

//     return p_new_head;
// }

// void LinkedList::AddAtTail(LinkedNode *p_head, int val)
// {
//     LinkedNode *p_last_node = new LinkedNode(val);

//     while (p_head->next != nullptr)
//     {
//         p_head++;
//     }

//     p_head->next = p_last_node;
// }

// // addAtIndex(index, val)：在链表中的第 index 个节点 之前 添加值为 val 的节点。
// // 如果 index 等于链表的长度，则该节点将附加到链表的末尾。
// // 如果 index 大于链表长度，则不会插入节点。
// // 如果index小于0，则在头部插入节点。
// LinkedNode *LinkedList::AddAtIndex(LinkedNode *p_head, int index, int val)
// {
//     if (index < 0)
//     {
//         return AddAtHead(p_head, val);
//     }

//     int num(0);
//     while (p_head[num].next != nullptr)
//     {
//         if (num + 1 == index && p_head[num].next->next != nullptr)
//         {
//             LinkedNode *p_add_node = new LinkedNode(val);
//             p_add_node->next = p_head[num].next->next;
//             p_head[num].next = p_add_node;

//             return p_head;
//         }
//         num++;
//     }

//     if (index = num)
//     {
//         AddAtTail(p_head, val);
//         return p_head;
//     }
//     else if (index > num)
//     {
//         return p_head;
//     }
// }
// // deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
// void LinkedList::DeleteAtIndex(LinkedNode *p_head, int index)
// {
//     if(index<0)
//     {

//     }
//     else
//     {
//         int num(0);
//         while (p_head[num].next != nullptr)
//         {
//             if (num + 1== index)
//             {
//                 LinkedNode *p_temp = p_head[num].next;
//                 p_head[num].next = p_head[num].next->next;
//                 p_temp->next = nullptr;
//                 delete p_temp;
//             }
//             num++;
//         }
//     }
// }

// // 第一版宣告失败，链表不能像数组一样进行下标访问，难受昨天写了好久，一些思路挺好的但是对链表不太熟练，想着直接用下标进行访问。

// //@ 反转链表

// #include <iostream>

// // 链表节点
// struct LinkedNode
// {
//     int val;
//     LinkedNode *next;

//     // 默认结构体构造函数
//     LinkedNode(int v = 0)
//         : val(v), next(nullptr) {}
// };

// class LinkedList
// {
// public:
//     // 反转单链表
//     LinkedNode *ReversalLinkedList(LinkedNode *p_head);
// };

// // 快慢指针法
// LinkedNode *LinkedList::ReversalLinkedList(LinkedNode *p_head)
// {
//     // 这里面temp是精髓所在
//     LinkedNode *p_temp(nullptr);

//     LinkedNode *p_cur = p_head;
//     // 用一个指向nullptr来代替虚拟头指针相当不错
//     LinkedNode *p_pre(nullptr);

//     // 中间的cur作为循环判断结束的标志。
//     // 最终状态cur与temp都指向nullptr，而pre此时指向最后一个节点。
//     while (p_cur != nullptr)
//     {
//         // 每次进入循环之前,cur是快指针，pre是慢指针，第一遍想错的就是，改变了箭头指向，再执行= ->next操作是反向的。相当于就是过河拆桥，再想过就过不去了。
//         // 因此说这个temp是精髓，每次先把temp抛过去插个眼，再通过翻转箭头，再把p_pre送到p_cur的地方，然后把p_cur送到p_temp处。注意顺序。
//         // 此时temp和cur在一起，pre在后面。
//         // 再进入下一个循环，temp就又被抛到cur所指向的下一个节点
//         p_temp = p_cur->next;
//         p_cur->next = p_pre;
//         p_pre = p_cur;
//         p_cur = p_temp;
//     }

//     return p_pre;
// }

// int main()
// {
//     // 创建一个简单的链表进行测试
//     LinkedNode *head = new LinkedNode(1);
//     head->next = new LinkedNode(2);
//     head->next->next = new LinkedNode(3);

//     // 打印原始链表
//     LinkedNode *cur = head;
//     std::cout << "Original Linked List: ";
//     while (cur != nullptr)
//     {
//         std::cout << cur->val << " ";
//         cur = cur->next;
//     }
//     std::cout << std::endl;

//     // 调用链表反转函数
//     LinkedList linkedList;
//     LinkedNode *new_head = linkedList.ReversalLinkedList(head);

//     // 打印反转后的链表
//     std::cout << "Reversed Linked List: ";
//     cur = new_head;

//     while (cur != nullptr)
//     {
//         std::cout << cur->val << " ";
//         cur = cur->next;
//     }
//     std::cout << std::endl;

//     return 0;
// }
// //@ 两两翻转链表
// //自己深思熟虑后成功证明自己的思路是错的，不过深度思考，进一步理解指针挺好的
// #include <iostream>

// // 链表节点
// struct LinkedNode
// {
//     int val;
//     LinkedNode *next;

//     // 默认结构体构造函数
//     LinkedNode(int v = 0)
//         : val(v), next(nullptr) {}
// };

// class LinkedList
// {
// public:
//     LinkedNode *ChangeLinkedList(LinkedNode *p_head);
//     LinkedNode *ChangeLinkedNode(LinkedNode *p_first);
// };

// LinkedNode *LinkedList::ChangeLinkedList(LinkedNode *p_head)
// {
//     LinkedNode *p_new_head(nullptr);
//     LinkedNode *p_cur = p_head;
//     int count(0);
//     while (p_cur->next != nullptr)
//     {
//         if ((count % 2) == 0)
//         {
//             p_cur = ChangeLinkedNode(p_cur);
//             if (count == 0)
//             {
//                 p_new_head = p_cur;
//             }
//         }
//         count++;
//         p_cur = p_cur->next;
//     }

//     return p_new_head;
// }
// LinkedNode *LinkedList::ChangeLinkedNode(LinkedNode *p_first)
// {
//     LinkedNode *p_new_first = new LinkedNode(p_first->next->val);
//     p_new_first->next = p_first;
//     LinkedNode *p_temp = p_first->next;
//     p_first->next = p_new_first->next->next;

//     p_temp->next = nullptr;
//     delete p_temp;

//     return p_new_first;
// }

// int main()
// {
//     // 创建一个简单的链表进行测试
//     LinkedNode *head = new LinkedNode(1);
//     head->next = new LinkedNode(2);
//     head->next->next = new LinkedNode(3);
//     head->next->next->next = new LinkedNode(4);

//     // 打印原始链表
//     LinkedNode *cur = head;
//     std::cout << "Original Linked List: ";
//     while (cur != nullptr)
//     {
//         std::cout << cur->val << " ";
//         cur = cur->next;
//     }
//     std::cout << std::endl;

//     // 调用链表反转函数
//     LinkedList linkedList;
//     LinkedNode *new_head = linkedList.ChangeLinkedList(head);

//     // 打印反转后的链表
//     std::cout << "Reversed Linked List: ";
//     cur = new_head;

//     while (cur != nullptr)
//     {
//         std::cout << cur->val << " ";
//         cur = cur->next;
//     }
//     std::cout << std::endl;

//     return 0;
// }

// //@ 两两翻转链表

// // 动指针一定是先插眼到对岸然后断桥，从后往前动指针，多插几个眼也就是指针不动指针，只动next即可
// #include <iostream>

// // 链表节点
// struct LinkedNode
// {
//     int val;
//     LinkedNode *next;

//     // 默认结构体构造函数
//     LinkedNode(int v = 0)
//         : val(v), next(nullptr) {}
// };

// class LinkedList
// {
// public:
//     // 实现链表节点的两两翻转
//     LinkedNode *ChangeLinkedList(LinkedNode *p_head);
// };

// LinkedNode *LinkedList::ChangeLinkedList(LinkedNode *p_head)
// {
//     // 创建虚拟头节点
//     LinkedNode *p_dummy_head = new LinkedNode(0);
//     // cur指向虚拟头节点
//     LinkedNode *p_cur = p_dummy_head;
//     // 虚拟头节点接入链表头部
//     p_dummy_head->next = p_head;

//     // 当cur指向倒数第二个节点，temp_0指向最后一个节点，temp_1指向nullptr循环结束此时
//     // 注意理解,上述情况是链表为奇数的时候,因为加了虚拟头节点,此时链表变为偶数.
//     // 就拿3来举例,此时一个有四个节点,第一次交换会换第二个节点和第三个节点(算上虚拟头节点),然后cur会移动到第三个节点的位置此时就会停止循环.第三个节点就是原链表的第二个节点此时原链表的第一二节点都已完成了交换即可停止循环.

//     // 同理可以理解偶数时,拿4来举例此时,加上虚拟头节点就是5个从指向第一个节点开始换2,3也就是原1,2,然后cur再移动到第三个节点处,此时还有3,4,5因此不会停止循环,进入循环换4,5,也就是原来的3,4.好,此时cur到了第五个节点,此时就满足第一个循环截止的条件,此时也就结束循环,而且原链表的1,2,3,4也都分别完成了交换.
//     while (p_cur->next != nullptr && p_cur->next->next != nullptr)
//     {
//         // 创建temp0,指向cur的下一块
//         LinkedNode *p_temp_0 = p_cur->next;
//         // 创建temp1,指向cur的下下下一块,cur是1,temp0是2,temp1是4.
//         // 这个挺关键的就是插个眼,把后续的地址接上
//         LinkedNode *p_temp_1 = p_cur->next->next->next;
//         // 关键就是如何理解交换时的步骤
//         // 首先先完成最难的一步就是把第三块地址给第一块next,让第一块指向第三块
//         p_cur->next = p_temp_0->next;
//         // 第二步把第三块的next存上第二块的地址,让第三块指向第二块
//         p_cur->next->next = p_temp_0;
//         // 最后将第二块的next存上第四块的地址,让第二块指向第四块
//         p_temp_0->next = p_temp_1;
//         // 此上把进入循环的时候,cur所指的为第一块,temp0所指的为第二块,temp1所指的为第四块.

//         p_cur = p_cur->next->next;
//     }
//     // 创建一个新的头指针承接链表交换后的真正头指针,便于去释放那块虚拟头节点
//     LinkedNode *p_new_head = p_dummy_head->next;
//     delete p_dummy_head;
//     return p_new_head;
// }

// int main()
// {
//     // 创建一个简单的链表进行测试
//     LinkedNode *head = new LinkedNode(1);
//     head->next = new LinkedNode(2);
//     head->next->next = new LinkedNode(3);
//     head->next->next->next = new LinkedNode(4);

//     // 打印原始链表
//     LinkedNode *cur = head;
//     std::cout << "Original Linked List: ";
//     while (cur != nullptr)
//     {
//         std::cout << cur->val << " ";
//         cur = cur->next;
//     }
//     std::cout << std::endl;

//     // 调用链表翻转函数
//     LinkedList linkedList;
//     LinkedNode *new_head = linkedList.ChangeLinkedList(head);

//     // 打印翻转后的链表
//     std::cout << "Reversed Linked List: ";
//     cur = new_head;

//     while (cur != nullptr)
//     {
//         std::cout << cur->val << " ";
//         cur = cur->next;
//     }
//     std::cout << std::endl;

//     return 0;
// }
// //@ 删除倒数第n个元素
// #include <iostream>

// // 链表节点
// struct LinkedNode
// {
//     int val;
//     LinkedNode *next;

//     // 默认结构体构造函数
//     LinkedNode(int v = 0)
//         : val(v), next(nullptr) {}
// };

// class LinkedList
// {
// public:
//     // 实现删除链表倒数第n个节点
//     LinkedNode *DeleteLinkedList(LinkedNode *p_head,int n);
// };

// LinkedNode *LinkedList::DeleteLinkedList(LinkedNode *p_head,int n)
// {
//     // 虚拟头节点
//     LinkedNode *p_dummy_head = new LinkedNode(0);
//     // 连上原链表
//     p_dummy_head->next = p_head;

//     LinkedNode *p_cur = p_dummy_head;
//     // 计数器记录链表长度
//     int count(1);

//     // 遍历链表记录长度
//     while (p_cur->next!=nullptr)
//     {
//         p_cur = p_cur->next;
//         count++;
//     }
//     // 把cur倒拨回虚拟头节点
//     p_cur = p_dummy_head;

//     // 循环到要删除的头一个节点
//     while((count-n-1)>0)
//     {
//         count--;
//         p_cur = p_cur->next;
//     }
//     // 创建临时指针指向要删除的节点，目的就是为了断开链表后这个节点可以被释放
//     LinkedNode *p_temp = p_cur->next;

//     // 为了防止极端情况直接传空链表进来，此时temp指向nullptr，它是没有next的就会出问题。
//     // 考虑问题需要全面
//     if(p_cur->next!=nullptr)
//     {
//         p_cur->next = p_temp->next;
//         p_temp->next = nullptr;
//         delete p_temp;
//     }
//     // 释放虚拟头节点
//     LinkedNode *p_tmp = p_dummy_head->next;
//     p_dummy_head->next = nullptr;
//     delete p_dummy_head;
//     // 返回头节点
//     return p_tmp;
// }

// #include <iostream>
// // 用stack需要包含头文件，并且需要std::
// #include <stack>
// // 用list底层容器
// #include <list>
// int main(void)
// {
//     // 底层容器list
//     std::list<int> a{0, 1, 2, 3, 4, 5};
//     // 用底层容器完成对栈完成初始化
//     std::stack<int, std::list<int>> my_stack_0(a);
//     // 也可以用栈对栈完成初始化
//     std::stack<int,std::list<int>> my_stack_2(my_stack_0);
//     // c++11的新标准可以直接完成初始化
//     std::stack<int,std::list<int>> my_stack_1({11,22,33,44,55});

//     // 增加元素
//     my_stack_1.emplace(9);
//     my_stack_1.emplace(8);
//     my_stack_1.emplace(7);
//     my_stack_1.emplace(6);
//     // 访问栈顶的元素
//     std::cout << my_stack_0.top() << std::endl;
//     // 弹出栈顶元素
//     my_stack_0.pop();
//     std::cout << my_stack_0.top() << std::endl;
//     // 增加元素
//     my_stack_0.push(1);
//     std::cout << my_stack_0.top() << std::endl;
//     my_stack_0.emplace(22);
//     std::cout << my_stack_0.top() << std::endl;
//     // 返回栈的大小
//     std::cout << my_stack_0.size() << std::endl;
//     my_stack_0.swap(my_stack_1);

//     std::cout << my_stack_1.top() << std::endl;
//     // 判断是否为空如果为空则返回true
//     std::cout << my_stack_1.empty() << std::endl;

//     return 0;
// }

// @这是研究vector容器的演示代码

// #include <iostream>
// // 翻译为向量，在cpp中被称为容器，因为它可以装许多类型的数据
// #include <vector>
// //  格式化输出 流操作算子
// #include <iomanip>
// // 算法 algorithm 用sort的时候会用到
// #include <algorithm>

// // 比较大小函数，小到大
// inline bool Compare1(int a, int b);
// // 大到小
// inline bool Compare2(int a, int b);

// int main(void)
// {
//     // 六个元素，均赋值为1.
//     std::vector<int> my_vector(6, 1);
//     // for的新标准，c++ 11，前面是类型，后跟名字，再:接要循环的对象。
//     for (auto my_vector_e : my_vector)
//     {
//         std::cout << my_vector_e << std::endl;
//     }
//     // 清除容器中所有的元素，不单单是把值归0，是直接释放
//     my_vector.clear();

//     std::cout << "*****" << std::endl;

//     // 尾部插入
//     my_vector.push_back(0);
//     my_vector.push_back(1);
//     my_vector.push_back(2);
//     my_vector.push_back(3);
//     my_vector.push_back(4);

//     for (auto my_vector_e : my_vector)
//     {
//         std::cout << my_vector_e << std::endl;
//     }
//     // 这是容量，是一个容器的直接大小
//     std::cout << "my_vector.capacity() =" << my_vector.capacity() << std::endl;
//     // size 就是具体有几个元素
//     std::cout << "my_vector.size() =" << my_vector.size() << std::endl;

//     // 尾部删除
//     my_vector.pop_back();

//     std::cout << "my_vector.size() =" << my_vector.size() << std::endl;
//     // 调用algorithm算法库中的sort应该是快排的函数，三个指针，首地址，尾地址，比较函数的地址
//     // 小到大排序
//     sort(my_vector.begin(), my_vector.end(), Compare1);

//     std::cout << "*******" << std::endl;
//     for (auto i : my_vector)
//     {
//         std::cout << i << std::endl;
//     }
//     // 大到小排序
//     sort(my_vector.begin(), my_vector.end(), Compare2);

//     std::cout << "*******" << std::endl;

//     for (auto i : my_vector)
//     {
//         std::cout << i << std::endl;
//     }

//     std::cout << "my_vector.at(0)=" << my_vector.at(0) << std::endl;

//     // 二维vector
//     std::vector<std::vector<int>> obj(5, std::vector<int>(6));
//     for (int i = 0; i < obj.size(); i++)
//     {
//         for (int j = 0; j < obj[i].size(); j++)
//         {
//             // 按照索引顺序对应赋值。
//             obj[i][j] = 6 * i + j;
//             // 默认右对齐以及十进制
//             // 这里用了左对齐，以及设置宽度函数
//             std::cout << std::left << std::setw(4) << obj[i][j] << " ";
//         }

//         std::cout << std::endl;
//     }
// }

// // 小于就是小到大
// inline bool Compare1(int a, int b)
// {
//     return a < b;
// }
// // 大于就是大到小
// inline bool Compare2(int a, int b)
// {
//     return a > b;
// }
// // @用链表实现栈

// #include <iostream>
// // 链表节点
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int v = 0) : val(v), next(nullptr) {}
// };

// class LinkedListStack
// {
// private:
//     // 头节点也就是栈顶，这样非常便利，pop，push都很好实现，否则就需要遍历到链表尾部。
//     // 注意理解栈的特性，把头节点当作栈顶非常符合栈，入栈出栈。
//     ListNode *stack_top;
//     // 栈的大小
//     int stack_size;

// public:
//     // 构造函数
//     LinkedListStack()
//         : stack_size(0), stack_top(nullptr) {}
//     // 释放链表内存
//     void FreeMemoryLinkedList();
//     // 析构函数
//     ~LinkedListStack()
//     {
//         FreeMemoryLinkedList();
//     }
//     // pop
//     void Pop();
//     // push
//     void Push(int number);
//     // size
//     int Size();
//     // empty
//     bool Empty();
//     // top
//     int Top();
// };

// int main(void)
// {
//     LinkedListStack my_stack;
//     my_stack.Push(1);
//     my_stack.Push(2);
//     my_stack.Push(3);
//     my_stack.Push(4);
//     my_stack.Push(5);
//     my_stack.Push(6);
//     std::cout << "my_stack.Size()=" << my_stack.Size() << std::endl;
//     std::cout << "my_stack.Top()=" << my_stack.Top() << std::endl;

//     my_stack.Pop();
//     std::cout << "my_stack.Top()=" << my_stack.Top() << std::endl;
//     std::cout << "my_stack.Size()=" << my_stack.Size() << std::endl;
//     return 0;
// }

// // LinkedListStack
// void LinkedListStack::FreeMemoryLinkedList()
// {

//     while (stack_top != nullptr)
//     {
//         ListNode *p_temp = stack_top;
//         stack_top = stack_top->next;
//         p_temp->next = nullptr;
//         delete p_temp;
//     }
//     stack_size = 0;
// }

// void LinkedListStack::Pop()
// {
//     ListNode *p_temp = stack_top;
//     stack_top = stack_top->next;
//     p_temp->next = nullptr;
//     delete p_temp;
//     stack_size--;
// }

// void LinkedListStack::Push(int number)
// {
//     ListNode *new_node = new ListNode(number);
//     new_node->next = stack_top;
//     stack_top = new_node;
//     stack_size++;
// }

// int LinkedListStack::Size()
// {
//     return stack_size;
// }

// bool LinkedListStack::Empty()
// {
//     if (stack_top == nullptr)
//     {
//         return true;
//     }

//     return false;
// }

// int LinkedListStack::Top()
// {
//     return stack_top->val;
// }

// // @ 初探queue
// #include <iostream>
// // 需要包含头文件
// #include <queue>
// #include <list>

// int main(void)
// {
//     // c++11新标准 初始化单向队列
//     std::queue<int> my_queue_0({1, 2, 3, 4, 5, 6});
//     // 列表可以直接初始化
//     std::list<int> my_list_0 = {9, 8, 7, 6, 5, 4};
//     // 以链表为底层容器完成对queue完成初始化
//     std::queue<int, std::list<int>> my_queue_1(my_list_0);
//     // 默认的底层容器为双端队列deque，这样就只能通过后面自己往里面增加元素。
//     std::queue<int> my_queue_2;

//     // 先入先出，后端插入，前端弹出

//     // 打印头元素
//     std::cout << "my_queue_0.front()=" <<my_queue_0.front() << std::endl;
//     // 弹出头元素
//     my_queue_0.pop();
//     // 打印新的头元素
//     std::cout << "my_queue_0.front()=" <<my_queue_0.front() << std::endl;
//     // 尾插
//     my_queue_0.emplace(7);
//     // 打印尾元素
//     std::cout << "my_queue_0.back()=" <<my_queue_0.back() << std::endl;
//     // queue size
//     std::cout << "my_queue_0.size()=" <<my_queue_0.size() << std::endl;

//     return 0;
// }

// // @用栈实现队列
// // 栈是先入后出，尾插尾弹，队列是先入先出，尾插头弹。

// // 很好的一个思路，就是创建两个栈，另一个栈作为辅助，他们一个正着装一个反这装这样弹出访问插入都可以实现了。这是看别人的思路
// // 我自己的思路就是在弹出头部是导两次，中间做一个临时的栈，最后返回弹出后的新栈。
// #include <iostream>
// #include <stack>
// class StackToQueue
// {
// private:
//     // 创建两个栈，来满足头删除，把栈的栈底当作是队列的头部
//     std::stack<int> stack_to_queue_0;
//     std::stack<int> stack_to_queue_1;

// public:
//     // pop
//     void Pop();
//     // front
//     int Front();
//     // back
//     int Back();
//     // push
//     void Push(int val);
//     // size
//     int Size();
//     // empye
//     bool Empty();
// };
// int main(void)
// {
//     StackToQueue my_queue;
//     my_queue.Push(1);
//     my_queue.Push(2);
//     my_queue.Push(3);
//     my_queue.Push(4);
//     my_queue.Push(5);
//     my_queue.Push(6);

//     std::cout << "my_queue.Size() =" << my_queue.Size() << std::endl;
//     std::cout << "my_queue.Front() =" << my_queue.Front() << std::endl;
//     std::cout << "my_queue.Back() =" << my_queue.Back() << std::endl;
//     std::cout << "my_queue.Empty() =" << my_queue.Empty() << std::endl;

//     my_queue.Pop();

//     std::cout << "my_queue.Size() =" << my_queue.Size() << std::endl;
//     std::cout << "my_queue.Front() =" << my_queue.Front() << std::endl;
//     std::cout << "my_queue.Back() =" << my_queue.Back() << std::endl;
//     std::cout << "my_queue.Empty() =" << my_queue.Empty() << std::endl;

//     my_queue.Pop();
//     my_queue.Pop();
//     my_queue.Pop();
//     my_queue.Pop();
//     my_queue.Pop();
//     std::cout << "my_queue.Size() =" << my_queue.Size() << std::endl;
//     std::cout << "my_queue.Empty() =" << my_queue.Empty() << std::endl;
//     return 0;
// }

// // 以下函数实现比较巧妙的都是两个栈来回转，进去之前判断一下想实现的功能对应的栈的另一个栈是否为空，不为空就导到想实现的功能的所对应的栈，为空就说明已经在对应栈中直接执行。
// // StackToQueue

// // 由于用栈来实现队列，队列的弹出是头部弹出，栈是尾部弹出，所以需要把0栈中的元素弹出然后再入栈到1栈中此时1栈的尾部就正好是原队列的头部，直接用栈中的pop弹出即可。
// // 此处不需要再考虑说要不要把1栈中的元素再导回到0栈中。
// // 有两种处理方案。
// // 1.是向下面实现的方式，数据只存储在两个栈中，每次进去只需要检测一下对应栈中的是否为空。然后实现功能即可，不为空就需要导一下。
// // 2.是向上面说的，始终把数据留存在栈0中如果需要导过去实现完功能后再在函数中倒回来。
// // 综上，由于每次调用函数所需栈的功能是不一样的有时候是栈1，有时候需要栈0，一直留存在栈0中不一定会比第一种方案合适。

// void StackToQueue::Pop()
// {
//     while (stack_to_queue_0.empty() != true)
//     {
//         int temp = stack_to_queue_0.top();
//         stack_to_queue_1.push(temp);
//         stack_to_queue_0.pop();
//     }
//     // 栈1的尾部就是原队列的头部，也就是栈0的栈底（栈0的头部）
//     stack_to_queue_1.pop();
// }

// int StackToQueue::Front()
// {
//     // 有两种情况，第一种是数据储存在satck0中，此时需要弹出再入栈然后返回stack1top
//     // 第二种已经储存在stack1中那就直接返回top非常巧妙！！！！
//     while (stack_to_queue_0.empty() != true)
//     {
//         int temp = stack_to_queue_0.top();
//         stack_to_queue_1.push(temp);
//         stack_to_queue_0.pop();
//     }
//     // 栈1的尾部就是队列的头部
//     return stack_to_queue_1.top();
// }

// int StackToQueue::Back()
// {
//     while (stack_to_queue_1.empty() != true)
//     {
//         int temp = stack_to_queue_1.top();
//         stack_to_queue_0.push(temp);
//         stack_to_queue_1.pop();
//     }
//     // 非常巧妙，如果为空就直接返回stack0top，如果不为空就导一下。
//     // 栈0的尾部就是队列的尾部
//     return stack_to_queue_0.top();
// }

// void StackToQueue::Push(int val)
// {
//     // 尾插
//     while (stack_to_queue_1.empty() != true)
//     {
//         int temp = stack_to_queue_1.top();
//         stack_to_queue_0.push(temp);
//         stack_to_queue_1.pop();
//     }
//     // 栈0的尾部就是队列的尾部
//     stack_to_queue_0.push(val);
// }

// // 以下两个函数就都是判断一下是否为空，找到不为空的栈，也就是找到存放现在数据的栈，以免返回错误的值。

// int StackToQueue::Size()
// {
//     if (stack_to_queue_0.empty() != true)
//     {
//         return stack_to_queue_0.size();
//     }
//     else
//     {
//         return stack_to_queue_1.size();
//     }
// }

// bool StackToQueue::Empty()
// {
//     if (stack_to_queue_0.empty() && stack_to_queue_1.empty())
//     {
//         return true;
//     }
//     return false;
// }

// // @ 双链表实现双向队列
// // 第二版-自己想想那些地方可以更加简洁高效
// #include <iostream>
// // double是一种数据类型，doubly为前缀意为双向
// struct DoublyListNode
// {
//     int val;
//     DoublyListNode *next;
//     DoublyListNode *prev;

//     DoublyListNode(int num = 0)
//         : val(num), next(nullptr), prev(nullptr) {}
// };

// class DoublyLinkedListDeque
// {
// private:
//     // 头节点
//     DoublyListNode *front;
//     // 尾节点
//     DoublyListNode *rear;
//     int doubly_list_node_size;

// public:
//     // 默认构造函数完成初始化
//     DoublyLinkedListDeque()
//         : doubly_list_node_size(0), front(nullptr), rear(nullptr) {}
//     // PushBack
//     void PushBack(int num);
//     // Empty
//     bool Empty();
//     // Size
//     int Size();
//     // PushFront
//     void PushFront(int num);
//     // PopBack
//     void PopBack();
//     // PopFront
//     void PopFront();
//     // Back
//     int Back();
//     // Front
//     int Front();
//     // Clear
//     void Clear();
// };
// int main(void)
// {
//     // 实例化对象
//     DoublyLinkedListDeque deque;

//     // 测试 PushBack 和 PushFront
//     deque.PushBack(1);
//     deque.PushBack(2);
//     deque.PushBack(3);
//     deque.PushFront(0);

//     std::cout << std::endl;

//     // 测试 Size 和 Empty
//     std::cout << "Deque size: " << deque.Size() << std::endl;
//     // 条件运算符挺巧妙的
//     std::cout << "Is deque empty? " << (deque.Empty() ? "Yes" : "No") << std::endl;

//     // 测试 Front 和 Back
//     std::cout << "Front element: " << deque.Front() << std::endl;
//     std::cout << "Back element: " << deque.Back() << std::endl;

//     // 测试 PopFront 和 PopBack
//     deque.PopFront();
//     std::cout << "Front element: " << deque.Front() << std::endl;
//     deque.PopBack();
//     std::cout << "Back element: " << deque.Back() << std::endl;

//     // 测试 Clear
//     deque.Clear();
//     std::cout << "Deque size after clearing: " << deque.Size() << std::endl;

//     return 0;
// }

// // DoublyLinkedListDeque
// // 直接用size完成empty检验，就是需要注意控制size
// bool DoublyLinkedListDeque::Empty()
// {
//     return (doubly_list_node_size == 0) ? true : false;
// }
// // 直接返回size
// int DoublyLinkedListDeque::Size()
// {
//     return doubly_list_node_size;
// }

// // 尾插

// void DoublyLinkedListDeque::PushBack(int num)
// {
//     // new一块内存
//     DoublyListNode *new_node = new DoublyListNode(num);
//     // 如果size为0则头尾指针都指向这块节点
//     if (doubly_list_node_size == 0)
//     {
//         front = new_node;
//         rear = new_node;
//     }
//     else
//     {
//         // size不为零则就newnode接上然后让尾指针指向新的尾节点
//         new_node->prev = rear;
//         rear->next = new_node;
//         rear = new_node;
//     }
//     doubly_list_node_size++;
// }
// // 头插
// void DoublyLinkedListDeque::PushFront(int num)
// {
//     // new一块节点，其余同理尾插
//     DoublyListNode *new_node = new DoublyListNode(num);
//     if (doubly_list_node_size == 0)
//     {
//         front = new_node;
//         rear = new_node;
//     }
//     else
//     {
//         new_node->next = front;
//         front->prev = new_node;
//         front = new_node;
//     }
//     doubly_list_node_size++;
// }
// // 尾删
// void DoublyLinkedListDeque::PopBack()
// {
//     // 还存在一种为0的情况，但是为0不需要进行任何操作因此就直接跳跃
//     if (doubly_list_node_size == 1)
//     {
//         DoublyListNode *temp = front;
//         delete temp;
//         temp = nullptr;
//         front = nullptr;
//         rear = nullptr;
//         // 但是注意不能把这个移到外面去，因为size为0也会进入函数，如果把它放到外面就会size-1，本来就是0再-1就会出问题。
//         doubly_list_node_size--;
//     }
//     else if (doubly_list_node_size > 1)
//     {
//         rear = rear->prev;
//         delete rear->next;
//         rear->next = nullptr;
//         doubly_list_node_size--;
//     }
// }
// // 头删
// void DoublyLinkedListDeque::PopFront()
// {
//     if (doubly_list_node_size == 1)
//     {
//         delete front;
//         front = nullptr;
//         rear = nullptr;
//         doubly_list_node_size--;
//     }
//     else if (doubly_list_node_size > 1)
//     {
//         front = front->next;
//         delete front->prev;
//         front->prev = nullptr;
//         doubly_list_node_size--;
//     }
// }

// int DoublyLinkedListDeque::Back()
// {
//     return (doubly_list_node_size == 0) ? -1 :rear->val;
// }

// int DoublyLinkedListDeque::Front()
// {
//     return (doubly_list_node_size == 0) ? -1 :front->val;
// }

// void DoublyLinkedListDeque::Clear()
// {
//     if (doubly_list_node_size > 0)
//     {
//         while (front->next != nullptr)
//         {
//             PopFront();
//         }
//         rear = nullptr;
//         doubly_list_node_size = 0;
//     }
// }
// // @ 双链表实现双向队列
// // 第一版-自己手撸出来的，有些地方可以进行优化，简洁高效
// #include <iostream>
// // double是一种数据类型，doubly为前缀意为双向
// struct DoublyListNode
// {
//     int val;
//     DoublyListNode *next;
//     DoublyListNode *prev;

//     DoublyListNode(int num = 0)
//         : val(num), next(nullptr), prev(nullptr) {}
// };

// class DoublyLinkedListDeque
// {
// private:
//     // 头节点
//     DoublyListNode *front;
//     // 尾节点
//     DoublyListNode *rear;
//     int doubly_list_node_size;

// public:
//     DoublyLinkedListDeque()
//         : doubly_list_node_size(0), front(nullptr), rear(nullptr) {}
//     // PushBack
//     void PushBack(int num);
//     // Empty
//     bool Empty();
//     // Size
//     int Size();

//     // PushFront
//     void PushFront(int num);
//     // PopBack
//     void PopBack();
//     // PopFront
//     void PopFront();
//     // Back
//     int Back();
//     // Front
//     int Front();
//     // Clear
//     void Clear();
// };
// int main(void)
// {
//     DoublyLinkedListDeque deque;

//     // 测试 PushBack 和 PushFront
//     deque.PushBack(1);
//     deque.PushBack(2);
//     deque.PushBack(3);
//     deque.PushFront(0);

//     std::cout << std::endl;

//     // 测试 Size 和 Empty
//     std::cout << "Deque size: " << deque.Size() << std::endl;
//     std::cout << "Is deque empty? " << (deque.Empty() ? "Yes" : "No") << std::endl;

//     // 测试 Front 和 Back
//     std::cout << "Front element: " << deque.Front() << std::endl;
//     std::cout << "Back element: " << deque.Back() << std::endl;

//     // 测试 PopFront 和 PopBack
//     deque.PopFront();
//     std::cout << "Front element: " << deque.Front() << std::endl;
//     deque.PopBack();
//     std::cout << "Back element: " << deque.Back() << std::endl;

//     // 测试 Clear
//     deque.Clear();
//     std::cout << "Deque size after clearing: " << deque.Size() << std::endl;

//     return 0;
// }

// // DoublyLinkedListDeque
// bool DoublyLinkedListDeque::Empty()
// {
//     if (doubly_list_node_size == 0)
//     {
//         return true;
//     }
//     return false;
// }

// int DoublyLinkedListDeque::Size()
// {
//     return doubly_list_node_size;
// }

// // 尾插
// void DoublyLinkedListDeque::PushBack(int num)
// {
//     DoublyListNode *new_node = new DoublyListNode(num);
//     if(doubly_list_node_size==0)
//     {
//         front = new_node;
//         rear = new_node;
//         doubly_list_node_size++;
//     }
//     else
//     {
//         new_node->prev = rear;
//         new_node->next = nullptr;
//         rear->next = new_node;
//         rear = new_node;
//         doubly_list_node_size++;
//     }
// }
// // 头插
// void DoublyLinkedListDeque::PushFront(int num)
// {
//     DoublyListNode *new_node = new DoublyListNode(num);
//     if (doubly_list_node_size == 0)
//     {
//         front = new_node;
//         rear = new_node;
//         doubly_list_node_size++;
//     }
//     else
//     {
//         new_node->next = front;
//         new_node->prev = nullptr;
//         front->prev = new_node;
//         front = new_node;
//         doubly_list_node_size++;
//     }
// }
// // 没处理只有一个的情况
// void DoublyLinkedListDeque::PopBack()
// {
//     if(doubly_list_node_size==0)
//     {

//     }
//     else if(doubly_list_node_size==1)
//     {
//         DoublyListNode *temp = front;
//         delete temp;
//         temp = nullptr;
//         front = nullptr;
//         rear = nullptr;
//     }
//     else
//     {
//         rear = rear->prev;
//         DoublyListNode *temp = rear->next;
//         rear->next = nullptr;
//         temp->prev = nullptr;
//         delete temp;
//         temp = nullptr;
//         doubly_list_node_size--;
//     }
// }
// // 头删
// void DoublyLinkedListDeque::PopFront()
// {
//     if (doubly_list_node_size == 0)
//     {
//     }
//     else if (doubly_list_node_size == 1)
//     {
//         DoublyListNode *temp = front;
//         delete temp;
//         temp = nullptr;
//         front = nullptr;
//         rear = nullptr;
//     }
//     else
//     {
//         front = front->next;
//         DoublyListNode *temp = front->prev;
//         temp->next = nullptr;
//         front->prev = nullptr;
//         delete temp;
//         temp = nullptr;
//         doubly_list_node_size--;
//     }
// }

// int DoublyLinkedListDeque::Back()
// {
//     if(doubly_list_node_size==0)
//     {
//         return -1;
//     }
//     else
//     {
//         return rear->val;
//     }
// }

// int DoublyLinkedListDeque::Front()
// {
//     if(doubly_list_node_size==0)
//     {
//         return -1;
//     }
//     else
//     {
//         return front->val;
//     }
// }

// void DoublyLinkedListDeque::Clear()
// {
//     if(doubly_list_node_size==0)
//     {

//     }
//     else
//     {
//         while(front->next!=nullptr)
//         {
//             PopFront();
//         }
//         delete rear;
//         rear = nullptr;
//         doubly_list_node_size = 0;
//     }
// }
