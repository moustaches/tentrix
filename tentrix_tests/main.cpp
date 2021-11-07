// Include Project
#include "tentrix/print.h"
#include "tentrix/structure.h"
#include "tentrix/move.h"

// Include 3rd-part
#include <gtest/gtest.h>

// Include STD
#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <array>
#include <algorithm>
#include <ranges>



using namespace std;
using u64 = uint64_t;


TEST(Position, computeMoveQueenWhite)
{
    Position position{};
    u64 queen_move{};

    position.setPosition(PositionLetter{ "......"
                                         "......"
                                         "......"
                                         "......"
                                         "......"
                                         "q....." });
    queen_move = position.computeMoveQueenWhite(0);

    ASSERT_EQ( 0b0000000000000000000000000000'100001'010001'001001'000101'000011'111110, queen_move);
    position.setPosition(PositionLetter{ "RNKQNR"
                                         "PPPPPP"
                                         "......"
                                         "......"
                                         "pppppp"
                                         "rnkqnr" });
    queen_move = position.computeMoveQueenWhite(3);
    ASSERT_EQ( 0b0000000000000000000000000000'000000'000000'000000'000000'000000'000000, queen_move);

    position.setPosition(PositionLetter{ "RNKQNR"
                                         "PPPPPP"
                                         "......"
                                         "......"
                                         "ppp.pp"
                                         "rnkqnr" });
    queen_move = position.computeMoveQueenWhite(3);
    ASSERT_EQ( 0b0000000000000000000000000000'000000'001000'001000'001000'001000'000000, queen_move);

    position.setPosition(PositionLetter{ "RNKQNR"
                                         "PPPPPP"
                                         "......"
                                         "...q.."
                                         "pp..pp"
                                         "rnk.nr" });
    queen_move = position.computeMoveQueenWhite(15);
    ASSERT_EQ( 0b0000000000000000000000000000'000000'101010'011100'110111'001100'001000, queen_move);

    position.setPosition(PositionLetter{ "RNKQNq"
                                         "PPPPPp"
                                         "......"
                                         "......"
                                         "pppppp"
                                         "rnkqnr" });
    queen_move = position.computeMoveQueenWhite(35);
    ASSERT_EQ( 0b0000000000000000000000000000'010000'010000'000000'000000'000000'000000, queen_move);
}


TEST(Position, computeMoveQueenWhite_2)
{
    Position position{};
    u64 queen_move{};

    position.setPosition(PositionLetter{ "......"
                                         "......"
                                         "......"
                                         "......"
                                         "......"
                                         "q....." });
    queen_move = position.computeMoveQueenWhite_2(0);

    ASSERT_EQ( 0b0000000000000000000000000000'100001'010001'001001'000101'000011'111110, queen_move);
    position.setPosition(PositionLetter{ "RNKQNR"
                                         "PPPPPP"
                                         "......"
                                         "......"
                                         "pppppp"
                                         "rnkqnr" });
    queen_move = position.computeMoveQueenWhite_2(3);
    ASSERT_EQ( 0b0000000000000000000000000000'000000'000000'000000'000000'000000'000000, queen_move);

    position.setPosition(PositionLetter{ "RNKQNR"
                                         "PPPPPP"
                                         "......"
                                         "......"
                                         "ppp.pp"
                                         "rnkqnr" });
    queen_move = position.computeMoveQueenWhite_2(3);
    ASSERT_EQ( 0b0000000000000000000000000000'000000'001000'001000'001000'001000'000000, queen_move);

    position.setPosition(PositionLetter{ "RNKQNR"
                                         "PPPPPP"
                                         "......"
                                         "...q.."
                                         "pp..pp"
                                         "rnk.nr" });
    queen_move = position.computeMoveQueenWhite_2(15);
    ASSERT_EQ( 0b0000000000000000000000000000'000000'101010'011100'110111'001100'001000, queen_move);

    position.setPosition(PositionLetter{ "RNKQNq"
                                         "PPPPPp"
                                         "......"
                                         "......"
                                         "pppppp"
                                         "rnkqnr" });
    queen_move = position.computeMoveQueenWhite_2(35);
    ASSERT_EQ( 0b0000000000000000000000000000'010000'010000'000000'000000'000000'000000, queen_move);
}


