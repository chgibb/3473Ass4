#include <vector>

#include "lru.hpp"

::Comp3473Ass4::LRU::LRU(int frameNum)
{
    this->reset();
    this->setFrameNumber(frameNum);
}

::Comp3473Ass4::LRU::~LRU() = default;

void ::Comp3473Ass4::LRU::setFrameNumber(int num)
{
    this->pages.clear();
    this->frames.clear();
    this->time.clear();
    for(int i = 0; i != num; ++i)
    {
        this->pages.push_back(0);
        this->frames.push_back(0);
        this->time.push_back(0);
    }
}

void ::Comp3473Ass4::LRU::reset()
{
    this->faults = 0;
    this->pages.clear();
    this->frames.clear();
    this->time.clear();
}

int ::Comp3473Ass4::LRU::findLRU(std::vector<int>&time)
{
    int minimum = time[0];
    int pos = 0;
    for(int i = 1; i < time.size(); ++i)
    {
        if(time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}