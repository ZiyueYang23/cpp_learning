
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

// //@ 初探堆
// //包含 <algorithm> 头文件时，通常会隐式包含 <functional> 头文件
// //用greater和less时就需要包含头文件<functional>
// #include <algorithm>
// #include <iomanip>
// #include <iostream>
// #include <queue>

// int main(void)
// {
//     // 创建优先队列
//     std::priority_queue<int> pq;

//     // 底层容器是 vector
//     // greater 与 less 是比较器 你想要大顶堆就对应 less ，想要小顶堆对应 greater
//     std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
//     // 默认的是大顶堆
//     std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;

//     pq.push(1);
//     pq.push(3);
//     pq.push(7);
//     pq.push(9);
//     pq.push(4);
//     pq.push(5);

//     min_heap.push(1);
//     min_heap.push(3);
//     min_heap.push(7);
//     min_heap.push(9);
//     min_heap.push(4);
//     min_heap.push(5);

//     max_heap.push(1);
//     max_heap.push(3);
//     max_heap.push(7);
//     max_heap.push(9);
//     max_heap.push(4);
//     max_heap.push(5);

//     // 由此可见优先队列默认的是大顶堆
//     std::cout << "堆顶元素的值为:" << pq.top()<<std::endl;

//     pq.pop();
//     std::cout << "堆顶元素的值为:" << pq.top()<<std::endl;
//     std::cout << "是否为空:" << pq.empty() << std::endl;

//     std::cout << "堆顶元素的值为:" << min_heap.top()<<std::endl;

//     min_heap.pop();
//     std::cout << "堆顶元素的值为:" << min_heap.top()<<std::endl;
//     std::cout << "是否为空:" << min_heap.empty() << std::endl;

//     std::cout << "堆顶元素的值为:" << max_heap.top()<<std::endl;

//     max_heap.pop();
//     std::cout << "堆顶元素的值为:" << max_heap.top()<<std::endl;
//     std::cout << "是否为空:" << max_heap.empty() << std::endl;

//     // 也可以先创建一个底层容器vector，然后在用迭代器完成转化为堆
//     std::vector<int> input{1, 2, 3, 4, 7 ,8, 9, 5, 4, 3};
//     std::priority_queue<int> max_heap_1(input.begin(), input.end());

//     std::cout << "堆顶元素的值为:" << max_heap_1.top()<<std::endl;

//     max_heap_1.pop();
//     std::cout << "堆顶元素的值为:" << max_heap_1.top()<<std::endl;
//     std::cout << "是否为空:" << max_heap_1.empty() << std::endl;

//     std::make_heap(input.begin(), input.end(), std::greater<int>());
//     std::cout << "堆顶元素的值为:" <<max_heap_1.top()<<std::endl;
//     input.push_back(10);
//     std::cout << "堆顶元素的值为:" << input.front()<<std::endl;
//     std::pop_heap(input.begin(), input.end());

//     input.pop_back();
//     std::cout << "堆顶元素的值为:" << input.front()<<std::endl;

//     return 0;
// }

// //@ 动态数组实现堆

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <stdexcept>
// #include <limits>

// class MaxHeapVector
// {
// private:
//     std::vector<int> max_heap;
//     // 自堆底到堆顶实现筛选目的是维持大顶堆，sift是筛选
//     void SiftUp(int index);
//     // 返回三个数的最大值的索引
//     int MaxOFThreeIndex(int father_index);
//     // 自顶向下完成堆化
//     void SiftDown(int index);
//     // 获得左子节点的值，如果不存在就返回int的最小值
//     int GetLeftChildVal(int left_child_index);
//     // 获得右子节点的值，如果不存在就返回int的最小值
//     int GetRightChildVal(int right_child_index);

// public:
//     // 默认构造函数
//     MaxHeapVector() {}
//     // 传一个数组进来完成堆化，时间复杂度O(n)非常好
//     MaxHeapVector(std::vector<int> vector);
//     // 返回左子节点索引
//     int LeftChildIndex(int father_index);
//     // 返回右子节点索引
//     int RightChildIndex(int father_index);
//     // 返回父节点索引
//     int FatherIndex(int child_index);
//     // 返回值
//     int At(int index);
//     // 插入元素
//     void Insert(int val);
//     // 弹出堆顶元素
//     void Pop();
//     // 堆大小
//     int Size();
//     // 按照树的层级进行打印
//     void PrintHeapShape();
// };

// int main()
// {
//     std::vector<int> temp = {11, 22, 43, 67, 39, 66, 99, 61, 55, 22};
//     MaxHeapVector max_heap_0; // 创建 MaxHeapVector 对象
//     MaxHeapVector max_heap_1(temp);

//     // 添加一些元素到堆中
//     max_heap_0.Insert(5);
//     max_heap_0.Insert(3);
//     max_heap_0.Insert(8);
//     max_heap_0.Insert(1);
//     max_heap_0.Insert(7);
//     max_heap_0.Insert(9);
//     max_heap_0.Insert(4);
//     max_heap_0.Insert(6);

//     // 输出堆中的元素（未排序）
//     std::cout << "堆中的元素：";
//     for (int i = 0; i < max_heap_0.Size(); ++i)
//     {
//         std::cout << max_heap_0.At(i) << " ";
//     }
//     std::cout << std::endl;
//     // 输出堆的形状
//     std::cout << "堆的形状：" << std::endl;
//     max_heap_0.PrintHeapShape();
//     // 自顶向下进行筛选
//     max_heap_0.Pop();

//     std::cout << std::endl;
//     // 输出堆中的元素（已排序）
//     std::cout << "弹出堆顶元素后的堆：";
//     for (int i = 0; i < max_heap_0.Size(); ++i)
//     {
//         std::cout << max_heap_0.At(i) << " ";
//     }
//     std::cout << std::endl;
//     // 输出堆的形状
//     std::cout << "堆的形状：" << std::endl;
//     max_heap_0.PrintHeapShape();

//     std::cout << std::endl;
//     // 输出堆中的元素（已排序）
//     std::cout << "2号堆：";
//     for (int i = 0; i < max_heap_1.Size(); ++i)
//     {
//         std::cout << max_heap_1.At(i) << " ";
//     }
//     std::cout << std::endl;
//     // 输出堆的形状
//     std::cout << "堆的形状：" << std::endl;
//     max_heap_1.PrintHeapShape();

//     return 0;
// }

// // MaxHeapVector
// // pubilc:
// // 返回左子节点索引
// int MaxHeapVector::LeftChildIndex(int father_index)
// {
//     return 2 * father_index + 1;
// }
// // 返回右子节点索引
// int MaxHeapVector::RightChildIndex(int father_index)
// {
//     return 2 * father_index + 2;
// }
// // 返回父节点索引
// int MaxHeapVector::FatherIndex(int child_index)
// {
//     // 非常巧妙的利用规则，不管是左子节点还是右子节点-1除2都是该父节点的索引
//     return (child_index - 1) / 2;
// }
// // 返回节点值
// int MaxHeapVector::At(int index)
// {
//     return max_heap[index];
// }
// // 插入元素
// void MaxHeapVector::Insert(int val)
// {
//     // 先进行尾插插入元素
//     max_heap.push_back(val);
//     // 再从底部至顶完成堆化
//     SiftUp(max_heap.size() - 1);
// }
// // 弹出堆顶元素，自研算法
// void MaxHeapVector::Pop()
// {
//     if (max_heap.empty() == true)
//     {
//         // 抛出异常信息
//         throw std::out_of_range("堆为空");
//     }
//     // 直接用的自带的算法库的swap
//     std::swap(max_heap[0], max_heap[max_heap.size() - 1]);
//     // 把堆顶元素与最右叶节点交换，在进行尾删pop，完成对堆顶元素的删除。
//     max_heap.pop_back();
//     // 此后需要进行把换到堆顶的小元素完成自顶至底的堆化
//     SiftDown(0);
// }
// // size
// int MaxHeapVector::Size()
// {
//     // 直接用vector的接口size非常方便
//     return max_heap.size();
// }
// // 按照层级打印heap gpt写的
// void MaxHeapVector::PrintHeapShape()
// {
//     int level = 0;
//     int levelNodes = 1;
//     int count = 0;

//     for (int i = 0; i < max_heap.size(); ++i)
//     {
//         if (count == 0)
//         {
//             std::cout << "Level " << level << ": ";
//         }

//         std::cout << max_heap[i] << " ";

//         ++count;
//         if (count == levelNodes)
//         {
//             std::cout << std::endl;
//             count = 0;
//             levelNodes *= 2;
//             ++level;
//         }
//     }
// }

// // private:
// // 自底向顶进行筛选
// void MaxHeapVector::SiftUp(int index)
// {
//     while (1)
//     {
//         int father_index = FatherIndex(index);
//         // 如果该节点的值大于其父节点的值则进行交换并且更新索引继续进入循环
//         if (max_heap[index] > max_heap[father_index])
//         {
//             std::swap(max_heap.at(index), max_heap.at(FatherIndex(index)));
//             index = father_index;
//         }
//         // 循环停止的条件就是该节点到达了根节点，或者该节点小于等于其子节点不需要再进行交换
//         else if (index == 0 || max_heap[index] <= max_heap[father_index])
//         {
//             return;
//         }
//     }
// }
// // 获得左子节点的值如果不存在则返回int类型最小值
// int MaxHeapVector::GetLeftChildVal(int left_child_index)
// {
//     int size = max_heap.size();

//     if (size - 1 >= left_child_index)
//     {
//         return max_heap[left_child_index];
//     }
//     else
//     {
//         //(size - 1 < left_child_index)
//         // 目的是给其一个最小值
//         // left_child_val = std::numeric_limits<int>::min();
//         return INT_MIN;
//     }
// }
// // 获得右子节点的值如果不存在则返回int类型最小值
// int MaxHeapVector::GetRightChildVal(int right_child_index)
// {
//     int size = max_heap.size();

//     if (size - 1 >= right_child_index)
//     {
//         return max_heap[right_child_index];
//     }
//     else
//     {
//         //(size - 1 < right_child_index)
//         return std::numeric_limits<int>::min();
//     }
// }
// // 返回小树中的最大值的索引
// // 自研算法
// int MaxHeapVector::MaxOFThreeIndex(int father_index)
// {
//     // 获得父节点的值
//     int father_val = max_heap[father_index];
//     // 获得size
//     int size = max_heap.size();
//     // 左子节点的索引
//     int left_child_index = LeftChildIndex(father_index);
//     // 右子节点的索引
//     int right_child_index = RightChildIndex(father_index);
//     // 目的是判断一下左右子节点是否存在，如果存在就正常赋值，如果不存在就给其一个很小的值
//     // 左子节点的值
//     int left_child_val = GetLeftChildVal(left_child_index);
//     // 右子节点的值
//     int right_child_val = GetLeftChildVal(right_child_index);

//     // 判断最大值算法，先假设父节点的值为最大值，再分别于左子节点和右子节点进行比较
//     // 第一次比出左子节点和父节点中的最大值
//     // 第二次比出左子节点和父节点中的最大值与右子节点比较，此时确保了max中存放了拥有最大节点的值
//     // 如果子节点不存在则直接给一个int类型的负最小值，只需比出最大值即可，就不需要考虑到底有几个子节点存在。
//     int max = max_heap[father_index];
//     max = max > left_child_val ? max : left_child_val;
//     max = max > right_child_val ? max : right_child_val;

//     if (max == father_val)
//     {
//         return father_index;
//     }
//     else if (max == left_child_val)
//     {
//         return LeftChildIndex(father_index);
//     }
//     else
//     {
//         // (max == right_child_val)
//         return RightChildIndex(father_index);
//     }
// }
// // 自顶向下进行筛选
// void MaxHeapVector::SiftDown(int index)
// {
//     while (1)
//     {
//         int max_index = MaxOFThreeIndex(index);
//         int size = max_heap.size();
//         if (max_index == index || index == size - 1)
//         {
//             return;
//         }
//         else
//         {
//             std::swap(max_heap.at(max_index), max_heap.at(index));
//             index = max_index;
//         }
//     }
// }

// MaxHeapVector::MaxHeapVector(std::vector<int> vector)
// {
//     this->max_heap = vector;
//     for (int i = max_heap.size() - 1; i >= 0; i--)
//     {
//         SiftDown(i);
//     }
// }

// #include <iostream>
// #include <vector>
// #include <queue>
// // 用greater和less需要包含头文件functional
// #include <functional>

// // 声明 TopKMInHeap 函数
// std::priority_queue<int, std::vector<int>, std::greater<int>> TopKMInHeap(std::vector<int> &nums, int k);

// int main()
// {
//     std::vector<int> nums = {5, 3, 8, 1, 7, 9, 4, 6};
//     int k = 3;

//     std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap = TopKMInHeap(nums, k);

//     std::cout << "前" << k << "个最大元素为：";
//     while (!min_heap.empty())
//     {
//         std::cout << min_heap.top() << " ";
//         min_heap.pop();
//     }
//     std::cout << std::endl;

//     return 0;
// }

// // 定义 TopKMInHeap 函数
// std::priority_queue<int, std::vector<int>, std::greater<int>> TopKMInHeap(std::vector<int> &nums, int k)
// {
//     // 为何要采用小顶堆是非常巧妙的，最小的元素永远是放在堆顶，此时正好有接口top可以访问，并且可以用pop弹出，相当容易。
//     // 如果是大顶堆，首先最小值就不好找，不一定在最后面
//     std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
//     // 前k个元素入堆
//     for (int i = 0; i < k; i++)
//     {
//         min_heap.push(nums[i]);
//     }
//     // 后面的元素一一与堆顶最小值对比，如果大于最小值则堆顶弹出，大值插入，如果是小于则下一个元素。
//     for (int i = k; i < nums.size(); i++)
//     {
//         if (nums[i] > min_heap.top())
//         {
//             min_heap.pop();
//             min_heap.push(nums[i]);
//         }
//     }
//     return min_heap;
// }
// #include <iostream>
// #include <algorithm>
// #include <vector>
// int main(void)
// {
//     std::vector<int> vec = {1, 2, 3, 4, 4, 4, 5, 5, 6, 7, 8, 7, 7, 6, 4, 9};
//     // 在使用unique时需要注意一定是容器中的数据已经完成排序
//     // 快排默认是小到大，可以传一个cmp函数进去完成大到小，或者用reverse翻转函数完成大到小。
//     std::sort(vec.begin(), vec.end());
//     for (int i : vec)
//     {
//         std::cout << i << " ";
//     }
//     std::cout << std::endl;
//     std::reverse(vec.begin(), vec.end());
//     for (int num : vec)
//     {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;
//     // 倒着排序也没有问题，unique同样把重复元素移动到容器末尾
//     auto new_end = std::unique(vec.begin(), vec.end());

//     for (int j : vec)
//     {
//         std::cout << j << " ";
//     }
//     std::cout << std::endl;
//     // 迭代器是左闭右开的
//     // 这是函数返回的下标，直接用返回地址减去首地址输出下标
//     // 由于迭代器是左闭右开的因此返回的索引是出现的是去重元素后第一个重复的值的下标
//     std::cout << "first repeat ele index :>" << new_end - vec.begin();

//     std::cout << std::endl;
//     // 完成排序完成查重完成删除，三个函数辅助完成去重功能。
//     // 改了字体使用vim感觉挺不错的。
//     vec.erase(new_end, vec.end());
//     for (int k : vec)
//     {
//         std::cout << k << " ";
//     }
//     std::cout << std::endl;
//     std::sort(vec.begin(), vec.end());
//     for (int k : vec)
//     {
//         std::cout << k << " ";
//     }
//     std::cout << std::endl;
//     // 查找第一个大于等于的1的元素，返回值是该元素的地址，同样可以-begin()得出返回的下标
//     int value = 1;
//     auto index = std::lower_bound(vec.begin(), vec.end(), value) - vec.begin();
//     std::cout << "value :> " << index << std::endl;
//     // 若没有找到第一个x
//     int value_1 = 100;
//     auto index_1 = std::lower_bound(vec.begin(), vec.end(), value_1) - vec.begin();
//     std::cout << "value :> " << index_1 << std::endl;

//     return 0;
// }
// #include <iostream>
// #include <string>

// int main(void)
// {
//     std::string str_0;
//     str_0 = "abcdefghijklmn";
//     std::string str_1("asdfjlsadkjfalksd");
//     std::string str_2 = {'a', 'b', 'c', 'd'};
//     std::string str_3(str_0);
//     std::string str_4 = str_1;
//     std::string &str_5 = str_2;

//     for (int i = 0; i < str_0.size(); i++)
//     {
//         std::cout << str_0[i] << " ";
//     }
//     std::cout << std::endl;
//     for (auto i = str_1.begin(); i != str_1.end(); i++)
//     {
//         std::cout << *i << " ";
//     }
//     std::cout << std::endl;
//     for (auto i : str_2)
//     {
//         std::cout << i << " ";
//     }
//     std::cout << std::endl;
//     for (auto i : str_3)
//     {
//         std::cout << i << " ";
//     }
//     std::cout << std::endl;
//     for (auto &i : str_4)
//     {
//         i++;
//         std::cout << i << " ";
//     }
//     std::cout << std::endl;
//     // 在字符串末尾添加字符串
//     str_2.append("efgh");
//     str_2 += "ijk";

//     for (int i(0); i < str_2.size(); i++)
//     {
//         str_2[i]++;
//         std::cout << str_5[i] << " ";
//     }
//     std::cout << std::endl;
//     str_5 = str_1 + str_0;
//     // 加法运算符完成了重载。
//     for (int i(0); i < str_2.size(); i++)
//     {
//         std::cout << str_5[i] << " ";
//     }
//     std::cout << std::endl;
//     // 从下标位置插入新字符串 or str
//     str_2.insert(4, "aaaaaaaaaa");
//     for (int i(0); i < str_2.size(); i++)
//     {
//         std::cout << str_5[i] << " ";
//     }
//     std::cout << std::endl;
//     // 从pos索引处开始清楚长度为n的字符，注意不是字符串，如上面的“aaa……”字符串长度是11但是insert进去的是10个a最后一个是空格需要注意。
//     str_2.erase(4, 10);

//     for (int i(0); i < str_2.size(); i++)
//     {
//         std::cout << str_5[i] << " ";
//     }
//     std::cout << std::endl;
//     // 从下标pos开始到，替换指定长度n1，为另一个字符串s
//     // 需要注意的是如果s只有“ab”两个元素它会去掉asdf然后直接就是ad
//     // 如果s的长度超过了n1“aaaaaaaaa”，它会去掉asdf然后把整个aaa……都加进去这就有可能造成越界访问会出问题谨慎使用。
//     str_2.replace(0, 4, "abcd");

//     for (int i(0); i < str_2.size(); i++)
//     {
//         std::cout << str_5[i] << " ";
//     }
//     std::cout << std::endl;
//     // 从下标pos开始，提取n个元素，返回值为新的字串，突然发现字符串可以直接打印，前面还遍历半天难绷。
//     std::cout << str_2.substr(0, 5);
//     // 预留字符串的存储空间函数，减少动态内存的分配次数
//     str_2.reserve(100);
//     std::cout << std::endl;
//     // 倒序遍历，rbegin是最后一个元素的地址，rend是第一个元素前面的那个元素的地址，类似于end是指向最后一个元素的后面的那个元素的地址，迭代器左闭右开。
//     for (auto i = str_1.rbegin(); i != str_1.rend(); i++)
//     {
//         std::cout << *i << " ";
//     }
//     return 0;
// }
// #include <iostream>
// #include <set>
// #include <vector>
// // 用greater和less比较器需要包含头文件
// #include <functional>
// bool MyCmp(int a, int b)
// {
//     return a > b;
// }
// int main(void)
// {

//     std::set<int> s_0;
//     s_0 = {1, 2, 3, 3, 5, 3, 5, 65, 7, 8, 6, 45, 10};
//     std::set<int> s_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
//     std::set<int> s_2(s_1);
//     std::vector<int> vec{1, 2, 3, 4, 5};
//     // 大到小，由于底层实现是红黑树因此不能直接用传vector进去作为底层容器，用迭代器完成赋值
//     std::set<int, std::greater<int>> m_s_3(vec.begin(), vec.end());
//     // 默认的是less即从小到大，底层实现是红黑树
//     std::set<int, std::less<int>>m_s_4(s_1);
//     // 这里首先是自定义了一个比较函数，而不使用库函数，这里告诉了函数指针的类型，后面括号里面直接把函数名传进去作为函数指针。
//     // 再讲讲decltype 类似与auto，括号里面给参数，会自动给出括号里面的类型加上*就是函数指针。
//     std::set<int, decltype(MyCmp) *> m_s_5(MyCmp);
//     m_s_5.insert(10);
//     m_s_5.insert(19);
//     m_s_5.insert(12);
//     m_s_5.insert(13);
//     m_s_5.insert(14);
//     m_s_5.insert(2);
//     // 也可以一次性插入多个元素
//     m_s_5.insert({1, 23, 3, 45, 43, 3});
//     for(auto i:m_s_5)
//     {
//         std::cout << i << " ";
//     }
//     std::cout << std::endl;
//     for (auto i : m_s_3)
//     {
//         std::cout << i << " ";
//     }
//     std::cout << std::endl;
//     for (auto i : m_s_4)
//     {
//         std::cout << i << " ";
//     }
//     std::cout << std::endl;
//     // 删除元素如果没有这个元素也不会出错，函数的返回值只有1或者0如果删除成功返回1，如果没有这个元素则会返回0
//     m_s_5.erase(4);
//     // 返回值是迭代器如果找到则指向该元素，如果没找到返回.end（）
//     auto it = m_s_5.find(4);
//     // 常量迭代器常见与遍历的时候
//     auto kIt = m_s_5.cbegin();
//     return 0;
//  }

// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>
// #include <iomanip>
// #include <unordered_map>

// int main(void)
// {
//     std::map<int, std::string> m_i_s_0{{1, "a"}, {2, "b"}, {3, "c"}};
//     std::map<int, std::string> m_i_s_1(m_i_s_0);
//     std::vector<std::pair<int, std::string>> v_pairs{{1, "c"}, {2, "b"}, {3, "a"}};
//     std::map<int, std::string> m_i_s_2(v_pairs.begin(), v_pairs.end());
//     std::unordered_map<int, std::string> u_m_i_s(v_pairs.begin(), v_pairs.end());
//     m_i_s_2.emplace(8, "dsalfkasdj");
//     m_i_s_2.insert({{99, "SADTGSAFD"}, {666, "sfdgdsfg"}, {7777, "asdfgsdafgh"}});
//     // 如果是找到了就会返回值，at里面传入的是键。
//     std::string s = m_i_s_2.at(8);
//     // 如果没找到就会抛出问题std::out of range
//     // std::string ss = m_i_s_2.at(88888);
//     // std::cout << s << ss << std::endl;
//     auto it_0 = m_i_s_2.find(3);
//     // 输出的地方需要注意，*it是指向这个pair的，没法直接输出pair，需要.first和.second
//     std::cout << (*it_0).first << (*it_0).second << std::endl;
//     m_i_s_2.erase(3);
//     auto it_1 = m_i_s_2.find(3);
//     if (it_1 == m_i_s_2.end())
//     {
//         std::cout << "yes!" << std::endl;
//     }
//     // 如果find找到了对应的key则会返回指向该元素的指针，如果没找到就会返回.end()
//     // std::cout << (*it_1).first << (*it_1).second << std::endl;
//     // count函数会返回key的元素的数量，因为在map中是没有重复元素的，每个key对应一个val如果说你想重复插入它会更新key对应的键的值而不是创建新的。
//     std::cout << m_i_s_2.count(1) << std::endl;
//     // 此时没有3了返回值为0
//     std::cout << m_i_s_2.count(3) << std::endl;
//     // 注意到map是使用红黑树实现的，自平衡的二叉搜索树与AVL树类似，它内部数据是有序的，遍历打印出的结果是有序的
//     for (auto pair : m_i_s_2)
//     {
//         std::cout << std::setw(4) << pair.first << "  " << pair.second << std::endl;
//     }
//     // unordered_map是使用哈希表实现的，内部存储数据时无序的具有更高的查找和插入的性能
//     for(auto pair:u_m_i_s)
//     {
//         std::cout << std::setw(4) << pair.first << " " << pair.second << std::endl;
//     }

//     return 0;
// }

// //@ 数组模板求最大值，每年期末考试都会考一体
// #include <iostream>
// #include <algorithm>
// #include <map>

// template <typename ValType>
// ValType Max(ValType *array,int size)
// {
//     ValType max_ele = array[0];
//     for (int i(0); i < size;i++)
//     {
//         max_ele = max_ele > array[i] ? max_ele : array[i];
//     }
// }

// int main(void)
// {
//     return 0;
// }
// //@ 二分查找未完成没写完
// #include <iostream>
// #include <vector>
// #include <algorithm>

// template <class VectorValType>
// class BinarySearch
// {
// private:
//     std::vector<VectorValType> vector_;
//     int flag_ = 0;

// public:
//     // 二分查找
//     BinarySearch(std::vector<VectorValType> &vector);
//     // 左闭右闭
//     VectorValType BinarySearchLeftRightClosed(VectorValType tagert);
//     // 判断是否排过序
//     bool IsSorted();
//     // print
//     void Print();
// };

// int main(void)
// {
//     std::vector<int> text_vector{-5, -1, 1, 3, 4, 5, 8, 10, 11, 2, 4, 5, 6, 7, 8};
//     std::sort(text_vector.begin(), text_vector.end());
//     BinarySearch<int> text_0(text_vector);
//     BinarySearch<int> text_1(text_vector);
//     std::cout << text_0.BinarySearchLeftRightClosed(4) << std::endl;
//     text_0.Print();
//     return 0;
// }

// template <typename VectorValType>
// BinarySearch<VectorValType>::BinarySearch(std::vector<VectorValType> &vector) : vector_(vector)
// {
//     flag_ = IsSorted();
//     if (flag_ == true)
//     {
//         std::cout << "This vector is sorted!";
//     }
// }
// template <typename VectorValType>
// VectorValType BinarySearch<VectorValType>::BinarySearchLeftRightClosed(VectorValType target)
// {
//     int left_index(0);
//     int right_index(vector_.size() - 1);

//     while (left_index <= right_index)
//     {
//         // 这个地方非常巧妙的能够避免越界而且还使用了右移运算符>>1这种位运算符直接进行操作，非常高效。
//         int middle(left_index + ((right_index - left_index) >> 1));
//         if (vector_[middle] == target)
//         {
//             return middle;
//         }
//         else if (vector_[middle] < target)
//         {
//             left_index = middle + 1;
//         }
//         else
//         {
//             // vector_[middle]>target
//             right_index = middle - 1;
//         }
//     }

//     return -1;
// }

// template <typename VectorValType>
// bool BinarySearch<VectorValType>::IsSorted()
// {
//     int size(vector_.size());
//     for (int i(0); i < size; i++)
//     {
//         if (vector_[i] > vector_[i + 1])
//         {
//             return false;
//         }
//     }

//     return true;
// }

// template <typename VectorValType>
// void BinarySearch<VectorValType>::Print()
// {
//     for (auto i : vector_)
//     {
//         std::cout << i << " ";
//     }
// }
// // 这是单例模式的演示代码

// #include <iostream>

// using namespace std;

// class SingleInstance
// {
// private:
//     SingleInstance();
//     SingleInstance(const SingleInstance &obj);

//     static SingleInstance *p_single_instance;

// public:
//     static SingleInstance *GetSingleInstance();
//     ~SingleInstance();
//     int num_;
// };
// SingleInstance *SingleInstance::p_single_instance = NULL;

// int main(void)
// {
//     // 显示不可访问
//     // SingleInstance a;

//     // 输出三个地址都是一样的

//     SingleInstance *p_single_class_1 = SingleInstance::GetSingleInstance();
//     cout << hex << p_single_class_1 << endl;
//     cout << p_single_class_1->num_ << endl;

//     SingleInstance *p_single_class_2 = SingleInstance::GetSingleInstance();
//     cout << hex << p_single_class_2 << endl;
//     p_single_class_1->num_ = 15;

//     SingleInstance *p_single_class_3 = SingleInstance::GetSingleInstance();
//     cout << hex << p_single_class_3 << endl;
//     cout << p_single_class_1->num_ << endl;

//     return 0;
// }

// // 输出结果：
// // 0xda2600
// // 0
// // 0xda2600
// // 0xda2600
// // f

// // private
// SingleInstance::SingleInstance()
// {
//     num_ = 0;
// }
// // public
// SingleInstance *SingleInstance::GetSingleInstance()
// {
//     if (p_single_instance == NULL)
//     {
//         p_single_instance = new SingleInstance;
//     }

//     return p_single_instance;
// }

// SingleInstance::~SingleInstance()
// {
// }
// // 水仙花数
// #include <iostream>
// int main(void)
// {
//     int num(0);
//     int sum(0);
//     std::cin >> num;
//     int tmp = num;
//     while (num != 0)
//     {
//         int temp = num % 10;
//         sum += (temp * temp * temp);
//         num = num / 10;
//     }

//     if (tmp == sum)
//     {
//         std::cout << "yes";
//     }
//     return 0;
// }

// #include <iostream>

// int main()
// {
//     int length;
//     std::cout << "请输入菱形的边长：";
//     std::cin >> length;

//     // 打印上半部分
//     for (int i = 0; i < length; i++)
//     {
//         // 打印左半部分空格
//         for (int j = 0; j < length - i - 1; j++)
//         {
//             std::cout << "*";
//         }
//         // 打印左半部分星号
//         for (int j = 0; j < i * 2 + 1; j++)
//         {
//             if (j == 0 || j == i * 2)
//             {
//                 std::cout << "*";
//             }
//             else
//             {
//                 std::cout << " ";
//             }
//         }
//         // 打印右半部分星号
//         for (int j = 0; j < length - i - 1; j++)
//         {
//             std::cout << "*";
//         }
//         std::cout << std::endl;
//     }

//     // 打印下半部分
//     for (int i = length - 2; i >= 0; i--)
//     {
//         // 打印左半部分空格
//         for (int j = 0; j < length - i - 1; j++)
//         {
//             std::cout << "*";
//         }
//         // 打印左半部分星号
//         for (int j = 0; j < i * 2 + 1; j++)
//         {
//             if (j == 0 || j == i * 2)
//             {
//                 std::cout << "*";
//             }
//             else
//             {
//                 std::cout << " ";
//             }
//         }
//         // 打印右半部分星号
//         for (int j = 0; j < length - i - 1; j++)
//         {
//             std::cout << "*";
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>

// std::vector<int> countBits(int n)
// {
//     std::vector<int> counts(n + 1, 0);
//     for (int i = 1; i <= n; ++i)
//     {
//         counts[i] = counts[i >> 1] + (i & 1);
//     }
//     return counts;
// }

// int main()
// {
//     int n;
//     std::cout << "Enter a non-negative integer n: ";
//     std::cin >> n;

//     std::vector<int> result = countBits(n);

//     std::cout << "Output: [";
//     for (int i = 0; i < result.size(); ++i)
//     {
//         std::cout << result[i];
//         if (i < result.size() - 1)
//         {
//             std::cout << ",";
//         }
//     }
//     std::cout << "]" << std::endl;

//     return 0;
// }

// @ s中删除t子串
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// struct LinkedList
// {
//     char val;
//     LinkedList *next;
//     LinkedList() : val(), next(nullptr) {}
// };

// LinkedList *ShiftStringtoLinkedList(string &s);
// void DisplayLinkedList(LinkedList *head);
// void DeleteTFromS(LinkedList *&s_head, LinkedList *&t_head);

// int main()
// {
//     string s = "abcdefgbceascsdf";
//     string t = "bce";
//     LinkedList *LL1 = ShiftStringtoLinkedList(s);
//     LinkedList *LL2 = ShiftStringtoLinkedList(t);
//     DisplayLinkedList(LL1);
//     DisplayLinkedList(LL2);
//     DeleteTFromS(LL1, LL2);
//     DisplayLinkedList(LL1);
//     DisplayLinkedList(LL2);

//     return 0;
// }

// LinkedList *ShiftStringtoLinkedList(string &s)
// {
//     LinkedList *head = new LinkedList;
//     LinkedList *cur = head;
//     for (int i = 0; i < s.size()-1; i++)
//     {
//         cur->val = s[i];
//         cur->next = new LinkedList;
//         cur = cur->next;
//     }
//     cur->val = s[s.size() - 1];
//     return head;
// }

// void DisplayLinkedList(LinkedList *head)
// {
//     LinkedList *cur = head;
//     while (cur != nullptr)
//     {
//         cout << cur->val << " ";
//         cur = cur->next;
//     }
//     cout << endl;
// }
// // 快慢指针法
// void DeleteTFromS(LinkedList *&s_head, LinkedList *&t_head)
// {
//     LinkedList *fast = s_head;
//     LinkedList *slow = t_head;

//     while (slow != nullptr && fast != nullptr)
//     {
//         if (fast->val != slow->val)
//         {
//             fast = fast->next;
//         }
//         else
//         {
//             LinkedList *fast_head = fast;
//             LinkedList *slow_head = slow;
//             bool flage = true;

//             while (slow != nullptr && fast != nullptr)
//             {
//                 if (fast->val == slow->val)
//                 {
//                     fast = fast->next;
//                     slow = slow->next;
//                 }
//                 else
//                 {
//                     flage = false;
//                     break;
//                 }
//             }
//             if (flage == true)
//             {
//                 LinkedList *temp = s_head;
//                 while (temp->next != fast_head)
//                 {
//                     temp = temp->next;
//                 }
//                 temp->next = fast;
//             }
//             slow = slow_head;
//         }
//     }
// }

// // @ 二叉树复习
// // 思路：前序后序中序遍历一遍加一个计数即可

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int num = 0) : val(num), left(nullptr), right(nullptr) {}
// };
// // 前序遍历
// void PreOrder(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     cout << root->val << " ";
//     PreOrder(root->left);
//     PreOrder(root->right);
// }
// // 中序遍历
// void MidOrder(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     PreOrder(root->left);
//     cout << root->val << " ";
//     PreOrder(root->right);
// }
// // 后序遍历
// void LastOrder(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     PreOrder(root->left);
//     PreOrder(root->right);
//     cout << root->val << " ";
// }

// // 正常的层序遍历
// vector<int> NormalLevelOrder(TreeNode *root)
// {
//     queue<TreeNode *> que;
//     que.push(root);
//     vector<int> vec;
//     while (!que.empty())
//     {
//         TreeNode *temp = que.front();
//         que.pop();
//         vec.push_back(temp->val);
//         if (temp->left != nullptr)
//         {
//             que.push(temp->left);
//         }
//         if (temp->right != nullptr)
//         {
//             que.push(temp->right);
//         }
//     }
//     return vec;
// }
// // 自上而下 从右到左的层序遍历
// vector<int> RToLLevelOrder(TreeNode *root)
// {
//     queue<TreeNode *> que;
//     que.push(root);
//     vector<int> vec;
//     while (!que.empty())
//     {
//         TreeNode *temp = que.front();
//         que.pop();
//         vec.push_back(temp->val);
//         if (temp->right != nullptr)
//         {
//             que.push(temp->right);
//         }
//         if (temp->left != nullptr)
//         {
//             que.push(temp->left);
//         }
//     }
//     return vec;
// }

// // 计算节点总数
// int ColNodeNum(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }

//     return 1 + ColNodeNum(root->left) + ColNodeNum(root->right);
// }
// int main(void)
// {
//     TreeNode *root = new TreeNode(0);
//     TreeNode *n1 = new TreeNode(1);
//     TreeNode *n2 = new TreeNode(2);
//     TreeNode *n3 = new TreeNode(3);
//     TreeNode *n4 = new TreeNode(4);
//     TreeNode *n5 = new TreeNode(5);
//     TreeNode *n6 = new TreeNode(6);
//     TreeNode *n7 = new TreeNode(7);

//     root->left = n1;
//     root->right = n2;
//     n1->left = n3;
//     n1->right = n4;
//     n3->left = n6;
//     n4->right = n7;
//     n2->right = n5;

//     cout << "先序遍历：";
//     PreOrder(root);
//     cout << endl;
//     cout << "中序遍历：";
//     MidOrder(root);
//     cout << endl;
//     cout << "后序遍历: ";
//     LastOrder(root);
//     cout << endl;
//     cout << "节点个数为：" << ColNodeNum(root) << endl;
//     cout << "正常的层序遍历：";
//     vector<int> vec_0 = NormalLevelOrder(root);
//     for (auto i : vec_0)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     cout << "从右至左的层序遍历：";
//     vector<int> vec_1 = RToLLevelOrder(root);
//     for (auto i : vec_1)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }

// #include <iostream>
// #include <stack>
// #include <string>
// // isdigit函数需要包含头文件
// #include <cctype>
// #include <cstdlib>

// using namespace std;

// // 运算符优先级
// int precedence(char op)
// {
//     if (op == '+' || op == '-')
//         return 1;
//     if (op == '*' || op == '/')
//         return 2;
//     return 0;
// }

// // 中缀转后缀
// string infixToPostfix(const string &exp)
// {
//     stack<char> opStack;
//     string postfix;
//     opStack.push('=');

//     for (size_t i = 0; i < exp.size(); ++i)
//     {
//         char ch = exp[i];

//         if (isdigit(ch))
//         {
//             // 如果是数字，读取完整的数字，直到遇到非数字字符
//             while (i < exp.size() && isdigit(exp[i]))
//             {
//                 postfix += exp[i++];
//             }
//             postfix += '#';
//             i--;
//         }
//         else if (ch == '(')
//         {
//             // 左括号直接进栈
//             opStack.push(ch);
//         }
//         else if (ch == ')')
//         {
//             // 右括号时，将栈顶的运算符出栈，直到遇到左括号
//             while (opStack.top() != '(')
//             {
//                 postfix += opStack.top();
//                 opStack.pop();
//             }
//             opStack.pop();
//         }
//         else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
//         {
//             //  比较优先级
//             while (precedence(opStack.top()) >= precedence(ch))
//             {
//                 postfix += opStack.top();
//                 opStack.pop();
//             }
//             opStack.push(ch);
//         }
//     }

//     // 弹出所有剩余的运算符
//     while (opStack.top() != '=')
//     {
//         postfix += opStack.top();
//         opStack.pop();
//     }

//     return postfix;
// }

// // 求值后缀
// int evaluatePostfix(const string &postfix)
// {
//     stack<int> valueStack;

//     for (size_t i = 0; i < postfix.size(); ++i)
//     {
//         char ch = postfix[i];

//         if (isdigit(ch))
//         {

//             string numStr = "";
//             while (i < postfix.size() && isdigit(postfix[i]))
//             {
//                 numStr += postfix[i++];
//             }
//             valueStack.push(atoi(numStr.c_str()));
//             i--;
//         }
//         else if (ch == '#')
//         {
//             continue;
//         }
//         else
//         {
//             int val2 = valueStack.top();
//             valueStack.pop();
//             int val1 = valueStack.top();
//             valueStack.pop();
//             switch (ch)
//             {
//             case '+':
//                 valueStack.push(val1 + val2);
//                 break;
//             case '-':
//                 valueStack.push(val1 - val2);
//                 break;
//             case '*':
//                 valueStack.push(val1 * val2);
//                 break;
//             case '/':
//                 if (val2 == 0)
//                 {
//                     cout << "Error: Division by zero!" << endl;
//                     return 0;
//                 }
//                 valueStack.push(val1 / val2);
//                 break;
//             default:
//                 break;
//             }
//         }
//     }

//     return valueStack.top();
// }

// int main()
// {
//     string exp;
//     cout << "Enter an infix expression: ";
//     getline(cin, exp);

//     // 中缀转为后缀
//     string postfix = infixToPostfix(exp);
//     cout << "Postfix expression: " << postfix << endl;

//     // 求值后缀
//     int result = evaluatePostfix(postfix);
//     cout << "Result: " << result << endl;

//     return 0;
// }
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 初始化缓冲轨道
vector<queue<int>> initializeTracks(int k)
{
    return vector<queue<int>>(k);
}

// 找到满足条件的缓冲轨道编号
int findTrackToInsert(vector<queue<int>> &tracks, int car)
{
    for (int i = 0; i < tracks.size(); ++i)
    {
        // 如果轨道为空，或者轨道中的车厢编号比当前车厢编号大，可以插入
        if (tracks[i].empty() || tracks[i].back() > car)
        {
            return i; // 返回合适的缓冲轨道编号
        }
    }
    return -1; // 没有合适的缓冲轨道
}

// 输出车厢编号
void outputCar(int car)
{
    cout << "输出车厢编号: " << car << endl;
}

// 判断是否可以重排车厢
bool canReorderCars(vector<int> &cars, int k)
{
    vector<queue<int>> tracks = initializeTracks(k); // 初始化k个缓冲轨道
    int nowOut = 1;                                  // 初始化next output car number

    for (int car : cars)
    {
        // Step 1: 如果车厢编号等于nowOut，直接输出
        if (car == nowOut)
        {
            outputCar(car);
            nowOut++;
            continue;
        }

        // Step 2: 检查缓冲轨道中的车厢是否可以输出
        bool found = false;
        for (int j = 0; j < k; ++j)
        {
            while (!tracks[j].empty() && tracks[j].front() == nowOut)
            {
                outputCar(tracks[j].front());
                tracks[j].pop();
                nowOut++;
                found = true;
            }
        }
        if (found)
            continue; // 如果从缓冲轨道中找到了车厢并输出，继续处理下一个车厢

        // Step 3: 尝试将当前车厢插入一个合适的缓冲轨道
        int trackIndex = findTrackToInsert(tracks, car);
        if (trackIndex != -1)
        {
            tracks[trackIndex].push(car); // 将车厢插入合适的缓冲轨道
        }
        else
        {
            // 如果没有找到合适的缓冲轨道，车厢无法重排
            cout << "无法重排车厢！" << endl;
            return false;
        }
    }

    // Step 4: 将缓冲轨道中的车厢按顺序输出
    for (int j = 0; j < k; ++j)
    {
        while (!tracks[j].empty())
        {
            if (tracks[j].front() == nowOut)
            {
                outputCar(tracks[j].front());
                tracks[j].pop();
                nowOut++;
            }
            else
            {
                cout << "无法重排车厢！" << endl;
                return false;
            }
        }
    }
    return true; // 成功完成车厢重排
}

int main()
{
    vector<int> cars = {5, 1, 4, 2, 3}; // 示例车厢序列
    int k = 3;                          // 缓冲轨数量

    if (canReorderCars(cars, k))
    {
        cout << "车厢重排成功！" << endl;
    }
    else
    {
        cout << "车厢重排失败！" << endl;
    }

    return 0;
}
