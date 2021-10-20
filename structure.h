#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <string_view>
#include <cstdint>
#include <array>


using u64 = std::uint64_t;

enum E_PIECE{WHITE=0, BLACK, PAWN, KNIGHT, ROOK, QUEEN, KING};

class PositionLetter{
public:
    PositionLetter(std::string_view position_char);
    std::array<char,36> letter_board;
    char& operator[](std::size_t idx);
    char operator[](std::size_t idx) const;

    u64 getPawns() const;
    u64 getKnights() const;
    u64 getRooks() const;
    u64 getQueens() const;
    u64 getKings() const;
    u64 getWhites() const;
    u64 getBlacks() const;

private:
    u64 getLetter(char letter) const;

};
#endif // STRUCTURE_H
