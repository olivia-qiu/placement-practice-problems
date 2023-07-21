#ifndef _Vertex_
#define _Vertex_

#include <vector>
#include <string>

/**
 * A class for representing vertices in a graph.
 *
 * Public attributes:
 *   name: The name of the vertex.
 *   color: The color of the vertex.
 *   neighbors: A list of the neighbors of this vertex
 *    (Vertex v is a neighbor of Vertex w, if the graph
       contains a directed edge from w to v.)
 *
 * Public methods:
 *   add_edge: Adds an from this vertex to another vertex
 **/
class Vertex {
public:
std::string name;
std::string color;
std::vector<Vertex*> neighbors;

Vertex(std::string const &_name, std::string const &_color)
: name(_name), color(_color), neighbors(std::vector<Vertex*>()) {}

void addEdge(Vertex* v) {
    neighbors.push_back(v);
}

std::string to_string() const {
    std::string rv = name + " (" + color + "):";
    for (auto v : neighbors) {
        rv += v->name;
    }
    return rv;
}

};

#endif
