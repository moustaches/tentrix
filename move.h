#ifndef MOVE_H
#define MOVE_H

#include "structure.h"

#include <cstdint>
#include <array>
#include <bitset>
#include <bit>
#include <map>
#include <array>
#include <algorithm>
#include <ranges>

using u64 = std::uint64_t;

template <auto Start, auto End, class F>
constexpr void constexpr_for(F&& f)
{
    if constexpr (Start < End)
    {
        f(std::integral_constant<decltype(Start), Start>());
        constexpr_for<Start + 1, End>(f);
    }
}

template<typename T>
constexpr T setBase36To64(T index_36){
    T i = index_36/6;
    T j = index_36%6;
    return 8+i*8+1+j;
}

constexpr u64 getRectangleSN(unsigned int level, bool is_null_down){
    u64 rectangle(-1);
    if (is_null_down){
        rectangle <<= (8*level);
    }
    else{
        rectangle >>= (8*level);
    }
    return rectangle;
};

constexpr u64 getRectangleWE(int level, bool is_null_east){
    u64 rectangle(-1);
    const u64 column = 0b11111110'11111110'11111110'11111110'11111110'11111110'11111110'11111110;
    for (int i = 0; i<level; ++i){
        rectangle &= std::rotl(column, i);
    }
    if (!is_null_east){
        rectangle =~rectangle;
    }
    return rectangle;
};

constexpr u64 getTriangle(int level, bool is_east_west, bool is_null_down){
    u64 triangle = is_east_west ?
        0b11111111'11111110'11111100'11111000'11110000'11100000'11000000'10000000:
        0b11111111'01111111'00111111'00011111'00001111'00000111'00000011'00000001;
    if (level < 0){
        triangle >>= (-8*level);
        triangle =~(triangle ^ getRectangleSN(-level, false));
    }
    else{
        triangle <<= (8*level);
    }
    if (!is_null_down){
        triangle=~triangle;
    }
    return triangle;
};

consteval std::array<std::array<u64, 8>, 36> computeFreeMoveQueen(){
    const u64 south_north = 0b00000001'00000001'00000001'00000001'00000001'00000001'00000001'00000001;
    const u64 east_west = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'11111111;
    const u64 south_east_north_west = 0b00000001'00000010'00000100'00001000'00010000'00100000'01000000'10000000;
    const u64 south_west_north_east = 0b10000000'01000000'00100000'00010000'00001000'00000100'00000010'00000001;
    const u64 board_36 =  0b00000000'01111110'01111110'01111110'01111110'01111110'01111110'00000000; // fill 36 borad
    std::array<std::array<u64, 8>, 36> pieces_rays{};
    constexpr_for<u64(0), u64(36)>([&](u64 i){
        u64 index_64 = setBase36To64(i);
        int level_diagonal_WE = index_64/8 - index_64%8;
        int level_diagonal_EW = index_64/8 - (8 - index_64%8);
        std::array<u64, 8> piece_ray{};
        piece_ray[0] = (east_west << index_64) & getRectangleWE(index_64%8+1, true); // West ray
        piece_ray[1] = (south_west_north_east << (index_64+9)) & getTriangle(level_diagonal_WE+1, false, false); // North West ray
        piece_ray[2] = (south_north << (index_64+8)); // North ray
        piece_ray[3] = (south_east_north_west << index_64) & getTriangle(level_diagonal_EW+2, true, false);// North East ray
        piece_ray[4] = (east_west << (index_64-8)) & getRectangleWE(index_64%8, false); // East ray
        piece_ray[5] = (south_west_north_east >> (63 - index_64 + 9)) & getTriangle(level_diagonal_WE-1, false, true) ; // South West ray
        piece_ray[6] = (south_north >> (64 - index_64)); // South ray
        piece_ray[7] = (south_east_north_west >> (63 - index_64 )) & getTriangle(level_diagonal_EW-1, true, true) ; // South east ray
        std::ranges::for_each(piece_ray,[&](auto& bit_board){bit_board &= board_36;});
        pieces_rays[i] = piece_ray;
    });
    return pieces_rays;
};


consteval std::array<std::array<u64, 4>, 36> computeFreeMoveRook(){
    const u64 south_north = 0b00000001'00000001'00000001'00000001'00000001'00000001'00000001'00000001;
    const u64 east_west = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'11111111;
    const u64 board_36 =  0b00000000'01111110'01111110'01111110'01111110'01111110'01111110'00000000; // fill 36 borad
    std::array<std::array<u64, 4>, 36> piece_rays{};
    constexpr_for<u64(0), u64(36)>([&](u64 i){
        u64 index_64 = setBase36To64(i);
        std::array<u64, 4> piece_ray{};
        piece_ray[0] = (east_west << index_64) & getRectangleWE(index_64%8+1, true); // West ray
        piece_ray[1] = (south_north << (index_64+8)); // North ray
        piece_ray[2] = (east_west << (index_64-8)) & getRectangleWE(index_64%8, false); // East ray
        piece_ray[3] = (south_north >> (64 - index_64)); // South ray
        std::ranges::for_each(piece_ray,[&](auto& bit_board){bit_board &= board_36;});
        piece_rays[i] = piece_ray;
    });
    return piece_rays;
};


consteval std::array<u64, 36> computeFreeMoveKnight(){
    const u64 move_knight_centred = 0b00000100'01000010'10000000'00000000'00000000'00000010'10000100'01000000;
    const u64 board_36 =  0b00000000'01111110'01111110'01111110'01111110'01111110'01111110'00000000; // fill 36 borad
    std::array<u64, 36> piece_move{};
    for (int i=0; i<36; ++i){
        u64 index_64 = setBase36To64(i);
        piece_move[i] =  std::rotl(move_knight_centred, index_64);
    }
    std::ranges::for_each(piece_move,[&](auto& bit_board){bit_board &= board_36;});
    return piece_move;
};




class BitBoard{
    u64 pieces[7];

public:
    enum E_RAY_DIR{ N=0, NE, E, SE, S, SW, W, NW};

    void setPosition(const PositionLetter& position_letter);
    u64 computeMoveQueenWhite() const;

private:
    static constexpr std::array<std::array<u64, 8>, 36> freeMovesQueen = computeFreeMoveQueen();
    static constexpr std::array<std::array<u64, 4>, 36> freeMovesRook = computeFreeMoveRook();
    static constexpr std::array<u64, 36> freeMovesKnight = computeFreeMoveKnight();
};









#endif // MOVE_H
