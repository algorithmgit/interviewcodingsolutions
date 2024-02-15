/*
Leetcode - 1146. Snapshot Array 

https://leetcode.com/problems/snapshot-array/

Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
 

Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class SnapshotArray {
private:
    vector<map<int, int>> snapshots; // Store the snapshot states
    int currSnapId; // Current snapshot ID
    
public:
    SnapshotArray(int length) {
        snapshots.resize(length); // Resize the snapshots vector to the specified length
        currSnapId = 0; // Initialize current snapshot ID to 0
    }
    
    void set(int index, int val) {
        snapshots[index][currSnapId] = val; // Update the value at the given index for the current snapshot ID
    }
    
    int snap() {
        return currSnapId++; // Increment the current snapshot ID and return its previous value
    }
    
    int get(int index, int snap_id) {
        auto it = snapshots[index].upper_bound(snap_id); // Find the snapshot with the smallest ID greater than snap_id
        if (it == snapshots[index].begin()) return 0; // No previous snapshot found
        return prev(it)->second; // Return the value of the previous snapshot
    }
};

// Example usage:
int main() {
    SnapshotArray obj(3);
    obj.set(0, 5);
    obj.snap();
    obj.set(0, 6);
    int param_2 = obj.get(0, 0);
    cout << "value at index " << "0 " << "for snap id " << "0 " << "is " << param_2 << endl;
    param_2 = obj.get(0, 1);
    cout << "value at index " << "0 " << "for snap id " << "1 " << "is " << param_2;
    return 0;
}

/* 

Output: 

value at index 0 for snap id 0 is 5
value at index 0 for snap id 1 is 6

*/
