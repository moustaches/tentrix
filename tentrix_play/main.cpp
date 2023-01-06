
// Include Project
#include "tentrix/print.h"
#include "tentrix/structure.h"
#include "tentrix/move.h"

// Include STD
#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <array>
#include <algorithm>
#include <ranges>
#include <variant>
#include <vector>

using namespace std;
using u64 = uint64_t;



int main()
{
    PositionLetter position_string{std::string{
            "RNKQNR"
            "PPPPPP"
            "......"
            "...q.."
            "pp..pp"
            "rnk.nr"
        }};

    print(position_string.getPawnsBB(), BB36 );

    PositionMaker position{};
    position.setPosition(position_string);



    return 0;
}



