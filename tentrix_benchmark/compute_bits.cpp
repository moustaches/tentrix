
// Include Project
#include "tentrix/print.h"
#include "tentrix/structure.h"
#include "tentrix/move.h"

// Include 3rd-part
#include <benchmark/benchmark.h>

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



// Only for gcc because std::bitset._Find_first() only define there
#if defined(__GNUC__) || defined(__GNUG__)
static void BM_getPopIndexBB_1(benchmark::State& state) {
    PositionMaker position{};
    int index;
    u64 bb_0{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    for (auto _ : state){
        u64 bb {bb_0};
        for (int i = 0; i<8; ++i){
            index = position.getPopIndexBB_1(bb);
        }
    };
}

static void BM_getPopIndexBB_2(benchmark::State& state) {
    PositionMaker position{};
    int index;
    u64 bb_0{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    for (auto _ : state){
        u64 bb {bb_0};
        for (int i = 0; i<8; ++i){
            index = position.getPopIndexBB_1(bb);
        }
    };
}

static void BM_getPopIndexBB_3(benchmark::State& state) {
    PositionMaker position{};
    int index;
    u64 bb_0{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    for (auto _ : state){
        u64 bb {bb_0};
        for (int i = 0; i<8; ++i){
            index = position.getPopIndexBB_1(bb);
        }
    };
}
#endif

static void BM_getPopIndexBB_4(benchmark::State& state) {
    PositionMaker position{};
    int index;
    u64 bb_0{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    for (auto _ : state){
        u64 bb {bb_0};
        for (int i = 0; i<8; ++i){
            auto ret = position.getPopIndexBB_4(bb);
            bb = ret.second;
        }
    };
}

static void BM_getPopIndexBB_5(benchmark::State& state) {
    PositionMaker position{};
    int index;
    u64 bb_0{0b0000000000000000000000000000'100000'000000'001000'000001'000010'100001};
    for (auto _ : state){
        u64 bb {bb_0};
        for (int i = 0; i<8; ++i){
            auto ret = position.getPopIndexBB_5(bb);
            bb = ret.second;
        }
    };
}


BENCHMARK(BM_getPopIndexBB_5);
BENCHMARK(BM_getPopIndexBB_4);

// Only for gcc because std::bitset._Find_first() only define there
#if defined(__GNUC__) || defined(__GNUG__)
BENCHMARK(BM_getPopIndexBB_3);
BENCHMARK(BM_getPopIndexBB_2);
BENCHMARK(BM_getPopIndexBB_1);
#endif








