#ifndef TENTRIX_SANDBOX_HEADER_H
#define TENTRIX_SANDBOX_HEADER_H

#include <array>
#include <limits>
#include <string>
#include <numeric>

enum class side{ white, black};
namespace value{
    const int deep = 4 ;
    const int width = 3;
}

struct Coup{
    int piece;
    int position;
    std::string print() const {return std::string("P")+std::to_string(piece)+std::string("p")+std::to_string(position)+std::string("  ");}
};


//-------------------------------------------------

consteval int pow_int(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return a * pow_int(a, b-1);
    };
};

template<std::size_t size>
consteval std::array<double, size> build_eval_pos(){
    std::array<double, size> eval_pos{};
    std::iota(eval_pos.begin(), eval_pos.end(), size/2);
    return eval_pos;
};

static constexpr std::array<double, pow_int(value::width, value::deep) >eval_pos = build_eval_pos<pow_int(value::width, value::deep)>();
static auto eval_pos_iter = eval_pos.cbegin();


template<side T> std::array<Coup, value::width> compute_coups(int level);
template<> std::array<Coup, value::width> compute_coups<side::white>(int level){
    std::array<Coup, value::width> coups{};
    for (int iter = 0; iter < coups.size(); ++iter){
        coups[iter].piece = level;
        coups[iter].position = iter;
    }
    return coups;
};
template<> std::array<Coup, value::width> compute_coups<side::black>(int level){
    std::array<Coup, value::width> coups{};
    for (int iter = 0; iter < coups.size(); ++iter){
        coups[iter].piece = -level;
        coups[iter].position = -iter;
    }
    return coups;
};


template<side T> std::pair<double, std::array<Coup, value::deep>> eval_coups(std::array<Coup, value::deep>::size_type level, Coup coup);
template<> std::pair<double, std::array<Coup, value::deep>> eval_coups<side::white>(std::array<Coup, value::deep>::size_type level, Coup coup);
template<> std::pair<double, std::array<Coup, value::deep>> eval_coups<side::black>(std::array<Coup, value::deep>::size_type level, Coup coup);

template<>
std::pair<double, std::array<Coup, value::deep>> eval_coups<side::white>(std::array<Coup, value::deep>::size_type level, Coup coup) {
    auto eval = std::make_pair( std::numeric_limits<double>::min() , std::array<Coup, value::deep>{});
    if (level == value::deep-1){
        eval.first = (*eval_pos_iter);
        ++eval_pos_iter;
    }
    else {
        for (const auto& coup: compute_coups<side::white>(level)){
            if (auto eval_son = eval_coups<side::black>(level + 1, coup); eval.first < eval_son.first){
                eval = std::move(eval_son);
            }
        }
    }
    eval.second[level] = coup;
    return eval;
}

template<>
std::pair<double, std::array<Coup, value::deep>> eval_coups<side::black>(std::array<Coup, value::deep>::size_type level, Coup coup){
    auto eval = std::make_pair( std::numeric_limits<double>::max() , std::array<Coup, value::deep>{});
    if (level == value::deep-1){
        eval.first = (*eval_pos_iter);
        ++eval_pos_iter;
    }
    else {
        for (const auto& coup: compute_coups<side::black>(level)){
            if (auto eval_son = eval_coups<side::white>(level + 1, coup); eval.first > eval_son.first){
                eval = std::move(eval_son);
            }
        }
    }
    eval.second[level] = coup;
    return eval;
};

//-----------------------------------------------------------------
enum class NodeType{normal_white, normal_black, over_white, over_black, final_white, final_black};

template<NodeType node_type> struct Node{};

template<>
struct Node<NodeType::normal_white>{
    constexpr Node (Node& node_son, std::array<Coup, value::deep>::size_type level):
        level(level), son(node_son){};

    const std::array<Coup, value::deep>::size_type level;
    std::array<Coup, value::deep> variant;

    std::array<Coup, value::width> coups;
    //std::array<Coup, value::width>::const_iterator coup_end;
    Node& son;


    template<side T>
    std::pair<double, std::array<Coup, value::deep>> eval_coups() const;
};

//template<> std::pair<double, std::array<Coup, value::deep>> Node::eval_coups<side::white>() const;
//template<> std::pair<double, std::array<Coup, value::deep>> Node::eval_coups<side::black>() const;

//template<>
//std::pair<double, std::array<Coup, value::deep>> Node::eval_coups<side::white>() const{
//    double eval_score = std::numeric_limits<double>::min();
//    std::array<Coup, value::deep> line;
//    for (const auto& coup: coups){
//        if (auto eval_son = son.eval_coups<side::black>(); eval_score < eval_son.first){
//            line = std::move(eval_son.second);
//        }
//    }
//    return std::pair(eval_score, line);
//};

//template<>
//std::pair<double, std::array<Coup, value::deep>> Node::eval_coups<side::black>() const{
//    double eval_score = std::numeric_limits<double>::min();
//    std::array<Coup, value::deep> line;
//    return std::pair(eval_score, line);
//};

#endif
