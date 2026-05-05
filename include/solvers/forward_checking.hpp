#ifndef NQUEENS_FORWARD_CHECKING_HPP
#define NQUEENS_FORWARD_CHECKING_HPP

#include "solver.hpp"
#include <vector>

class ForwardCheckingSolver : public Solver {
public:
    explicit ForwardCheckingSolver(int n);

    SolverResult solve() override;
    std::string name() const override;

private:
    bool solve_recursive(int row, std::vector<int>& board,
                         std::vector<bool>& cols,
                         std::vector<bool>& diag1,
                         std::vector<bool>& diag2,
                         uint64_t& nodes);
};

#endif // NQUEENS_FORWARD_CHECKING_HPP