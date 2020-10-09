#include <iostream> 
#include <vector> 
#include <map>   

using namespace std; 

int main() {
    vector<int> data {1, 2, 3, 3, 4, 5, 6, 7, 8, 9};

    map<int, int> dataCounter;

    for(unsigned int i = 0; i < data.size(); i++) {
        if(dataCounter.count(data[i])) {
            cout<<"Duplicate number detected, it is "<<data[i];
            break;
        }
        dataCounter.insert(pair<int, int>(data[i], 1));
    }
    return 0;
}