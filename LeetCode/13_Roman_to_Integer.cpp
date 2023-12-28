#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    int total = 0;
    unordered_map<string, int> um ={ 
        { "I", 1},
        { "V", 5},
        { "X", 10},
        { "L", 50},
        { "C", 100},
        { "D", 500},
        { "M", 1000},
        { "IV", 4},
        { "IX", 9},
        { "XL", 40},
        { "XC", 90},
        { "CD", 400},
        { "CM", 900},
    };

    for (int i = 0; i < s.length(); i++) {
        
        if (i + 1 < s.length() && um.find(s.substr(i, 2)) != um.end()) {
            total += um[s.substr(i, 2)];
            //cout << "i = " << i << ", " << s.substr(i, 2) << " " ;
            //cout << total << endl;
            i++; // Skip the next character
        } else {
            total += um[s.substr(i, 1)]; 
            //cout << "i = " << i << ", " << s.substr(i, 1) << " " ;
            //cout << total << endl;
        }
    }
    
    return total;        
}

int main() {
    string input = "MCMXCIV";
    int result = romanToInt(input);
    cout << "Result: " << result << endl;
    return 0;
}

/* Output:

Result: 1994
*/
