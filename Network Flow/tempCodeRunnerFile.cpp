#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Function to find the chromatic number using the greedy
// coloring algorithm
int greedyColoring(const vector<vector<int> >& graph)
{
	int n = graph.size();
	vector<int> colors(n, -1);

	for (int v = 0; v < n; ++v) {
		unordered_set<int> usedColors;

		// Check neighbors and mark their colors as used
		for (int neighbor : graph[v]) {
			if (colors[neighbor] != -1) {
				usedColors.insert(colors[neighbor]);
			}
		}

		// Find the smallest available color
		for (int color = 1;; ++color) {
			if (usedColors.find(color)
				== usedColors.end()) {
				colors[v] = color;
				break;
			}
		}
	}

	// Find the maximum color used (chromatic number)
	int chromaticNumber
		= *max_element(colors.begin(), colors.end()) + 1;
	return chromaticNumber;
}

int main()
{
	// Sample graph represented as an adjacency list
	vector<vector<int> > graph
		= { { 1, 2, 3 }, { 0, 2 }, { 0, 1, 3 }, { 0, 2 } };

	// Find and output the chromatic number
	int chromaticNumber = greedyColoring(graph);
	cout << "Chromatic Number: " << chromaticNumber << endl;

	return 0;
}
