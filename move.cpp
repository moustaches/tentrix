#include "move.h"


void BitBoard::setPosition(const PositionLetter &position_letter){
    pieces[WHITE] = position_letter.getWhites();
    pieces[BLACK] = position_letter.getBlacks();
    pieces[PAWN] = position_letter.getPawns();
    pieces[KNIGHT] = position_letter.getKnights();
    pieces[ROOK] = position_letter.getRooks();
    pieces[QUEEN] = position_letter.getQueens();
    pieces[KING] = position_letter.getKings();
}

u64 BitBoard::computeMoveQueenWhite() const{
    u64 queen = pieces[QUEEN] & pieces[BLACK];
    const auto free_moves_queen = freeMovesQueen[queen];

}
