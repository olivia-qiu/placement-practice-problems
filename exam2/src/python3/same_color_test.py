import os
import sys
sys.path.insert(0, os.getcwd())

from same_color import has_same_color_path
import test_helpers as th
from graph import Graph, Vertex


def load_graph(file: str) -> Graph:
    '''
    Loads a graph from a file.

    Arguments:
        file (str): The file to load the graph from.
        verbose (bool): Whether or not to print out the graph as it is loaded.
            Set to False by default.

    Returns:
        Graph: The graph loaded from the file.
    '''
    try:
        with open(file, 'r') as f:
            lines = f.readlines()
    except FileNotFoundError:
        raise FileNotFoundError(f'Could not find file {file}')

    vertex_num, edge_num = (int(x) for x in lines[0].strip().split())

    # Get the vertices
    graph = Graph()
    vertices = {}
    for line in lines[1:vertex_num + 1]:
        name, color = line.strip().split()
        vertex = Vertex(name, color)
        vertices[name] = vertex
        graph.add_vertex(vertex)
    
    # Build edges between vertices
    for line in lines[vertex_num + 1:vertex_num + edge_num + 1]:
        start, end = line.strip().split()
        vertices[start].add_edge(vertices[end])

    start, end = lines[-1].split()
    return graph, start, end


if __name__ == '__main__':
    # Initialize argument parser
    args = th.create_parser('Test the cold solution.').parse_args()

    # Figure out if we're testing all files or just one, if we're testing all
    # files, get the list of files to test
    if args.test_dir is not None:
        test_files = th.get_test_files(args.test_dir)

        for test_file in test_files:
            graph, start, end = load_graph(test_file)
            # Read the results file
            expected = th.read_results_file(test_file)
            expected = expected.strip().lower() == "true"
            actual = has_same_color_path(graph, start, end)
            th.print_results(test_file, expected, actual)

    elif args.test_file is not None:
        test_file = args.test_file
        graph, start, end = load_graph(test_file)
        expected = th.get_test_string(test_file.replace('.in', '.ans')).strip() == 'True'

        actual = has_same_color_path(graph, start, end)

        th.print_results_autograder(expected, actual)

    else:
        raise ValueError('Must provide either a test file or a test directory.')
