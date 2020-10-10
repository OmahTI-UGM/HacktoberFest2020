#include <iostream>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <ctime>
using namespace std;
ifstream ambil;
ofstream simpan;
int banyakdata=0;
typedef struct{
	string nama,kode;
	int layanan, lama;
	float berat, harga;	
}pelanggan;
pelanggan datapelanggan[100];
string username,pass,n_file;
char choose,bersihkan;
int pilih,tambahdata,pilout,unik,log;
int a=0;
string carifile;
void ambil_data(){
		cout<<"Nama file yang akan diambil : ";cin>>carifile;
ifstream ambil(carifile.c_str());
	for(int i=0;i<3;i++){
		ambil>>datapelanggan[i].nama;
		if(ambil.eof())
		break;
		ambil>>datapelanggan[i].layanan;
		ambil>>datapelanggan[i].lama;
		ambil>>datapelanggan[i].berat;
		ambil>>datapelanggan[i].harga;
		ambil>>datapelanggan[i].kode;
		banyakdata=banyakdata+1;
	}ambil.close();
}

void login (){
	do{
	cout << "User     = ";
		cin >> username;
	cout<< "Password = ";
		cin >> pass;
		if(username=="admin"&& pass=="sukses")
			cout<<"Berhasil login"<<endl;
		else{
			cout<<"ada yang salah"<<endl;
		}
	}while (username!="admin"|| pass!="sukses"); 
}

string randomString(int maxLength = 5, string charIndex = "abcdefghijklmnaoqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890")
{
    int length = maxLength;
    int indexesOfRandomChars[15];
    for (int i = 0; i < length; ++i)
        indexesOfRandomChars[i] = rand() % charIndex.length();
    string randomString = "";
    for (int i = 0; i < length; ++i){
        randomString += charIndex[indexesOfRandomChars[i]];
    } 
    return randomString;
}

void kode(string *ke){
string jajal;
    srand(time(NULL));
		jajal=randomString();
		cout<<"\n	Kode Unik Anda = "<<jajal<<"	(Harap simpan baik\" nanti untuk pengambilan)\n";
	*ke=jajal;
}

void input(){
	int bnyk_data,data_t;
	string namanyafile = "DB_",temp;
	cout<<"Input data Menu"<<endl;
	cout<<"Masukkan nama file = ";
	cin>>temp;
	namanyafile+=temp;
	n_file=temp;
	
	ambil.open(namanyafile.c_str());
	ambil>>data_t;
	ambil.close();
	
		cout<<"Banyak data = ";
		cin>>bnyk_data;
		banyakdata=data_t + bnyk_data;
	
	simpan.open(namanyafile.c_str());
	simpan<<banyakdata;
	simpan.close();
		string oke[banyakdata];
	for(int i = 0;i<bnyk_data;i++){
		cout<<endl<<i+1<<"	"<<"Nama = ";
		cin>>datapelanggan[i].nama;
		cout<<"	Pilih layanan"<<endl;
		cout<<"		1.Clean & Clear"<<endl<<"		2.Cuci & Keringkan"<<endl;
		cout<<"		3.Setrika"<<endl;
		cout<<"		Pil(1-3) = ";
			cin>>datapelanggan[i].layanan;
		cout<<"	Lama Laundry"<<endl;
		cout<<"		1.Reguler (3 hari)"<<endl<<"		2.One Day service"<<endl;
		cout<<"		3.Super Kilat"<<endl;
		cout<<"		Pil(1-3) = ";
			cin>>datapelanggan[i].lama;
		cout<<"	Masukkan berat cucian"<<endl;
		int y=0;
		while(y<3){
		cout<<"	ALERT!!!!!!"<<endl;
		y++;}
		cout<<"	*Jika Berat <2Kg, hitungan akan sama dengan 2kg";
		cout<<"	\n	Masukkan berat laundry= ";
			cin>>datapelanggan[i].berat;
				if(datapelanggan[i].berat<2){
				datapelanggan[i].berat=2;
				}
	cout<<"\n	Total biaya yang harus dibayar : Rp ";
		if(datapelanggan[i].layanan==1 && datapelanggan[i].lama==1){
			datapelanggan[i].harga=datapelanggan[i].berat*4500;
			cout<<datapelanggan[i].harga;
		}
		else if(datapelanggan[i].layanan==1 && datapelanggan[i].lama==2){
			datapelanggan[i].harga=datapelanggan[i].berat*6000;
			cout<<datapelanggan[i].harga;
		}
			else if(datapelanggan[i].layanan==1 && datapelanggan[i].lama==3){
				datapelanggan[i].harga=datapelanggan[i].berat*8000;
				cout<<datapelanggan[i].harga;
			}
				else if(datapelanggan[i].layanan==2 && datapelanggan[i].lama==1){
					datapelanggan[i].harga=datapelanggan[i].berat*3500;
					cout<<datapelanggan[i].harga;
				}
					else if(datapelanggan[i].layanan==2 && datapelanggan[i].lama==2){
						datapelanggan[i].harga=datapelanggan[i].berat*5000;
						cout<<datapelanggan[i].harga;
					}
						else if(datapelanggan[i].layanan==2 && datapelanggan[i].lama==3){
							datapelanggan[i].harga=datapelanggan[i].berat*7000;
							cout<<datapelanggan[i].harga;
						}
							else if(datapelanggan[i].layanan==3 && datapelanggan[i].lama==1){
								datapelanggan[i].harga=datapelanggan[i].berat*1500;
								cout<<datapelanggan[i].harga;
							}
								else if(datapelanggan[i].layanan==3 && datapelanggan[i].lama==2){
									datapelanggan[i].harga=datapelanggan[i].berat*2000;
									cout<<datapelanggan[i].harga;
								}
									else if(datapelanggan[i].layanan==3 && datapelanggan[i].lama==3){
										datapelanggan[i].harga=datapelanggan[i].berat*3000;
										cout<<datapelanggan[i].harga;
									}
										else 
											cout<<"Ada input yang salah";

	kode(&oke[i]);
		simpan.open(n_file.c_str(),ios::app);
		simpan<<datapelanggan[i].nama<<endl<<datapelanggan[i].layanan<<endl<<datapelanggan[i].lama<<endl
			  <<datapelanggan[i].berat<<endl<<datapelanggan[i].harga<<endl<<oke[i]<<endl;
		simpan.close();
		
	}
}

void ngesort(){
	if(a==0){
	ambil_data();
	a=a+1;
	}
	int pilihansort;
	string tempnama,tempkode;
	int templama,templayanan;
	float tempberat,tempharga;
	cout<<"Menu Sorting/Mengurutkan data"<<endl;
	cout<<"Pilih yang hendak di sorting"<<endl;
		cout<<"	1.Nama Pelanggan"<<endl;
		cout<<"	2.Berat"<<endl;
	cout<<"Pil : ";cin>>pilihansort;
	switch(pilihansort){
		case 1 : 
			cout<<"Bubble sort dengan nama pelanggan"<<endl;
			for (int i = 0; i < banyakdata-1; i++)
						{
							for (int j = 0; j <(banyakdata-1-i);j++)
							{
								if (datapelanggan[j].nama>datapelanggan[j+1].nama)
								{
									tempnama=datapelanggan[j].nama;
									templayanan=datapelanggan[j].layanan;
									templama=datapelanggan[j].lama;
									tempberat=datapelanggan[j].berat;
									tempharga=datapelanggan[j].harga;
									tempkode=datapelanggan[j].kode;
									
									datapelanggan[j].nama=datapelanggan[j+1].nama;
									datapelanggan[j].layanan=datapelanggan[j+1].layanan;
									datapelanggan[j].lama=datapelanggan[j+1].lama;
									datapelanggan[j].berat=datapelanggan[j+1].berat;
									datapelanggan[j].harga=datapelanggan[j+1].harga;
									datapelanggan[j].kode=datapelanggan[j+1].kode;
									
									datapelanggan[j+1].nama=tempnama;
									datapelanggan[j+1].layanan=templayanan;
									datapelanggan[j+1].lama=templama;
									datapelanggan[j+1].berat=tempberat;
									datapelanggan[j+1].harga=tempharga;
									datapelanggan[j+1].kode=tempkode;
								}
							}
						}
									
				for (int i=0;i<2;i++){
					cout<<datapelanggan[i].nama<<endl;
					cout<<datapelanggan[i].layanan<<endl;
					cout<<datapelanggan[i].lama<<endl;
					cout<<datapelanggan[i].berat<<endl;
					cout<<datapelanggan[i].harga<<endl;
					cout<<datapelanggan[i].kode<<endl;			
				}	
			
		break;
		case 2 :
			cout<<"Straight Insertion Sort mengurutkan berat laundry pelanggan"<<endl;
			for(int i=1;i<banyakdata;i++){
				tempnama=datapelanggan[i].nama;
				templayanan=datapelanggan[i].layanan;
				templama=datapelanggan[i].lama;
				tempberat=datapelanggan[i].berat;
				tempharga=datapelanggan[i].harga;
				tempkode=datapelanggan[i].kode;
				int k=i-1;
				while((tempberat>datapelanggan[k].berat) && (k>=0)){
					datapelanggan[k+1].nama=datapelanggan[k].nama;
					datapelanggan[k+1].layanan=datapelanggan[k].layanan;
					datapelanggan[k+1].lama=datapelanggan[k].lama;
					datapelanggan[k+1].berat=datapelanggan[k].berat;
					datapelanggan[k+1].harga=datapelanggan[k].harga;
					datapelanggan[k+1].kode=datapelanggan[i].kode;
					k=k-1;
						datapelanggan[k+1].nama=tempnama;
						datapelanggan[k+1].layanan=templayanan;
						datapelanggan[k+1].lama=templama;
						datapelanggan[k+1].berat=tempberat;
						datapelanggan[k+1].harga=tempharga;
						datapelanggan[k+1].kode=tempkode;
				}
			}
			for (int i=0;i<2;i++){
					cout<<datapelanggan[i].nama<<endl;
					cout<<datapelanggan[i].layanan<<endl;
					cout<<datapelanggan[i].lama<<endl;
					cout<<datapelanggan[i].berat<<endl;
					cout<<datapelanggan[i].harga<<endl;
					cout<<datapelanggan[i].kode<<endl;			
				}
		break;
	}
}

void output(){
	string unik,namadicari; int x,y,pilih;
	bool ketemunama,ketemukode;
	system("CLS");
	cout<<"====================================================================\n"
		<<"============================ Menu Output ===========================\n"
		<<"====================================================================\n";
	if(a==0){
	ambil_data();
	a=a+1;
	}
	cout<<"\n1. Tampilkan Semua Data\n"<<"2. Tampilkan Data Pilihan\n";
	cout<<"Pilihan : ";
	cin>>pilout;
		switch(pilout){
			case 1:
				for(int i=0;i<banyakdata;i++){
					cout<<i+1<<".	Nama = "<<datapelanggan[i].nama<<endl;
					cout<<"	Pesanan dan Layanan\n";
						if(datapelanggan[i].layanan==1){
							cout<<"		Clean & Clear";
						}
						else if(datapelanggan[i].layanan==2){
							cout<<"		Cuci & Keringkan";
						}
						else if(datapelanggan[i].layanan==3){
							cout<<"		Setrika";
						}
						else {
							cout<<"	Layanan Tidak diketahui";
						}
	
						if(datapelanggan[i].lama==1){
							cout<<", Reguler (3 Hari)"<<endl;
						}
						else if(datapelanggan[i].lama==2){
							cout<<", One Day Service"<<endl;
						}
						else if(datapelanggan[i].lama==3){
							cout<<", Super Kilat"<<endl;
						}
						else {
							cout<<", Laundry Tidak akan selesai"<<endl;
						}
					cout<<"	Berat laundry = "<<datapelanggan[i].berat<<" Kg"<<endl;
					cout<<"	Total Bayar = Rp "<<datapelanggan[i].harga<<"-,\n";
					cout<<"	Kode UNIK = "<<datapelanggan[i].kode<<endl;
				}
			break;
			
			case 2: cout<<"\nMencari berdasarkan apa?\n1. Nama\n2. Kode Unik\nPilihan";cin>>pilih;
				if(pilih==1){
					cout<<"-----------------------------------------------\n";
					cout<<"Masukan nama yang dicari : ";cin.ignore();getline(cin,namadicari);
					cout<<"-----------------------------------------------\n";
					ketemunama = false;
					x=0;
					while ((x<banyakdata)&&(!ketemunama))
					{
						if (datapelanggan[x].nama == namadicari)
						{
							ketemunama=true;
						}
						else
							x=x+1;
					}
					if (ketemunama)
					{
						cout<<"	Data Saudara "<<datapelanggan[x].nama<<endl;
						cout<<"	Pesanan dan Layanan\n";
								cout<<"	Pesanan dan Layanan\n";
						if(datapelanggan[x].layanan==1){
							cout<<"		Clean & Clear";
						}
						else if(datapelanggan[x].layanan==2){
							cout<<"		Cuci & Keringkan";
						}
						else if(datapelanggan[x].layanan==3){
							cout<<"		Setrika";
						}
						else {
							cout<<"	Layanan Tidak diketahui";
						}
	
						if(datapelanggan[x].lama==1){
							cout<<", Reguler (3 Hari)"<<endl;
						}
						else if(datapelanggan[x].lama==2){
							cout<<", One Day Service"<<endl;
						}
						else if(datapelanggan[x].lama==3){
							cout<<", Super Kilat"<<endl;
						}
						else {
							cout<<", Laundry Tidak akan selesai"<<endl;
						}
					cout<<"	Berat laundry = "<<datapelanggan[x].berat<<" Kg"<<endl;
					cout<<"	Total Bayar = Rp "<<datapelanggan[x].harga<<"-,\n";
					cout<<"	Kode UNIK = "<<datapelanggan[x].kode<<endl;
					}
				}

				else if(pilih==2){cout<<"Masukkan Kode UNIK = ";
				cin.ignore();getline(cin,unik);
				ketemukode = false;
				y=0;
					while ((y<banyakdata)&&(!ketemukode))
					{
						if (datapelanggan[y].kode == unik)
						{
							ketemukode=true;
						}
						else
							y=y+1;
					}
					if (ketemukode)
					{
						cout<<"	Data Saudara "<<datapelanggan[y].nama<<endl;
						cout<<"	Pesanan dan Layanan\n";
								cout<<"	Pesanan dan Layanan\n";
						if(datapelanggan[y].layanan==1){
							cout<<"		Clean & Clear";
						}
						else if(datapelanggan[y].layanan==2){
							cout<<"		Cuci & Keringkan";
						}
						else if(datapelanggan[y].layanan==3){
							cout<<"		Setrika";
						}
						else {
							cout<<"	Layanan Tidak diketahui";
						}
	
						if(datapelanggan[y].lama==1){
							cout<<", Reguler (3 Hari)"<<endl;
						}
						else if(datapelanggan[y].lama==2){
							cout<<", One Day Service"<<endl;
						}
						else if(datapelanggan[y].lama==3){
							cout<<", Super Kilat"<<endl;
						}
						else {
							cout<<", Laundry Tidak akan selesai"<<endl;
						}
					cout<<"	Berat laundry = "<<datapelanggan[y].berat<<" Kg"<<endl;
					cout<<"	Total Bayar = Rp "<<datapelanggan[y].harga<<"-,\n";
					cout<<"	Kode UNIK = "<<datapelanggan[y].kode<<endl;
					}
				}
				
			break;
			
			default: cout<<"Input Salah!";break;
		char x;
		cout<<"Cek Lagi ? (y/n) ";
		cin>>x;
		if(x=='y')
			output();	
	}
}


int main(){

	if(log==0){
	cout<<"=====================================================================\n"
		<<"====================== Welcome to Nagi Laundry ======================\n"
		<<"=====================================================================\n"
		<<"\nPlease login"<<endl;
	login();log+=1;}
	
system("CLS");
	cout<<"=====================================================================\n"
		<<"======================== Welcome to Main Menu =======================\n"
		<<"=====================================================================\n"
		<<"Choose what you want to do next";
	cout<<"\n1. Input data\n2. Check data\n3. Sorting\n4. Exit\nWhat you want to do next = ";
	cin>>pilih;
		switch (pilih){
		case 1 :
			input();
		break;
		case 2 :
			output();
		break;
		case 3:
			ngesort();
		break;
		case 4:
			cout<<"============================ Terima Kasih ============================";
			return 0;
		break;
		default:
			cout<<"Input salah";
		}
		cout<<"	Back to menu ?(y/n) = ";
			cin>>choose;
				system("CLS");
		if(choose=='y'||choose=='Y')main();
		else cout<<"============================ Terima Kasih ============================";
}