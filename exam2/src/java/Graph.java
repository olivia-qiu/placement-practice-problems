import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

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

public class Graph {
    public Map<String, Vertex> vertices;

    public Graph() {
        vertices = new HashMap<String, Vertex>();
    }

    /** Add vertex v to the graph
     *
     * Arguments:
     *   v: the vertex to add
     **/
    public void addVertex(Vertex v) {
        this.vertices.put(v.name, v);
    }

    /**
     * Get the vertex associated with a name
     *
     * Arguments:
     *   String name;
     *
     * Returns: the Vertex associated with the name or null
     **/
    public Vertex getVertex(String name) {
        if (this.vertices.containsKey(name)) {
            return this.vertices.get(name);
        } else {
            return null;
        }
    }

    public String toString() {
        String rv = "";
        List<String> vertexNames = new ArrayList<String>(this.vertices.keySet());
        Collections.sort(vertexNames);
        for (String vname : vertexNames) {
            Vertex v = this.getVertex(vname);
            rv += v + "\n";
        }
        return rv;
    }

}






    
