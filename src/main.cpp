#include <iostream>
#include "solvers/brute_force.hpp"

int main() {
    BruteForceSolver solver(8);
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

    return 0;
}