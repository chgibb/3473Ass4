#include <vector>

#include "fifo.hpp"

//adapted from http://meansofmine.blogspot.ca/2011/04/c-program-to-implement-fifo-page.html

::Comp3473Ass4::FIFO::FIFO(int frameNum) :
::Comp3473Ass4::PageRepAlgo<::Comp3473Ass4::FIFO>::PageRepAlgo(frameNum)
{
    this->reset();
    this->setFrameNumber(frameNum);
}

::Comp3473Ass4::FIFO::~FIFO() = default;

void ::Comp3473Ass4::FIFO::setFrameNumber(int num)
{
    this->pages.clear();
    this->frames.clear();
    for(int i = 0; i != num; ++i)
    {
        this->pages.push_back(0);
        this->frames.push_back(-1);
    }
}

void ::Comp3473Ass4::FIFO::reset()
{
    this->faults = 0;
    this->pages.clear();
    this->frames.clear();
}

int ::Comp3473Ass4::FIFO::run()
{
    int j = 0;
    int avail = 0;
    for(int i = 1; i <= this->pages.size(); ++i)
    {
        avail = 0;
        for(int k = 0; k < this->frames.size(); ++k)
        {
            if(this->frames[k] == this->pages[i])
            {
                avail = 1;
            }
            if(avail == 0)
            {
                this->frames[j] = this->pages[i];
                j = (j + 1) % this->frames.size();
                this->faults++;
            }
        }
    }
    return this->faults;
}