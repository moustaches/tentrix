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
    PositionMaker position{};
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


TEST(Position, getPopIndexBB_1)
{
    u64 bb{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    PositionMaker position{};
    ASSERT_EQ( 0, position.getPopIndexBB_1(bb));
    ASSERT_EQ( 5, position.getPopIndexBB_1(bb));
    ASSERT_EQ( 7, position.getPopIndexBB_1(bb));
    ASSERT_EQ( 12, position.getPopIndexBB_1(bb));
    ASSERT_EQ( 21, position.getPopIndexBB_1(bb));
    ASSERT_EQ( 35, position.getPopIndexBB_1(bb));
    ASSERT_EQ( 64, position.getPopIndexBB_1(bb));
}


TEST(Position, getPopIndexBB_2)
{
    u64 bb{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    PositionMaker position{};
    ASSERT_EQ( 0, position.getPopIndexBB_2(bb));
    ASSERT_EQ( 5, position.getPopIndexBB_2(bb));
    ASSERT_EQ( 7, position.getPopIndexBB_2(bb));
    ASSERT_EQ( 12, position.getPopIndexBB_2(bb));
    ASSERT_EQ( 21, position.getPopIndexBB_2(bb));
    ASSERT_EQ( 35, position.getPopIndexBB_2(bb));
    ASSERT_EQ( 64, position.getPopIndexBB_2(bb));
}

TEST(Position, getPopIndexBB_3)
{
    u64 bb{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    PositionMaker position{};
    ASSERT_EQ( 0, position.getPopIndexBB_3(bb));
    ASSERT_EQ( 5, position.getPopIndexBB_3(bb));
    ASSERT_EQ( 7, position.getPopIndexBB_3(bb));
    ASSERT_EQ( 12, position.getPopIndexBB_3(bb));
    ASSERT_EQ( 21, position.getPopIndexBB_3(bb));
    ASSERT_EQ( 35, position.getPopIndexBB_3(bb));
//    ASSERT_EQ( 0, position.getPopIndexBB_3(bb));
}

TEST(Position, getPopIndexBB_4)
{
    u64 bb{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    PositionMaker position{};
    auto ret = position.getPopIndexBB_4(bb);
    ASSERT_EQ( 0, ret.first);
    ret = position.getPopIndexBB_4(ret.second);
    ASSERT_EQ( 5, ret.first);
    ret = position.getPopIndexBB_4(ret.second);
    ASSERT_EQ( 7, ret.first);
    ret = position.getPopIndexBB_4(ret.second);
    ASSERT_EQ( 12, ret.first);
    ret = position.getPopIndexBB_4(ret.second);
    ASSERT_EQ( 21, ret.first);
    ret = position.getPopIndexBB_4(ret.second);
    ASSERT_EQ( 35, ret.first);
    ret = position.getPopIndexBB_4(ret.second);
   // ASSERT_EQ( 0, ret.first);
}

TEST(Position, getPopIndexBB_5)
{
    u64 bb{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    PositionMaker position{};
    auto ret = position.getPopIndexBB_5(bb);
    ASSERT_EQ( 0, ret.first);
    ret = position.getPopIndexBB_5(ret.second);
    ASSERT_EQ( 5, ret.first);
    ret = position.getPopIndexBB_5(ret.second);
    ASSERT_EQ( 7, ret.first);
    ret = position.getPopIndexBB_5(ret.second);
    ASSERT_EQ( 12, ret.first);
    ret = position.getPopIndexBB_5(ret.second);
    ASSERT_EQ( 21, ret.first);
    ret = position.getPopIndexBB_5(ret.second);
    ASSERT_EQ( 35, ret.first);
    ret = position.getPopIndexBB_5(ret.second);
   // ASSERT_EQ( 0, ret.first);
}
