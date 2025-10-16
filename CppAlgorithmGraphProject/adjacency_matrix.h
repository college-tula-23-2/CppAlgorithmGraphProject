#pragma once

#include "graph.h"

typedef std::vector<std::vector<int>> matrix;

class adjacency_matrix : public graph
{
	matrix _matrix;

	void create_matrix();

public:

	adjacency_matrix();
	adjacency_matrix(int vertexes);
	adjacency_matrix(names vertex_names);

	void add_edge(int vertex_one, int vertex_two) override;
	void add_edge(std::string vertex_one, int vertex_two) override;
	void add_edge(int vertex_one, std::string vertex_two) override;
	void add_edge(std::string vertex_one, std::string vertex_two) override;

	void add_edge(int vertex_one, int vertex_two, int weight);

	int add_vertex() override;
	int add_vertex(std::string vertex) override;

	void remove_edge(int vertex_one, int vertex_two) override;
	void remove_edge(std::string vertex_one, int vertex_two) override;
	void remove_edge(int vertex_one, std::string vertex_two) override;
	void remove_edge(std::string vertex_one, std::string vertex_two) override;

	int remove_vertex(int vertex) override;
	int remove_vertex(std::string vertex) override;

	bool adjacent(int vertex_one, int vertex_two) override;
	bool adjacent(std::string vertex_one, int vertex_two) override;
	bool adjacent(int vertex_one, std::string vertex_two) override;
	bool adjacent(std::string vertex_one, std::string vertex_two) override;
	
	std::vector<int> neighbors(int vertex) override;
	std::vector<int> neighbors(std::string vertex) override;

	std::vector<std::string> neighbors_names(int vertex) override;
	std::vector<std::string> neighbors_names(std::string vertex) override;

	int weight_edge(int vertex_one, int vertex_two);

	friend std::ostream& operator<<(
		std::ostream& out,
		const adjacency_matrix& graph);
};

