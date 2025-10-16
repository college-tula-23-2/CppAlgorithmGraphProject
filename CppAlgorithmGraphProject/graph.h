#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <exception>
#include <map>
#include <set>

typedef std::vector<std::string> names;

class graph
{
protected:
	int _vertexes;
	int _edges;

	names _vertex_names;

	int vertex_maxlength() const;

public:
	graph();
	graph(int vertexes, int edges);
	graph(names vertex_names);

	int vertices();
	int edges();

	int vertex_index(std::string vertex);

	virtual void add_edge(int vertex_one, int vertex_two) = 0;
	virtual void add_edge(std::string vertex_one, int vertex_two) = 0;
	virtual void add_edge(int vertex_one, std::string vertex_two) = 0;
	virtual void add_edge(std::string vertex_one, std::string vertex_two) = 0;

	virtual void remove_edge(int vertex_one, int vertex_two) = 0;
	virtual void remove_edge(std::string vertex_one, int vertex_two) = 0;
	virtual void remove_edge(int vertex_one, std::string vertex_two) = 0;
	virtual void remove_edge(std::string vertex_one, std::string vertex_two) = 0;

	virtual int add_vertex() = 0;
	virtual int add_vertex(std::string vertex) = 0;

	virtual int remove_vertex(int vertex) = 0;
	virtual int remove_vertex(std::string vertex) = 0;

	virtual bool adjacent(int vertex_one, int vertex_two) = 0;
	virtual bool adjacent(std::string vertex_one, int vertex_two) = 0;
	virtual bool adjacent(int vertex_one, std::string vertex_two) = 0;
	virtual bool adjacent(std::string vertex_one, std::string vertex_two) = 0;

	virtual std::vector<int> neighbors(int vertex) = 0;
	virtual std::vector<int> neighbors(std::string vertex) = 0;

	virtual std::vector<std::string> neighbors_names(int vertex) = 0;
	virtual std::vector<std::string> neighbors_names(std::string vertex) = 0;

	virtual ~graph() {}
};

