#include<iostream>
using namespace std;

/*
	Program untuk mendeteksi Longest Increasing Subarray
*/

int main() {
	int n;
	cout<<"Masukkan panjang array : ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	
	int hasil=0, buffer=0;
	
	for(int i=0; i<n; i++) {
		
		if(i==0 || arr[i]<=arr[i-1]) {
			
			buffer = 1;
			
		} else {
			
			buffer++;
			
		}
		
		hasil = max(buffer,hasil);
	}
	
	cout<<"Panjang subarray menaik terpanjang adalah : "<<hasil;
}
