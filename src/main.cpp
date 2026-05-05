#include <iostream>
#include "solvers/brute_force.hpp"
#include "solvers/backtracking.hpp"

void print_result(Solver& solver) {
    auto result = solver.solve();

    std::cout << solver.name() << " (N=" << solver.board_size() << ")\n";
    std::cout << "Nodes explored: " << result.nodes_explored << "\n";

    if (result.solution) {
        std::cout << "Solution: ";
        for (int col : *result.solution) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "No solution found.\n";
    }
    std::cout << "\n";
}

int main() {
    int n = 8;

    BruteForceSolver brute(n);
    BacktrackingSolver backtrack(n);

    print_result(brute);
    print_result(backtrack);

    return 0;
}