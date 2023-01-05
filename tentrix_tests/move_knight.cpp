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



using u64 = uint64_t;


TEST(Position, computeMoveKnight_templated_white)
{
    PositionMaker position{};
    u64 bb_move{};
    position.setPosition(PositionLetter{ "......"
                                         "......"
                                         "......"
                                         "......"
                                         "......"
                                         "n....." });
    bb_move = position.computeMoveKnight<white>(0);

    ASSERT_EQ( 0b0000000000000000000000000000'000000'000000'000000'000010'000100'000000, bb_move);
    position.setPosition(PositionLetter{ "RNKQNR"
                                         "PPPPPP"
                                         "......"
                                         "......"
                                         "pppppp"
                                         "rnkqnr" });
    bb_move = position.computeMoveKnight<white>(1);
    ASSERT_EQ( 0b0000000000000000000000000000'000000'000000'000000'000101'000000'000000, bb_move);

    position.setPosition(PositionLetter{ "RNKQNR"
                                         "PPPPPP"
                                         "..n..."
                                         "......"
                                         "pppppp"
                                         "rnkq.r" });
    bb_move = position.computeMoveKnight<white>(20);
    ASSERT_EQ( 0b0000000000000000000000000000'001010'010001'000000'010001'000000'000000, bb_move);

    position.setPosition(PositionLetter{ "RNKQNR"
                                         "PPPPPP"
                                         "......"
                                         "...n.."
                                         "pp..pp"
                                         "rnk.nr" });
    bb_move = position.computeMoveKnight<white>(15);
    ASSERT_EQ( 0b0000000000000000000000000000'000000'010100'100010'000000'000000'000000, bb_move);

    position.setPosition(PositionLetter{ "RNKQNn"
                                         "PPPPPp"
                                         "......"
                                         "......"
                                         "pppppp"
                                         "rnkqnr" });
    bb_move = position.computeMoveKnight<white>(35);
    ASSERT_EQ( 0b0000000000000000000000000000'000000'001000'010000'000000'000000'000000, bb_move);
}
