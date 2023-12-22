/* 
You are given CPU_ID and Resource_ID as follow: you need to print in the specified output:
0 0
1 4
1 5
1 6
0 1
0 2
0 3
0 7
0 13
1 8
1 10
1 11

Output:
0-{0-3}, {7},{13}
1-{4-6},{8},{10-11}
*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<int, int> mm = { {0, 0}, 
                                   {1, 4}, {1, 5}, {1, 6},
                                   {0, 1}, {0, 2}, {0, 3}, {0, 7}, {0, 13},
                                   {1, 8}, {1, 10}, {1, 11}
                                };
                                


    int curCPU_ID = -1; 
    int startRange = -1;
    int endRange = -1;
    int prevResource = -1;
    
    
    for (auto &e: mm){
        //cout << e.first << " " << e.second << endl;
        
        int cpu = e.first;
        int resource = e.second; 
        
        if (curCPU_ID != cpu){
            if(startRange != -1 )
                cout << "{" << startRange << "}" << endl;
            
            curCPU_ID = cpu;
            startRange = prevResource = resource;
            
        } else if(prevResource + 1 != resource){
            if (startRange != prevResource)
                cout << curCPU_ID << "-" << "{" << startRange << "-" << prevResource << "},";
            else{
                cout << "{" << startRange << "},";
            }
            startRange = resource;
        }
        prevResource = resource;
    }
    
    if(startRange != -1 )
        cout << "{" << startRange << "-" << prevResource << "}" << endl;

    return 0;
}

/* Output:

0-{0-3},{7},{13}
1-{4-6},{8},{10-11}
*/
