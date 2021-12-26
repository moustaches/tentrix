
// Include Project
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



static void BM_computeMoveQueenWhite(benchmark::State& state) {
    PositionLetter position_string{std::string{
            "RNKQNR"
            "PPPPPP"
            "......"
            "...q.."
            "pp..pp"
            "rnk.nr"
        }};
    PositionMaker position{};
    position.setPosition(position_string);
    for (auto _ : state)
        u64 bb_moves = position.computeMoveQueenWhite(15);
}

static void BM_computeMoveQueen_templated(benchmark::State& state) {
    PositionLetter position_string{std::string{
            "RNKQNR"
            "PPPPPP"
            "......"
            "...q.."
            "pp..pp"
            "rnk.nr"
        }};
    PositionMaker position{};
    position.setPosition(position_string);
    for (auto _ : state)
        u64 bb_moves = position.computeMoveQueen<white>(std::size_t{15});
}


static void BM_computeMoveKnight_templated(benchmark::State& state) {
    PositionLetter position_string{std::string{
            "RNKQNR"
            "PPPPPP"
            "......"
            "...n.."
            "pp..pp"
            "rnkq.r"
        }};
    PositionMaker position{};
    position.setPosition(position_string);
    for (auto _ : state)
        u64 bb_moves = position.computeMoveKnight<white>(std::size_t{15});
}

BENCHMARK(BM_computeMoveQueenWhite);
BENCHMARK(BM_computeMoveQueen_templated);
BENCHMARK(BM_computeMoveKnight_templated);

BENCHMARK_MAIN();








