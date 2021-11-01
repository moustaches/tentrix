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


TEST(Foo, Sum)
{
    PositionLetter position_string{std::string{
            "RNKQNR"
            "PPPPPP"
            "......"
            "...q.."
            "pp..pp"
            "rnk.nr"
        }};
    Position position{};
    position.setPosition(position_string);
    u64 queen_move = position.computeMoveQueenWhite_1(15);
    EXPECT_EQ(2, 1 + 1);
}



