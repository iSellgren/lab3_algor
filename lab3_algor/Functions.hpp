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
void cleanUp()
{
    if (remove("BalanceTree.txt") == 0)
        printf("Deleted successfully");
    if (remove("BalanceTreeComp.txt") == 0)
        printf("Deleted successfully");
    if (remove("BalanceTreeCompfindItem.txt") == 0)
        printf("Deleted successfully");
    if (remove("BalanceTreefindItem.txt") == 0)
        printf("Deleted successfully");
    
    
    if (remove("HashTable.txt") == 0)
        printf("Deleted successfully");
    if (remove("HashTableComp.txt") == 0)
        printf("Deleted successfully");
    if (remove("HashTableCompfindItem.txt") == 0)
        printf("Deleted successfully");
    if (remove("HashTablefindItem.txt") == 0)
        printf("Deleted successfully");

    
    if (remove("BinarySearch.txt") == 0)
        printf("Deleted successfully");
    if (remove("BinarySearchComp.txt") == 0)
        printf("Deleted successfully");
    if (remove("BinarySearchCompfindItem.txt") == 0)
        printf("Deleted successfully");
    if (remove("BinarySearchfindItem.txt") == 0)
        printf("Deleted successfully");
    
    
    if (remove("LinearSearch.txt") == 0)
        printf("Deleted successfully");
    if (remove("LinearSearchComp.txt") == 0)
        printf("Deleted successfully");
    if (remove("LinearSearchCompfindItem.txt") == 0)
        printf("Deleted successfully");
    if (remove("LinearSearchfindItem.txt") == 0)
        printf("Deleted successfully");
    
}
#endif /* Functions_hpp */
