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

    //TEST(Position, getPopIndexBB_1)
    //{
    //    u64 bb{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    //    PositionMaker position{};
    //    ASSERT_EQ( 0, position.getPopIndexBB_1(bb));
    //    ASSERT_EQ( 5, position.getPopIndexBB_1(bb));
    //    ASSERT_EQ( 7, position.getPopIndexBB_1(bb));
    //    ASSERT_EQ( 12, position.getPopIndexBB_1(bb));
    //    ASSERT_EQ( 21, position.getPopIndexBB_1(bb));
    //    ASSERT_EQ( 35, position.getPopIndexBB_1(bb));
    //    ASSERT_EQ( 64, position.getPopIndexBB_1(bb));
    //}
    //
    //
    //TEST(Position, getPopIndexBB_2)
    //{
    //    u64 bb{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    //    PositionMaker position{};
    //    ASSERT_EQ( 0, position.getPopIndexBB_2(bb));
    //    ASSERT_EQ( 5, position.getPopIndexBB_2(bb));
    //    ASSERT_EQ( 7, position.getPopIndexBB_2(bb));
    //    ASSERT_EQ( 12, position.getPopIndexBB_2(bb));
    //    ASSERT_EQ( 21, position.getPopIndexBB_2(bb));
    //    ASSERT_EQ( 35, position.getPopIndexBB_2(bb));
    //    ASSERT_EQ( 64, position.getPopIndexBB_2(bb));
    //}
    //
    //TEST(Position, getPopIndexBB_3)
    //{
    //    u64 bb{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    //    PositionMaker position{};
    //    ASSERT_EQ( 0, position.getPopIndexBB_3(bb));
    //    ASSERT_EQ( 5, position.getPopIndexBB_3(bb));
    //    ASSERT_EQ( 7, position.getPopIndexBB_3(bb));
    //    ASSERT_EQ( 12, position.getPopIndexBB_3(bb));
    //    ASSERT_EQ( 21, position.getPopIndexBB_3(bb));
    //    ASSERT_EQ( 35, position.getPopIndexBB_3(bb));
    ////    ASSERT_EQ( 0, position.getPopIndexBB_3(bb));
    //}

    TEST(Position, getPopIndexBB_4)
    {
        u64 bb{ 0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001 };
        PositionMaker position{};
        auto ret = position.getPopIndexBB_4(bb);
        ASSERT_EQ(0, ret.first);
        ret = position.getPopIndexBB_4(ret.second);
        ASSERT_EQ(5, ret.first);
        ret = position.getPopIndexBB_4(ret.second);
        ASSERT_EQ(7, ret.first);
        ret = position.getPopIndexBB_4(ret.second);
        ASSERT_EQ(12, ret.first);
        ret = position.getPopIndexBB_4(ret.second);
        ASSERT_EQ(21, ret.first);
        ret = position.getPopIndexBB_4(ret.second);
        ASSERT_EQ(35, ret.first);
        ret = position.getPopIndexBB_4(ret.second);
        // ASSERT_EQ( 0, ret.first);
    }

    TEST(Position, getPopIndexBB_5)
    {
        u64 bb{ 0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001 };
        PositionMaker position{};
        auto ret = position.getPopIndexBB_5(bb);
        ASSERT_EQ(0, ret.first);
        ret = position.getPopIndexBB_5(ret.second);
        ASSERT_EQ(5, ret.first);
        ret = position.getPopIndexBB_5(ret.second);
        ASSERT_EQ(7, ret.first);
        ret = position.getPopIndexBB_5(ret.second);
        ASSERT_EQ(12, ret.first);
        ret = position.getPopIndexBB_5(ret.second);
        ASSERT_EQ(21, ret.first);
        ret = position.getPopIndexBB_5(ret.second);
        ASSERT_EQ(35, ret.first);
        ret = position.getPopIndexBB_5(ret.second);
        // ASSERT_EQ( 0, ret.first);
    }
}
