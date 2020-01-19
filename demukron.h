#pragma once

#include <vector>
#include <stack>

namespace graphs {
    std::vector<std::vector<int>> demukronSort(std::vector<std::vector<int>>& graph);
    std::vector<int> tarianSort(std::vector<std::vector<int>>& graph);
}
