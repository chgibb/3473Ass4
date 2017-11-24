#pragma once
#include <vector>
namespace Comp3473Ass4
{
    /**
     * @brief 
     * 
     * Static page replacement algorithm template
     * 
     * @tparam Derived 
     */
    template <class Derived> class PageRepAlgo
    {
        public:
            PageRepAlgo(int a){}

            /**
             * @brief 
             * 
             * Sets frame number to use
             * 
             * @param  
             */
            void setFrameNumber(int num)
            {
                static_cast<Derived*>(this)->setFrameNumber(num);
            }

            /**
             * @brief 
             * 
             * Sets reference string
             * 
             * @tparam T 
             * @param ref 
             */
            template <class T> void setReferenceString(T ref)
            {
                static_cast<Derived*>(this)->setReferenceString<decltype(ref)>(ref);
            }

            /**
             * @brief 
             * 
             * Reset all state to allow for reuse
             * 
             */
            void reset()
            {
                static_cast<Derived*>(this)->reset();
            }

            /**
             * @brief 
             * 
             * Run algorithm. Returns number of page faults found
             * 
             * @return int 
             */
            int run()
            {
                static_cast<Derived*>(this)->run();
            }
        protected:
            /**
             * @brief 
             * 
             * Pages to use
             * 
             */
            std::vector<int> pages;

            /**
             * @brief 
             * 
             * Frames to use
             * 
             */
            std::vector<int> frames;

            /**
             * @brief 
             * 
             * Total number of faults found
             * 
             */
            int faults;
    };
}