#include <iostream>
#include <vector>

#include "lru.hpp"
int main(int argc,char*argv[])
{
    ::Comp3473Ass4::LRU lru(5);

    lru.setReferenceString<std::vector<int>>({5,7,5,6,7});

    std::cout<<lru.run()<<std::endl;
    return 0;
}