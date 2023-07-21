#ifndef _Graph_
#define _Graph_

#include "Vertex.h"
#include <vector>
#include <unordered_map>

/**
 * A class for representing graphs
 *
 * Public attributes:
 *   vertices: the vertices in the graph represented as a map that
 *     maps vertex names to instances of the Vertex class
 *
 * Public methods:
 *   add_vertex: Adds a vertex to the graph.
 *   get_vertex: Gets a vertex from the graph.
 **/
class Graph {
public:
std::unordered_map<std::string, Vertex*> vertices;

Graph() : vertices(std::unordered_map<std::string, Vertex*>()) {};

/** @brief vertex v to the graph
 *
 * @param v the vertex to add
 **/
void add_vertex(Vertex* v) { vertices[v->name] = v; }

/** @brief Get the vertex associated with a name
 *
 * @param name
 *
 * @return the Vertex associated with the name or null
 **/
Vertex* get_vertex(std::string name) {
    if (vertices.find(name) != vertices.end()) {
        return vertices[name];
    } else {
        return nullptr;
    }
}

std::string to_string() {
    std::string rv = "";
    std::unordered_map<std::string, Vertex*>::iterator pos;
    for (pos = vertices.begin(); pos != vertices.end(); ++pos) {
        rv += pos->first + "\n";
    }
    return rv;
}

};

#endif
