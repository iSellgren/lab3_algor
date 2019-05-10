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

namespace Search_Algorithms{
    template <typename Iter>
    int binarysearch(Iter left, Iter right,int target)
    {
        int *leftPtr = &*(left);
        int *rightPtr = &*(right-1);
        int Comp = 0;
        while(left < right)
        {
            int* mid = leftPtr +((rightPtr-leftPtr)/2);
            
            
            if(*mid == target)
            {
                //return static_cast<double>(std::distance(&*left, mid));
                return Comp;
            }
            
            else if(*mid < target)
            {
                Comp++;
                leftPtr = &*(++mid);
            }
            
            else
            {
                Comp++;
                rightPtr = &*(--mid);
            }
        }
        std::cout << "Fucked up" << std::endl;
        return -1;
    }
}
#endif /* BinarySearch_hpp */
