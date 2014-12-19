/**
 * Binary Search Tree Class
 * Stub written by Sorrachai Yingchareonthawornchai, 26 Sep 2014
 * Completed by [Gabriel Morcote]
 */

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

#include <iostream>
using namespace std;
template<class T> class BinarySearchTree
{
    public:
    BinarySearchTree() {root = nullptr;}
    //destructor
    ~BinarySearchTree() {
        deleteTree(root);
    }

    void insert(const T &t);
   

    void display() const
    {
        int level=0;
        _display(root,level);
    }
    void inOrderTraverse(vector<T>& vec) const;  //TODO
    void deleteNode(const T &t); //TODO
    void forEachInterval(const T &a, const T&b, function<void (const T)> func) const; //TODO
    void filter(function<bool (const T)> isIn); //TODO
    bool verifyBinarySearchTree() const; //TODO
    
     
    private:
        // class Node (you can modify,but it is not necessary)
        // The nested node class for objects in our tree.
        struct Node
        {
                friend class BinarySearchTree;

                Node() {m_ll = nullptr;  m_rl = nullptr;}

                Node(const T &t) {m_num = t;  m_ll = nullptr;  m_rl = nullptr;}
                Node(const T &t, Node * l, Node *r) : m_num{t}, m_ll{l}, m_rl{r} {}

                T &data() {return m_num;}

                const T &data() const {return m_num;}

                Node    *m_ll;
                Node    *m_rl;
                T       m_num;
        };

    Node *root;

    //internal method
    void _display(Node *p,int level) const
    {
        if (p ==nullptr) return;
        level++;
        if (p->m_rl != nullptr)
        {
            _display(p->m_rl,level);
        }
        for (int i = 0; i <= level; i++)
        {
            cout<<"    ";
        } 
        cout << "__" << p->data()<<endl;
        if (p->m_ll != nullptr)
        {
            _display(p->m_ll, level);
        }
    }


    void deleteTree(Node* node){}

    //////////// privately defined insert, recursively call ///////////////
    void insertNode ( Node * &newNode, const T &t )
    {
	// empty tree
	if (newNode == nullptr)
	{
		newNode = new Node(t);
	}
	else if ( t < newNode->m_num )
	{
		insertNode(newNode->m_ll, t);
	}
	else if ( t > newNode->m_num )
	{
		insertNode(newNode->m_rl, t);
	}	
    }

    // private function ///////////
    void inOrderMovement ( Node* currentNode, vector<T>& vec ) const
    {
	// as long as tree isnt empty /////
	if ( currentNode != nullptr )
	{
		inOrderMovement( currentNode->m_ll, vec );
		vec.push_back( currentNode->m_num );		
		inOrderMovement( currentNode->m_rl, vec );
	}
    }

    void filterInOrder ( Node* currentNode, function<bool (const T)> isIn, vector<T>& vec )
    {
	if ( currentNode != nullptr )
	{
		if (! isIn( currentNode->m_num ))
			vec.push_back( currentNode->m_num );

		filterInOrder( currentNode->m_ll, isIn, vec);
		filterInOrder( currentNode->m_rl, isIn, vec);
	}
    }
    
    // USE TO FIND MIN IN remove /////////////////////
    Node * findMin( Node* node )
    {
	Node* current = node;
	while ( current->m_ll != nullptr )
	{
		current = current->m_ll;
	}
	return ( current );
    }

    // private REMOVE  method //////////////////////
    void remove( const T &x, Node * &t )
    {
	if ( t == nullptr )
		return;   // item not found, do nothing
	if ( x < t->m_num )
		remove( x, t->m_ll );
	else if ( t->m_num < x )
		remove( x, t->m_rl );
	else if ( (t->m_ll != nullptr) && (t->m_rl != nullptr) ) //Two Children
	{
		t->m_num = findMin( t->m_rl )->m_num;
		remove( t->m_num, t->m_rl );
	}
	else
	{
		Node *oldNode = t;
		t = ( t->m_ll != nullptr ) ? t->m_ll : t->m_rl;
		delete oldNode;
	}
    }


    // is BST//////////////////////////////////////
    bool isBST ( Node *root ) const
    {
	static Node *prev = nullptr;
	
	if ( root )
	{
		if (!isBST( root->m_ll ))
			return false;
		if ((prev != nullptr) && (root->m_num <= prev->m_num))
			return false;
		prev = root;

		return isBST( root->m_rl );
	}
	return true;
    }

    // TRAVERSE FOR EACH INTERVAL ///////////////////////////
    void forEachNode ( Node *currentNode, const T &a, const T &b, function<void (const T)> func ) const
    {
        if ( currentNode != nullptr )
	{
		if ( (currentNode->m_num >= a) && (currentNode->m_num <= b) )
		{	
			func( currentNode->m_num );
		}
		forEachNode( currentNode->m_ll, a, b, func );
    		forEachNode( currentNode->m_rl, a, b, func );
	}
    }

};
// OUTSIDE CLASS DEFINITION

	// INSERT          (done)
	template <class T> void BinarySearchTree<T>::insert(const T &t) {
		insertNode(root, t);
	}
	
	// INORDER TRAVERSAL         (done)
 	template <class T> void BinarySearchTree<T>::inOrderTraverse(vector<T>& vec) const 
	{	
		inOrderMovement( root, vec );
	}
 	
	// DELETE           (done)
        template <class T> void BinarySearchTree<T>::deleteNode(const T &t) {
		remove( t, root );
	}

	// FOR EACH INTERVAL       (done)
    	template <class T> void BinarySearchTree<T>::forEachInterval(const T &a, const T&b, function<void (const T)> func) const {
		forEachNode( root, a, b, func );
	}

	// FILTER   (done)
    	template <class T> void BinarySearchTree<T>::filter(function<bool (const T)> isIn) {
		vector<T> vec;
		filterInOrder( root, isIn, vec );
		for ( auto node : vec )
		{
			deleteNode(node);
		}
	}

	// VERIFY BST   (not working... argh)
  	template <class T> bool BinarySearchTree<T>::verifyBinarySearchTree() const {
		isBST( root );
	}



#endif
