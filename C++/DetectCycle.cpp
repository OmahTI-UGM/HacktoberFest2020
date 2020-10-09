#include <iostream> 
#include <vector>

using namespace std; 

int main() {
    vector<int> data {4, 7, 8, 0, 1, 6, 8, 0, 1, 6};

    int i = 0, j = 0;

    while(j++ != data.size() && j + 2 != data.size()) {
        i++;
        j += 2;
        if(data[i] == data[j]) {
            i = 0;
            while(data[i] != data[j]) {
                i++;
                j++;
            }

            cout<<"Cycle Detected";
            break;
        }
    }

    return 0;
}