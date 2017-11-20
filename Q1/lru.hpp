#pragma once
#include <vector>
namespace Comp3473Ass4
{
    class LRU
    {
        public:
            LRU(int);
            ~LRU();
            void setFrameNumber(int);
            template<class T>
            void setReferenceString(T ref)
            {
                for(int i = 0; i != this->pages.size(); ++i)
                {
                    this->pages[i] = ref[i];
                }
            }
            void reset();
            int run();
        private:
            std::vector<int> pages;
            std::vector<int> frames;
            std::vector<int> time;
            int faults;
            int findLRU(std::vector<int>&);
    };
}