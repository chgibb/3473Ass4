#include <vector>

#include "lru.hpp"

//adapted from https://www.thecrazyprogrammer.com/2016/11/lru-page-replacement-algorithm-c.html


::Comp3473Ass4::LRU::LRU(int frameNum) : ::Comp3473Ass4::PageRepAlgo::PageRepAlgo(frameNum)
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
        this->frames.push_back(-1);
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

int ::Comp3473Ass4::LRU::run()
{
    int flag1 = 0;
    int flag2 = 0;
    int pos = 0;
    int counter = 0;

    for(int i = 0; i < this->pages.size(); ++i)
    {
        flag1 = 0;
        flag2 = 0;

        for(int j = 0; j < this->frames.size(); ++j)
        {
            if(this->frames[j] == this->pages[i])
            {
                counter++;
                this->time[j] = counter;
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if(flag1 == 0)
        {
            for(int j = 0; j < this->frames.size(); ++j)
            {
                if(frames[j] == -1)
                {
                    counter++;
                    this->faults++;
                    this->frames[j] = this->pages[i];
                    this->time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        
        if(flag2 == 0)
        {
            pos = this->findLRU(this->time);
            counter++;
            this->faults++;
            this->frames[pos] = this->pages[i];
            this->time[pos] = counter;
        }
    }
    return this->faults;
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