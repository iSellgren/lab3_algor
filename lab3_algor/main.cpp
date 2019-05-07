//
//  main.cpp
//  Lab3_algo
//
//  Created by Fredrik Sellgren on 2019-05-02.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <random>
#include "LinearSearch.hpp"
#include "GenePrime.hpp"
#include "BinarySearch.hpp"
#include "BinarySearchTreeBalance.hpp"
#include "BinarySearchTree.hpp"
#include "Hashtable.hpp"
#include "TimeMeasuring.hpp"
/*template <typename Container>
Container Create(std::vector<int> &Primes)
{
    Container cont;
    for(int i = 0; i < Primes.size(); i++)
    {
        cont.insert(Primes[i]);
    }
    return cont;
}
*/
int main() {
    
    std::vector<int> Primes;
    Primes=Generate::Prime(100000);
    
    TimeMeas(BalanceTree<int>(), 10000, 5, "BalanceTree");
    TimeMeas(BinaryTree<int>(), 10000, 5, "BinaryTree");
    TimeMeas(HashTable<int>(), 10000, 5, "HashTable");
    TimerMeas(BinarySearch, 10000, 5, "BinarySearch");
    TimerMeas(LinearSearch, 10000, 5, "LinearSearch");
    
    
    return 0;
}
