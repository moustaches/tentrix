#ifndef TENTRIX_PRINT_H
#define TENTRIX_PRINT_H

//Include STD
#include <iostream>
#include <bitset>
#include <cstdint>



enum PRINT_MODE{BB36, BB64};

template<typename Position>
void print(const Position& position, PRINT_MODE print_mode = PRINT_MODE::BB36){
    if (print_mode == BB36){
        std::cout << "\n";
        for (int i = 0; i < 6; ++i){
            std::cout << 6-i << " | ";
            for (int j = 0; j < 6; ++j){
                std::cout << position[(5-i)*6+j] << " ";
            };
            std::cout << "\n";
        };
        std::cout << "    A B C D E F\n" << std::endl;
    }
    else if (print_mode == BB64){
        std::cout << "\n";
        for (int i = 0; i < 8; ++i){
            std::cout << 8-i << " | ";
            for (int j = 0; j < 8; ++j){
                std::cout << position[(7-i)*8+j] << " ";
            };
            std::cout << "\n";
        };
        std::cout << "    A B C D E F G H\n" << std::endl;
    }
};

template<>
inline void print<std::uint64_t>(const std::uint64_t& bit_board, PRINT_MODE print_mode ){
    print( std::bitset<64>(bit_board), print_mode);
};

#endif // TENTRIX_PRINT_H
