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
#include "LinearSearch.hpp"
#include "GenePrime.hpp"
#include "BinarySearch.hpp"
#include "BinarySearchTreeBalance.hpp"
#include "BinarySearchTree.hpp"
#include "Hashtable.hpp"
#include "TimeMeasuring.hpp"

int main() {
//    std::vector<int>Primes;
//    Primes=Generate::Prime(INT_MAX);
//    std::cout << Primes.back() << std::endl;
    
    
    TimeMeas(BalanceTree<int>(), 100000, 100000, "BalanceTree");
//    TimeMeas(BinaryTree<int>(), 10000, 100000, "BinaryTree");
    TimeMeas(HashTable<int>(), 100000, 100000, "HashTable");
    TimerMeas(BinarySearch, 100000, 100000, "BinarySearch");
    TimerMeas(LinearSearch, 100000, 100000, "LinearSearch");
    
    
    return 0;
}
