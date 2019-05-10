//
//  Hashtable.hpp
//  lab3_algor
//
//  Created by Fredrik Sellgren on 2019-05-06.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef Hashtable_hpp
#define Hashtable_hpp

#include <stdio.h>
#include <vector>
template <typename T>
class HashTable
{
private:
    struct Node
    {
    public:
        
        T data;
        Node* next;
       
        
        Node(T _n ) : data(_n), next(NULL) { }
        
    };
    std::vector<Node *> hashTable;
    int items = 0;
    double loadfactor = 0.5;
    double load;
    int comparisons = 0;
    
public:
    HashTable();
    void insert(T &value);
    size_t newTableSize();
    void reHash();
    bool find(const T &value);
    int Comps();
    
    
    
};
template<class T>
HashTable<T>::HashTable()
{

    hashTable = std::vector<Node*>(2);
    for (int i = 0; i < hashTable.size(); i++)
        hashTable[i] = NULL;
    
    
}
template<class T>
int HashTable<T>::Comps()
{
    int temp = this->comparisons;
    comparisons = 0;
    return temp;
}
template<class T>
void HashTable<T>::insert(T &value)
{
    

    int pos = (value % hashTable.size());
    Node * iter = hashTable[pos];
    if(iter != NULL)
    {
        while (iter->next != NULL)
            iter = iter->next;
        iter->next = new Node(value);
        ++items;
        
    }
    else
    {
        hashTable[pos] = new Node(value);
        ++items;

    }
    load = (static_cast<double>(items)/static_cast<double>(hashTable.size()));
    if(load >= loadfactor)
    {
        reHash();
    }

}

bool isPrime(int n)
{
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
            return false;
    }
    
    return true;
}
template<class T>
size_t HashTable<T>::newTableSize()
{
    
    bool found = false;
    
    int newSize = 2*static_cast<int>(hashTable.size()); //trying to get next prime.
    
    while(!found) {
        
        newSize++;
        if(isPrime(newSize))
            found = true;
    }
    
    return newSize;
}
template<class T>
void HashTable<T>::reHash()
{
    items = 0;
    std::vector<Node*> temp;
    temp = std::move(hashTable);
    
    hashTable.clear();
    hashTable.resize(temp.size());
    
    hashTable.resize(newTableSize());
    
    for(int i = 0; i < temp.size();i++)
    {
        auto ptr = temp[i];
        
        while(ptr)
        {
            
            insert(ptr->data);
            ptr = ptr->next;
        }
        
    }
}
template<class T>
bool HashTable<T>::find(const T &value)
{
    int pos = (value % hashTable.size());
    Node * iter = hashTable[pos];
    while(iter)
    {
        ++comparisons;
        if(iter->data == value)
        {

            return 1;
        }
        iter = iter->next;
    }
    std::cout << "Fucked up" << std::endl;

    return -1;
}
#endif /* Hashtable_hpp */
