#include "structure.h"

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <bitset>

PositionLetter::PositionLetter(std::string_view position_char)
{
    constexpr std::array<char,12> available_char{' ','.','p','n','t','k','q','P','N','T','K','Q'};
    // check position contain only available char
    if (std::ranges::all_of(position_char, [&available_char](auto signe){
                            return std::ranges::find(available_char, signe);})){
        for (int i=0; i<6; ++i){
            for (int j=0; j<3; ++j){
                letters_board[12+i-6*j] = position_char[18+i+6*j];
                letters_board[18+i+6*j] = position_char[12+i-6*j];
            }
        }
    }
    else{
        throw std::invalid_argument("Only ' ','p','n','r','k','q','P','N','R','K','Q' are available.");
    }
}

char& PositionLetter::operator[](std::size_t idx)
{
    return letters_board[idx];
}

char PositionLetter::operator[](std::size_t idx) const
{
    return letters_board[idx];
}

u64 PositionLetter::getLetter(char letter) const{
    u64 letter_bb = 0;
    auto iter = std::ranges::find(letters_board, letter);
    while(iter != letters_board.end()){
        letter_bb |= (1ul << std::distance(letters_board.begin(), iter));
        iter = std::find(std::next(iter), letters_board.end(), letter);
    }
    return letter_bb;
}


u64 PositionLetter::getPawnsBB() const
{
    u64 bb(0);
    for (auto letter : {'p', 'P'}){
        bb |= getLetter(letter);
    };
    return bb;
}


u64 PositionLetter::getKnightsBB() const
{
    u64 bb(0);
    for (auto letter : {'n', 'N'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getRooksBB() const
{
    u64 bb(0);
    for (auto letter : {'r', 'R'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getQueensBB() const
{
    u64 bb(0);
    for (auto letter : {'q', 'Q'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getKingsBB() const
{
    u64 bb(0);
    for (auto letter : {'k', 'K'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getWhitesBB() const
{
    u64 bb(0);
    for (auto letter : {'p', 'n', 'r', 'q', 'k'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getBlacksBB() const
{
    u64 bb(0);
    for (auto letter : {'P', 'N', 'R', 'Q', 'K'}){
        bb |= getLetter(letter);
    };
    return bb;
}


std::vector<Piece> PositionLetter::getPieces() const
{
    std::vector<Piece> pieces;
    for (auto letter = letters_board.begin(); letter != letters_board.end(); ++letter){
        Piece piece{};
        if ((*letter != ' ') && (*letter != '.')){
            piece.index=std::distance(letters_board.begin(), letter);
            switch(*letter){
            case 'p': piece.type = E_PIECE::PAWN_WHITE; break;
            case 'P': piece.type = E_PIECE::PAWN_BLACK; break;
            case 'n': piece.type = E_PIECE::KNIGHT_WHITE; break;
            case 'N': piece.type = E_PIECE::KNIGHT_BLACK; break;
            case 'r': piece.type = E_PIECE::ROOK_WHITE; break;
            case 'R': piece.type = E_PIECE::ROOK_BLACK; break;
            case 'q': piece.type = E_PIECE::QUEEN_WHITE; break;
            case 'Q': piece.type = E_PIECE::QUEEN_BLACK; break;
            case 'k': piece.type = E_PIECE::KING_WHITE; break;
            case 'K': piece.type = E_PIECE::KING_BLACK; break;
            };
            pieces.push_back(piece);
        }
    }
    return pieces;
}
