#include <vector>

#include "fifo.hpp"

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
        this->frames.push_back(0);
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

}