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

namespace {

    TEST(Position, computeMoveQueenWhite)
    {
        PositionMaker position{};
        u64 bb_move{};

        position.setPosition(PositionLetter{ "......"
                                             "......"
                                             "......"
                                             "......"
                                             "......"
                                             "q....." });
        bb_move = position.computeMoveQueenWhite(0);

        ASSERT_EQ(0b0000000000000000000000000000'100001'010001'001001'000101'000011'111110, bb_move);
        position.setPosition(PositionLetter{ "RNKQNR"
                                             "PPPPPP"
                                             "......"
                                             "......"
                                             "pppppp"
                                             "rnkqnr" });
        bb_move = position.computeMoveQueenWhite(3);
        ASSERT_EQ(0b0000000000000000000000000000'000000'000000'000000'000000'000000'000000, bb_move);

        position.setPosition(PositionLetter{ "RNKQNR"
                                             "PPPPPP"
                                             "......"
                                             "......"
                                             "ppp.pp"
                                             "rnkqnr" });
        bb_move = position.computeMoveQueenWhite(3);
        ASSERT_EQ(0b0000000000000000000000000000'000000'001000'001000'001000'001000'000000, bb_move);

        position.setPosition(PositionLetter{ "RNKQNR"
                                             "PPPPPP"
                                             "......"
                                             "...q.."
                                             "pp..pp"
                                             "rnk.nr" });
        bb_move = position.computeMoveQueenWhite(15);
        ASSERT_EQ(0b0000000000000000000000000000'000000'101010'011100'110111'001100'001000, bb_move);

        position.setPosition(PositionLetter{ "RNKQNq"
                                             "PPPPPp"
                                             "......"
                                             "......"
                                             "pppppp"
                                             "rnkqnr" });
        bb_move = position.computeMoveQueenWhite(35);
        ASSERT_EQ(0b0000000000000000000000000000'010000'010000'000000'000000'000000'000000, bb_move);
    }


    TEST(Position, computeMoveQueen_templated_white)
    {
        PositionMaker position{};
        u64 queen_move{};
        position.setPosition(PositionLetter{ "......"
                                             "......"
                                             "......"
                                             "......"
                                             "......"
                                             "q....." });
        queen_move = position.computeMoveQueen<white>(0);

        ASSERT_EQ(0b0000000000000000000000000000'100001'010001'001001'000101'000011'111110, queen_move);
        position.setPosition(PositionLetter{ "RNKQNR"
                                             "PPPPPP"
                                             "......"
                                             "......"
                                             "pppppp"
                                             "rnkqnr" });
        queen_move = position.computeMoveQueen<white>(3);
        ASSERT_EQ(0b0000000000000000000000000000'000000'000000'000000'000000'000000'000000, queen_move);

        position.setPosition(PositionLetter{ "RNKQNR"
                                             "PPPPPP"
                                             "......"
                                             "......"
                                             "ppp.pp"
                                             "rnkqnr" });
        queen_move = position.computeMoveQueen<white>(3);
        ASSERT_EQ(0b0000000000000000000000000000'000000'001000'001000'001000'001000'000000, queen_move);

        position.setPosition(PositionLetter{ "RNKQNR"
                                             "PPPPPP"
                                             "......"
                                             "...q.."
                                             "pp..pp"
                                             "rnk.nr" });
        queen_move = position.computeMoveQueen<white>(15);
        ASSERT_EQ(0b0000000000000000000000000000'000000'101010'011100'110111'001100'001000, queen_move);

        position.setPosition(PositionLetter{ "RNKQNq"
                                             "PPPPPp"
                                             "......"
                                             "......"
                                             "pppppp"
                                             "rnkqnr" });
        queen_move = position.computeMoveQueen<white>(35);
        ASSERT_EQ(0b0000000000000000000000000000'010000'010000'000000'000000'000000'000000, queen_move);
    }

    TEST(Position, computeMoveQueen_templated_black)
    {
        PositionMaker position{};
        u64 queen_move{};

        position.setPosition(PositionLetter{ "......"
                                             "......"
                                             "......"
                                             "......"
                                             "......"
                                             "Q....." });
        queen_move = position.computeMoveQueen<black>(0);

        ASSERT_EQ(0b0000000000000000000000000000'100001'010001'001001'000101'000011'111110, queen_move);
        position.setPosition(PositionLetter{ "RNKQNR"
                                             "PPPPPP"
                                             "......"
                                             "......"
                                             "pppppp"
                                             "rnkqnr" });
        queen_move = position.computeMoveQueen<black>(33);
        ASSERT_EQ(0b0000000000000000000000000000'000000'000000'000000'000000'000000'000000, queen_move);

        position.setPosition(PositionLetter{ "RNKQNR"
                                             "PPP.PP"
                                             "......"
                                             "......"
                                             "pppppp"
                                             "rnkqnr" });
        queen_move = position.computeMoveQueen<black>(33);
        ASSERT_EQ(0b0000000000000000000000000000'000000'001000'001000'001000'001000'000000, queen_move);

        position.setPosition(PositionLetter{ "RNK.NR"
                                             "PP..PP"
                                             "...Q.."
                                             "......"
                                             "pppppp"
                                             "rnkqnr" });
        queen_move = position.computeMoveQueen<black>(21);
        ASSERT_EQ(0b0000000000000000000000000000'001000'001100'110111'011100'101010'000000, queen_move);

        position.setPosition(PositionLetter{ "RNKQNR"
                                             "PPPPPP"
                                             "......"
                                             "......"
                                             "pppppP"
                                             "rnkqnQ" });
        queen_move = position.computeMoveQueen<black>(5);
        ASSERT_EQ(0b0000000000000000000000000000'000000'000000'000000'000000'010000'010000, queen_move);
    }
}
