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

constexpr u64 computeRay(int index, std::pair<int,int> direction){
    u64 bitboard{0};
    int i = index%6 + direction.first;
    int j = index/6 + direction.second;
    while ((i >=0 && i <= 5) && (j >=0 && j <= 5)){
        bitboard |= (1ul << (i+j*6));
        i += direction.first;
        j += direction.second;
    }
    return bitboard;
}

consteval std::array<std::array<u64, 8>, 36> computeFreeMoveQueen(){
    const std::array<std::pair<int,int>, 8> directions{
        std::make_pair(1,0), std::make_pair(1,1), std::make_pair(0,1),std::make_pair(-1,1), std::make_pair(-1,0),std::make_pair(-1,-1),std::make_pair(0,-1),std::make_pair(1,-1)};
    std::array<std::array<u64, 8>, 36> pieces_rays{};
    constexpr_for<u64(0), u64(36)>([&](u64 index){
        std::array<u64, 8> piece_ray{};
        int iter=0;
        for (const auto& direction: directions){
            piece_ray[iter++] = computeRay(index, direction);
        }
        pieces_rays[index] = piece_ray;
    });
    return pieces_rays;
};

consteval std::array<std::array<u64, 4>, 36> computeFreeMoveRook(){
    const std::array<std::pair<int,int>, 4> directions{std::make_pair(1,0), std::make_pair(0,1), std::make_pair(-1,0), std::make_pair(0,-1)};
    std::array<std::array<u64, 4>, 36> pieces_rays{};
    constexpr_for<u64(0), u64(36)>([&](u64 index){
        std::array<u64, 4> piece_ray{};
        int iter=0;
        for (const auto& direction: directions){
            piece_ray[iter++] = computeRay(index, direction);
        }
        pieces_rays[index] = piece_ray;
    });
    return pieces_rays;
};

consteval std::array<u64, 36> computeFreeMoveKnight(){
    const std::array<std::pair<int,int>, 8> directions{
        std::make_pair(-2,-1), std::make_pair(-2,1), std::make_pair(-1,-2),std::make_pair(-1,2),
                std::make_pair(1,-2),std::make_pair(1,2),std::make_pair(2,-1),std::make_pair(2,1)};
    std::array<u64, 36> piece_move{};
    for (int iter = 0 ; iter < 36; ++iter){
        u64 pos(0ul);
        int i_0 = iter%6;
        int j_0 = iter/6;
        for (auto direction : directions){
            if ((i_0+direction.first >= 0) && (i_0+direction.first <=5) && (j_0+direction.second >= 0) && (j_0+direction.second <=5)){
               pos |= (1ul <<((i_0+direction.first)+((j_0+direction.second)*6)));
            }
        }
        piece_move[iter]=pos;
    };
    return piece_move;
};


class Position{
public:

    void setPosition(const PositionLetter& position_letter);
    u64 computeMoveQueenWhite_1(unsigned char index) const;
    u64 computeMoveQueenWhite_2(unsigned char index) const;

private:
    const u64 mask_36 = 0b0000000000000000000000000000'111111'111111'111111'111111'111111'111111;
    static constexpr std::array<std::array<u64, 8>, 36> freeMovesQueen = computeFreeMoveQueen();
    static constexpr std::array<std::array<u64, 4>, 36> freeMovesRook = computeFreeMoveRook();
    static constexpr std::array<u64, 36> freeMovesKnight = computeFreeMoveKnight();

    u64 bitboard[7];
    std::vector<Piece> pieces;

};


#endif // MOVE_H
