#include "solvers/forward_checking.hpp"

ForwardCheckingSolver::ForwardCheckingSolver(int n) : Solver(n) {}

std::string ForwardCheckingSolver::name() const {
    return "Forward Checking";
}

bool ForwardCheckingSolver::solve_recursive(int row, std::vector<int>& board,
                                            std::vector<bool>& cols,
                                            std::vector<bool>& diag1,
                                            std::vector<bool>& diag2,
                                            uint64_t& nodes) {
    if (row == n_) return true;

    for (int col = 0; col < n_; ++col) {
        ++nodes;
        if (!cols[col] && !diag1[row + col] && !diag2[row - col + n_ - 1]) {
            board[row] = col;
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n_ - 1] = true;

            if (solve_recursive(row + 1, board, cols, diag1, diag2, nodes)) return true;

            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n_ - 1] = false;
        }
    }
    return false;
}

SolverResult ForwardCheckingSolver::solve() {
    SolverResult result;
    result.nodes_explored = 0;

    std::vector<int> board(n_, -1);
    std::vector<bool> cols(n_, false);
    std::vector<bool> diag1(2 * n_ - 1, false);
    std::vector<bool> diag2(2 * n_ - 1, false);

    if (solve_recursive(0, board, cols, diag1, diag2, result.nodes_explored)) {
        result.solution = board;
    }

    return result;
}