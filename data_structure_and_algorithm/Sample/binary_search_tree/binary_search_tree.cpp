// @二叉树-二叉搜索树
// 功能都很齐全，注释也是齐全的，小瑕疵就是删除就直接删除该节点和子树懒得再改了
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

// 树节点
template <typename ValType>
struct TreeNode
{
    ValType val;
    // 左指针
    TreeNode *left;
    // 右指针
    TreeNode *right;

    TreeNode(ValType value)
        : val(value), left(nullptr), right(nullptr) {}
};

template <class ValType>
class BinaryTree
{
private:
    TreeNode<ValType> *root_;

public:
    // 析构函数初始化root_
    BinaryTree();
    // 析构调用删除函数
    ~BinaryTree();

    // 插入节点:
    // 普通二叉树 递归实现 插入节点。这就是随机插入生成效率太低了只是写一下。
    void InsertAny(TreeNode<ValType> *node, ValType val);
    // 二叉搜索树 递归实现 插入节点
    void InsertBinarySearchTreeNodeRecursion(TreeNode<ValType> *&node, ValType val);
    // 二叉搜索树 循环实现 插入节点
    void InsertBSTNodeWhile(ValType val);

    // 删除节点:
    //从二叉树中删除指定节点和该节点的子树
    void RemoveTreeNodeAndAllChildTreeWhile(ValType val);

    // 查找节点:
    // 在二叉树中查找具有特定值的节点。
    TreeNode<ValType> *FindTreeNode(ValType val);

    // 遍历二叉树:
    // 以某种顺序访问二叉树中的所有节点，包括前序、中序和后序遍历，以及层序遍历等。
    // 中序遍历打印，升序且顺序。
    void InOrderTraversal(TreeNode<ValType> *node);

    // 获取根节点
    TreeNode<ValType> *GetRoot() const;

    // 获取树的高度:
    // 高度是从叶节点到当前节点，也就是说叶节点的高度是0
    int GetTreeNodeHight(TreeNode<ValType> *node);

    // 获取树的深度:
    // 深度是从根节点到当前节点，也就是说根节点的深度是0
    int GetTreeNodeDepth(TreeNode<ValType> *node);

    // 判断树是否为空：判断二叉树是否为空树。
    bool IsEmptyTree();

    // 销毁二叉树:
    // 释放二叉树的所有节点内存。
    // 循环删除
    void DestroyTreeWhile();
    // 由于需要频繁递归，这里用inline更加合适，极致效率。
    // 递归删除
    inline void DestroyTreeRecursion(TreeNode<ValType> *node);

    // 其他功能：根据需要，可能还需要实现节点的旋转、查找最大值或最小值等功能。
    // 后加的比较好看的打印方式，直接把整个树的结构给打印出来

    void PrintTree(TreeNode<ValType> *node, int level);
};

int main(void)
{
    // 生成随机数，知识点很多。
    // srand函数是生成随机数，需要传入种子类似就是给这个函数模板按照这个模板来生成随机数。需要包含头文件<cstdlib>
    // static_cast是类型转换操作符，其实也可以直接用强转(unsigned_int),前者更加正式，后者更加简洁。
    // time是一个函数需要包含头文件<ctime>，从某个时间到现在时间所经历的秒数。
    srand(static_cast<unsigned int>(time(nullptr)));

    // 创建一个二叉搜索树
    BinaryTree<int> tree;

    // 插入一些节点
    tree.InsertBSTNodeWhile(5);
    tree.InsertBSTNodeWhile(3);
    tree.InsertBSTNodeWhile(7);
    tree.InsertBSTNodeWhile(1);
    tree.InsertBSTNodeWhile(4);
    tree.InsertBSTNodeWhile(6);
    tree.InsertBSTNodeWhile(0);
    tree.InsertBSTNodeWhile(2);

    // 插入重复节点
    tree.InsertBSTNodeWhile(6);
    // 获得根节点地址
    TreeNode<int> *root = tree.GetRoot();

    // 用递归函数插入节点
    tree.InsertBinarySearchTreeNodeRecursion(root, 10);
    tree.InsertBinarySearchTreeNodeRecursion(root, 8);
    tree.InsertBinarySearchTreeNodeRecursion(root, 9);

    std::cout << std::endl;
    std::cout << "Binary Search Tree: " << std::endl;
    std::cout << std::endl;
    tree.PrintTree(root,0);
    std::cout << std::endl;

    // 中序遍历打印节点值
    std::cout << "Inorder Traversal: ";
    tree.InOrderTraversal(root);
    std::cout << std::endl;

    // 深度，从根节点到该节点
    TreeNode<int> *node = tree.FindTreeNode(0);
    if (node != nullptr)
    {
        std::cout << "Depth of node 4: " << tree.GetTreeNodeDepth(node) << std::endl;
    }

    // 高度是最大高度，是最远叶节点到该节点的高度。
    node = tree.FindTreeNode(7);
    if (node != nullptr)
    {
        std::cout << "Hight of node 4: " << tree.GetTreeNodeHight(node) << std::endl;
    }

    // 高度
    node = tree.FindTreeNode(9);
    if (node != nullptr)
    {
        std::cout << "Hight of node 4: " << tree.GetTreeNodeHight(node) << std::endl;
    }
    // 移除元素7
    tree.RemoveTreeNodeAndAllChildTreeWhile(7);


    std::cout << std::endl;
    std::cout << "Binary Search Tree: " << std::endl;
    std::cout << std::endl;
    tree.PrintTree(root,0);
    std::cout << std::endl;

    // 中序遍历打印
    std::cout << "Inorder Traversal: ";
    tree.InOrderTraversal(root);
    std::cout << std::endl;

    // 释放整个树
    tree.DestroyTreeWhile();

    // 注意这个地方，释放整个树是动了root_的（让root_地址为nullptr），而root还存者原来root_的地址，此时需要更新地址。
    root = tree.GetRoot();

    std::cout << std::endl;
    std::cout << "Binary Search Tree: " << std::endl;
    std::cout << std::endl;
    tree.PrintTree(root,0);

    //中序遍历打印
    std::cout << "Inorder Traversal: ";
    // 如果此时不更新就会出现野指针
    tree.InOrderTraversal(root);
    std::cout << std::endl;
    std::cout << std::endl;

    // 判断是否为空
    std::cout << "Binary Search Tree is empty :" << tree.IsEmptyTree() << std::endl;

    return 0;
}

// 循环实现释放内存
// DFS 深度优先搜索，是从右子树开始释放，属于 pre_order 前序遍历
// 循环实现，不会导致栈的溢出，相对应的性能也会更好，就是不太好理解。
// 通过栈stack为容器实现，先入后出尾插尾删。
template <class ValType>
void BinaryTree<ValType>::DestroyTreeWhile()
{
    // 如果根节点为空则直接返回
    if (root_ == nullptr)
    {
        return;
    }
    else
    {
        // 创建一个栈stack nodes来存储节点
        std::stack<TreeNode<ValType> *> nodes;
        // 插入根节点
        nodes.push(root_);
        // 当容器为空时结束循环
        while (!nodes.empty())
        {
            // cur指针指向栈顶，top函数返回值为引用，这个地方我是有点迷惑的。
            // 这个地方是发生了隐式转换，可以把引用近似的理解为取地址，左值是指针，右值约等于取地址。
            TreeNode<ValType> *cur = nodes.top();
            // 弹出了栈顶节点，注意这个地方弹出只是移出容器而不是删掉，前面存了指针，还可以进行后续操作
            nodes.pop();
            // 如果左节点不为空则插入其左节点
            if (cur->left != nullptr)
            {
                nodes.push(cur->left);
            }
            // 如果右节点不为空则插入其右节点
            if (cur->right != nullptr)
            {
                nodes.push(cur->right);
            }

            // 释放该节点内存，等第二次进入循环则cur又被创建然后指向栈顶元素
            delete cur;
        }
    }
    // 总的过程就是先从根节点开始，先压入栈然后再弹出，把它的左右节点都压入栈，最后释放掉根节点内存，完成一次循环。
    // 此后栈中存在俩个元素，根的左右子节点。然后还是弹出父节点，左右子节点进去，释放父节点内存，
    root_ = nullptr;
}

// DFS 深度优先搜索，也是后序遍历 Post-order 和循环实现的前序遍历 Pre_order 逻辑有所区别
// 递归实现，代码直观，如果递归深度过深时可能会导致栈溢出的问题，因此也可以使用循环实现，效率更高，但是代码会复杂。
template <typename ValType>
void BinaryTree<ValType>::DestroyTreeRecursion(TreeNode<ValType> *node)
{
    // 这个地方是删除元素的函数中嵌套了这个函数，而当我们释放完之后没有需要将root_置空，这样在输出时传root_进去才不会出问题
    if (node == root_)
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            // 灵活使用递归
            // 递归逻辑就是一条路走到底，直到叶节点，然后删除，到父节点的右侧再走到底直到叶节点
            DestroyTreeRecursion(node->left);
            DestroyTreeRecursion(node->right);
            delete node;
        }
        root_ = nullptr;
    }
    else if (node != root_)
    {// 如果传进来的不是root_则说明时其他节点就说明是移除元素的函数调用此时并不会完全释放掉所有元素因此不需要置空
        if (node == nullptr)
        {
            return;
        }
        else
        {
            // 灵活使用递归
            // 递归逻辑就是一条路走到底，直到叶节点，然后删除，到父节点的右侧再走到底直到叶节点
            DestroyTreeRecursion(node->left);
            DestroyTreeRecursion(node->right);
            delete node;
        }
    }
}

// 构造函数root_置空
template <typename ValType>
BinaryTree<ValType>::BinaryTree()
    : root_(nullptr) {}

// 析构是没有参数的，因此如果用递归实现释放内存就需要再创建一个函数，因为需要传节点进去。
// 如果是用循环则可以直接写在析构函数里面。
template <typename ValType>
BinaryTree<ValType>::~BinaryTree()
{
    // DestroyTreeRecursion(root_);
    // 不需要传值进去
    DestroyTreeWhile();
}

// 任意随机插入节点生成普通二叉树，没意义
template <typename ValType>
void BinaryTree<ValType>::InsertAny(TreeNode<ValType> *node, ValType val)
{
    if (node == nullptr)
    {
        node = new TreeNode<ValType>;
        node->val = val;
        return;
    }

    if (rand() % 2 == 0)
    {
        if (node->left != nullptr)
        {
            InsertAny(node->left);
        }
        else if (node->right != nullptr)
        {
            InsertAny(node->right);
        }
    }
    else
    {
        if (node->left != nullptr)
        {
            InsertAny(node->left, val);
        }
        else if (node->right != nullptr)
        {
            InsertAny(node->right, val);
        }
    }
}

// 首先是递归思想的实现，其次*&的使用，想清楚.还可以实现一种用while循环实现的。
template <typename ValType>
void BinaryTree<ValType>::InsertBinarySearchTreeNodeRecursion(TreeNode<ValType> *&node, ValType val)
{
    // 一开始是只穿了*指针进去企图改树，但是请注意，比如说一开始root_为空时传进去，node是保存了new的新内存但是，不是对root_的修改
    // node只是形参，接收了root_的地址然后进行后续的成树，因为这个地方不是把new的节点接入root_的左右而是直接以新的节点的地址开始成树。
    // 因此你需要传指针的引用进去完成对root_的值的改变，new的新内存地址存在了node形参上
    if (node == nullptr)
    {
        node = new TreeNode<ValType>(val);
        return;
    }

    if (val < node->val)
    {
        if (node->left == nullptr)
        {
            node->left = new TreeNode<ValType>(val);
        }
        else
        {
            InsertBinarySearchTreeNodeRecursion(node->left, val);
        }
    }
    else if (val > node->val)
    {
        if (node->right == nullptr)
        {
            node->right = new TreeNode<ValType>(val);
        }
        else
        {
            InsertBinarySearchTreeNodeRecursion(node->right, val);
        }
    }
}

// 二叉搜索树循环插入元素
template <typename ValType>
void BinaryTree<ValType>::InsertBSTNodeWhile(ValType val)
{
    // 当树为空时，插入一个新节点
    if (root_ == nullptr)
    {
        root_ = new TreeNode<ValType>(val);
        return;
    }

    TreeNode<ValType> *cur = root_;
    TreeNode<ValType> *pre = nullptr;

    // 根节点不为空的时候，循环到最后cur指向nullptr截止，此时cur指向nullptr，pre指向父节点。
    // 循环结束是pre已经指向要插入节点的父节点，后续只需要判断插入父节点左边还是右边。
    while (cur != nullptr)
    {
        if (val > cur->val)
        {
            pre = cur;
            cur = cur->right;
        }
        else if (val < cur->val)
        {
            pre = cur;
            cur = cur->left;
        }
        // 重复元素直接退出函数
        else if (val == cur->val)
        {
            return;
        }
    }

    // 插入节点，只需要判断插左边还是插入右边即可
    if (val < pre->val)
    {
        pre->left = new TreeNode<ValType>(val);
    }
    else if (val > pre->val)
    {
        pre->right = new TreeNode<ValType>(val);
    }
}

// 查找元素
template <typename ValType>
TreeNode<ValType> *BinaryTree<ValType>::FindTreeNode(ValType val)
{
    if (root_ == nullptr)
    {
        return nullptr;
    }

    TreeNode<ValType> *cur = root_;

    while (cur != nullptr)
    {
        if (val > cur->val)
        {
            cur = cur->right;
        }
        else if (val < cur->val)
        {
            cur = cur->left;
        }
        else
        {
            break;
        }
    }

    return cur;
}

// 删除节点包括其子树。
template <typename ValType>
void BinaryTree<ValType>::RemoveTreeNodeAndAllChildTreeWhile(ValType val)
{
    if (root_ == nullptr)
    {
        return;
    }

    TreeNode<ValType> *cur = root_;
    TreeNode<ValType> *parent = nullptr;

    while (cur != nullptr)
    {
        if (val == cur->val)
        {
            break;
        }
        else if (val < cur->val)
        {
            parent = cur;
            cur = cur->left;
        }
        else
        {
            parent = cur;
            cur = cur->right;
        }
    }

    if (cur == nullptr)
    {
        // 没找到要删除的节点
        return;
    }

    // 删除节点
    DestroyTreeRecursion(cur);

    // 更新父节点指针
    if (parent != nullptr)
    {
        if (parent->left == cur)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
    }
    else
    {
        root_ = nullptr;
    }
}

// 判断是否为空
template <typename ValType>
bool BinaryTree<ValType>::IsEmptyTree()
{
    if (root_ == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 获得高度，高度是从叶节点到该节点 递归实现， 这个个人感觉非常巧妙我看GPT的。
template <typename ValType>
int BinaryTree<ValType>::GetTreeNodeHight(TreeNode<ValType> *node)
{
    // 要领悟到递归的精髓
    // 如果传进来的节点是空指针直接返回-1，计算不了
    if (node == nullptr)
    {
        // 这个-1的值设置的也非常巧妙
        return -1;
    }
    // 进来算左右子树的高度，进递归，到最末的状态就是node为空指针，此时左右子树的返回值都是-1然后三目运算符相等给值变为0，上一层左右又都是0加一上一层变为1.继续递归下去。递归可以解决不是平衡树的问题。
    int left_Child_tree_hight = GetTreeNodeHight(node->left);
    int right_Child_tree_hight = GetTreeNodeHight(node->right);

    return left_Child_tree_hight > right_Child_tree_hight
               ? left_Child_tree_hight + 1
               : right_Child_tree_hight + 1;
}

// 获得深度，深度是从根节点到该节点
template <typename ValType>
int BinaryTree<ValType>::GetTreeNodeDepth(TreeNode<ValType> *node)
{
    int depth(0);
    // 树为空返回-1，如果节点传进来为空，判断不了在哪里也就只能返回-1
    if (root_ == nullptr || node == nullptr)
    {
        return -1;
    }
    // 承接根节点遍历并且计数，相等时返回深度，从根节点到该节点
    TreeNode<ValType> *cur = root_;

    while (cur != nullptr)
    {
        if (node->val > cur->val)
        {
            depth++;
            cur = cur->right;
        }
        else if (node->val < cur->val)
        {
            depth++;
            cur = cur->left;
        }
        else if (node->val == cur->val)
        {
            return depth;
        }
    }

    return -1;
}

// 中序遍历打印节点值的实现-GPT的后续再看看现在不想弄了
template <typename ValType>
void BinaryTree<ValType>::InOrderTraversal(TreeNode<ValType> *node)
{
    if (node == nullptr)
    {
        return;
    }

    InOrderTraversal(node->left);
    std::cout << node->val << " ";
    InOrderTraversal(node->right);
}
// 访问root_
template <typename ValType>
TreeNode<ValType> *BinaryTree<ValType>::GetRoot() const
{
    return root_;
}

// 后加的比较好看的打印方式，直接把整个树的结构给打印出来
template <typename ValType>
void BinaryTree<ValType>::PrintTree(TreeNode<ValType> *node, int level)
{
    if (node == nullptr)
    {
        return;
    }

    PrintTree(node->right, level + 1);

    if (level != 0)
    {
        for (int i = 0; i < level - 1; i++)
        {
            std::cout << "|\t";
        }
        std::cout << "|-------";
    }

    std::cout << node->val << std::endl;

    PrintTree(node->left, level + 1);
}
