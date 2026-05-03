#ifndef NQUEENS_BACKTRACKING_HPP
#define NQUEENS_BACKTRACKING_HPP

#include "solver.hpp"

class BacktrackingSolver : public Solver {
public:
    explicit BacktrackingSolver(int n);

    SolverResult solve() override;
    std::string name() const override;

private:
    bool solve_recursive(int row, std::vector<int>& board, uint64_t& nodes);
    bool is_safe(const std::vector<int>& board, int row, int col) const;
};

#endif // NQUEENS_BACKTRACKING_HPP