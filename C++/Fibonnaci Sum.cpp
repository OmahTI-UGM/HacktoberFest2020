#include <iostream>
using namespace std;
    
int main(){
	int sum = 1, x = 1, z = 0, y = 0, input;
	cin >> input;
	cout << x;
	do {
		z = y + x;
		y = x;
		x = z;
		sum += z;
		if (sum > input){
			break;
		}
		cout << ", " << z;
	} while (true);

	if ((sum - input < input - (sum - z))){
		cout << ", " << z;
		cout << "\n" << sum;
	}
	else {
		cout << "\n" << sum - z;
	}
	return 0;
}

