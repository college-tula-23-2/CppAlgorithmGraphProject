#include "adjacency_matrix.h"

void adjacency_matrix::create_matrix()
{
	_matrix.resize(_vertexes);
	for (int i{}; i < _matrix.size(); i++)
		_matrix[i].resize(_vertexes, 0);
}

adjacency_matrix::adjacency_matrix()
	: adjacency_matrix(0){}

adjacency_matrix::adjacency_matrix(int vertexes)
	: graph(vertexes, 0)
{
	this->create_matrix();
}

adjacency_matrix::adjacency_matrix(names vertex_names)
	: graph(vertex_names)
{
	this->create_matrix();
}

void adjacency_matrix::add_edge(int vertex_one, int vertex_two)
{
	if (vertex_one < 0 || vertex_one >= _vertexes 
		|| vertex_two< 0 || vertex_two >= _vertexes)
		throw std::exception("index of vertex out of range");
	
	_matrix[vertex_one][vertex_two] = 1;
	_matrix[vertex_two][vertex_one] = 1;

	_edges++;
}

void adjacency_matrix::add_edge(std::string vertex_one, int vertex_two)
{
	this->add_edge(vertex_index(vertex_one), vertex_two);
}

void adjacency_matrix::add_edge(int vertex_one, std::string vertex_two)
{
	this->add_edge(vertex_one, vertex_index(vertex_two));
}

void adjacency_matrix::add_edge(std::string vertex_one, std::string vertex_two)
{
	this->add_edge(vertex_index(vertex_one), vertex_index(vertex_two));
}

void adjacency_matrix::add_edge(int vertex_one, int vertex_two, int weight)
{
	if (vertex_one < 0 || vertex_one >= _vertexes
		|| vertex_two < 0 || vertex_two >= _vertexes)
		throw std::exception("index of vertex out of range");

	_matrix[vertex_one][vertex_two] = weight;
	_matrix[vertex_two][vertex_one] = weight;

	_edges++;
}

int adjacency_matrix::add_vertex()
{
	_vertexes++;

	_matrix.resize(_vertexes);
	
	for (int i{}; i < _vertexes; i++)
		_matrix[i].resize(_vertexes, 0);
	
	_vertex_names.resize(_vertexes, "");

	return _vertexes;
}

int adjacency_matrix::add_vertex(std::string vertex)
{
	this->add_vertex();
	this->_vertex_names.back() = vertex;
	
	return _vertexes;
}

int adjacency_matrix::remove_vertex(int vertex)
{
	if (vertex < 0 || vertex >= _vertexes)
		throw std::exception("index of vertex out of range");

	_matrix.erase(_matrix.begin() + vertex);
	for (int i{}; i < _vertexes - 1; i++)
		_matrix[i].erase(_matrix[i].begin() + vertex);

	_vertex_names.erase(_vertex_names.begin() + vertex);

	_vertexes--;

	return _vertexes;
}

int adjacency_matrix::remove_vertex(std::string vertex)
{
	return this->remove_vertex(vertex_index(vertex));
}

bool adjacency_matrix::adjacent(int vertex_one, int vertex_two)
{
	return _matrix[vertex_one][vertex_two];
}

bool adjacency_matrix::adjacent(std::string vertex_one, int vertex_two)
{
	return this->adjacent(vertex_index(vertex_one), vertex_two);
}

bool adjacency_matrix::adjacent(int vertex_one, std::string vertex_two)
{
	return this->adjacent(vertex_one, vertex_index(vertex_two));
}

bool adjacency_matrix::adjacent(std::string vertex_one, std::string vertex_two)
{
	return this->adjacent(vertex_index(vertex_one), vertex_index(vertex_two));
}

std::vector<int> adjacency_matrix::neighbors(int vertex)
{
	std::vector<int> neighbors;
	for (int i{}; i < _vertexes; i++)
		if (i != vertex && _matrix[vertex][i])
			neighbors.push_back(i);
	return neighbors;
}

std::vector<int> adjacency_matrix::neighbors(std::string vertex)
{
	return this->neighbors(vertex_index(vertex));
}

std::vector<std::string> adjacency_matrix::neighbors_names(int vertex)
{
	std::vector<std::string> neighbors;

	for (int i{}; i < _vertexes; i++)
		if (i != vertex && _matrix[vertex][i])
			neighbors.push_back(_vertex_names[i]);
	return neighbors;
}

std::vector<std::string> adjacency_matrix::neighbors_names(std::string vertex)
{
	return this->neighbors_names(vertex_index(vertex));
}

int adjacency_matrix::weight_edge(int vertex_one, int vertex_two)
{
	return _matrix[vertex_one][vertex_two];
}



void adjacency_matrix::remove_edge(int vertex_one, int vertex_two)
{
	if (vertex_one < 0 || vertex_one >= _vertexes
		|| vertex_two < 0 || vertex_two >= _vertexes)
		throw std::exception("index of vertex out of range");

	_matrix[vertex_one][vertex_two] = 0;
	_matrix[vertex_two][vertex_one] = 0;

	_edges--;
}

void adjacency_matrix::remove_edge(std::string vertex_one, int vertex_two)
{
	int vertex_one_index
		= std::distance(_vertex_names.begin(),
			std::ranges::find(_vertex_names, vertex_one));
	this->remove_edge(vertex_one_index, vertex_two);
}

void adjacency_matrix::remove_edge(int vertex_one, std::string vertex_two)
{
	int vertex_two_index
		= std::distance(_vertex_names.begin(),
			std::ranges::find(_vertex_names, vertex_two));
	this->remove_edge(vertex_one, vertex_two_index);
}

void adjacency_matrix::remove_edge(std::string vertex_one, std::string vertex_two)
{
	int vertex_one_index
		= std::distance(_vertex_names.begin(),
			std::ranges::find(_vertex_names, vertex_one));
	int vertex_two_index
		= std::distance(_vertex_names.begin(),
			std::ranges::find(_vertex_names, vertex_two));
	this->remove_edge(vertex_one_index, vertex_two_index);
}



std::ostream& operator<<(std::ostream& out, const adjacency_matrix& graph)
{
	int length_max = graph.vertex_maxlength();

	for (int row{}; row < graph._vertexes + 1; row++)
	{
		if (!row)
		{
			out << std::setw(length_max + 1) << "";
			for (int i{}; i < graph._vertexes; i++)
			{
				out << std::setw(length_max + 1);
				if (graph._vertex_names[i].length() > 0)
					out << graph._vertex_names[i];
				else
					out << i;
			}
		}
		else
		{
			out << std::setw(length_max + 1);
			if (graph._vertex_names[row - 1].length() > 0)
				out << graph._vertex_names[row - 1];
			else
				out << row - 1;

			for (auto weight : graph._matrix[row - 1])
				out << std::setw(length_max + 1) << weight;

		}
		std::cout << std::endl;
	}

	return out;
}
