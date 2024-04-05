//@ AVL树的实现功能非常齐全
// 核心功能自己敲了一遍，难度有点大，对递归的理解等等，其余函数由GPT生成
#include <iostream>
#include <algorithm>
#include <iomanip>

    struct TreeNode
{
    int val_{};
    int height = 0;
    TreeNode *left{};
    TreeNode *right{};
    TreeNode() = default;
    explicit TreeNode(int val) : val_(val) {}
};

class AVLTree
{
private:
    TreeNode *root_;

public:
    AVLTree() : root_(nullptr) {}
    inline int GetHeight(TreeNode *node);
    void UpdateHeight(TreeNode *node);
    int BalanceFactor(TreeNode *node);
    TreeNode *RightRotate(TreeNode *node);
    TreeNode *LeftRotate(TreeNode *node);
    TreeNode *Rotate(TreeNode *node);
    void Insert(int val);
    TreeNode *InsertHelper(TreeNode *node, int val);
    void Remove(int val);
    TreeNode *RemoveHelper(TreeNode *node, int val);
    void PrintTree(TreeNode *node, int space);
    TreeNode *Search(TreeNode *node, int val);
    TreeNode *FindMin(TreeNode *node);
    TreeNode *FindMax(TreeNode *node);
    void InOrder(TreeNode *node);
    void PreOrder(TreeNode *node);
    void PostOrder(TreeNode *node);
    int CountNodes(TreeNode *node);
    void ClearTree(TreeNode *node);
    TreeNode *CopyTree(TreeNode *node);
    TreeNode *GetRoot();
};

int main()
{
    AVLTree avl;

    // 插入测试
    avl.Insert(10);
    avl.Insert(11);
    avl.Insert(20);
    avl.Insert(30);
    avl.Insert(50);
    avl.Insert(55);
    avl.Insert(90);
    avl.Insert(80);
    avl.Insert(35);
    avl.Insert(33);
    avl.Insert(40);
    avl.Insert(46);
    avl.Insert(25);
    avl.Insert(100);

    std::cout << std::endl;
    std::cout << "Tree structure:" << std::endl;
    std::cout << std::endl;
    avl.PrintTree(avl.GetRoot(), 0);

    // 删除测试
    avl.Remove(35);
    avl.Remove(11);

    std::cout << std::endl;
    std::cout << "----------------------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    // 打印树
    std::cout << "Tree structure:" << std::endl;
    std::cout << std::endl;
    avl.PrintTree(avl.GetRoot(), 0);
    std::cout << std::endl;

    // 搜索测试
    TreeNode *searchedNode = avl.Search(avl.GetRoot(), 40);
    if (searchedNode)
    {
        std::cout << "Found node: " << searchedNode->val_ << std::endl;
    }
    else
    {
        std::cout << "Node not found." << std::endl;
    }

    // 查找最小值和最大值测试
    TreeNode *minNode = avl.FindMin(avl.GetRoot());
    TreeNode *maxNode = avl.FindMax(avl.GetRoot());
    std::cout << "Minimum value: " << minNode->val_ << std::endl;
    std::cout << "Maximum value: " << maxNode->val_ << std::endl;

    // 中序遍历测试
    std::cout << "In-order traversal:" << std::endl;
    avl.InOrder(avl.GetRoot());
    std::cout << std::endl;

    // 前序遍历测试
    std::cout << "Pre-order traversal:" << std::endl;
    avl.PreOrder(avl.GetRoot());
    std::cout << std::endl;

    // 后序遍历测试
    std::cout << "Post-order traversal:" << std::endl;
    avl.PostOrder(avl.GetRoot());
    std::cout << std::endl;

    // 节点计数测试
    std::cout << "Node count: " << avl.CountNodes(avl.GetRoot()) << std::endl;

    // 清空树测试
    avl.ClearTree(avl.GetRoot());
    std::cout << "Tree cleared." << std::endl;

    std::cout << std::endl;
    return 0;
}

int AVLTree::GetHeight(TreeNode *node)
{
    return node == nullptr ? -1 : node->height;
}

void AVLTree::UpdateHeight(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
}

int AVLTree::BalanceFactor(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return GetHeight(node->left) - GetHeight(node->right);
}

TreeNode *AVLTree::RightRotate(TreeNode *node)
{
    TreeNode *child = node->left;
    TreeNode *grandChild = child->right;
    child->right = node;
    node->left = grandChild;

    UpdateHeight(node);
    UpdateHeight(child);

    return child;
}

TreeNode *AVLTree::LeftRotate(TreeNode *node)
{
    TreeNode *child = node->right;
    TreeNode *grandChild = child->left;
    child->left = node;
    node->right = grandChild;

    UpdateHeight(node);
    UpdateHeight(child);

    return child;
}

TreeNode *AVLTree::Rotate(TreeNode *node)
{
    int balanceFactor = BalanceFactor(node);
    if (balanceFactor > 1)
    {
        if (BalanceFactor(node->left) >= 0)
        {
            return RightRotate(node);
        }
        else
        {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }
    }
    else if (balanceFactor < -1)
    {
        if (BalanceFactor(node->right) <= 0)
        {
            return LeftRotate(node);
        }
        else
        {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }
    }

    return node;
}

void AVLTree::Insert(int val)
{
    root_ = InsertHelper(root_, val);
}

TreeNode *AVLTree::InsertHelper(TreeNode *node, int val)
{
    if (node == nullptr

    )
    {
        return new TreeNode(val);
    }

    if (val > node->val_)
    {
        node->right = InsertHelper(node->right, val);
    }
    else if (val < node->val_)
    {
        node->left = InsertHelper(node->left, val);
    }
    else if (val == node->val_)
    {
        return node;
    }

    UpdateHeight(node);
    node = Rotate(node);

    return node;
}

void AVLTree::Remove(int val)
{
    root_ = RemoveHelper(root_, val);
}

TreeNode *AVLTree::RemoveHelper(TreeNode *node, int val)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (val < node->val_)
    {
        node->left = RemoveHelper(node->left, val);
    }
    else if (val > node->val_)
    {
        node->right = RemoveHelper(node->right, val);
    }
    else
    {
        if (node->left == nullptr || node->right == nullptr)
        {
            TreeNode *temp = node->left ? node->left : node->right;
            if (temp == nullptr)
            {
                delete node;
                return nullptr;
            }
            else
            {
                *node = *temp;
                delete temp;
            }
        }
        else
        {
            TreeNode *temp = FindMin(node->right);
            node->val_ = temp->val_;
            node->right = RemoveHelper(node->right, temp->val_);
        }
    }

    UpdateHeight(node);
    node = Rotate(node);

    return node;
}

void AVLTree::PrintTree(TreeNode *node, int level)
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

    std::cout << node->val_ << std::endl;

    PrintTree(node->left, level + 1);
}

TreeNode *AVLTree::Search(TreeNode *node, int val)
{
    if (node == nullptr || node->val_ == val)
    {
        return node;
    }

    if (val < node->val_)
    {
        return Search(node->left, val);
    }
    else
    {
        return Search(node->right, val);
    }
}

TreeNode *AVLTree::FindMin(TreeNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

TreeNode *AVLTree::FindMax(TreeNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    while (node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

void AVLTree::InOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    InOrder(node->left);
    std::cout << node->val_ << " ";
    InOrder(node->right);
}

void AVLTree::PreOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->val_ << " ";
    PreOrder(node->left);
    PreOrder(node->right);
}

void AVLTree::PostOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    PostOrder(node->left);
    PostOrder(node->right);
    std::cout << node->val_ << " ";
}

int AVLTree::CountNodes(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return 1 + CountNodes(node->left) + CountNodes(node->right);
}

void AVLTree::ClearTree(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    ClearTree(node->left);
    ClearTree(node->right);
    delete node;
}

TreeNode *AVLTree::CopyTree(TreeNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    TreeNode *newNode = new TreeNode(node->val_);
    newNode->left = CopyTree(node->left);
    newNode->right = CopyTree(node->right);

    return newNode;
}

TreeNode *AVLTree::GetRoot()
{
    return root_;
}