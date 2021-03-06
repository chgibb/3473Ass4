/*
    The program will take in a list of integers off of the command line and report the number of page faults found
    using LRU and FIFO page replacement algorithms.
*/
#include <iostream>
#include <vector>

#include "lru.hpp"
#include "fifo.hpp"

/**
 * @brief 
 * 
 * Main entry
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc,char*argv[])
{
    //read list of ints
    std::vector<int> referenceString;
    for(int i = 1; i != argc; ++i)
    {
        referenceString.push_back(std::atoi(argv[i]));
    }

    //restrict list to be less than or equal to 15 elements
    if(referenceString.size() >= 15)
    {
        std::cerr<<"Reference string must be less than or equal to 15 elements"<<std::endl;
        return 1;
    }

    //restrict elements of the list to be non negative and less than 10
    auto refEnd = referenceString.end();
    for(auto it = referenceString.begin(); it != refEnd; ++it)
    {
        if(*it < 0)
        {
            std::cerr<<"Elements in reference string must be more than or equal to 0"<<std::endl;
            return 1;
        }
        if(*it >= 10)
        {
            std::cerr<<"Elements in reference string must be less than 10"<<std::endl;
            return 1;
        }
    }
    
    //initialize algorithm objects
    ::Comp3473Ass4::LRU lru(5);
    ::Comp3473Ass4::FIFO fifo(5);

    lru.setReferenceString<std::vector<int>>(referenceString);
    fifo.setReferenceString<std::vector<int>>(referenceString);

    //print results
    std::cout<<"Page faults:"<<std::endl;
    std::cout<<"    Least Recently Used: "<<lru.run()<<std::endl;
    std::cout<<"    First In First Out: "<<fifo.run()<<std::endl;
    return 0;
}