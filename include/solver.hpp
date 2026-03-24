#ifndef NQUEENS_SOLVER_HPP
#define NQUEENS_SOLVER_HPP

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

struct SolverResult {
    std::optional<std::vector<int>> solution;  // Column position per row, or nullopt if no solution
    uint64_t nodes_explored = 0;
    double time_seconds = 0.0;
};

// Base class for all solvers.
// Each solver takes a board size N and produces a SolverResult.
class Solver {
public:
    explicit Solver(int n);
    virtual ~Solver() = default;

    virtual SolverResult solve() = 0;
    virtual std::string name() const = 0;

    int board_size() const;

protected:
    int n_;
};

#endif // NQUEENS_SOLVER_HPP