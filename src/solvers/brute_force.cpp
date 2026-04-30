#include "solvers/brute_force.hpp"
#include <cmath>

BruteForceSolver::BruteForceSolver(int n) : Solver(n) {}

std::string BruteForceSolver::name() const {
    return "Brute Force";
}

bool is_valid(const std::vector<int>& board) {
    for (int i = 0; i < static_cast<int>(board.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(board.size()); ++j) {
            if (board[i] == board[j]) return false;
            if (std::abs(i - j) == std::abs(board[i] - board[j])) return false;
        }
    }
    return true;
}

SolverResult BruteForceSolver::solve() {
    SolverResult result;
    result.nodes_explored = 0;

    std::vector<int> board(n_, 0);

    while (true) {
        ++result.nodes_explored;

        if (is_valid(board)) {
            result.solution = board;
            return result;
        }

        // Increment the board like an odometer
        int row = n_ - 1;
        while (row >= 0) {
            ++board[row];
            if (board[row] < n_) break;
            board[row] = 0;
            --row;
        }

        // If row went below 0, we've tried everything
        if (row < 0) return result;
    }
}