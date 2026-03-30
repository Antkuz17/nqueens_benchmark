#include <iostream>
#include "solvers/brute_force.hpp"

int main() {
    BruteForceSolver solver(8);
    auto result = solver.solve();

    if (result.solution) {
        std::cout << solver.name() << " found a solution for N=" << solver.board_size() << "\n";
        for (int col : *result.solution) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << solver.name() << " found no solution.\n";
    }

    return 0;
}