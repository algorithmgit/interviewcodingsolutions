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
