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
#include <random>
#include "LinearSearch.hpp"
#include "GenePrime.hpp"
#include "BinarySearch.hpp"
#include "BinarySearchTreeBalance.hpp"
#include "BinarySearchTree.hpp"


int main() {
    
    std::vector<int> Test;
    Test=Generate::Prime(10000);
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> range(0, Test.size() - 1);
    BSTB<int> K;
    BST<int> I;
    for(int i = 0; i < Test.size(); i++)
    {
        K.insert(Test[i]);
        I.insert(Test[i]);
    }
    
    //int Line = Sorting_Algorithms::linearsearch(Test.begin(), Test.end(), 468709);
    for(int i=0; i < 100; i++)
    {
        int randPrime = Test[range(eng)];
        int Tine = Sorting_Algorithms::binarysearch(Test.begin(), Test.end(), randPrime);


        
        //std::cout << Line << std::endl;
        //std::cout << Tine << std::endl;
        std::cout << K.find(randPrime) << std::endl;
        std::cout << I.find(randPrime) << std::endl;
    }
    
    
    return 0;
}
