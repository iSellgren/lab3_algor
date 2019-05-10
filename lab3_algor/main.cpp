//
//  main.cpp
//  Lab3_algo
//
//  Created by Fredrik Sellgren on 2019-05-02.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
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
#include <thread>
#include <utility>

void task1()
{
    TimeMeas(BalanceTree<int>(), 10000, 100000, "BalanceTree");
}
void task2()
{
    TimeMeas(HashTable<int>(), 10000, 100000, "HashTable");
}
void task3()
{
    TimerMeas(BinarySearch, 10000, 100000, "BinarySearch");
}
void task4()
{
    TimerMeas(LinearSearch, 10000, 100000, "LinearSearch");
}
int main() {
    
    cleanUp();
    
    
    std::thread t1(task1);
    std::thread t2(task2);
    std::thread t3(task3);
    std::thread t4(task4);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot  HashTable.p");
    system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot  LinearSearch.p");
    system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot  BinarySearch.p");
//    system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot -persist BalanceTree.p");
    return 0;
}
