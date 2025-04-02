// Problem: Check if Grid can be Cut into Sections
/*Explanation:
// Given an `n x n` grid with non-overlapping rectangles, we need to determine whether 
// it is possible to make exactly two horizontal or two vertical cuts such that:
// 1. Each of the three resulting sections contains at least one rectangle.
// 2. Every rectangle belongs to exactly one section.
*/
/* Approach:
// 1. Store the x-coordinates and y-coordinates of rectangle edges separately.
// 2. Sort the coordinates and process them to check if we can form exactly two valid cuts.
// 3. If we can find either two valid vertical or two valid horizontal cuts, return true.
4. Otherwise, return false. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

// Function to count possible valid cuts
bool countValidCuts(vector<pii>& coordinates) {
    int cutCount = 0, overlap = 0;

    // Iterate through the sorted coordinate list
    for (const auto& point : coordinates) {
        if (point.second == 0) { 
            overlap--;  // Ending a rectangle
        } else { 
            overlap++;  // Starting a new rectangle
        }

        // If no rectangles overlap at this point, a cut is possible
        if (overlap == 0) {
            cutCount++;
        }
    }

    // We need at least 3 sections (2 cuts) to return true
    return (cutCount >= 3);
}

// Function to check if valid cuts can be made
bool canCutGrid(int n, vector<vector<int>>& rectangles) {
    vector<pii> xCoordinates, yCoordinates;

    // Store rectangle edges in separate coordinate lists
    for (const auto& rect : rectangles) {
        xCoordinates.push_back({rect[0], 1}); // Start of a rectangle (x-coord)
        xCoordinates.push_back({rect[2], 0}); // End of a rectangle (x-coord)
        yCoordinates.push_back({rect[1], 1}); // Start of a rectangle (y-coord)
        yCoordinates.push_back({rect[3], 0}); // End of a rectangle (y-coord)
    }

    // Sort coordinates
    sort(xCoordinates.begin(), xCoordinates.end());
    sort(yCoordinates.begin(), yCoordinates.end());

    // Check if either horizontal or vertical cuts are possible
    return (countValidCuts(xCoordinates) || countValidCuts(yCoordinates));
}

int main() {
    int n, numRectangles;

    // Taking user input
    cout << "Enter grid size (n x n): ";
    cin >> n;

    cout << "Enter the number of rectangles: ";
    cin >> numRectangles;

    vector<vector<int>> rectangles(numRectangles, vector<int>(4));

    cout << "Enter the rectangles in the format [startx starty endx endy]:" << endl;
    for (int i = 0; i < numRectangles; i++) {
        cin >> rectangles[i][0] >> rectangles[i][1] >> rectangles[i][2] >> rectangles[i][3];
    }

    // Call function and display result
    if (canCutGrid(n, rectangles)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }

    return 0;
}
