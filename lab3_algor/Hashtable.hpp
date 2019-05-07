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
class HT
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
    HT();
    void insert(T &value);
    size_t newTableSize();
    void reHash();
    
};
template<class T>
HT<T>::HT()
{
    
    //hashTable.resize(reserve_size);
    hashTable = std::vector<Node*>(2);
    for (int i = 0; i < hashTable.size(); i++)
        hashTable[i] = NULL;
    
    
}
template<class T>
void HT<T>::insert(T &value)
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
size_t HT<T>::newTableSize()
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
void HT<T>::reHash()
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
            std::cout << iter->data << std::endl;
            insert(iter->data);
            while (iter->next != NULL)
            {
                
                insert(iter->next->data);
                break;
            }

        }
    }
    
}
#endif /* Hashtable_hpp */
