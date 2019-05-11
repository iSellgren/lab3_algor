//
//  LinearSearch.hpp
//  Lab3_algo
//
//  Created by Fredrik Sellgren on 2019-05-03.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef LinearSearch_hpp
#define LinearSearch_hpp

#include <stdio.h>
#include <algorithm>
#include <iterator>
namespace Search_Algorithms{
    template <typename Iter>
int linearsearch(Iter left, Iter right,int target)
    {
        int *leftPtr = &*(left);
        int *rightPtr = &*(right-1);
        for(int* i = leftPtr; i <= rightPtr; i++)
        {
            if(*i == target)
            {
                //return static_cast<double>(std::distance(&*left, i));
                return *i;
            }
        }
        
        std::cout << "Fucked up" << std::endl;
        return -1;
    }
}
#endif /* LinearSearch_hpp */
