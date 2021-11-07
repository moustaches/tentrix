
// Include Project
#include "tentrix/move.h"
#include "tentrix/structure.h"
#include "tentrix/print.h"

// Include STD
#include "iostream"



void Position::setPosition(const PositionLetter &position_letter){
    bitboard[E_BB::WHITE] = position_letter.getWhitesBB();
    bitboard[E_BB::BLACK] = position_letter.getBlacksBB();
    bitboard[E_BB::PAWNS] = position_letter.getPawnsBB();
    bitboard[E_BB::KNIGHTS] = position_letter.getKnightsBB();
    bitboard[E_BB::ROOKS] = position_letter.getRooksBB();
    bitboard[E_BB::QUEENS] = position_letter.getQueensBB();
    bitboard[E_BB::KINGS] = position_letter.getKingsBB();
    pieces = std::move(position_letter.getPieces());
}

u64 Position::computeMoveQueenWhite(unsigned char index) const{
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
        u64 bloquers = rayBB & (bitboard[WHITE] | bitboard[BLACK]) & mask_36;
        int first_bloquer = 63-std::countl_zero(bloquers);
        if (bloquers>0){
            rayBB ^= freeMovesQueen[first_bloquer][dir];
        }
        rayBB &= ~bitboard[WHITE];
        moveBB |= rayBB;
    }
    return moveBB;
}

u64 Position::computeMoveQueenWhite_2(int index) const{
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
