#include <iostream>

#include "adjacency_matrix.h"
#include "adjacency_list.h"

int main()
{
    adjacency_matrix graph(9);
    

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


}
