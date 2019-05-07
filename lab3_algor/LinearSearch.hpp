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
namespace Sorting_Algorithms{
    template <typename Iter>
int linearsearch(Iter left, Iter right,int target)
    {
        --right;
        auto start = std::chrono::steady_clock::now();
        for(int* i = &*left; i < &*right; i++)
        {
            if(*i == target)
            {
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<float,std::milli> duration = end - start;
                std::cout << duration.count() << " LS " << std::endl;
                return std::distance(&*left, i);
            }
        }
        return 0;
    }
}
#endif /* LinearSearch_hpp */
