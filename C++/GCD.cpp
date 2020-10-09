#include <iostream>
using namespace std;

int gcd(int x, int y){
	
	if(y==0) {
		return x;
	} else {
		return gcd(y,x%y);
	}
	
}

int main(){
	int n;
	cout<<"Enter how many numbers: ";
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cout<<"Enter number "<<i+1<<": ";
		cin>>num[i];
	}
	int result=num[0];
	for(int i=1;i<n;i++){
		result=gcd(result,num[i]);
	}
	cout<<"Greatest Common Divisor: "<<result;
}
