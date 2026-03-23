#include <iostream>

class AStack 
{
 char *s;
 int i;
 
 public:
 AStack ( int k)  {s = new char [k];i = 0; }	
 ~AStack () {delete [] s;}
 
 void push ( char a)  {s[i++] = a;}
 char pop ()  {if(i == 0 )	return 0; else return s[--i]; }
};

class AQueue 
{
 int *q;
 int h, t;
 
 public:
 AQueue ()  {q = new int [1000]; h = t = 0; }	
 ~AQueue () {delete [] q;}
 
 void push ( int a)  { q[t++] = a;}
 int pop ()  {if(h == t )	return -1; else return q[h++]; }
 int Out ( int *A, int p) { int i = 0; while ( i != -1) { i = pop(); if ( i != -1) A[p++] = i; } return p; }
 void Init () { h = t = 0; }
};

class AList 
{
 struct Node
  {
  int Key;
   Node *T;
  };
  
  Node *L;
  public:
  	AList();
  	void push(int k);
  	void out(int *A);
};
AList::AList()
{
	L = new Node;
	L -> Key = 0;
	L -> T = nullptr;
}
void AList::push(int k)

{
    Node *N, *M, *H; int K1 = 1;
	N = L;
	
	if(N -> T == nullptr)
	{
	 M = new Node;
	 M -> Key = k;
	 M -> T = nullptr;
	 N -> T = M; 
	}
	else 
	{
	while (K1 == 1)
		{
		if(N -> T != nullptr)
			{
			H = N;
			 N = N -> T;
			 if(k<N->Key)
			 {
			 M = new Node;
			  M -> Key = k;
			  M -> T = N; 
			  H -> T = M;
			  K1=0;
			 }
			}
			else
			{
			M = new Node;
	 		 M -> Key = k;
	 		 M -> T = nullptr;
	 		 N -> T = M;
			 K1 = 0;		
			}
		}
	}
}

void AList :: out(int *A)

{Node *N; int i = 0;
	N = L;
	while(N -> T != nullptr)
	{N = N -> T;
	 A[i++] = N -> Key;
	}
}
/*
class BTS // Binary search tree 
{
	struct Node
  {
  int Key;
   Node *L, *R;
  };
  Node *T;
  
  public:
  BTS() { T = new Node; T -> Key = 0; T -> L = nullptr; T -> R = nullptr;};
  ~BTS() { delete T; };
  void push( int x);
  void show();
  int binSearch( int x);
  int MinValue();
  int MaxValue();
};

void BTS::push ( int x)
{ 
    Node *Tree;
	if( T -> Key == x) return;
	while( )
 { 
	if( x < Tree -> Key) 
	{

	 Tree -> Key = x;
	 Tree -> L = nullptr;
	 Tree -> R = nullptr;
	 T -> L = Tree;
	}
	if( x > Tree -> Key) 
	{ 
	 T -> Key = x;
	 T -> L = nullptr;
	 T -> R = nullptr;
	 Tree -> R = T;
	}
 }
     if( T -> L == nullptr && T -> R == nullptr) T -> Key = x; // если дерево пустое
}

void BTS::show()              //Функция обхода
{
	BTS::Node *Tree;
	Tree = T;
     int i = 0;
	 std::cout<< " Root:\t" << Tree -> Key <<'\n';
		while(Tree -> L != nullptr && Tree -> R != nullptr)
	{
	  Tree -> L = T -> L -> L;
	  Tree -> R = T -> R -> R;
	  std::cout<< " Left[" << i << "]:\t" << Tree -> L -> Key << '\t' << " Right[" << i << "]:\t" << Tree -> R -> Key << '\t\n';
	  i++;
	}

}

int BTS::binSearch ( int x)
{
	BTS::Node *Tree;
	Tree = T;
	while( Tree != 0)
	{
	if ( x == Tree -> Key) return x;
	else
   {
	if ( x < Tree -> Key){ Tree -> L = T -> L -> L; push( x);} //При помощи рекурсии продвигаемся дальше по левой ветке
	if ( x > Tree -> Key){ Tree -> R = T -> R -> R; push( x);} //При помощи рекурсии продвигаемся дальше по левой ветке
   }
	}
 std::cout<< " NO SIMILIAR ITEMS FOUND"<<std::endl;
}

int BTS::MinValue()
{
    BTS::Node *Tree;
    Tree = T;
	if ( Tree -> L != NULL)
	{
	 Tree -> L = T -> L -> L;
	 return MinValue();	
	} 
	else return Tree -> Key;
}

int BTS::MaxValue()
{
    BTS::Node *Tree;
    Tree = T;
	if ( Tree -> R != NULL)
	{
     Tree -> R = T -> R -> R;
	 return MinValue();
	}
	else return Tree -> Key;
}
*/

struct Node
{
	int key;
	Node *L, *R;
	Node( int Key)
	{
		key = Key;
		L = nullptr;
		R = nullptr;
	}
	~Node()
	{
		delete L;
		delete R;
	}
};

void push( Node *root, int x)
{ 
  if( root == nullptr) { root = new Node( x);}
  if( x < root -> key) { push( root -> L, x);}
  if( x == root -> key) {return;}
  if( x > root -> key) { push( root -> R, x);}
}

void show( Node *root)
{
	if( root == nullptr) { return;}
	if( root -> L == nullptr && root -> R == nullptr) 
	std::cout<< "\t[" << root -> key << "]\t" << std::endl;
	else
	{ 
     if( root -> L == nullptr)  
	}
}

int output( Node *root)
{
	Node *node, *left, *right;
	node = root;
	int *A; A = new int[];
	if( node == nullptr) { return A;}
	while( left != nullptr && right != nullptr)  
	{
     
	}
}

int MinValue( Node* root)
{
	if ( root -> L != nullptr)
	{
	 root -> L = root -> L -> L;
	 MinValue( root);	
	} 
	else return root -> key;
}

int MaxValue( Node* root)
{ 
	if ( root -> R != nullptr)
	{
     root -> R = root -> R -> R;
	 MaxValue( root);
	}
	else return root -> key;
}
