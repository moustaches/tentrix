
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



static void BM_computeMoveQueenWhite_1(benchmark::State& state) {
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
    for (auto _ : state)
        u64 queen_move = position.computeMoveQueenWhite(15);
}
BENCHMARK(BM_computeMoveQueenWhite_1);

static void BM_computeMoveQueenWhite_2(benchmark::State& state) {
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
    for (auto _ : state)
        u64 queen_move = position.computeMoveQueenWhite_2(15);
}
BENCHMARK(BM_computeMoveQueenWhite_2);


BENCHMARK_MAIN();





