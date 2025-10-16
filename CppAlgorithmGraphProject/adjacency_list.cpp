#include "adjacency_list.h"

void adjacency_list::create_list()
{
	for (int i{}; i < _vertexes; i++)
		list.insert(std::pair(i, std::set<int>()));
}

adjacency_list::adjacency_list()
	: adjacency_list(0) {}

adjacency_list::adjacency_list(int vertexes) 
	: graph(vertexes, 0)
{
	this->create_list();
}

adjacency_list::adjacency_list(names vertexes)
	: graph(vertexes)
{
	this->create_list();
}

void adjacency_list::add_edge(int vertex_one, int vertex_two)
{
	list[vertex_one].insert(vertex_two);
	list[vertex_two].insert(vertex_one);

	_edges++;
}

void adjacency_list::add_edge(std::string vertex_one, int vertex_two)
{
	this->add_edge(vertex_index(vertex_one), vertex_two);
}

void adjacency_list::add_edge(int vertex_one, std::string vertex_two)
{
	this->add_edge(vertex_one, vertex_index(vertex_two));
}

void adjacency_list::add_edge(std::string vertex_one, std::string vertex_two)
{
	this->add_edge(vertex_index(vertex_one), vertex_index(vertex_two));
}

int adjacency_list::add_vertex()
{
	list.insert(std::pair(_vertexes, std::set<int>()));
	_vertexes++;

	_vertex_names.resize(_vertexes, "");

	return _vertexes;
}

int adjacency_list::add_vertex(std::string vertex)
{
	this->add_vertex();
	_vertex_names.back() = vertex;

	return _vertexes;
}

int adjacency_list::remove_vertex(int vertex)
{
	auto vertex_remove = list.find(vertex);
	list.erase(vertex_remove);

	for (auto vertex_adj_list : list)
	{
		vertex_adj_list.second.extract(vertex);
	}

	_vertexes--;
	return 0;
}

std::ostream& operator<<(std::ostream& out, const adjacency_list& graph)
{
	int length_max = graph.vertex_maxlength();

	for (auto vertex : graph.list)
	{
		out << std::setw(length_max + 1);
		
		if (graph._vertex_names[vertex.first].length() > 0)
			out << graph._vertex_names[vertex.first];
		else
			out << vertex.first;

		out << ": ";

		for (auto adj_vertex : vertex.second)
		{
			out << std::setw(length_max + 1);

			if (graph._vertex_names[adj_vertex].length() > 0)
				out << graph._vertex_names[adj_vertex];
			else
				out << adj_vertex;
		}

		out << std::endl;
	}

	return out;
}
