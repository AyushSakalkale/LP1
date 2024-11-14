#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Recursive function for the Branch and Bound approach
void tspBranchAndBound(vector<vector<int>> &dist, vector<bool> &visited, int pos, int count, int cost, int &minDistance, vector<int> &currentTour, vector<int> &bestTour) {
    int n = dist.size();

    // Base case: if we've visited all cities and can return to the starting city
    if (count == n && dist[pos][0] != 0) {
        int totalCost = cost + dist[pos][0];
        if (totalCost < minDistance) {
            minDistance = totalCost;
            bestTour = currentTour; // Save the current path as best tour
            bestTour.push_back(0);   // Add starting city to complete the tour
        }
        return;
    }

    // Try all cities as the next step in the tour
    for (int i = 0; i < n; i++) {
        // Visit unvisited cities only
        if (!visited[i] && dist[pos][i] != 0) {
            visited[i] = true;
            currentTour[count] = i;

            // Recursive call with the updated cost and count
            tspBranchAndBound(dist, visited, i, count + 1, cost + dist[pos][i], minDistance, currentTour, bestTour);

            // Backtrack: unmark the city as visited
            visited[i] = false;
        }
    }
}

void solveTSP(vector<vector<int>> &dist) {
    int n = dist.size();
    int minDistance = INT_MAX;
    vector<int> bestTour, currentTour(n); // bestTour to store the final result
    vector<bool> visited(n, false); // visited array to track visited cities

    // Start from the first city (0)
    visited[0] = true;
    currentTour[0] = 0;

    // Start the recursive Branch and Bound search
    tspBranchAndBound(dist, visited, 0, 1, 0, minDistance, currentTour, bestTour);

    // Output the results
    cout << "Minimum distance: " << minDistance << endl;
    cout << "Tour: ";
    for (int city : bestTour) {
        cout << city << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    solveTSP(dist);
    return 0;
}
