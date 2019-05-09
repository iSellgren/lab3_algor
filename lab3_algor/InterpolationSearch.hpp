//
//  InterpolationSearch.hpp
//  lab3_algor
//
//  Created by Fredrik Sellgren on 2019-05-09.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef InterpolationSearch_hpp
#define InterpolationSearch_hpp

#include <stdio.h>
#include <iterator>
namespace Search_Algorithms{
    template <typename Iter>
    int interpolationsearch(Iter left, Iter right,int target)
    {
        int *leftPtr = &*(left);
        int *rightPtr = &*(right-1);
        while(left < right)
        {
            int* mid = leftPtr +((rightPtr-leftPtr)/2);
            
            if(*mid == target)
            {
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
#endif /* InterpolationSearch_hpp */
