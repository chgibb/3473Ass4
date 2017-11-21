#pragma once
#include <vector>
namespace Comp3473Ass4
{
    template <class Derived> class PageRepAlgo
    {
        public:
            PageRepAlgo(int a){}
            void setFrameNumber(int num)
            {
                static_cast<Derived*>(this)->setFrameNumber(num);
            }
            template <class T> void setReferenceString(T ref)
            {
                static_cast<Derived*>(this)->setReferenceString<decltype(ref)>(ref);
            }
            void reset()
            {
                static_cast<Derived*>(this)->reset();
            }
            int run()
            {
                static_cast<Derived*>(this)->run();
            }
        protected:
            std::vector<int> pages;
            std::vector<int> frames;
            int faults;
    };
}