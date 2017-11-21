#include <iostream>
#include <vector>

#include "lru.hpp"
#include "fifo.hpp"

int main(int argc,char*argv[])
{
    ::Comp3473Ass4::LRU lru(5);

    lru.setReferenceString<std::vector<int>>({5,7,5,6,7});

    ::Comp3473Ass4::FIFO fifo(5);

    fifo.setReferenceString<std::vector<int>>({5,7,5,6,7});

    std::cout<<lru.run()<<std::endl;
    std::cout<<fifo.run()<<std::endl;
    return 0;
}