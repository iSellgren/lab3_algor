//
//  GenePrime.hpp
//  Lab3_algo
//
//  Created by Fredrik Sellgren on 2019-05-04.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef GenePrime_hpp
#define GenePrime_hpp

#include <stdio.h>
namespace Generate
{
    std::vector<int> Prime(unsigned long size)
    {
        std::vector<int> temp;
        std::vector<bool> table(100*size,true);
        
        temp.reserve(size);
        
        for(unsigned long i = 2; i < sqrt(100*size); i++)
        {
            if(table[i])
            {
                for(unsigned long j = i*i; j < 100*size; j += i)
                {
                    table[j] = false;
                }
            }
        }
        
        unsigned long lastprime = 0;
        for(unsigned long i = 2; temp.size() < size;)
        {
            if(table[i])
            {
                lastprime = i;
                temp.push_back(static_cast<int>(lastprime));
            }
            
            if(table.begin() + i + 1 != table.end())
                ++i;
            else temp.push_back(static_cast<int>(lastprime));
        }
        return temp;
    }
}


#endif /* GenePrime_hpp */
