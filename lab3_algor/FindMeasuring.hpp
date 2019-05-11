//
//  FindMeasuring.hpp
//  lab3_algor
//
//  Created by Fredrik Sellgren on 2019-05-10.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef FindMeasuring_hpp
#define FindMeasuring_hpp


#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include "Functions.hpp"
#include <thread>
#include <utility>
#include <functional>

/*
template <typename F1>
void runningThread(F1 &Algor,std::vector<int>&comps, std::vector<int> &foundItems, std::vector<int> &container)
{
    
    
}
 */
template <typename F1>
void FindMeasHTBT(F1 algo, int size, std::string name)
{
    std::vector<calTime> foundValues;
    std::vector<calTime> comparisons;
    std::vector<std::uintmax_t> comps;
    std::vector<std::uintmax_t> foundItems;
    std::vector<int> container;
    container=Generate::Prime(size);
    auto Algor = Create<F1>(container);
    std::uintmax_t Comp = 0, FI = 0;
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> range(0, static_cast<int>(container.size() - 1));
    bool running = true;
    
    auto func = [&]()
    {
        while(running)
        {
            
            Algor.find(container[range(eng)]);
            Comp += Algor.Comps();
            FI++;
        }
        
        comps.push_back(Comp);
        foundItems.push_back(FI);
    };
    
    std::thread t1(func);
    
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
    running = false;
    t1.join();
    
    comparisons.push_back(StdDiv(comps.begin(),comps.end(),size));
    foundValues.push_back(StdDiv(foundItems.begin(), foundItems.end(),size));
    
    foundItems.clear();
    comps.clear();
    
    std::ofstream myfile;
    myfile.open (name+"findItem"+".txt", std::ios::app);
    myfile << " #X " << ' ' << " Y " << "\r\n";
    for(int k = 0; k < foundValues.size(); k++)
    {
        
        myfile << foundValues[k].Size << " " << foundValues[k].mean << " " << foundValues[k].Stdev << " " << foundValues[k].Sample << "\r\n";
        
        
    }
    myfile.close();
    
    std::ofstream compfile;
    compfile.open (name+"CompfindItem"+".txt", std::ios::app);
    compfile << " #X " << ' ' << " Y " << "\r\n";
    for(int k = 0; k < comparisons.size(); k++)
    {
        
        compfile << comparisons[k].Size << " " << comparisons[k].mean << " " << comparisons[k].Stdev << " " << comparisons[k].Sample << "\r\n";
        
    }
    compfile.close();
    
}

template <typename F1>
void FindMeasLSBS(F1 algo, int size, std::string name)
{
    std::vector<calTime> foundValues;
    std::vector<calTime> comparisons;
    std::vector<std::uintmax_t> comps;
    std::vector<std::uintmax_t> foundItems;
    std::vector<int> container;
    container=Generate::Prime(size);
    
    std::uintmax_t Comp = 0, FI = 0;
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> range(0, static_cast<int>(container.size() - 1));
    bool running = true;
    
    auto func = [&]()
    {
        while(running)
        {
            Comp += algo(container,container[range(eng)]);
            FI++;
        }
        
        comps.push_back(Comp);
        foundItems.push_back(FI);
    };
    
    std::thread t1(func);
    
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
    running = false;
    t1.join();
    
    comparisons.push_back(StdDiv(comps.begin(),comps.end(),size));
    foundValues.push_back(StdDiv(foundItems.begin(), foundItems.end(),size));
    
    foundItems.clear();
    comps.clear();
    
    std::ofstream myfile;
    myfile.open (name+"findItem"+".txt", std::ios::app);
    myfile << " #X " << ' ' << " Y " << "\r\n";
    for(int k = 0; k < foundValues.size(); k++)
    {
        
        myfile << foundValues[k].Size << " " << foundValues[k].mean << " " << foundValues[k].Stdev << " " << foundValues[k].Sample << "\r\n";
        
        
    }
    myfile.close();
    
    std::ofstream compfile;
    compfile.open (name+"CompfindItem"+".txt", std::ios::app);
    compfile << " #X " << ' ' << " Y " << "\r\n";
    for(int k = 0; k < comparisons.size(); k++)
    {
        
        compfile << comparisons[k].Size << " " << comparisons[k].mean << " " << comparisons[k].Stdev << " " << comparisons[k].Sample << "\r\n";
        
    }
    compfile.close();
    
}
#endif /* FindMeasuring_hpp */
