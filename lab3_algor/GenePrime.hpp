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
namespace Generate{
    std::vector<int> Prime(int size)
    {
        std::vector<int> temp;
        std::vector<bool> table(1000*size,true);
        
        temp.reserve(size);
        
        for(int i = 2; i < sqrt(1000*size); i++)
        {
            if(table[i])
            {
                for(int j = i*i; j < 1000*size; j += i)
                {
                    table[j] = false;
                }
            }
        }
        
        int lastprime = 0;
        for(int i = 2; temp.size() < size;)
        {
            if(table[i])
            {
                lastprime = i;
                temp.push_back(lastprime);
            }
            
            if(table.begin() + i + 1 != table.end())
                ++i;
            else temp.push_back(lastprime);
        }
        
        return temp;
    }
}
#endif /* GenePrime_hpp */
