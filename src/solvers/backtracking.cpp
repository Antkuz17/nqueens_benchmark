#include "solvers/backtracking.hpp"
#include <cmath>

BacktrackingSolver::BacktrackingSolver(int n) : Solver(n) {}

std::string BacktrackingSolver::name() const {
    return "Backtracking";
}

bool BacktrackingSolver::is_safe(const std::vector<int>& board, int row, int col) const {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col) return false;
        if (std::abs(i - row) == std::abs(board[i] - col)) return false;
    }
    return true;
}

bool BacktrackingSolver::solve_recursive(int row, std::vector<int>& board, uint64_t& nodes) {
    if (row == n_) return true;

    for (int col = 0; col < n_; ++col) {
        ++nodes;
        if (is_safe(board, row, col)) {
            board[row] = col;
            if (solve_recursive(row + 1, board, nodes)) return true;
        }
    }
    return false;
}

SolverResult BacktrackingSolver::solve() {
    SolverResult result;
    result.nodes_explored = 0;

    std::vector<int> board(n_, -1);

    if (solve_recursive(0, board, result.nodes_explored)) {
        result.solution = board;
    }

    return result;
}