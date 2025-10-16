#include <iostream>
#include <vector>
#include <limits>

#include "adjacency_matrix.h"
#include "adjacency_list.h"

void report_print(std::vector<int> distances, std::vector<int> parents, std::vector<bool> visited)
{
    for (int i{}; i < distances.size(); i++)
    {
        std::cout << "visited[" << i << "]=" << ((visited[i]) ? "true" : "false")
            << "\tdistance[" << i << "]=" << distances[i]
            << "\tparent[" << i << "]=" << parents[i] << "\n";
    }
    std::cout << "\n";
}

int main()
{
    int vertexes_count{ 9 };
    adjacency_matrix graph(vertexes_count);
    

    graph.add_edge(0, 2, 3);
    graph.add_edge(1, 2, 1);
    graph.add_edge(1, 4, 3);
    graph.add_edge(1, 5, 2);
    graph.add_edge(1, 6, 5);
    graph.add_edge(2, 3, 3);
    graph.add_edge(3, 6, 7);
    graph.add_edge(4, 5, 8);
    graph.add_edge(4, 6, 1);
    graph.add_edge(5, 7, 6);
    graph.add_edge(5, 8, 1);
    graph.add_edge(6, 7, 2);

    std::cout << graph << "\n";

    std::vector<int> distances(vertexes_count, std::numeric_limits<int>::max());
    std::vector<int> parents(vertexes_count, -1);
    std::vector<bool> visited(vertexes_count, false);

    int current{ 4 };

    distances[current] = 0;

    

    while (true)
    {
        report_print(distances, parents, visited);

        int current{};
        for (; current < vertexes_count; current++)
            if (!visited[current])
                break;

        for (int v{}; v < vertexes_count; v++)
            if (!visited[v] && distances[v] < distances[current])
                current = v;

        visited[current] = true;

        for (int neighbor{}; neighbor < vertexes_count; neighbor++)
        {
            if (int weight = graph.weight_edge(current, neighbor))
            {
                if (distances[neighbor] > distances[current] + weight)
                {
                    distances[neighbor] = distances[current] + weight;
                    parents[neighbor] = current;
                }
            }
            
        }

        bool isFinish{ true };
        for (int v{}; v < vertexes_count; v++)
            isFinish = isFinish && visited[v];
        if (isFinish)
            break;
    }

    report_print(distances, parents, visited);
}
