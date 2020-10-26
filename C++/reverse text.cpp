#include <iostream>
#include <string.h>
using namespace std;

int main(){
	string text;
	int n;
	cin >> text;
	
	n = text.length();
	
	while (n >= 0){
		cout << text[n-1];
		n--;
	}
	
	return 0;
}
