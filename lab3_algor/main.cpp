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
#include "InterpolationSearch.hpp"
#include "TimeMeasuring.hpp"
#include <thread>
#include <utility>

void cleanUp()
{
    if (remove("BalanceTree.txt") == 0)
        printf("Deleted successfully");
    if (remove("BinarySearchComp.txt") == 0)
        printf("Deleted successfully");
    if (remove("LinearSearchComp.txt") == 0)
        printf("Deleted successfully");
    if (remove("HashTable.txt") == 0)
        printf("Deleted successfully");
    if (remove("BinarySearch.txt") == 0)
        printf("Deleted successfully");
    if (remove("LinearSearch.txt") == 0)
        printf("Deleted successfully");
    
}

void task1()
{
    TimeMeas(BalanceTree<int>(), 1000, 10000, "BalanceTree");
}
void task2()
{
    TimeMeas(HashTable<int>(), 1000, 10000, "HashTable");
}
void task3()
{
    TimerMeas(BinarySearch, 1000, 10000, "BinarySearch");
}
void task4()
{
    TimerMeas(LinearSearch, 1000, 10000, "LinearSearch");
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
    
    //system("/usr/local/Cellar/gnuplot/5.2.6_1/bin/gnuplot -persist gnuplot.p");
    return 0;
}
