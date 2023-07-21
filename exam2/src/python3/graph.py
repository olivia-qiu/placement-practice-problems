from typing import Dict, List, Optional

class Vertex:
    '''
    A vertex in a graph.
    
    Attributes:
        name (str): The name of the vertex.
        color (str): The color of the vertex.
        neighbors (List(vertex)): A list of the vertices that are a
          destination of an edge starting at this vertex.
        
    Methods:
        add_edge: Adds an edge to this vertex.
    '''
    name : str
    color : str
    neighbors : List["Vertex"]

    def __init__(self, name: str, color: str):
        '''
        Initializes a vertex.
        
        Arguments:
            name (str): The name of the vertex.
            color (str): The color of the vertex.
        '''
        self.name = name
        self.color = color
        self.neighbors = []

    def add_edge(self, dest: "Vertex") -> None:
        '''
        Adds an edge to this vertex.

        Arguments:
            dest (Vertex): The vertex to add an edge to.

        Returns:
            None
        '''
        self.neighbors.append(dest)


class Graph:
    '''
    A graph.

    Attributes:
        vertices (Dict[str, Vertex]): A dictionary of vertices in the graph.
            Note that these are vertex names mapped to vertex objects, and not
            vertex objects mapped to vertex objects representing edges.

    Methods:
        add_vertex: Adds a vertex to the graph.
        get_vertex: Gets a vertex from the graph.
    '''
    vertices : Dict[str, Vertex]

    def __init__(self):
        '''
        Initializes a graph.
        '''
        self.vertices = {}

    def add_vertex(self, vertex: Vertex) -> None:
        '''
        Adds a vertex to the graph.

        Arguments:
            vertex (Vertex): The vertex to add to the graph.

        Returns:
            None
        '''
        self.vertices[vertex.name] = vertex

    def get_vertex(self, name: str) -> Optional[Vertex]:
        '''
        Gets a vertex from the graph.

        Arguments:
            name (str): The name of the vertex to get.

        Returns:
            Optional[Vertex]: The vertex with the given name, or None if no
                vertex with that name exists.
        '''
        return self.vertices.get(name)

    
