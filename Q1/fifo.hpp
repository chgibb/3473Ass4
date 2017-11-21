#pragma once
#include <vector>

#include "pageRepAlgo.hpp"
namespace Comp3473Ass4
{
    class FIFO : public ::Comp3473Ass4::PageRepAlgo
    {
        public:
            FIFO(int);
            ~FIFO();
            void setFrameNumber(int);
            template <class T>
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
            
    };
}