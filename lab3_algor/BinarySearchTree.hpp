//
//  BinarySearchTree.hpp
//  Lab3_algo
//
//  Created by Fredrik Sellgren on 2019-05-04.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
//subRoot är noden som är root till subträdet
template <typename T>
class BinaryTree
{
private:
    struct Node
    {
    public:
        
        T data;
        Node* left;
        Node* right;
        
        Node(const T &d, Node *l,Node *r)
        :   data{d},left{l},right{r}{}
    };
    Node* root;
    void chopTree( Node *&t ) const;
    void insert(const T & x, Node * & t) const;
    Node* find(const T & x, Node *subRoot ) const
    {

        while( subRoot != NULL )
            if( x < subRoot->data )
                subRoot = subRoot->left;
            else if( subRoot->data < x )
                subRoot = subRoot->right;
            else
            {
                return subRoot;
            }
        
        
        return NULL;
    }
    const T* elementAt(Node *t ) const;
    
public:
    BinaryTree();
    ~BinaryTree();
    void chopTree();
    void insert(const T & x);
    const T &find(const T & value) const;
    
    
};
template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}
template <class T>
BinaryTree<T>::~BinaryTree()
{
    chopTree();
}

template <class T>
void BinaryTree<T>::chopTree()
{
    chopTree( root );
}
template <class T>
void BinaryTree<T>::insert(const T & value)
{
    insert(value,root);
}

template <class T>
const T & BinaryTree<T>::find( const T & value ) const
{
    return *elementAt(find(value, root));
}




template <class T>
void BinaryTree<T>::chopTree( Node *&subRoot ) const
{
    if( subRoot != NULL )
    {
        chopTree(subRoot->left);
        chopTree(subRoot->right);
        delete subRoot;
    }
    subRoot = NULL;
    
}

template <class T>
void BinaryTree<T>::insert(const T & x, Node* & subRoot ) const
{
    if( subRoot == NULL )
    {
        subRoot = new Node( x, NULL, NULL );
    }
    else if( x < subRoot->data )
    {
        insert(x, subRoot->left);
    }
    else if( x > subRoot->data )
    {
        insert(x, subRoot->right);
    }
    else;
    
}
template <class T>
const T* BinaryTree<T>::elementAt(Node *subRoot ) const
{
    if( subRoot == NULL )
        return NULL;
    else
        return &subRoot->data;
}
#endif /* BinarySearchTree_hpp */
