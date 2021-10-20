
#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <array>
#include <algorithm>
#include <ranges>

// Include Projrct
#include "print.h"
#include "structure.h"
#include "move.h"

using namespace std;
using u64 = uint64_t;


inline std::uint64_t computeKnightMove(std::uint64_t index_night){
    std::uint64_t move_knight_centred = 0b00000000'00000000'00000000'00001010'00010001'00000000'00010001'00001010;
    if (index_night>18)
        move_knight_centred <<= index_night-18;
    else
        move_knight_centred >>= 18-index_night;
    return move_knight_centred;
};

inline std::uint64_t computeKnightMove_rot(std::uint64_t index_night){
    std::uint64_t move_knight_centred = 0b00000000'00000000'00000000'00001010'00010001'00000000'00010001'00001010;
    return std::rotl(move_knight_centred, index_night - 18);
};



constinit std::array<std::array<u64, 8>, 36> movesQueen = computeFreeMoveQueen();
constinit std::array<u64, 36> movesKnight = computeFreeMoveKnight();

int main()
{
    const uint board_size = 36;

    struct Piece{
        unsigned int type:3;
        unsigned int has_moved:1;
    };


    PositionLetter position_string{std::string{
            "RNKQNR"
            "PPPPPP"
            "...p.."
            "......"
            "ppp.pp"
            "rnkqnr"
        }};

    print(position_string.getPawns(), BB36 );

//    for (u64 i = 0; i < 36; ++i){
//        std::cout <<i<<std::endl;
//        u64 mvmt(0);
//        mvmt = movesKnight[i];
//        for (u64 j = 0; j < 8; ++j){
//            mvmt |= movesQueen[i][j];
//        }
//        print(mvmt, BB64 );
//    }
    return 0;
}
