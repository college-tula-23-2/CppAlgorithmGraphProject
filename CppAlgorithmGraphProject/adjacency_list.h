#pragma once

#include "graph.h"

typedef std::map<int, std::set<int>> vertex_list;

class adjacency_list : public graph
{
protected:
	vertex_list list;

	void create_list();

public:
	adjacency_list();
	adjacency_list(int vertexes);
	adjacency_list(names vertexes);

	void add_edge(int vertex_one, int vertex_two) override;
	void add_edge(std::string vertex_one, int vertex_two) override;
	void add_edge(int vertex_one, std::string vertex_two) override;
	void add_edge(std::string vertex_one, std::string vertex_two) override;

	int add_vertex() override;
	int add_vertex(std::string vertex) override;

	void remove_edge(int vertex_one, int vertex_two) override {};
	void remove_edge(std::string vertex_one, int vertex_two) override {};
	void remove_edge(int vertex_one, std::string vertex_two) override {};
	void remove_edge(std::string vertex_one, std::string vertex_two) override {};

	int remove_vertex(int vertex) override;
	int remove_vertex(std::string vertex) override { return 0; };

	bool adjacent(int vertex_one, int vertex_two) override { return 0; };
	bool adjacent(std::string vertex_one, int vertex_two) override { return 0; };
	bool adjacent(int vertex_one, std::string vertex_two) override { return 0; };
	bool adjacent(std::string vertex_one, std::string vertex_two) override { return 0; };

	std::vector<int> neighbors(int vertex) override { return std::vector<int>(0); };
	std::vector<int> neighbors(std::string vertex) override { return std::vector<int>(0); };

	std::vector<std::string> neighbors_names(int vertex) override { return std::vector<std::string>(0); };
	std::vector<std::string> neighbors_names(std::string vertex) override { return std::vector<std::string>(0); };

	friend std::ostream& operator<<(std::ostream& out, const adjacency_list& graph);
	

};

