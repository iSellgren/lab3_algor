//
//  BinarySearchTreeBalance.hpp
//  Lab3_algo
//
//  Created by Fredrik Sellgren on 2019-05-03.
//  Copyright © 2019 Fredrik Sellgren. All right reserved.
//

#ifndef BinarySearchTreeBalance_hpp
#define BinarySearchTreeBalance_hpp

#include <stdio.h>
#include <iostream>
//subRoot är noden som är root till subträdet
template <typename T>
class BalanceTree
{
private:
    struct Node
    {
        public:
        
        T data;
        Node *leftLeaf;
        Node *rightLeaf;
        int height;
        
        Node(const T &d, Node *l,Node *r,int h = 0)
        :   data{d},leftLeaf{l},rightLeaf{r},height{h}{}
        
        Node(const T &&d, Node *l,Node *r,int h = 0)
        :   data{std::move(d)},leftLeaf{l},rightLeaf{r},height{h}{}
        
    };
    Node *root;
    int height(Node* subRoot) const;
    void chopTree( Node *&subRoot ) const;
    void insert(const T & x, Node *&subRoot) const;
    void rotateWithleftLeafChild(Node *& tempRoot2) const;
    void rotateWithrightLeafChild( Node* & tempRoot1 ) const;
    void doubleWithleftLeafChild( Node *&tempRoot3 ) const;
    void doubleWithrightLeafChild( Node *&tempRoot1 ) const;
    
    Node* find(const T & x, Node *subRoot ) const
    {
        while( subRoot != NULL )
            if( x < subRoot->data )
                subRoot = subRoot->leftLeaf;
            else if( subRoot->data < x )
                subRoot = subRoot->rightLeaf;
            else
            {
                return subRoot;
            }
        
        
        return NULL;
    }
    int max(int left,int right)const;
    const T* elementAt(Node *t ) const;

    
public:
    BalanceTree();
    ~BalanceTree();
    void chopTree();
    void insert(const T & x);
    const T &find(const T & value) const;

};
template <class T>
BalanceTree<T>::BalanceTree()
{
    root = NULL;
}
template <class T>
BalanceTree<T>::~BalanceTree()
{
    chopTree();
}


template <class T>
void BalanceTree<T>::chopTree()
{
    chopTree(root);
}

template<class T>
int BalanceTree<T>::height(Node* subRoot) const
{
    return subRoot == NULL ? -1 : subRoot->height;
}
template <class T>
int BalanceTree<T>::max( int left, int right ) const
{
    return left > right ? left : right;
}
template <class T>
    void BalanceTree<T>::insert(const T & value)
{
    insert(value,root);
}
template <class T>
const T & BalanceTree<T>::find( const T & value ) const
{
    return *elementAt(find(value, root));
}


template <class T>
void BalanceTree<T>::chopTree( Node *&subRoot ) const
{
    if( subRoot != NULL )
    {
        chopTree( subRoot->leftLeaf );
        chopTree( subRoot->rightLeaf );
        delete subRoot;
    }
    subRoot = NULL;
    
}

template <class T>
    void BalanceTree<T>::insert(const T & x, Node* & subRoot ) const
{
    if( subRoot == NULL )
        subRoot = new Node( x, NULL, NULL );
    else if( x < subRoot->data )
    {
        insert( x, subRoot->leftLeaf );
        if( height( subRoot->leftLeaf ) - height( subRoot->rightLeaf ) == 2 )
        {
            if( x < subRoot->leftLeaf->data )
                rotateWithleftLeafChild(subRoot);
            else
                doubleWithleftLeafChild(subRoot);
        }
    }
    else if( subRoot->data < x )
    {
        insert( x, subRoot->rightLeaf );
        if( height( subRoot->rightLeaf ) - height( subRoot->leftLeaf ) == 2 )
        {
            if( subRoot->rightLeaf->data < x )
                rotateWithrightLeafChild(subRoot);
            else
                doubleWithrightLeafChild(subRoot);
        }
    }
    else
        ;
    subRoot->height = max( height( subRoot->leftLeaf ), height( subRoot->rightLeaf ) ) + 1;
        
}


template <class T>
const T* BalanceTree<T>::elementAt(Node *subRoot ) const
{
    if( subRoot == NULL )
        return NULL;
    else
        return &subRoot->data;
}
template <typename T>
void BalanceTree<T>::rotateWithleftLeafChild(Node *& tempRoot2) const
{
    Node *tempRoot1 = tempRoot2->leftLeaf;
    tempRoot2->leftLeaf = tempRoot1->rightLeaf;
    tempRoot1->rightLeaf = tempRoot2;
    tempRoot2->height = max( height( tempRoot2->leftLeaf ), height( tempRoot2->rightLeaf ) ) + 1;
    tempRoot1->height = max( height( tempRoot1->leftLeaf ), tempRoot2->height ) + 1;
    tempRoot2 = tempRoot1;
}
template <typename T>
void BalanceTree<T>::rotateWithrightLeafChild( Node *&tempRoot1 ) const
{
    Node *tempRoot2 = tempRoot1->rightLeaf;
    tempRoot1->rightLeaf = tempRoot2->leftLeaf;
    tempRoot2->leftLeaf = tempRoot1;
    tempRoot1->height = max( height( tempRoot1->leftLeaf ), height( tempRoot1->rightLeaf ) ) + 1;
    tempRoot2->height = max( height( tempRoot2->rightLeaf ), tempRoot1->height ) + 1;
    tempRoot1 = tempRoot2;
}
template <typename T>
void BalanceTree<T>::doubleWithleftLeafChild( Node *&tempRoot3 ) const
{
    rotateWithrightLeafChild( tempRoot3->leftLeaf );
    rotateWithleftLeafChild( tempRoot3 );
}
template <typename T>
void BalanceTree<T>::doubleWithrightLeafChild( Node *&tempRoot1 ) const
{
    rotateWithleftLeafChild( tempRoot1->rightLeaf );
    rotateWithrightLeafChild( tempRoot1 );
}
#endif /* BinarySearchTreeBalance_hpp */
