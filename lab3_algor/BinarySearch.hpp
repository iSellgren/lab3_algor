//
//  BinarySearch.hpp
//  Lab3_algo
//
//  Created by Fredrik Sellgren on 2019-05-03.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef BinarySearch_hpp
#define BinarySearch_hpp

#include <stdio.h>
#include <algorithm>
#include <iterator>
#endif /* BinarySearch_hpp */
namespace Search_Algorithms{
    template <typename Iter>
    int binarysearch(Iter left, Iter right,int target)
    {
        int *leftPtr = &*(left);
        int *rightPtr = &*(right-1);
        auto start = std::chrono::steady_clock::now();
        while(left < right)
        {
            int* mid = leftPtr +((rightPtr-leftPtr)/2);
            
            if(*mid == target)
            {
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<float,std::milli> duration = end - start;
                std::cout << duration.count() << " BS" << std::endl;
                return static_cast<double>(std::distance(&*left, mid));
            }
            
            if(*mid < target)
            {
                leftPtr = &*(++mid);
            }
            
            
            else
            {
                rightPtr = &*(--mid);
            }
        }
        return 0;
    }
}
