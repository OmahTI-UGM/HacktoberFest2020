#include <iostream>
using namespace std;

int MaxIndex(int *arr,int a, int b){
	if(a == b){
		return arr[a];
	}else{
		int m = a+(b-a)/2;
		int left = MaxIndex(arr,a,m);
		int right = MaxIndex(arr,m+1,b);
		
		if(left < right) return right;
		else return left;
	}
}
void cetakArray(int *arr,int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int n;
	
	cout<<"Masukkan panjang Array n: ";
	cin>>n;
	
	int arr[n];
	for(int i = 0; i < n; i++){
		cout<<"Masukkan item array ke-"<<i+1<<" : ";
		cin>>arr[i];
	}
	
	cout<<"\nArray : ";
	cetakArray(arr, n);
	
	int largest = MaxIndex(arr, 0, n-1);
	cout<<"\nMax Value: "<<largest;
	
	return 0;
}
