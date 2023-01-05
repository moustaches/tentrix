#ifndef TENTRIX_MOVE_H
#define TENTRIX_MOVE_H

// Include Project
#include "structure.h"

// Include STD
#include <cassert>
#include <cstdint>
#include <array>
#include <bitset>
#include <bit>
#include <map>
#include <array>
#include <algorithm>
#include <ranges>
#include <type_traits>
#include <iostream>

using u64 = std::uint64_t;

namespace chess_rules{
    const auto size_row = 6;
    const auto size_column = 6;
    const auto size_board = size_row * size_column;
    const auto nb_ray_diagonal = 4;
    const auto nb_ray_straight = 4;
    const auto nb_ray = nb_ray_diagonal + nb_ray_straight;
    const auto nb_move_knight = 8;
}

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
    int i = index%chess_rules::size_column + direction.first;
    int j = index/chess_rules::size_row + direction.second;
    while ((i >=0 && i < chess_rules::size_column) && (j >=0 && j < chess_rules::size_row)){
        bitboard |= (u64{ 1 } << (i + j * chess_rules::size_column));
        i += direction.first;
        j += direction.second;
    }
    return bitboard;
};


consteval std::array<std::array<u64, chess_rules::nb_ray>, chess_rules::size_board> computeFreeMoveQueen(){
    const std::array<std::pair<int,int>, chess_rules::nb_ray> directions{
        std::pair{1,0},
        std::pair{1,1},
        std::pair{0,1},
        std::pair{-1,1},
        std::pair{-1,0},
        std::pair{-1,-1},
        std::pair{0,-1},
        std::pair{1,-1}
    };
    std::array<std::array<u64, chess_rules::nb_ray>, chess_rules::size_board> pieces_rays{};
    if (std::is_constant_evaluated()){return pieces_rays;};
    constexpr_for<0, chess_rules::size_board>([&](int index){
        std::array<u64, chess_rules::nb_ray> piece_ray{};
        auto iter{0};
        for (const auto& direction: directions){
            piece_ray[iter++] = computeRay(index, direction);
        }
        pieces_rays[index] = piece_ray;
    });
    return pieces_rays;
};


consteval std::array<std::array<u64, chess_rules::nb_ray_straight>, chess_rules::size_board> computeFreeMoveRook(){
    const std::array<std::pair<int,int>, chess_rules::nb_ray_straight> directions{
        std::pair{1,0},
        std::pair{0,1},
        std::pair{-1,0},
        std::pair{0,-1}};
    std::array<std::array<u64, chess_rules::nb_ray_straight>, chess_rules::size_board> pieces_rays{};
    constexpr_for<0, chess_rules::nb_ray_straight>([&](int index){
        std::array<u64, chess_rules::nb_ray_straight> piece_ray{};
        auto iter {0};
        for (const auto& direction: directions){
            piece_ray[iter++] = computeRay(index, direction);
        }
        pieces_rays[index] = piece_ray;
    });
    return pieces_rays;
};


consteval std::array<u64, chess_rules::size_board> computeFreeMoveKnight(){
    const std::array<std::pair<int,int>, chess_rules::nb_move_knight> directions{
        std::pair{2,1},
        std::pair{-2,-1},
        std::pair{-1,-2},
        std::pair{-1,2},
        std::pair{1,-2},
        std::pair{1,2},
        std::pair{2,-1},
        std::pair{-2,1}
    };
    std::array<u64, chess_rules::size_board> piece_move{};
    for (int iter = 0 ; iter < chess_rules::size_board; ++iter){
        u64 pos{0ul};
        int i_0 = iter%chess_rules::size_column;
        int j_0 = iter/chess_rules::size_row;
        for (auto direction : directions){
            if ((i_0+direction.first >= 0)
                    && (i_0+direction.first < chess_rules::size_column)
                    && (j_0+direction.second >= 0)
                    && (j_0+direction.second <chess_rules::size_row)){
                pos |= (u64{ 1 } << ((i_0 + direction.first) + ((j_0 + direction.second) * chess_rules::size_column)));
            }
        }
        piece_move[iter]=pos;
    };
    return piece_move;
};


struct white;
struct black;

struct Move{
    u64 finish;
    Piece piece;
    Piece piece_;
    bool eat;
};

struct Node{
    std::vector<Node*> sons;
    int iter{};
    float eval;
    Move move;
};

struct Tree{
    Node root;
    PositionLetter position;
};

struct PositionMaker{
    void setTree(Tree& tree);
    void setPosition(const PositionLetter& position_letter);
    u64 computeMoveQueenWhite(unsigned char index) const{
        u64 moveBB{0};
        for (int dir = 0; dir<4; ++dir){
            u64 rayBB = freeMovesQueen[index][dir];
            u64 bloquers = rayBB & (bitboard[WHITE] | bitboard[BLACK]);
            int first_bloquer = std::countr_zero(bloquers);
            if (first_bloquer<36){
                rayBB ^= freeMovesQueen[first_bloquer][dir];
            }
            rayBB &= ~bitboard[WHITE];
            moveBB |= rayBB;
        }
        for (int dir = 4; dir<8; ++dir){
            u64 rayBB = freeMovesQueen[index][dir];
            u64 bloquers = rayBB & (bitboard[WHITE] | bitboard[BLACK]);
            int first_bloquer = 63-std::countl_zero(bloquers);
            if (bloquers>0){
                rayBB ^= freeMovesQueen[first_bloquer][dir];
            }
            rayBB &= ~bitboard[WHITE];
            moveBB |= rayBB;
        }
        return moveBB;
    }


    template<typename T> u64 computeMoveQueen(std::size_t index) const;
    template<> u64 computeMoveQueen<white>(std::size_t index) const{
        u64 moveBB{0};
        for (int dir = 0; dir<4; ++dir){
            u64 rayBB = freeMovesQueen[index][dir];
            u64 bloquers = rayBB & (bitboard[WHITE] | bitboard[BLACK]);
            int first_bloquer = std::countr_zero(bloquers);
            if (first_bloquer<36){
                rayBB ^= freeMovesQueen[first_bloquer][dir];
            }
            rayBB &= ~bitboard[WHITE];
            moveBB |= rayBB;
        }
        for (int dir = 4; dir<8; ++dir){
            u64 rayBB = freeMovesQueen[index][dir];
            u64 bloquers = rayBB & (bitboard[WHITE] | bitboard[BLACK]);
            int first_bloquer = 63-std::countl_zero(bloquers);
            if (bloquers>0){
                rayBB ^= freeMovesQueen[first_bloquer][dir];
            }
            rayBB &= ~bitboard[E_BB::WHITE];
            moveBB |= rayBB;
        }
        return moveBB;
    }
    template<> u64 computeMoveQueen<black>(std::size_t index) const{
        u64 moveBB{0};
        for (int dir = 0; dir<4; ++dir){
            u64 rayBB = freeMovesQueen[index][dir];
            u64 bloquers = rayBB & (bitboard[WHITE] | bitboard[BLACK]);
            int first_bloquer = std::countr_zero(bloquers);
            if (first_bloquer<36){
                rayBB ^= freeMovesQueen[first_bloquer][dir];
            }
            rayBB &= ~bitboard[BLACK];
            moveBB |= rayBB;
        }
        for (int dir = 4; dir<8; ++dir){
            u64 rayBB = freeMovesQueen[index][dir];
            u64 bloquers = rayBB & (bitboard[WHITE] | bitboard[BLACK]);
            int first_bloquer = 63-std::countl_zero(bloquers);
            if (bloquers>0){
                rayBB ^= freeMovesQueen[first_bloquer][dir];
            }
            rayBB &= ~bitboard[BLACK];
            moveBB |= rayBB;
        }
        return moveBB;
    }


    template<typename T> u64 computeMoveKnight(std::size_t index) const;
    template<> u64 computeMoveKnight<white>(std::size_t index) const{
        return freeMovesKnight[index] & ~bitboard[WHITE];
    }
    template<> u64 computeMoveKnight<black>(std::size_t index) const{
        return freeMovesKnight[index] & ~bitboard[BLACK];
    }

    //static int getPopIndexBB_1(u64& bitboard);
    //static int getPopIndexBB_2(u64& bitboard);
    static int getPopIndexBB_3(u64& bitboard);
    static std::pair<int, u64> getPopIndexBB_4(u64 bitboard);
    static std::pair<int, u64> getPopIndexBB_5(u64 bitboard);

    static void makeMove_1(Node& current_position, Node futur_position, Move move);

private:
    const u64 mask_36 = 0b0000000000000000000000000000'111111'111111'111111'111111'111111'111111;
    static constexpr std::array<std::array<u64, 8>, 36> freeMovesQueen = computeFreeMoveQueen();
    static constexpr std::array<std::array<u64, 4>, 36> freeMovesRook = computeFreeMoveRook();
    static constexpr std::array<u64, 36> freeMovesKnight = computeFreeMoveKnight();

    Node* node{nullptr};
    u64 bitboard[7];
    std::vector<Piece> pieces;
};


#endif // TENTRIX_MOVE_H
