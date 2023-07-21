import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.io.*;

class SameColorException extends Exception {
    public SameColorException(String errMsg) {
        super(errMsg);
    }
}


public class SameColorTest extends Test {
    /**
     * runTest: run the test in the specified file.  Returns true, if
     *   the test passes and false otherwise.
     **/
    public boolean runTest(File f, boolean verbose) {
        Scanner scanner = null;
        try {
            scanner = new Scanner(f);
        } catch (FileNotFoundException e) {
            if (verbose) {
                System.out.println("Results file not found:" + f.getPath());
            }
            return false;
        }

        Graph g = loadGraph(scanner, f.getPath(), verbose);

        String source_name = null;
        String dest_name = null;        
        try {
            String line = scanner.nextLine();
            String[] data = line.split(" ");
            source_name = data[0];
            dest_name = data[1];            
        } catch (Exception e) {
            if (verbose) {
                String msg = "Unexpected exception when parsing the last line of the input file: ";
                System.out.println(msg + e);
            }
            return false;
        }

        Boolean expected = getResults(f, verbose);
        if (expected == null) {
            // bad results file
            return false;
        }

        Boolean actual = null;
        try {
            actual = SameColor.hasSameColor(g, source_name, dest_name);
        } catch (Exception e) {
            if (verbose) {
                System.out.println("Unexpected exception from call to hasSameColor: " + e);        
            }
            return false;
        }

        return expected == actual;
    }


    /**
     * loadGraph: load a graph from a file
     **/
    private Graph loadGraph(Scanner scanner, String filename, boolean verbose) {
        Graph g = new Graph();
        String line = "";
        try {
            line = scanner.nextLine();
            String[] data = line.split(" ");
            int numVertices = Integer.parseInt(data[0]);
            int numEdges = Integer.parseInt(data[1]);            

            for (int i = 0; i < numVertices; i++) {
                // vertex format: name color
                line = scanner.nextLine();
                data = line.split(" ");
                Vertex v = new Vertex(data[0], data[1]);
                g.addVertex(v);
            }

            for (int i = 0; i < numEdges; i++) {
                // edge format: source-vertex-name dest-vertex-name
                line = scanner.nextLine();
                data = line.split(" ");
                Vertex source = g.getVertex(data[0]);
                Vertex dest = g.getVertex(data[1]);
                if (source == null) {
                    throw new SameColorException("Bad source vertex: " + data[0]);

                }
                if (dest == null) {
                    throw new SameColorException("Bad destination vertex: " + data[1]);
                }
                source.addEdge(dest);
            }
        } catch (NumberFormatException e) {
            if (verbose) {
                System.out.println("Format error: line:" + line);
            }
            return null;
        } catch (Exception e) {
            if (verbose) {
                System.out.println("Unexpected exception: " + e);
            }
            return null;
        }

        return g;
    }

    /**
     * getResults: get the expected results from the results file.
     **/
    private static Boolean getResults(File inputFile, boolean verbose) {
        Boolean result = null;
        Scanner scanner = TestHelpers.getResultsFileScanner(inputFile);

        if (scanner == null) {
            return result;
        }

        try {
            String data = scanner.nextLine();
            result = data.toLowerCase().equals("true");
        } catch (Exception e) {
            if (verbose) {
                System.out.println("Expected exception when parsing the expected results file: " + e);
            }
            return null;
        }
        return result;
    }
    
    public static void main(String[] args) {
        System.exit(TestHelpers.doTests(args, new SameColorTest()));
    }
}

    
