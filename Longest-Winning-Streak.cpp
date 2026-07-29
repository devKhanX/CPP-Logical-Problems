// Problem: Find the longest consecutive winning streak
// Approach: Track the current winning streak and update the maximum streak
include <iostream>
#include <vector>

using namespace std;

int main() {
    int nR;
    int winS = 0;
    int largestS = 0;
    cout << "Enter number of rounds: ";
    cin >> nR;
    vector<char> arr(nR);
    cout << "Enter outcomes (W for win, L for loss) separated by spaces:\n";
    for (int i = 0; i < nR; i++) {
        cin >> arr[i]; 
    }

    for (int i = 0; i < nR; i++) {
        if (arr[i] == 'W' || arr[i] == 'w') {
            winS++; 
            
            if (winS > largestS) {
                largestS = winS;
            }
        } else {
            winS = 0; 
        }
    }
    cout << "Longest streak: " << largestS << endl;
    return 0;
}
