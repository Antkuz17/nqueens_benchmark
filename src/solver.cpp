#include "solver.hpp"

Solver::Solver(int n) : n_(n) {}

int Solver::board_size() const {
    return n_;
}