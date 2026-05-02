#ifndef NQUEENS_BRUTE_FORCE_HPP
#define NQUEENS_BRUTE_FORCE_HPP

#include "solver.hpp"

class BruteForceSolver : public Solver {
public:
    explicit BruteForceSolver(int n);

    SolverResult solve() override;
    std::string name() const override;
};

#endif // NQUEENS_BRUTE_FORCE_HPP