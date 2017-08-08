#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

template <typename T>
class BinTree
{
private:
    struct BinaryTree{
        T inf;
        T Data; //���� ������
        BinaryTree* Left; //��������� �� ����� �������
        BinaryTree* Right; //��������� �� ������ �������
    };
public:
    T tData;
    BinaryTree* BTree;
    BinaryTree* NewBTree;
    BinTree(int num);
    ~BinTree();
    void Make_Binary_Tree(BinaryTree** Node, int n);
    void Print_BinaryTree(BinaryTree* Node, int l);
    void PreOrder_BinaryTree(BinaryTree* Node);
    void PostOrder_BinaryTree(BinaryTree* Node);
    void SymmetricOrder_BinaryTree(BinaryTree* Node);
    void Extract_BinaryTree(BinaryTree* Node, T data);
    void Map_BT(BinaryTree* Node, T data);
    void Clean_BT(BinaryTree* Node);
};

int main()
{
    setlocale(LC_ALL, "rus");

    SetConsoleCP(1251); //win-cp 1251;
    SetConsoleOutputCP(1251);
    int num,type;

    cout << "������� ���������� �����:  ";
    cin >> num;

    BinTree <int> Tree(num);
    Tree.Make_Binary_Tree(&Tree.BTree,num);

    cout <<"\n\n������ ��������� ������(1)\n������ �����(2)\n�������� �����(3)\n������������ �����(4)\n���������� ��������� �� ��������� ��������(5)\n������������ ��������������(6)\n";
    cin >> type;

    switch (type)
    {
        case 1:
        {
        Tree.Print_BinaryTree(Tree.BTree,5);;
        break;
        }
        case 2:
        {
        Tree.PreOrder_BinaryTree(Tree.BTree);
        cout << endl;
        break;
        }
        case 3:
        {
        Tree.PostOrder_BinaryTree(Tree.BTree);
        cout << endl;
        break;
        }
        case 4:
        {
        Tree.SymmetricOrder_BinaryTree(Tree.BTree);
        cout << endl;
        break;
        }
        case 5:
        {
        cout << "\n���� �������� ��������: ";
        cin >> Tree.tData;
        Tree.Extract_BinaryTree(Tree.BTree, Tree.tData);
        Tree.Print_BinaryTree(Tree.NewBTree,3);
        break;
        }
        case 6:
        {
        cout << "\n������� ������� ��� �������������� ������ ����� ��������� ��������: ";
        cin >> Tree.tData;
        Tree.Map_BT(Tree.BTree, Tree.tData);
        Tree.Print_BinaryTree(Tree.BTree,3);
        break;
        }
        default:
                {
                 cout << "�������" << endl;
                }
    }

    cout << "Thanks!" << endl;
    return 0;
}

template <typename T>
BinTree<T>::BinTree(int num)
{
    BTree = NULL;
    cout << "������ ������ �� " << num << " ���������." << endl;
}

template <typename T>
void BinTree<T>::Clean_BT(BinaryTree* Node)
{
    if (Node != NULL) {
        Clean_BT(Node->Left);
        Clean_BT(Node->Right);
        delete(Node);
    }
}

template <typename T>
BinTree<T>::~BinTree()
{
    Clean_BT(BTree);
}

template <typename T>
void BinTree<T>::Make_Binary_Tree(BinaryTree** Node, int n){
  BinaryTree** ptr;                                 //��������������� ���������
  T tData;
  while (n > 0) {
    ptr = Node;
    cout << "������� �������� ";
    cin >> tData;
    while (*ptr != NULL) {
      if (((*ptr)->Data) >= tData)
        ptr = &((*ptr)->Left);
      else ptr = &((*ptr)->Right);
    }
    (*ptr) = new BinaryTree();
    (*ptr)->Data = tData;
    n--;
  }
}

template <typename T>
void BinTree<T>::Print_BinaryTree(BinaryTree* Node, int l)
{
    int i;
    if (Node != NULL) {
        Print_BinaryTree(Node->Right, l+1);
        for (i=0; i< l; i++) cout << "    ";
        cout << Node->Data;
        Print_BinaryTree(Node->Left, l+1);
    }
    else cout << endl;
}

template <typename T>
void BinTree<T>::PreOrder_BinaryTree(BinaryTree* Node){
  if (Node != NULL) {
    cout << Node->Data << "   ";
    PreOrder_BinaryTree(Node->Left);
    PreOrder_BinaryTree(Node->Right);
  }
}

template <typename T>
void BinTree<T>::PostOrder_BinaryTree(BinaryTree* Node){
  if (Node != NULL) {
    PostOrder_BinaryTree(Node->Left);
    PostOrder_BinaryTree(Node->Right);
    cout << Node->Data << "   ";
  }
}

template <typename T>
void BinTree<T>::SymmetricOrder_BinaryTree(BinaryTree* Node){
  if (Node != NULL) {
    PostOrder_BinaryTree(Node->Left);
    cout << Node->Data << "   ";
    PostOrder_BinaryTree(Node->Right);
  }
}

template <typename T>
void BinTree<T>::Extract_BinaryTree(BinaryTree* Node, T data){
    while (Node !=  NULL){
        if (Node->Data > data) {
            Node = Node->Left;
            continue;
        } else if (Node->Data < data) {
            Node = Node->Right;
            continue;
        } else {
            NewBTree = Node;
            break;
        }
    }
}

template <typename T>
void BinTree<T>::Map_BT(BinaryTree* Node, T data){
  if (Node != NULL) {
        Node->Data += data;
        //cout << Node->Data << "   ";
        Map_BT(Node->Left, data);
        Map_BT(Node->Right, data);
  }
}

