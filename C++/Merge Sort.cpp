#include<iostream>
using namespace std;

void merge(int *arr, int *temp, int lower, int middle, int upper) {
	int lowTemp, lowArr, midTemp;
	lowTemp = lower;
	lowArr = lower;
	midTemp = middle + 1;
	
	while ((lowArr <= middle) && (midTemp <= upper)) {
		if (arr[lowTemp] <= arr[midTemp]) {
			temp[lowArr] = arr[lowTemp];
			lowTemp++;
		} else {
			temp[lowArr] = arr[midTemp];
			midTemp++;
		}
		lowArr++;
	}
	
	if (lowTemp > middle) {
		for (int i = midTemp; i <= upper; i++) {
			temp[lowArr] = arr[i];
			lowArr++;
		}
	} else {
		for (int i = lowTemp; i <= middle; i++) {
			temp[lowArr] = arr[i];
			lowArr++;
		} 
	}
	
	for (int i = lower; i <= upper; i++) {
		arr[i] = temp[i];
	}
}

void mergeSort(int *arr, int *temp, int lower, int upper) {
	int middle;
	if (lower < upper) {
		middle = (lower + upper) / 2;
		mergeSort(arr, temp, lower, middle);
		mergeSort(arr, temp, middle+1, upper);
		merge(arr, temp, lower, middle, upper);
	}
}

int main () {
	int n;
	cin >> n;
	int arr[n];
	int temp[n];
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	mergeSort(arr, temp, 0, n-1);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
