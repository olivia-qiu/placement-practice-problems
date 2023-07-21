#include "TestHelpers.h"
#include "SameColor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <assert.h>

namespace test {

bool get_result(std::string& f) {
    std::string resultsFileName = TestHelpers::getResultsFile(f);
    std::ifstream ifs(resultsFileName);
    std::string res = "";

    if (ifs) {
        ifs >> res;
        if (res == "") {
            std::cout << "Format error" << std::endl;
        }
    } else {
        std::cout << "Results file not found: " << resultsFileName << std::endl;
        exit(1);
    }
    return res == "True";
 }

void get_data(
    std::string& f,
    Graph* g,
    std::string& source_name,
    std::string& dest_name
    ) {
    std::string dataFileName = TestHelpers::getDataFile(f);
    int numVertices = -1, numEdges = -1;

    std::ifstream ifs(dataFileName);
    if (ifs) {
        ifs >> numVertices >> numEdges;
        if (numVertices == -1 || numEdges == -1) {
            std::cout << "Format error" << std::endl;
            return;
        }

        for (size_t i = 0; i < numVertices; i++) {
            std::string name, color;
            ifs >> name >> color;
            g->add_vertex(new Vertex(name, color));
        }

        for (size_t i = 0; i < numEdges; i++) {
            // edge format: source-vertex-name dest-vertex-name
            std::string source_name, dest_name;
            ifs >> source_name >> dest_name;
            Vertex* source = g->get_vertex(source_name);
            Vertex* dest = g->get_vertex(dest_name);
            if (source == nullptr) std::cout << "Bad source vertex  " << source_name << "\n";
            if (dest == nullptr) std::cout << "Bad destination vertex  " << dest_name << "\n";
            source->addEdge(dest);
        }
        ifs >> source_name >> dest_name;
    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
        return;
    }

    return;
}


bool runTest(std::string f) {
    Graph* g = new Graph();
    std::string source_name, dest_name;
    get_data(f, g, source_name, dest_name);

    int actual = has_same_color_path(g, source_name, dest_name);
    int expected = get_result(f);

    if (actual == expected) {
        return true;
    } else {
        std::cout << "Failed actual result and expected result do not match" << "\n";
        std::cout << "    actual is " << std::to_string(actual) << "\n";
        std::cout << "    expected is " << std::to_string(expected) << "\n";
	    return false;
    }

    return true;
}

} // namespace test

int main (int argc, char* argv[])
{
    std::vector<std::string> files = TestHelpers::getFiles(argc, argv);
    if (files.size() == 0) {
        std::cout << "no test file found";
        exit(1);
    }

    int count = 0;
    for (size_t i = 0; i < files.size(); ++i) {
        std::string f = files[i];
        std::cout << "Test " << f << ": ";
        if (test::runTest(f)) {
            std::cout << "PASSED\n";
            count++;
        } else {
            std::cout << "FAILED\n";
        }
    }

    if (count == files.size()) {
        return 42;
    } else {
        return 0;
    }

}
