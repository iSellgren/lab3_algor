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
#include "FindMeasuring.hpp"



void task1()
{
    TimeMeas(BalanceTree<int>(), 100000, 10000, "BalanceTree");
    
    FindMeasHTBT(BalanceTree<int>(), 1000000, "BalanceTree");
}
void task2()
{
    TimeMeas(HashTable<int>(), 100000, 10000, "HashTable");
    FindMeasHTBT(HashTable<int>(), 1000000, "HashTable");
}
void task3()
{
    TimerMeas(BinarySearch, 100000, 10000, "BinarySearch");
    FindMeasLSBS(BinarySearch, 1000000, "BinarySearch");
}
void task4()
{
    TimerMeas(LinearSearch, 100000, 10000, "LinearSearch");
    FindMeasLSBS(LinearSearch, 1000000, "LinearSearch");
}
int main() {
    
    cleanUp();
    
    
    task1();
    task2();
    task3();
    task4();

    
    

    
    /*
    std::thread t1(task1);
    std::thread t2(task2);
    std::thread t3(task3);
    std::thread t4(task4);
    
    t4.join();
    t3.join();
    t2.join();
    t1.join();
    */
    system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot  HashTable.p");
    system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot  LinearSearch.p");
    system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot  BinarySearch.p");
    system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot  BalanceTree.p &");
    system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot  -p CompareItems.p ");
    
    
    return 0;
}
