import java.util.List;
import java.util.ArrayList;


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
public class Vertex {
    public String name;
    public String color;
    public List<Vertex> neighbors;

    public Vertex(String name, String color) {
        this.name = name;
        this.color = color;
        this.neighbors = new ArrayList<Vertex>();
        
    }

    public void addEdge(Vertex v) {
        this.neighbors.add(v);
    }

    public String toString() {
        String rv = String.format("%s (%s):", this.name, this.color);
        for (Vertex v : this.neighbors) {
            rv += " " + v.name;
        }
        return rv;
    }
}
