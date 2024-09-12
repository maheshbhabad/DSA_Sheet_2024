*******************Day-03****************************
Problem: Remove Duplicates
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Brute Force Approach
1) Intuition:
The brute force approach involves iterating through the array and creating a new array where duplicates are not included. Since the array is sorted, we can easily check if the current element is the same as the previous one and skip it. This, however, requires additional space, which we will use to store the new array without duplicates.

2) Code:
cpp
Copy code
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicatesBruteForce(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    
    // Create a new vector to store unique elements
    vector<int> unique;
    
    unique.push_back(nums[0]);
    
    for (int i = 1; i < nums.size(); i++) {
        // If current element is not equal to the last inserted unique element
        if (nums[i] != nums[i - 1]) {
            unique.push_back(nums[i]);
        }
    }
    
    // Copy the unique elements back to the original array
    for (int i = 0; i < unique.size(); i++) {
        nums[i] = unique[i];
    }
    
    // Return the number of unique elements
    return unique.size();
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 5, 5};
    int newLength = removeDuplicatesBruteForce(nums);
    cout << "New length: " << newLength << endl;
    
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
3) Time Complexity:
TC: O(n), where n is the size of the input array. We traverse the array once to gather unique elements and another time to copy the results back.
4) Space Complexity:
SC: O(n), since we use an extra array to store unique elements.

******************Optimal Approach (Two Pointers)*************************
1) Intuition:
Since the array is sorted, all duplicates will be adjacent. We can use a two-pointer technique to solve the problem in place. We maintain a write pointer, which keeps track of the position where the next unique element should be written. The read pointer goes through the array, and whenever it encounters a new element (different from the previous one), it moves the element to the write pointer's position and then increments the write pointer.

2) Code:
cpp
Copy code
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicatesOptimal(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    
    // The `write` pointer will track the position for unique elements
    int write = 1;
    
    for (int read = 1; read < nums.size(); read++) {
        // If current element is different from the previous, it is unique
        if (nums[read] != nums[read - 1]) {
            nums[write] = nums[read];
            write++;
        }
    }
    
    // Return the number of unique elements
    return write;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 5, 5};
    int newLength = removeDuplicatesOptimal(nums);
    cout << "New length: " << newLength << endl;
    
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}

3) Time Complexity:
	TC: O(n), where n is the size of the array. We only traverse the array once with both the read and write pointers.

4) Space Complexity:
	SC: O(1), as we are not using any extra space; all changes are made in place.
