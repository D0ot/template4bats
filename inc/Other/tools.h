#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>

#define SHOW_EXP(x)                                 \
    do{                                             \
        std::cout << #x << " = " << x << std::endl; \
    } while(0)

#define SHOW_STATEMENT(x)                           \
    do{                                             \
        std::cout << "BEFORE " << #x << std::endl;  \
        x;                                          \
        std::cout << std::endl << "AFTER  " << #x << std::endl;  \
    } while(0)



#endif //TOOLS_H