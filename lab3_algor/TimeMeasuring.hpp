//
//  TimeMeasuring.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-27.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef TimeMeasuring_hpp
#define TimeMeasuring_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include "Functions.hpp"
template <typename Container>
Container Create(std::vector<int> &Primes)
{
    Container cont;
    for(int i = 0; i < Primes.size(); i++)
    {
        cont.insert(Primes[i]);
    }
    return cont;
}
int multiply(int value,int mul) {
    
    int ret=0;
    
    int mulabs = mul;
    if(mulabs < 0) mulabs = 0 -mulabs;
    
    for(int n=0;n<mulabs;n++) {
        ret += value;
    }
    
    if(mul < 0) ret = 0-ret;
    
    return ret+ret;
}
struct subject {
    float mean;
    float Stdev;
    float Sample;
    float Size;
    
};
template <typename Iter>
subject StdDiv(Iter left, Iter right,int size)
{
    float N = std::distance(left, right);
    float  mean = std::accumulate(left, right, float{}) / N;
    
    float accum = 0.0;
    std::for_each (left, right, [&](const double d) {
        accum += (d - mean) * (d - mean);
    });
    float variance = accum / N;
    float stdev = sqrt(variance);
    
    subject test ={mean,stdev,N,static_cast<float>(size)};
    return test;
    

}

template <typename F1>
void TimeMeas(F1 algo, int size, int times, std::string name)
    {
        int Tid = (times+1);
       std::vector<subject> bar;
        std::vector<float> values;
        for(int j = 1; j < 11; j++)
        {
            int N = multiply(size, j);
            
            
            std::vector<int> container;
            container=Generate::Prime(N);
//            std::shuffle(begin(container), end(container), mt);
            auto Algor = Create<F1>(container);
            for(int i = 1; i < Tid; i++)
            {

                std::random_device rd;
                std::mt19937 eng(rd());
                std::uniform_int_distribution<> range(0, static_cast<int>(container.size() - 1));
                int randPrime = container[range(eng)];
                
                auto start = std::chrono::steady_clock::now();
                Algor.find(randPrime);
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<float,std::micro> duration = end - start;
                
                
                values.push_back(duration.count());

            }
            bar.push_back(StdDiv(values.begin(), values.end(),N));
            values.clear();
            
        }
        std::ofstream myfile;
        myfile.open (name+".txt", std::ios::app);
        myfile << " #X " << ' ' << " Y " << "\r\n";
        for(int k = 0; k < bar.size(); k++)
        {
         
            myfile << bar[k].Size << " " << bar[k].mean << " " << bar[k].Stdev << " " << bar[k].Sample << "\r\n";
         
            
        }
        myfile.close();
    }
template <typename F1>
void TimerMeas(F1 algo, int size, int times, std::string name)
{
    int Tid = (times+1);
    std::vector<subject> bar;
    std::vector<float> values;
    for(int j = 1; j < 11; j++)
    {
        int N = multiply(size, j);
        std::vector<int> container;
        container=Generate::Prime(N);
        for(int i = 1; i < Tid; i++)
        {
            

            
            std::random_device rd;
            std::mt19937 eng(rd());
            std::uniform_int_distribution<> range(0, static_cast<int>(container.size() - 1));
            int randPrime = container[range(eng)];
            auto start = std::chrono::steady_clock::now();
            algo(container,randPrime);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<float,std::micro> duration = end - start;
            
            
            values.push_back(duration.count());
            
        }
        bar.push_back(StdDiv(values.begin(), values.end(),N));
        values.clear();
        
    }
    std::ofstream myfile;
    myfile.open (name+".txt", std::ios::app);
    myfile << " #X " << ' ' << " Y " << "\r\n";
    for(int k = 0; k < bar.size(); k++)
    {
        
        myfile << bar[k].Size << " " << bar[k].mean << " " << bar[k].Stdev << " " << bar[k].Sample << "\r\n";
        
    }
    myfile.close();
}


#endif /* TimeMeasuring_hpp */
