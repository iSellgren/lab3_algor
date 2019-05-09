//
//  Algorithms.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-27.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef Functions_hpp
#define Functions_hpp
#include <stdio.h>
static std::random_device rd;
static std::mt19937 mt (rd());
int BinarySearch(std::vector<int> &data, int find)
{
    return Search_Algorithms::binarysearch(data.begin(), data.end(), find);
}
int LinearSearch(std::vector<int> &data, int find)
{
    return Search_Algorithms::linearsearch(data.begin(), data.end(), find);
}
void BinarySearchSTD(std::vector<int> &data, int find)
{
    std::binary_search(data.begin(), data.end(), find);
    
}

#endif /* Functions_hpp */
