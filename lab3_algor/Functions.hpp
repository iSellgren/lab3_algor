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
void BinarySearch(std::vector<int> &data, int find)
{
    Search_Algorithms::binarysearch(data.begin(), data.end(), find);
}
void LinearSearch(std::vector<int> &data, int find)
{
//    std::shuffle(begin(data), end(data), mt);
    Search_Algorithms::linearsearch(data.begin(), data.end(), find);
}

#endif /* Functions_hpp */
