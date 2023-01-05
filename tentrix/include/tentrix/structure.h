#ifndef TENTRIX_STRUCTURE_H
#define TENTRIX_STRUCTURE_H


// Include STD
#include <string_view>
#include <cstdint>
#include <array>
#include <vector>


using u64 = std::uint64_t;

enum class E_PIECE : char{
    EMPTY=0,
    PAWN_WHITE=1, KNIGHT_WHITE=2, ROOK_WHITE=3, QUEEN_WHITE=4, KING_WHITE=5,
    KING_BLACK=-5, QUEEN_BLACK=-4, ROOK_BLACK=-3, KNIGHT_BLACK=-2, PAWN_BLACK=-1
};

enum E_BB{WHITE=0, BLACK=1, PAWNS=2, KNIGHTS=3, ROOKS=4, QUEENS=5, KINGS=6};

enum E_RAY_DIR{ NORTH=0, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST};

struct Piece{
    unsigned char index: 6 {0};
    E_PIECE type : 4 {E_PIECE::EMPTY};
    bool has_moved: 1 {0};
};

class PositionLetter{
public:
    PositionLetter(std::string_view position_char);
    std::array<char,36> letters_board;
    char& operator[](std::size_t idx);
    char operator[](std::size_t idx) const;

    u64 getPawnsBB() const;
    u64 getKnightsBB() const;
    u64 getRooksBB() const;
    u64 getQueensBB() const;
    u64 getKingsBB() const;
    u64 getWhitesBB() const;
    u64 getBlacksBB() const;

    std::vector<Piece> getPieces() const;

private:
    u64 getLetter(char letter) const;

};


#endif // TENTRIX_STRUCTURE_H
