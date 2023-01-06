
// Include Project
#include "tentrix/move.h"
#include "tentrix/print.h"
#include "tentrix/structure.h"

// Include STD
#include <iostream>
#include <bitset>



void PositionMaker::setTree(Tree &tree){
    bitboard[E_BB::WHITE] = tree.position.getWhitesBB();
    bitboard[E_BB::BLACK] = tree.position.getBlacksBB();
    bitboard[E_BB::PAWNS] = tree.position.getPawnsBB();
    bitboard[E_BB::KNIGHTS] = tree.position.getKnightsBB();
    bitboard[E_BB::ROOKS] = tree.position.getRooksBB();
    bitboard[E_BB::QUEENS] = tree.position.getQueensBB();
    bitboard[E_BB::KINGS] = tree.position.getKingsBB();
    pieces = std::move(tree.position.getPieces());
    node = &tree.root;
}

void PositionMaker::setPosition(const PositionLetter &position_letter){
    bitboard[E_BB::WHITE] = position_letter.getWhitesBB();
    bitboard[E_BB::BLACK] = position_letter.getBlacksBB();
    bitboard[E_BB::PAWNS] = position_letter.getPawnsBB();
    bitboard[E_BB::KNIGHTS] = position_letter.getKnightsBB();
    bitboard[E_BB::ROOKS] = position_letter.getRooksBB();
    bitboard[E_BB::QUEENS] = position_letter.getQueensBB();
    bitboard[E_BB::KINGS] = position_letter.getKingsBB();
    pieces = std::move(position_letter.getPieces());
}


// Only for gcc because std::bitset._Find_first() only define there
#if defined(__GNUC__) || defined(__GNUG__)
int PositionMaker::getPopIndexBB_1(u64& bitboard) {
    std::bitset<64> bit_set{bitboard};
    auto index = bit_set._Find_first();
    if (index < 64){
        bitboard = bit_set.reset(index).to_ulong();
    }
    return index;
}

int PositionMaker::getPopIndexBB_2(u64& bitboard) {
    std::bitset<64> bit_set{bitboard};
    auto index = bit_set._Find_first();
    if (index < 64){
        bitboard &= ~(u64{1} << index);
    }
    return index;
}
#endif

int PositionMaker::getPopIndexBB_3(u64& bitboard) {
    auto index = std::countr_zero(bitboard);
    bitboard ^= (bitboard & -bitboard);
    return index;
}

std::pair<int, u64> PositionMaker::getPopIndexBB_4(u64 bitboard){
    return std::make_pair(std::countr_zero(bitboard), bitboard ^(bitboard & -bitboard));
}

std::pair<int, u64> PositionMaker::getPopIndexBB_5(u64 bitboard){
    auto index = std::countr_zero(bitboard);
    return std::make_pair(index , bitboard & ~(u64{1} << index));
}
