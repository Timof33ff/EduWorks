#include <cstdlib>
#include <iostream>
#include <locale.h>
#include <ctime>

int tabs = 0;
// описание узла дерева

typedef struct Node
{
    int key;
    struct Node* Left, * Right;
}Node;
// описание класса BDP (бинарное дерево поиска)

Node* createRoot(int x)
{
    Node* root = new Node;
    root->key = x;
    root->Left = NULL;
    root->Right = NULL;
    return root;
}

class BDP
{
public:
    Node* BinSTree;

    BDP(int x)
    {
        BinSTree = createRoot(x);
    }
    ~BDP()
    {
        Destructor(BinSTree);
    }
    void push(Node* Root, Node* newRoot);
    void Show(Node* Root);
    int maxDepth(Node* root);
    void printTree(Node* Root);
    bool BinSearch(Node* Root, int x);
    int MaxElement(Node* Root);
    int MinElement(Node* Root);

    void Destructor(Node* Root)
    {
        if (Root)
        {
            Destructor(Root->Left);
            Destructor(Root->Right);
            delete Root;
        }
    }
};

void BDP::push(Node* Root, Node* newRoot)
{
    if (Root->key > newRoot->key)
    {
        if (Root->Left == NULL)
        {
            Root->Left = newRoot;
        }
        else
        {
            push(Root->Left, newRoot);
        }
    }
    if (Root->key < newRoot->key)
    {
        if (Root->Right == NULL)
        {
            Root->Right = newRoot;
        }
        else
        {
            push(Root->Right, newRoot);
        }
    }
}

void BDP::Show(Node* Root)
{
    if (Root->Right != NULL)
    {
        Show(Root->Right);
    }
    std::cout << " Value" << "\t[" << Root->key << "]" << std::endl;
    if (Root->Left != NULL)
    {
        Show(Root->Left);
    }
}

int BDP::maxDepth(Node* root)
{
    if ( root == NULL) return 0;

    int nleft = maxDepth(root->Left);
    int nright = maxDepth(root->Right);

    return nleft > nright ? nleft + 1 : nright + 1;
}

void BDP::printTree(Node* Root)
{
    if (!Root) return;

    tabs += 5;
    printTree(Root->Right);
    for (int i = 0; i < tabs; i++) std::cout << " ";
    std::cout << "[" << Root->key << "]" << std::endl;
    printTree(Root->Left);
    tabs -= 5;
}

bool BDP::BinSearch( Node* Root, int x)
{
    if (Root == NULL) return false;
    if ( Root->key == x) 
    {
        return true;
    }
    else
    {
        if ( Root->key > x)
        {
            if (  Root->Left == NULL)
            {
                std::cout << " No matches :(" << std::endl;
                return false;
            }
            else
            {
                BinSearch( Root->Left, x);
            }
        }
        if ( Root->key < x)
        {
            if ( Root->Right == NULL)
            {
                std::cout << " No matches :(" << std::endl;
                return false;
            }
            else
            {
                BinSearch( Root->Right, x);
            }
        }
    }
}

int BDP::MinElement(Node* Root)
{
    if (Root->Left == NULL)
    {
        return Root->key;
    }
    else
    {
        return MinElement(Root->Left);
    }
}

int BDP::MaxElement(Node* Root)
{
    if (Root->Right == NULL)
    {
        return Root->key;
    }
    else
    {
        return MaxElement(Root->Right);
    }
}