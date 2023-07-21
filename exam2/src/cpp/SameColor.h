#ifndef _SameColor_
#define _SameColor_

#include "Vertex.h"
#include "Graph.h"
#include <vector>
#include <unordered_map>
#include <string>

/** @brief Determine whether there is a same color path in the graph between
 * two vertices.
 *
 * @param g The graph to search
 * @param start the name of the source vertex
 * @param end the name of the destination vertex
 *
 * @return True if there is a path between start and end where
 * all nodes in the path are the same color, False otherwise.
 **/
bool has_same_color_path(Graph* g, std::string const &s, std::string const &d);

#endif
