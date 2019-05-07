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
        
        Node* next;
        int data;
        
        Node( int _n ) : data(_n), next(NULL) { }
        
    };
    std::vector<Node *> hashTable;
    int items = 0;
    double loadfactor;
    
    
    
    
public:
    HashTable();
    void insert(T &value);
    size_t newTableSize();
    void reHash();
    bool find(const T &value);
    
};
template<class T>
HashTable<T>::HashTable()
{

    hashTable = std::vector<Node*>(2);
    for (int i = 0; i < hashTable.size(); i++)
        hashTable[i] = NULL;
    
    
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
    }
    else
    {
        hashTable[pos] = new Node(value);
        ++items;
        loadfactor = (static_cast<double>(items)/static_cast<double>(hashTable.size()));
        if(loadfactor >= 0.5)
        {
            reHash();
            items = 0;
        }
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
    
    int newSize = static_cast<int>(hashTable.size()); //trying to get next prime.
    
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
    std::vector<Node*> temp;
    temp = hashTable;
    
    hashTable.clear();
    hashTable.resize(temp.size());
    
    hashTable.resize(newTableSize());
    
    for(int i = 0; i < temp.size();i++)
    {
        if(temp[i] != NULL)
        {
            Node * iter = temp[i];
            insert(iter->data);
            while (iter->next != NULL)
            {
                
                insert(iter->next->data);
                break;
            }

        }
    }
    
}
template<class T>
bool HashTable<T>::find(const T &value)
{
    int pos = (value % hashTable.size());
    auto start = std::chrono::steady_clock::now();
    Node * iter = hashTable[pos];
    while(iter != NULL)
    {
        if(iter->data == value)
        {
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<float,std::milli> duration = end - start;
            std::cout << duration.count() << " HashTable " <<  std::endl;
            return 1;
        }
        iter = iter->next;
    }
    return 0;
}
#endif /* Hashtable_hpp */
