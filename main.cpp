
#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <array>
#include <algorithm>
#include <ranges>

// Include Projrct
#include "print.h"
#include "structure.h"
#include "move.h"
#include <benchmark/benchmark.h>

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
        u64 queen_move = position.computeMoveQueenWhite_1(15);
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


//int main()
//{
//    PositionLetter position_string{std::string{
//            "RNKQNR"
//            "PPPPPP"
//            "......"
//            "...q.."
//            "pp..pp"
//            "rnk.nr"
//        }};

//    print(position_string.getPawnsBB(), BB36 );

//    Position position{};
//    position.setPosition(position_string);
//    u64 queen_move = position.computeMoveQueenWhite(15);
//    print(queen_move);

////    for (u64 i = 0; i < 36; ++i){
////        std::cout <<i<<std::endl;
////        u64 mvmt(0);
////        for (u64 j = 0; j < 8; ++j){
////            mvmt |= movesQueen[i][j];
////        }
////        print(mvmt, BB36 );
////    }
//    return 0;
//}



