
// // @初探哈希表
// #include <iostream>
// // 需要包含头文件，ordered是无序的意思
// #include <unordered_map>
// int main()
// {
//     std::unordered_map<int, std::string> my_map;

//     my_map[12345] = "your";
//     my_map[12346] = "name";

//     std::string text = my_map[12345];

//     // unordered就是不会按照顺序把元素打印出来的，可以看到输出结果是 name your
//     for (auto kv : my_map)
//     {
//         std::cout << kv.first << "->" << kv.second << std::endl;
//     }

//     my_map.erase(12345);

//     for (auto it = my_map.begin(); it != my_map.end(); it++)
//     {
//         std::cout << it->first << " -> " << it->second << std::endl;
//     }
//     return 0;
// }

// // @简单实现哈希表
// // 底层实现就是数组，用数组下标作为所谓哈希值，然后通过直接取模得出，对应索引，哈希函数相当简单

// #include <iostream>
// #include <string>
// #include <vector>
// // c++中有这个类模板，就是一对的意思，类模板可以存任意两个类型的一对值，比如用作一个键值对，现在我自己写一个Pair
// struct Pair
// {
//     // 键
//     int key;
//     // 值
//     std::string val;

//     // 默认构造函数
//     Pair(int key, std::string val)
//     {
//         this->key = key;
//         this->val = val;
//     }
// };

// class ArrayHashMap
// {
// private:
//     // 这里存放指针更加高效
//     std::vector<Pair *> buckets_;
//     const int kCapacity_;

// public:
//     // 默认构造函数
//     ArrayHashMap();
//     // 析构函数
//     ~ArrayHashMap();

//     int HashFuntion(int key);
//     // 增
//     void Push(int key, std::string val);
//     // 删
//     void Remove(int key);
//     // 查
//     std::string Get(int key);
//     // 改
//     void Change(int key, std::string val);
//     // 打印
//     void PrintPair();
// };

// int main()
// {
//     ArrayHashMap map;

//     // 添加键值对
//     map.Push(12357, "Hello");
//     map.Push(46889, "Hash");
//     map.Push(23436, "Table");

//     // 打印哈希表
//     std::cout << "Initial ArrayHashMap:" << std::endl;
//     map.PrintPair();

//     // 修改值
//     map.Change(46889, "ArrayHash");
//     map.Change(23436, "Map");

//     std::cout << "\nAfter ArrayHashMap:" << std::endl;
//     map.PrintPair();

//     // 获取值
//     std::cout << "\nValue for key 12357: " << map.Get(12357) << std::endl;
//     std::cout << "Value for key 23436: " << map.Get(23436) << std::endl;
//     std::cout << "Value for key 46889: " << map.Get(46889) << std::endl;

//     // 移除键值对
//     map.Remove(12357);
//     map.Remove(23436);

//     std::cout << "\nAfter Removal:" << std::endl;
//     map.PrintPair();

//     return 0;
// }

// // *ArrayHashMap*

// ArrayHashMap::ArrayHashMap()
//     : kCapacity_(100)
// {
//     // 创建100个桶，桶中存放的都是Pair类型的指针
//     buckets_ = std::vector<Pair *>(kCapacity_);
// }

// ArrayHashMap::~ArrayHashMap()
// {
//     // 释放内存，这里传引用进去，需要修改值
//     for (const auto &bucket : buckets_)
//     {
//         delete bucket;
//     }
//     buckets_.clear();
// }

// // 简单的哈希函数
// int ArrayHashMap::HashFuntion(int key)
// {
//     // 就是直接把key键对容量取模
//     int index = key % kCapacity_;
//     return index;
// }

// // 增添元素
// void ArrayHashMap::Push(int key, std::string val)
// {
//     // new一块键值对
//     Pair *new_pair = new Pair(key, val);
//     // 找到下标
//     int index = HashFuntion(key);
//     // 对应下标存放键值对
//     buckets_[index] = new_pair;
// }
// // 删除元素
// void ArrayHashMap::Remove(int key)
// {
//     // 找到下标
//     int index = HashFuntion(key);
//     // delete对应下标的桶
//     delete buckets_[index];
//     // 注意delete之后需要将对应下标的桶指向nullptr
//     buckets_[index] = nullptr;
// }
// // 查找元素
// std::string ArrayHashMap::Get(int key)
// {
//     // 找到下标
//     int index = HashFuntion(key);
//     // 这里注意一种情况当桶里面是空指针时就不能返回val，此时是空指针没有val
//     if (buckets_[index] == nullptr)
//     {
//         // 空指针就直接返回空字符串
//         return "";
//     }
//     return buckets_[index]->val;
// }
// // 更改元素
// void ArrayHashMap::Change(int key, std::string val)
// {
//     // 找到下标
//     int index = HashFuntion(key);
//     // 修改对应下标的值
//     buckets_[index]->val = val;
// }
// // 打印哈希表
// void ArrayHashMap::PrintPair()
// {
//     // 从0下标开始遍历数组，找到不为空的桶，并且打印输出下标和val，此时是找不到key的，无法通过哈希值也就是下标来反向寻找键key，一个键就对应一个下标，是唯一的
//     for (int i(0); i < kCapacity_;i++)
//     {
//         if(buckets_[i]!=nullptr)
//         {
//             std::cout << "index = " << i << ", val = " << buckets_[i]->val << std::endl;
//         }
//     }
// }

// // 戒骄戒躁
// // @用动态数组实现哈希表
// #include <iostream>
// #include <vector>
// #include <string>

// struct Pair
// {
//     // 键
//     int key;
//     // 值
//     std::string val;

//     // 默认构造函数
//     Pair(int key, std::string val)
//     {
//         this->key = key;
//         this->val = val;
//     }
// };
// // chaining 链地址法 本来是要用链表的，用动态数组更加方便
// class HashMapChaining
// {
// private:
//     int size_;                                 // 键值对数量
//     int capacity_;                             // 哈希表容量
//     double load_thres_;                        // 触发扩容的负载因子阈值
//     int extend_ratio_;                         // 扩容倍数
//     std::vector<std::vector<Pair *>> buckets_; // 桶数组
// public:
//     // 构造
//     HashMapChaining();
//     // 析构
//     ~HashMapChaining();
//     // 哈希函数
//     int HashFunction(int key);
//     // 负载因子
//     double load_factor();
//     // 增
//     void Push(int key, std::string val);
//     // 扩容
//     void Expand();
//     // 删
//     void Remove(int key);
//     // 更新
//     void Change(int key, std::string val);
//     // 查
//     std::string Find(int key);
//     // 打印
//     void PrintHashMapChaining();
// };

// int main()
// {
//     HashMapChaining hashMap;

//     // 插入键值对
//     hashMap.Push(11111, "One");
//     hashMap.Push(22222, "Two");
//     hashMap.Push(33333, "Three");
//     hashMap.Push(44444, "Four");

//     // 输出当前哈希表内容
//     hashMap.PrintHashMapChaining();

//     // 修改键为 2 的值
//     hashMap.Change(22222, "New Two");

//     // 输出修改后的哈希表内容
//     hashMap.PrintHashMapChaining();

//     // 删除键为 3 的键值对
//     hashMap.Remove(33333);

//     // 输出删除后的哈希表内容
//     hashMap.PrintHashMapChaining();

//     return 0;
// }

// // HashMapChaining

// HashMapChaining::HashMapChaining()
//     : size_(0), capacity_(4), load_thres_(2.0 / 3.0), extend_ratio_(2)
// {
//     // resize 是重新调整大小的操作，如果大于当前大小则向vector添加新的元素，如果capacity小于当前大小，则删除多余元素。
//     buckets_.resize(capacity_);
// }

// // 析构函数释放内存
// HashMapChaining::~HashMapChaining()
// {
//     for (auto &bucket : buckets_)
//     {
//         for (Pair *pair : bucket)
//         {
//             delete pair;
//         }
//     }
// }
// // 负载因子
// inline double HashMapChaining::load_factor()
// {
//     // 返回当时的负载因子，如果超过了开始设定的2/3，就会发生扩容
//     return (double)size_ / (double)capacity_;
// }

// // 哈希函数-就是简单的取模
// inline int HashMapChaining::HashFunction(int key)
// {
//     return key % capacity_;
// }

// // 增加元素
// void HashMapChaining::Push(int key, std::string val)
// {
//     // 需要注意扩容操作，如果此时负载因子大于阈值则发生扩容
//     if (load_factor() > load_thres_)
//     {
//         Expand();
//     }
//     // 找下标
//     int index = HashFunction(key);
//     // 桶里面装的还是桶，是动态数组，直接用emplace_back即可完成插入元素。
//     buckets_[index].emplace_back(new Pair(key, val));
//     size_++;
// }

// // 不单单是容量变化因为你哈希函数中计算出的哈希值是根据容量算的，扩容之后容量变了对应的哈希值也就变了
// void HashMapChaining::Expand()
// {
//     // 精髓在此处
//     // 首先先创建一个临时的桶来装原来所有桶的元素，发生的是拷贝构造函数
//     std::vector<std::vector<Pair *>> buckets_tmp = buckets_;
//     // 扩容操作
//     capacity_ = capacity_ * extend_ratio_;
//     // 清空原来的桶，为何？ 是因为新的桶容量变大后，key所对应的索引也会变化，因此把原桶清空再一个个插入新桶即可
//     buckets_.clear();
//     // 重新定义容量
//     buckets_.resize(capacity_);
//     // 让size归0 ，因为你push函数里面是有size++的
//     size_ = 0;
//     // 传引用进去，然后一个个用push从临时桶出去再进入新桶，并且删除了旧桶的内存
//     for (auto &bucket : buckets_tmp)
//     {
//         for (Pair *pair : bucket)
//         {
//             Push(pair->key, pair->val);
//             delete pair;
//         }
//     }
// }

// // 删除元素还是找索引，进入二级桶遍历每一块pair如果key相同则删除size--
// void HashMapChaining::Remove(int key)
// {
//     int index = HashFunction(key);
//     auto &bucket = buckets_[index];
//     // 遍历桶，从中删除键值对
//     for (int i = 0; i < bucket.size(); i++)
//     {
//         if (bucket[i]->key == key)
//         {
//             Pair *tmp = bucket[i];
//             bucket.erase(bucket.begin() + i); // 从中删除键值对
//             delete tmp;                       // 释放内存
//             size_--;
//             // 小技巧，如果找到之后就不需要再进行遍历找元素了，直接返回即可，就算无返回值，也可以使用return，提前结束掉函数。
//             return;
//         }
//     }
// }
// // 更新元素
// void HashMapChaining::Change(int key, std::string val)
// {
//     int index = HashFunction(key);

//     for (Pair *pair : buckets_[index])
//     {
//         if (pair->key == key)
//         {
//             pair->val = val;
//             return;
//         }
//     }
// }
// //查找元素
// std::string HashMapChaining::Find(int key)
// {
//     int index = HashFunction(key);

//     for (Pair *pair : buckets_[index])
//     {
//         if (pair->key == key)
//         {
//             return pair->val;
//         }
//     }
//     return "";
// }
// //打印
// void HashMapChaining::PrintHashMapChaining()
// {
//     for (auto const bucket : buckets_)
//     {
//         for (Pair *const pair : bucket)
//         {
//             std::cout << "key = " << pair->key << " , val = " << pair->val << std::endl;
//         }
//     }
// }

// // @二叉树-二叉搜索树
// #include <iostream>
// #include <queue>
// #include <vector>
// #include <stack>
// #include <cstdlib>
// #include <ctime>

// // 树节点
// template <typename ValType>
// struct TreeNode
// {
//     ValType val;
//     // 左指针
//     TreeNode *left;
//     // 右指针
//     TreeNode *right;

//     TreeNode(ValType value)
//         : val(value), left(nullptr), right(nullptr) {}
// };

// template <class ValType>
// class BinaryTree
// {
// private:
//     TreeNode<ValType> *root_;

// public:
//     // 析构函数初始化root_
//     BinaryTree();
//     // 析构调用删除函数
//     ~BinaryTree();

//     // 插入节点:
//     // 普通二叉树 递归实现 插入节点。这就是随机插入生成效率太低了只是写一下。
//     void InsertAny(TreeNode<ValType> *node, ValType val);
//     // 二叉搜索树 递归实现 插入节点
//     void InsertBinarySearchTreeNodeRecursion(TreeNode<ValType> *&node, ValType val);
//     // 二叉搜索树 循环实现 插入节点
//     void InsertBSTNodeWhile(ValType val);

//     // 删除节点:
//     //从二叉树中删除指定节点和该节点的子树
//     void RemoveTreeNodeAndAllChildTreeWhile(ValType val);

//     // 查找节点:
//     // 在二叉树中查找具有特定值的节点。
//     TreeNode<ValType> *FindTreeNode(ValType val);

//     // 遍历二叉树:
//     // 以某种顺序访问二叉树中的所有节点，包括前序、中序和后序遍历，以及层序遍历等。
//     // 中序遍历打印，升序且顺序。
//     void InOrderTraversal(TreeNode<ValType> *node);

//     // 获取根节点
//     TreeNode<ValType> *GetRoot() const;

//     // 获取树的高度:
//     // 高度是从叶节点到当前节点，也就是说叶节点的高度是0
//     int GetTreeNodeHight(TreeNode<ValType> *node);

//     // 获取树的深度:
//     // 深度是从根节点到当前节点，也就是说根节点的深度是0
//     int GetTreeNodeDepth(TreeNode<ValType> *node);

//     // 判断树是否为空：判断二叉树是否为空树。
//     bool IsEmptyTree();

//     // 销毁二叉树:
//     // 释放二叉树的所有节点内存。
//     // 循环删除
//     void DestroyTreeWhile();
//     // 由于需要频繁递归，这里用inline更加合适，极致效率。
//     // 递归删除
//     inline void DestroyTreeRecursion(TreeNode<ValType> *node);

//     // 其他功能：根据需要，可能还需要实现节点的旋转、查找最大值或最小值等功能。
// };

// int main(void)
// {
//     // 生成随机数，知识点很多。
//     // srand函数是生成随机数，需要传入种子类似就是给这个函数模板按照这个模板来生成随机数。需要包含头文件<cstdlib>
//     // static_cast是类型转换操作符，其实也可以直接用强转(unsigned_int),前者更加正式，后者更加简洁。
//     // time是一个函数需要包含头文件<ctime>，从某个时间到现在时间所经历的秒数。
//     srand(static_cast<unsigned int>(time(nullptr)));

//     // 创建一个二叉搜索树
//     BinaryTree<int> tree;

//     // 插入一些节点
//     tree.InsertBSTNodeWhile(5);
//     tree.InsertBSTNodeWhile(3);
//     tree.InsertBSTNodeWhile(7);
//     tree.InsertBSTNodeWhile(1);
//     tree.InsertBSTNodeWhile(4);
//     tree.InsertBSTNodeWhile(6);
//     tree.InsertBSTNodeWhile(0);
//     tree.InsertBSTNodeWhile(2);

//     // 插入重复节点
//     tree.InsertBSTNodeWhile(6);
//     // 获得根节点地址
//     TreeNode<int> *root = tree.GetRoot();

//     // 用递归函数插入节点
//     tree.InsertBinarySearchTreeNodeRecursion(root, 10);
//     tree.InsertBinarySearchTreeNodeRecursion(root, 8);
//     tree.InsertBinarySearchTreeNodeRecursion(root, 9);

//     // 中序遍历打印节点值
//     std::cout << "Inorder Traversal: ";
//     tree.InOrderTraversal(root);
//     std::cout << std::endl;

//     // 深度，从根节点到该节点
//     TreeNode<int> *node = tree.FindTreeNode(0);
//     if (node != nullptr)
//     {
//         std::cout << "Depth of node 4: " << tree.GetTreeNodeDepth(node) << std::endl;
//     }

//     // 高度是最大高度，是最远叶节点到该节点的高度。
//     node = tree.FindTreeNode(7);
//     if (node != nullptr)
//     {
//         std::cout << "Hight of node 4: " << tree.GetTreeNodeHight(node) << std::endl;
//     }

//     // 高度
//     node = tree.FindTreeNode(9);
//     if (node != nullptr)
//     {
//         std::cout << "Hight of node 4: " << tree.GetTreeNodeHight(node) << std::endl;
//     }
//     // 移除元素7
//     tree.RemoveTreeNodeAndAllChildTreeWhile(7);

//     // 中序遍历打印
//     std::cout << "Inorder Traversal: ";
//     tree.InOrderTraversal(root);
//     std::cout << std::endl;

//     // 释放整个树
//     tree.DestroyTreeWhile();

//     // 注意这个地方，释放整个树是动了root_的（让root_地址为nullptr），而root还存者原来root_的地址，此时需要更新地址。
//     root = tree.GetRoot();

//     //中序遍历打印
//     std::cout << "Inorder Traversal: ";
//     // 如果此时不更新就会出现野指针
//     tree.InOrderTraversal(root);
//     std::cout << std::endl;

//     // 判断是否为空
//     std::cout << "Binary Search Tree is empty :" << tree.IsEmptyTree() << std::endl;

//     return 0;
// }

// // 循环实现释放内存
// // DFS 深度优先搜索，是从右子树开始释放，属于 pre_order 前序遍历
// // 循环实现，不会导致栈的溢出，相对应的性能也会更好，就是不太好理解。
// // 通过栈stack为容器实现，先入后出尾插尾删。
// template <class ValType>
// void BinaryTree<ValType>::DestroyTreeWhile()
// {
//     // 如果根节点为空则直接返回
//     if (root_ == nullptr)
//     {
//         return;
//     }
//     else
//     {
//         // 创建一个栈stack nodes来存储节点
//         std::stack<TreeNode<ValType> *> nodes;
//         // 插入根节点
//         nodes.push(root_);
//         // 当容器为空时结束循环
//         while (!nodes.empty())
//         {
//             // cur指针指向栈顶，top函数返回值为引用，这个地方我是有点迷惑的。
//             // 这个地方是发生了隐式转换，可以把引用近似的理解为取地址，左值是指针，右值约等于取地址。
//             TreeNode<ValType> *cur = nodes.top();
//             // 弹出了栈顶节点，注意这个地方弹出只是移出容器而不是删掉，前面存了指针，还可以进行后续操作
//             nodes.pop();
//             // 如果左节点不为空则插入其左节点
//             if (cur->left != nullptr)
//             {
//                 nodes.push(cur->left);
//             }
//             // 如果右节点不为空则插入其右节点
//             if (cur->right != nullptr)
//             {
//                 nodes.push(cur->right);
//             }

//             // 释放该节点内存，等第二次进入循环则cur又被创建然后指向栈顶元素
//             delete cur;
//         }
//     }
//     // 总的过程就是先从根节点开始，先压入栈然后再弹出，把它的左右节点都压入栈，最后释放掉根节点内存，完成一次循环。
//     // 此后栈中存在俩个元素，根的左右子节点。然后还是弹出父节点，左右子节点进去，释放父节点内存，
//     root_ = nullptr;
// }

// // DFS 深度优先搜索，也是后序遍历 Post-order 和循环实现的前序遍历 Pre_order 逻辑有所区别
// // 递归实现，代码直观，如果递归深度过深时可能会导致栈溢出的问题，因此也可以使用循环实现，效率更高，但是代码会复杂。
// template <typename ValType>
// void BinaryTree<ValType>::DestroyTreeRecursion(TreeNode<ValType> *node)
// {
//     // 这个地方是删除元素的函数中嵌套了这个函数，而当我们释放完之后没有需要将root_置空，这样在输出时传root_进去才不会出问题
//     if (node == root_)
//     {
//         if (node == nullptr)
//         {
//             return;
//         }
//         else
//         {
//             // 灵活使用递归
//             // 递归逻辑就是一条路走到底，直到叶节点，然后删除，到父节点的右侧再走到底直到叶节点
//             DestroyTreeRecursion(node->left);
//             DestroyTreeRecursion(node->right);
//             delete node;
//         }
//         root_ = nullptr;
//     }
//     else if (node != root_)
//     {// 如果传进来的不是root_则说明时其他节点就说明是移除元素的函数调用此时并不会完全释放掉所有元素因此不需要置空
//         if (node == nullptr)
//         {
//             return;
//         }
//         else
//         {
//             // 灵活使用递归
//             // 递归逻辑就是一条路走到底，直到叶节点，然后删除，到父节点的右侧再走到底直到叶节点
//             DestroyTreeRecursion(node->left);
//             DestroyTreeRecursion(node->right);
//             delete node;
//         }
//     }
// }

// // 构造函数root_置空
// template <typename ValType>
// BinaryTree<ValType>::BinaryTree()
//     : root_(nullptr) {}

// // 析构是没有参数的，因此如果用递归实现释放内存就需要再创建一个函数，因为需要传节点进去。
// // 如果是用循环则可以直接写在析构函数里面。
// template <typename ValType>
// BinaryTree<ValType>::~BinaryTree()
// {
//     // DestroyTreeRecursion(root_);
//     // 不需要传值进去
//     DestroyTreeWhile();
// }

// // 任意随机插入节点生成普通二叉树，没意义
// template <typename ValType>
// void BinaryTree<ValType>::InsertAny(TreeNode<ValType> *node, ValType val)
// {
//     if (node == nullptr)
//     {
//         node = new TreeNode<ValType>;
//         node->val = val;
//         return;
//     }

//     if (rand() % 2 == 0)
//     {
//         if (node->left != nullptr)
//         {
//             InsertAny(node->left);
//         }
//         else if (node->right != nullptr)
//         {
//             InsertAny(node->right);
//         }
//     }
//     else
//     {
//         if (node->left != nullptr)
//         {
//             InsertAny(node->left, val);
//         }
//         else if (node->right != nullptr)
//         {
//             InsertAny(node->right, val);
//         }
//     }
// }

// // 首先是递归思想的实现，其次*&的使用，想清楚.还可以实现一种用while循环实现的。
// template <typename ValType>
// void BinaryTree<ValType>::InsertBinarySearchTreeNodeRecursion(TreeNode<ValType> *&node, ValType val)
// {
//     // 一开始是只穿了*指针进去企图改树，但是请注意，比如说一开始root_为空时传进去，node是保存了new的新内存但是，不是对root_的修改
//     // node只是形参，接收了root_的地址然后进行后续的成树，因为这个地方不是把new的节点接入root_的左右而是直接以新的节点的地址开始成树。
//     // 因此你需要传指针的引用进去完成对root_的值的改变，new的新内存地址存在了node形参上
//     if (node == nullptr)
//     {
//         node = new TreeNode<ValType>(val);
//         return;
//     }

//     if (val < node->val)
//     {
//         if (node->left == nullptr)
//         {
//             node->left = new TreeNode<ValType>(val);
//         }
//         else
//         {
//             InsertBinarySearchTreeNodeRecursion(node->left, val);
//         }
//     }
//     else if (val > node->val)
//     {
//         if (node->right == nullptr)
//         {
//             node->right = new TreeNode<ValType>(val);
//         }
//         else
//         {
//             InsertBinarySearchTreeNodeRecursion(node->right, val);
//         }
//     }
// }

// // 二叉搜索树循环插入元素
// template <typename ValType>
// void BinaryTree<ValType>::InsertBSTNodeWhile(ValType val)
// {
//     // 当树为空时，插入一个新节点
//     if (root_ == nullptr)
//     {
//         root_ = new TreeNode<ValType>(val);
//         return;
//     }

//     TreeNode<ValType> *cur = root_;
//     TreeNode<ValType> *pre = nullptr;

//     // 根节点不为空的时候，循环到最后cur指向nullptr截止，此时cur指向nullptr，pre指向父节点。
//     // 循环结束是pre已经指向要插入节点的父节点，后续只需要判断插入父节点左边还是右边。
//     while (cur != nullptr)
//     {
//         if (val > cur->val)
//         {
//             pre = cur;
//             cur = cur->right;
//         }
//         else if (val < cur->val)
//         {
//             pre = cur;
//             cur = cur->left;
//         }
//         // 重复元素直接退出函数
//         else if (val == cur->val)
//         {
//             return;
//         }
//     }

//     // 插入节点，只需要判断插左边还是插入右边即可
//     if (val < pre->val)
//     {
//         pre->left = new TreeNode<ValType>(val);
//     }
//     else if (val > pre->val)
//     {
//         pre->right = new TreeNode<ValType>(val);
//     }
// }

// // 查找元素
// template <typename ValType>
// TreeNode<ValType> *BinaryTree<ValType>::FindTreeNode(ValType val)
// {
//     if (root_ == nullptr)
//     {
//         return nullptr;
//     }

//     TreeNode<ValType> *cur = root_;

//     while (cur != nullptr)
//     {
//         if (val > cur->val)
//         {
//             cur = cur->right;
//         }
//         else if (val < cur->val)
//         {
//             cur = cur->left;
//         }
//         else
//         {
//             break;
//         }
//     }

//     return cur;
// }

// // 删除节点包括其子树。
// template <typename ValType>
// void BinaryTree<ValType>::RemoveTreeNodeAndAllChildTreeWhile(ValType val)
// {
//     if (root_ == nullptr)
//     {
//         return;
//     }

//     TreeNode<ValType> *cur = root_;
//     TreeNode<ValType> *parent = nullptr;

//     while (cur != nullptr)
//     {
//         if (val == cur->val)
//         {
//             break;
//         }
//         else if (val < cur->val)
//         {
//             parent = cur;
//             cur = cur->left;
//         }
//         else
//         {
//             parent = cur;
//             cur = cur->right;
//         }
//     }

//     if (cur == nullptr)
//     {
//         // 没找到要删除的节点
//         return;
//     }

//     // 删除节点
//     DestroyTreeRecursion(cur);

//     // 更新父节点指针
//     if (parent != nullptr)
//     {
//         if (parent->left == cur)
//         {
//             parent->left = nullptr;
//         }
//         else
//         {
//             parent->right = nullptr;
//         }
//     }
//     else
//     {
//         root_ = nullptr;
//     }
// }

// // 判断是否为空
// template <typename ValType>
// bool BinaryTree<ValType>::IsEmptyTree()
// {
//     if (root_ == nullptr)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// // 获得高度，高度是从叶节点到该节点 递归实现， 这个个人感觉非常巧妙我看GPT的。
// template <typename ValType>
// int BinaryTree<ValType>::GetTreeNodeHight(TreeNode<ValType> *node)
// {
//     // 要领悟到递归的精髓
//     // 如果传进来的节点是空指针直接返回-1，计算不了
//     if (node == nullptr)
//     {
//         // 这个-1的值设置的也非常巧妙
//         return -1;
//     }
//     // 进来算左右子树的高度，进递归，到最末的状态就是node为空指针，此时左右子树的返回值都是-1然后三目运算符相等给值变为0，上一层左右又都是0加一上一层变为1.继续递归下去。递归可以解决不是平衡树的问题。
//     int left_Child_tree_hight = GetTreeNodeHight(node->left);
//     int right_Child_tree_hight = GetTreeNodeHight(node->right);

//     return left_Child_tree_hight > right_Child_tree_hight
//                ? left_Child_tree_hight + 1
//                : right_Child_tree_hight + 1;
// }

// // 获得深度，深度是从根节点到该节点
// template <typename ValType>
// int BinaryTree<ValType>::GetTreeNodeDepth(TreeNode<ValType> *node)
// {
//     int depth(0);
//     // 树为空返回-1，如果节点传进来为空，判断不了在哪里也就只能返回-1
//     if (root_ == nullptr || node == nullptr)
//     {
//         return -1;
//     }
//     // 承接根节点遍历并且计数，相等时返回深度，从根节点到该节点
//     TreeNode<ValType> *cur = root_;

//     while (cur != nullptr)
//     {
//         if (node->val > cur->val)
//         {
//             depth++;
//             cur = cur->right;
//         }
//         else if (node->val < cur->val)
//         {
//             depth++;
//             cur = cur->left;
//         }
//         else if (node->val == cur->val)
//         {
//             return depth;
//         }
//     }

//     return -1;
// }

// // 中序遍历打印节点值的实现-GPT的后续再看看现在不想弄了
// template <typename ValType>
// void BinaryTree<ValType>::InOrderTraversal(TreeNode<ValType> *node)
// {
//     if (node == nullptr)
//     {
//         return;
//     }

//     InOrderTraversal(node->left);
//     std::cout << node->val << " ";
//     InOrderTraversal(node->right);
// }
// // 访问root_
// template <typename ValType>
// TreeNode<ValType> *BinaryTree<ValType>::GetRoot() const
// {
//     return root_;
// }

// //@ 手搓AVL树
// // 既是二叉搜索树也是而二叉平衡树
// #include <iostream>
// #include <algorithm>
// #include <iomanip>
// struct TreeNode
// {
//     int val_{};
//     int hight = 0;
//     TreeNode *left{};
//     TreeNode *right{};
//     TreeNode() = default;
//     explicit TreeNode(int val)
//         : val_(val) {}
// };

// class AVLTree
// {
// private:
//     TreeNode *root_;

// public:
//     AVLTree()
//         : root_(nullptr) {}
//     inline int GetHight(TreeNode *node);
//     void UpdateHight(TreeNode *node);
//     int BalanceFactor(TreeNode *node);
//     TreeNode *RightRotate(TreeNode *node);
//     TreeNode *LeftRotate(TreeNode *node);
//     TreeNode *Rotate(TreeNode *node);
//     void Insert(int val);
//     TreeNode *InsertHelper(TreeNode *node, int val);
//     void Remove(int val);
//     TreeNode *RemoveHelper(TreeNode *node, int val);
//     void PrintTree(TreeNode *node, int space);
//     TreeNode *GetRoot();
// };
// int main()
// {
//     AVLTree avl;

//     // 插入测试
//     avl.Insert(10);
//     avl.Insert(11);
//     avl.Insert(20);
//     avl.Insert(30);
//     avl.Insert(50);
//     avl.Insert(55);
//     avl.Insert(90);
//     avl.Insert(80);
//     avl.Insert(35);
//     avl.Insert(33);
//     avl.Insert(40);
//     avl.Insert(46);
//     avl.Insert(25);

//     std::cout << "Tree structure:" << std::endl;
//     avl.PrintTree(avl.GetRoot(), 0);

//     // 删除测试
//     avl.Remove(35);
//     avl.Remove(20);

//     std::cout<<std::endl;
//     std::cout<<std::endl;
//     // 打印树
//     std::cout << "Tree structure:" << std::endl;
//     avl.PrintTree(avl.GetRoot(), 0);

//     return 0;
// }
// // AVLTree

// int AVLTree::GetHight(TreeNode *node)
// {
//     return node == nullptr ? -1 : node->hight;
// }

// void AVLTree::UpdateHight(TreeNode *node)
// {
//     if (node == nullptr)
//     {
//         return;
//     }

//     node->hight = std::max(GetHight(node->left), GetHight(node->right)) + 1;
// }

// int AVLTree::BalanceFactor(TreeNode *node)
// {
//     if (node == nullptr)
//     {
//         return 0;
//     }
//     // 平衡二叉树的条件左右子树的高度差 -1到1
//     return GetHight(node->left) - GetHight(node->right);
// }


// TreeNode *AVLTree::RightRotate(TreeNode *node)
// {

//     TreeNode *child = node->left;
//     TreeNode *grand_child = node->left->right;
//     child->right = node;
//     node->left = grand_child;

//     // 只有这两个节点的高度改变了
//     UpdateHight(child);
//     UpdateHight(node);

//     return child;
// }

// TreeNode *AVLTree::LeftRotate(TreeNode *node)
// {

//     TreeNode *child = node->right;

//     TreeNode *grand_child = node->right->left;
//     node->right = grand_child;
//     child->left = node;

//     UpdateHight(node);
//     UpdateHight(child);

//     return child;
// }

// TreeNode *AVLTree::Rotate(TreeNode *node)
// {
//     int balance_factor = BalanceFactor(node);
//     if (balance_factor > 1)
//     {
//         if (BalanceFactor(node->left) >= 0)
//         {
//             return RightRotate(node);
//         }
//         else if (BalanceFactor(node) < 0)
//         {
//             node->left = LeftRotate(node->left);
//             return RightRotate(node);
//         }
//     }

//     if (balance_factor < -1)
//     {
//         if (BalanceFactor(node) <= 0)
//         {
//             return LeftRotate(node);
//         }
//         else if (BalanceFactor(node) > 0)
//         {
//             node->right = RightRotate(node->right);
//             return LeftRotate(node);
//         }
//     }

//     return node;
// }

// void AVLTree::Insert(int val)
// {
//     root_ = InsertHelper(root_, val);
// }

// TreeNode *AVLTree::InsertHelper(TreeNode *node, int val)
// {
//     if (node == nullptr)
//     {
//         return new TreeNode(val);
//     }

//     if (val > node->val_)
//     {
//         node->right = InsertHelper(node->right, val);
//     }
//     else if (val < node->val_)
//     {
//         node->left = InsertHelper(node->left, val);
//     }
//     else if (val == node->val_)
//     {
//         return node;
//     }

//     UpdateHight(node);
//     node = Rotate(node);

//     return node;
// }

// void AVLTree::Remove(int val)
// {
//     root_ = RemoveHelper(root_, val);
// }
// /* 递归删除节点（辅助方法） */
// TreeNode *AVLTree::RemoveHelper(TreeNode *node, int val)
// {
//     if (node == nullptr)
//         return nullptr;
//     /* 1. 查找节点并删除 */
//     if (val < node->val_)
//         node->left = RemoveHelper(node->left, val);
//     else if (val > node->val_)
//         node->right = RemoveHelper(node->right, val);
//     else
//     {
//         if (node->left == nullptr || node->right == nullptr)
//         {
//             TreeNode *child = node->left != nullptr ? node->left : node->right;
//             // 子节点数量 = 0 ，直接删除 node 并返回
//             if (child == nullptr)
//             {
//                 delete node;
//                 return nullptr;
//             }
//             // 子节点数量 = 1 ，直接删除 node
//             else
//             {
//                 delete node;
//                 node = child;
//             }
//         }
//         else
//         {
//             // 子节点数量 = 2 ，则将中序遍历的下个节点删除，并用该节点替换当前节点
//             TreeNode *temp = node->right;
//             while (temp->left != nullptr)
//             {
//                 temp = temp->left;
//             }
//             int tempVal = temp->val_;
//             node->right = RemoveHelper(node->right, temp->val_);
//             node->val_ = tempVal;
//         }
//     }
//     UpdateHight(node); // 更新节点高度
//     /* 2. 执行旋转操作，使该子树重新恢复平衡 */
//     node = Rotate(node);
//     // 返回子树的根节点
//     return node;
// }

// TreeNode *AVLTree::GetRoot()
// {
//     return root_;
// }

// void AVLTree::PrintTree(TreeNode *node, int level)
// {
//     if (node == nullptr)
//     {
//         return;
//     }

//     PrintTree(node->right, level + 1);

//     if (level != 0)
//     {
//         for (int i = 0; i < level - 1; i++)
//         {
//             std::cout << "|\t";
//         }
//         std::cout << "|-------";
//     }

//     std::cout << node->val_ << std::endl;

//     PrintTree(node->left, level + 1);
// }

//@ 初探堆
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>

int main(void)
{
    // 创建优先队列
    std::priority_queue<int> pq;

    // 底层容器是 vector
    // greater 与 less 是比较器 你想要大顶堆就对应 less ，想要小顶堆对应 greater
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    // 默认的是大顶堆
    std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;


    pq.push(1);
    pq.push(3);
    pq.push(7);
    pq.push(9);
    pq.push(4);
    pq.push(5);


    min_heap.push(1);
    min_heap.push(3);
    min_heap.push(7);
    min_heap.push(9);
    min_heap.push(4);
    min_heap.push(5);

    max_heap.push(1);
    max_heap.push(3);
    max_heap.push(7);
    max_heap.push(9);
    max_heap.push(4);
    max_heap.push(5);


    // 由此可见优先队列默认的是大顶堆
    std::cout << "堆顶元素的值为:" << pq.top()<<std::endl;

    pq.pop();
    std::cout << "堆顶元素的值为:" << pq.top()<<std::endl;
    std::cout << "是否为空:" << pq.empty() << std::endl;



    std::cout << "堆顶元素的值为:" << min_heap.top()<<std::endl;

    min_heap.pop();
    std::cout << "堆顶元素的值为:" << min_heap.top()<<std::endl;
    std::cout << "是否为空:" << min_heap.empty() << std::endl;
    
    std::cout << "堆顶元素的值为:" << max_heap.top()<<std::endl;

    max_heap.pop();
    std::cout << "堆顶元素的值为:" << max_heap.top()<<std::endl;
    std::cout << "是否为空:" << max_heap.empty() << std::endl;

    // 也可以先创建一个底层容器vector，然后在用迭代器完成转化为堆
    std::vector<int> input{1, 2, 3, 4, 7 ,8, 9, 5, 4, 3};
    std::priority_queue<int> max_heap_1(input.begin(), input.end());

    std::cout << "堆顶元素的值为:" << max_heap_1.top()<<std::endl;

    max_heap_1.pop();
    std::cout << "堆顶元素的值为:" << max_heap_1.top()<<std::endl;
    std::cout << "是否为空:" << max_heap_1.empty() << std::endl;

    std::make_heap(input.begin(), input.end(), std::greater<int>());
    input.push_back(10);
    std::cout << "堆顶元素的值为:" << input.front()<<std::endl;
    std::pop_heap(input.begin(), input.end());
    input.pop_back();
    std::cout << "堆顶元素的值为:" << input.front()<<std::endl;
    return 0;
}



