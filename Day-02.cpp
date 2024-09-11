*****************Day-02*******************
problem:
	check if the array is sorted and rotated
	https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

1) Brute Force Approach
Intuition:
The brute force method would involve checking if the array is sorted in two ways:

Rotate the array from each possible index and check if the resulting array is sorted in ascending order.
If any such rotation results in a sorted array, then the original array is sorted and rotated.

2)Code:

#include <iostream>
#include <vector>
using namespace std;

// Function to check if an array is sorted
bool isSorted(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to check if the array is sorted and rotated
bool isSortedAndRotatedBruteForce(vector<int>& arr) {
    int n = arr.size();
    
    // Try rotating the array for all possible starting points
    for (int i = 0; i < n; i++) {
        // Rotate the array by i positions
        vector<int> rotatedArr;
        for (int j = i; j < n; j++) rotatedArr.push_back(arr[j]);
        for (int j = 0; j < i; j++) rotatedArr.push_back(arr[j]);
        
        // Check if the rotated array is sorted
        if (isSorted(rotatedArr)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {3, 4, 5, 1, 2};
    if (isSortedAndRotatedBruteForce(arr)) {
        cout << "Array is sorted and rotated." << endl;
    } else {
        cout << "Array is NOT sorted and rotated." << endl;
    }
    return 0;
}

Time Complexity:
TC: O(n^2), where n is the size of the array. We rotate the array n times and check if each rotated array is sorted, which takes O(n).
Space Complexity:
SC: O(n), since we create a temporary rotated array of size n for each rotation.
********************************************************************************

2) Optimal Approach
Intuition:
The optimal approach leverages the fact that in a sorted and rotated array, there should be exactly one place where the order is disrupted, i.e., an element greater than the next element. By counting the number of such disruptions (inversions), we can determine if the array is sorted and rotated:

If there is exactly one disruption, then the array is sorted and rotated.
If the array is completely sorted without any disruptions or has more than one disruption, then it's not a sorted and rotated array.

2)Code:

#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array is sorted and rotated
bool isSortedAndRotatedOptimal(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    // Count the number of disruptions (inversions)
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[(i + 1) % n]) {
            count++;
        }
    }
    
    // The array is sorted and rotated if there is exactly one disruption
    return (count == 1);
}

int main() {
    vector<int> arr = {3, 4, 5, 1, 2};
    if (isSortedAndRotatedOptimal(arr)) {
        cout << "Array is sorted and rotated." << endl;
    } else {
        cout << "Array is NOT sorted and rotated." << endl;
    }
    return 0;
}
Time Complexity:
TC: O(n), where n is the size of the array. We traverse the array once and check for disruptions.
Space Complexity:
SC: O(1), as no additional space is required apart from a few variables.