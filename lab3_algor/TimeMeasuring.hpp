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
struct calTime {
    double mean;
    double Stdev;
    int Sample;
    int Size;
    
};
template <typename Iter>
calTime StdDiv(Iter left, Iter right,int size)
{
    int N = 0;
    double accum = 0.0;
    double stdev = 0.0;
    double mean = 0.0;
    double variance = 0.0;
    N = static_cast<int>(std::distance(left, right));
    mean = std::accumulate(left, right, 0.0) / N;
    
    std::for_each (left, right, [&](const double d) {
        
        accum += pow(d-mean,2);
        
    });
    variance = (accum / (N));
    stdev = sqrt(variance);
    
    calTime test ={mean,stdev,N,static_cast<int>(size)};
    return test;
    

}

template <typename F1>
void TimeMeas(F1 algo, int size, int times, std::string name)
    {
        int Tid = (times+1);
        std::vector<calTime> Timers;
        std::vector<calTime> comparisons;
        std::vector<float> values;
        std::vector<int> comps;
        for(int j = 1; j < 11; j++)
        {
            int N = multiply(size, j);
            
            
            std::vector<int> container;
            container=Generate::Prime(N);
            auto Algor = Create<F1>(container);
            std::cout << N << std::endl;
            for(int i = 1; i < Tid; i++)
            {

                int Comp = 0;
                std::random_device rd;
                std::mt19937 eng(rd());
                std::uniform_int_distribution<> range(0, static_cast<int>(container.size() - 1));
                int randPrime = container[range(eng)];
                auto start = std::chrono::steady_clock::now();
                Algor.find(randPrime);
                Comp = Algor.Comps();
                
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<float,std::micro> duration = end - start;
                
                comps.push_back(Comp);
                values.push_back(duration.count());

            }
            comparisons.push_back(StdDiv(comps.begin(),comps.end(),N));
            Timers.push_back(StdDiv(values.begin(), values.end(),N));
            values.clear();
            comps.clear();
            
        }
        std::ofstream myfile;
        myfile.open (name+".txt", std::ios::app);
        myfile << " #X " << ' ' << " Y " << "\r\n";
        for(int k = 0; k < Timers.size(); k++)
        {
         
            myfile << Timers[k].Size << " " << Timers[k].mean << " " << Timers[k].Stdev << " " << Timers[k].Sample << "\r\n";
         
            
        }
        myfile.close();
        
        std::ofstream compfile;
        compfile.open (name+"Comp"+".txt", std::ios::app);
        myfile << " #X " << ' ' << " Y " << "\r\n";
        for(int k = 0; k < comparisons.size(); k++)
        {
            
            compfile << comparisons[k].Size << " " << comparisons[k].mean << " " << comparisons[k].Stdev << " " << comparisons[k].Sample << "\r\n";
            
        }
        compfile.close();
    }
template <typename F1>
void TimerMeas(F1 algo, int size, int times, std::string name)
{
    int Tid = (times+1);
    std::vector<calTime> Timers;
    std::vector<calTime> comparisons;
    std::vector<float> values;
    std::vector<int> comps;
    
    for(int j = 1; j < 11; j++)
    {
        int N = multiply(size, j);
        std::vector<int> container;
        container=Generate::Prime(N);
        if(algo == LinearSearch)
        {
            std::cout << N << " LinearSearch" << std::endl;
        }
        else if(algo == BinarySearch)
        {
            std::cout << N << " BinarySearch" << std::endl;
        }
        
        for(int i = 1; i < Tid; i++)
        {
            int Comp = 0;
            std::random_device rd;
            std::mt19937 eng(rd());
            std::uniform_int_distribution<> range(0, static_cast<int>(container.size() - 1));
            int randPrime = container[range(eng)];
            auto start = std::chrono::steady_clock::now();
            Comp = algo(container,randPrime);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<float,std::micro> duration = end - start;
            
            comps.push_back(Comp);
            values.push_back(duration.count());
            
        }
        
        comparisons.push_back(StdDiv(comps.begin(),comps.end(),N));
        Timers.push_back(StdDiv(values.begin(), values.end(),N));
        
        values.clear();
        comps.clear();
        
    }
    std::ofstream myfile;
    myfile.open (name+".txt", std::ios::app);
    myfile << " #X " << ' ' << " Y " << "\r\n";
    for(int k = 0; k < Timers.size(); k++)
    {
        
        myfile << Timers[k].Size << " " << Timers[k].mean << " " << Timers[k].Stdev << " " << Timers[k].Sample << "\r\n";
        
    }
    myfile.close();
    
    std::ofstream compfile;
    compfile.open (name+"Comp"+".txt", std::ios::app);
    myfile << " #X " << ' ' << " Y " << "\r\n";
    for(int k = 0; k < comparisons.size(); k++)
    {
        
        compfile << comparisons[k].Size << " " << comparisons[k].mean << " " << comparisons[k].Stdev << " " << comparisons[k].Sample << "\r\n";
        
    }
    compfile.close();
}


#endif /* TimeMeasuring_hpp */
