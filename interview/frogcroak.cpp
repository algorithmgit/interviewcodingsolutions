#include <iostream>

using namespace std;

int minNumberOfFrogs(string croakOfFrogs) {
    int cnt[5] = {}, frogs = 0, max_frogs = 0;
    for (auto ch : croakOfFrogs) {
        auto n = string("croak").find(ch);
        ++cnt[n];
        if (n == 0){
            max_frogs = max(max_frogs, ++frogs);
        }
        else if (--cnt[n - 1] < 0)
            return -1;
        else if (n == 4)
            --frogs;
    }
    return frogs == 0 ? max_frogs : -1;
}

int main()
{
    printf("frogs = %d\n", minNumberOfFrogs("croakcroak"));
    printf("frogs = %d\n", minNumberOfFrogs("crcoakroak"));
    printf("frogs = %d\n", minNumberOfFrogs("croakcrook"));

    return 0;
}


/* Output : 
frogs = 1
frogs = 2
frogs = -1
*/
