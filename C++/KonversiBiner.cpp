#include<iostream>

using namespace std;

void DtoB() {
	int angka;
	string biner="";
	cout<<"Masukkan angka : ";
	cin>>angka;
	while(angka>0) {
		if(angka%2) {
			biner = "1" + biner;
		} else {
			biner = "0" + biner;
		}
		angka = angka / 2;
	}
	cout<<"Hasil Konversi : "<<biner;
}

void BtoD() {
	int angka = 0, buffer=1;
	string biner;
	cout<<"Masukkan biner : ";
	cin>>biner;
	for(int i=biner.length()-1; i>=0; i--) {
		if(biner[i] == '1') {
			angka += buffer;
		}
		buffer = buffer * 2;
	}
	cout<<"Hasil Konversi : "<<angka;
}

int main() {
	int mode;
	cout<<"Program Konversi Decimal & Binary\n";
	cout<<"1. Decimal to Binary\n";
	cout<<"2. Binary to Decimal\n";
	cout<<"Pilih mode (1/2) : ";
	cin>>mode;
	switch(mode) {
		case 1 : {
			DtoB();
			break;
		}
		case 2 : {
			BtoD();
			break;
		}
		default : {
			return 0;
			break;
		}
	}
}
