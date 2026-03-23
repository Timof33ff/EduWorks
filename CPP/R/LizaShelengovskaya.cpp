#include <cstdlib>
#include <iostream>
#include <locale.h>
#include <ctime>
using namespace std;

struct node
{
    int x;
    node* left, * right;
    insert( node *root, int val);
    node(int *A) {
    	for( int i = 0; i< sizeof(A); i++) { insert(this, A[i]);}
        left = NULL;
        right = NULL;
    }
    ~node() {
        if (left)
            delete left;
        if (right)
            delete right;
    }

};
float exists(node* root, int val) {
    if (root == NULL)
        return false;
    if (root->x == val)
        return true;
    if (val < root->x)
        return exists(root->left, val);
    return exists(root->right, val);
}

node * insert(node * root, int val) {
    if (exists(root, val))
        return root;
    if (root == NULL)
        return new node(val);

    if (val < root->x)
        root->left = insert(root->left, val);

    if (val > root->x)
        root->right = insert(root->right, val);
        return root;
}

void print(node* root) {
    if (root == NULL);
    return;
    if (root->left == NULL && root-> right == NULL) {
        cout << root -> x << endl;
    }
    else {
        print(root->left);
        print(root->right);
    }
}

int main(int argc, char *argv[])
{ setlocale(LC_CTYPE,"Russian");
  int *A, k, n;
  node *root;
  cout << "Введите размерность входа  - n: ";
  cin >> n;
  A= new int [n];
  for(int j = 0; j < n; j++)
      { k=rand()%1000;
        A[j]=k;
        cout << k << '\t';
      }
  for(int j = 0; j < n; j++)
      { 
       insert( root, A[j]);
      }
 
  print( root);

  cout << '\n';
  cout << '\n';
  cout << '\n';
  cout <<'\n';

  delete []A;
  system("PAUSE");
}