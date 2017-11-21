#pragma once
#include <vector>
#include <stdexcept>

#include "pageRepAlgo.hpp"
namespace Comp3473Ass4
{
    class LRU : public ::Comp3473Ass4::PageRepAlgo<LRU>
    {
        public:
            LRU(int);
            ~LRU();
            void setFrameNumber(int);
            template <class T>
            void setReferenceString(T ref)
            {
                if(ref.size() > 15)
                    throw std::runtime_error("Reference string must be no larger than 15");
                for(int i = 0; i != this->pages.size(); ++i)
                {
                    this->pages[i] = ref[i];
                }
            }
            void reset();
            int run();
        private:
            std::vector<int> time;
            int findLRU(std::vector<int>&);
    };
}