#include "demukron.h"
#include <bitset>

enum class VertexColor {
    White,
    Grey,
    Black
};


void hgraphCreation(std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& hgraph)
{
    size_t vertexNumber = 0;
    for(auto& vertexBase: graph)
    {
        for(auto& vertex: vertexBase)
        {
            if(vertex < static_cast<int>(hgraph.size()))
                hgraph[vertex].push_back(vertexNumber);
        }
        vertexNumber++;
    }
}

bool isAllVerteciesUsed(std::vector<bool>& used)
{
    for(const auto& vertexMark: used)
        if(!vertexMark)
            return false;
    return true;
}

bool isAllVerticiesInUsed(std::vector<bool>& used, std::vector<int>& vec)
{
    for(const auto& vertex: vec)
        if(!used[static_cast<size_t>(vertex)])
            return false;
    return true;
}

std::vector<std::vector<int>> graphs::demukronSort(std::vector<std::vector<int> > &graph)
{
    std::vector<std::vector<int>> result;
    std::vector<std::vector<int>> hgraph(graph.size());
    std::vector<bool> used(graph.size(), false);

    hgraphCreation(graph, hgraph);
    int vertexCounter = 0;

    std::vector<int> level;
    while(!isAllVerteciesUsed(used))
    {
        for(auto& vec: hgraph)
        {
          if((vec.empty() || isAllVerticiesInUsed(used, vec)) && !used[static_cast<size_t>(vertexCounter)])
              level.push_back(vertexCounter);
          vertexCounter++;
        }

        for(auto& vertex: level)
            used[static_cast<size_t>(vertex)] = true;

        result.push_back(level);
        level.clear();
        vertexCounter = 0;
    }

    return result;
}

bool DFS(int vertex, std::stack<int>& vertexConseq, std::vector<VertexColor>& color, std::vector<std::vector<int>>& graph)
{
    color[static_cast<size_t>(vertex)] = VertexColor::Grey;
    for(auto& otherVertex: graph[static_cast<size_t>(vertex)])
    {
        if(color[static_cast<size_t>(otherVertex)] == VertexColor::White && !DFS(otherVertex, vertexConseq, color, graph))
            return false;
        else if(color[static_cast<size_t>(otherVertex)] == VertexColor::Grey)
            return false;
    }

    color[static_cast<size_t>(vertex)] = VertexColor::Black;
    vertexConseq.push(vertex);
    return true;
}

std::vector<int> graphs::tarianSort(std::vector<std::vector<int>>& graph)
{
    std::vector<VertexColor> color(graph.size(), VertexColor::White);
    std::stack<int> vertexConseq;
    std::vector<int> result;

    for(int i = 0; i < static_cast<int>(graph.size()); i++)
        if(color[static_cast<size_t>(i)] == VertexColor::White)
            DFS(i, vertexConseq, color, graph);

    for(int i = 0; i < static_cast<int>(graph.size()); i++)
    {
        auto top = vertexConseq.top();
        result.push_back(top);
        vertexConseq.pop();
    }
    return result;
}
