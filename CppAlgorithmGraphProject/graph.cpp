#include "graph.h"

int graph::vertex_maxlength() const
{
	auto longest = [](std::string left, std::string right)
		{
			return left.length() < right.length();
		};

	int length_max = std::ranges::max(_vertex_names, longest).length();
	if (!length_max) length_max = std::to_string(_vertexes).length();

	return length_max;
}

graph::graph() : graph(0, 0) {}

graph::graph(int vertexes, int edges)
	: _vertexes{ vertexes }, _edges{ edges } 
{
	_vertex_names.resize(_vertexes, "");
}

graph::graph(names vertex_names)
	: _vertexes{ (int)vertex_names.size() }, _edges{}
{
	std::ranges::copy(vertex_names.begin(),
					vertex_names.end(),
					std::back_inserter(_vertex_names));
}

int graph::vertices() { return _vertexes; }

int graph::edges() { return _edges; }

int graph::vertex_index(std::string vertex)
{
	return std::distance(_vertex_names.begin(),
		std::ranges::find(_vertex_names, vertex));
}

