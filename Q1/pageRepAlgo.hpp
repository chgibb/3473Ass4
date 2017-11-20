#pragma once
#include <vector>
namespace Comp3473Ass4
{
    class PageRepAlgo
    {
        public:
            PageRepAlgo(int a){}
            void setFrameNumber(int);
            template <class T> void setReferenceString(T ref);
            void reset();
            int run();
        protected:
            std::vector<int> pages;
            std::vector<int> frames;
            int faults;
    };
}