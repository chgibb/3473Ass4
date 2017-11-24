#pragma once
#include <vector>
#include <stdexcept>

#include "pageRepAlgo.hpp"
namespace Comp3473Ass4
{
    /**
     * @brief 
     * 
     * adapted from http://meansofmine.blogspot.ca/2011/04/c-program-to-implement-fifo-page.html
     * 
     */
    class FIFO : public ::Comp3473Ass4::PageRepAlgo<FIFO>
    {
        public:
            FIFO(int);

            ~FIFO();

            /**
             * @brief 
             * 
             * Sets frame number to use
             * 
             * @param  
             */
            void setFrameNumber(int);

            /**
             * @brief 
             * 
             * Sets reference string
             * 
             * @tparam T 
             * @param ref 
             */
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

            /**
             * @brief 
             * 
             * Reset all state to allow for reuse
             * 
             */
            void reset();

            /**
             * @brief 
             * 
             * Run algorithm. Returns number of page faults found
             * 
             * @return int 
             */
            int run();       
    };
}