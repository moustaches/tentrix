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
                this->letter_board[12+i-6*j] = position_char[18+i+6*j];
                this->letter_board[18+i+6*j] = position_char[12+i-6*j];
            }
        }
    }
    else{
        throw std::invalid_argument("Only ' ','p','n','r','k','q','P','N','R','K','Q' are available.");
    }
}

char& PositionLetter::operator[](std::size_t idx)
{
    return letter_board[idx];
}

char PositionLetter::operator[](std::size_t idx) const
{
    return letter_board[idx];
}

u64 PositionLetter::getLetter(char letter) const{
    u64 letter_bb = 0;
    auto iter = std::ranges::find(letter_board, letter);
    while(iter != letter_board.end()){
        auto d = std::distance(letter_board.begin(), iter);
        letter_bb |= (1ul << ((d/6)*8+9+d%6));
        iter = std::find(std::next(iter), letter_board.end(), letter);
    }
    return letter_bb;
}


u64 PositionLetter::getPawns() const
{
    u64 bb(0);
    for (auto letter : {'p', 'P'}){
        bb |= getLetter(letter);
    };
    return bb;
}


u64 PositionLetter::getKnights() const
{
    u64 bb(0);
    for (auto letter : {'n', 'N'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getRooks() const
{
    u64 bb(0);
    for (auto letter : {'r', 'R'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getQueens() const
{
    u64 bb(0);
    for (auto letter : {'q', 'Q'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getKings() const
{
    u64 bb(0);
    for (auto letter : {'k', 'K'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getWhites() const
{
    u64 bb(0);
    for (auto letter : {'p', 'n', 'r', 'q', 'k'}){
        bb |= getLetter(letter);
    };
    return bb;
}

u64 PositionLetter::getBlacks() const
{
    u64 bb(0);
    for (auto letter : {'P', 'N', 'R', 'Q', 'K'}){
        bb |= getLetter(letter);
    };
    return bb;
}
