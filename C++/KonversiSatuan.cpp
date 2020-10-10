#include<iostream>

using namespace std;


int main() {
	cout<<"1. Konversi satuan panjang\n";
	cout<<"2. Konversi satuan berat\n";
	cout<<"Pilih tipe yang akan dikonversi : ";
	
	int n;
	cin>>n;
	
	string tabel[10];
	
	switch(n) {
		case 1 : {
			cout<<"\nKonversi satuan panjang\n";
			cout<<"Kode satuan : (1)km (2)hm (3)dam (4)m (5)dm (6)cm (7)mm\n";
			tabel[0] = "km";
			tabel[1] = "hm";
			tabel[2] = "dam";
			tabel[3] = "m";
			tabel[4] = "dm";
			tabel[5] = "cm";
			tabel[6] = "mm";
			break;
		}
		case 2 : {
			cout<<"\nKonversi satuan berat\n";
			cout<<"Kode satuan : (1)kg (2)hg (3)dag (4)g (5)dg (6)cg (7)mg\n";
			tabel[0] = "kg";
			tabel[1] = "hg";
			tabel[2] = "dag";
			tabel[3] = "g";
			tabel[4] = "dg";
			tabel[5] = "cg";
			tabel[6] = "mg";			
			break;
		}
		default : {
			return 0;
			break;
		}
	}
	
	int asal, akhir;
	double nilai;
	
	cout<<"Masukkan kode satuan asal : ";
	cin>>asal;
	
	cout<<"Masukkan kode satuan akhir : ";
	cin>>akhir;
	
	cout<<tabel[asal-1]<<"-->"<<tabel[akhir-1]<<"\n";
	
	cout<<"Masukkan nilai : ";
	cin>>nilai;
	
	while(asal != akhir) {
		if(asal>akhir) {
			asal--;
			nilai = nilai/10;
		} else {
			asal++;
			nilai = nilai*10;
		}
	}
	
	cout<<"Nilai setelah konversi : "<<nilai<<" "<<tabel[akhir];
}
