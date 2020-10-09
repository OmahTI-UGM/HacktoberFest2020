#include <iostream>
using namespace std;
long long n,k,p;
string s[20]={" nol"," satu"," dua"," tiga"," empat"," lima"," enam"," tujuh"," delapan"," sembilan"," sepuluh"," sebelas"," dua belas"," tiga belas"," empat belas"," lima belas"," enam belas"," tujuh belas"," delapan belas"," sembilan belas"};
void puluhan(long long a){a=a%100;
		if(a<20&&a>0){cout<<s[a];}
		else if(a/10!=0){cout<<s[a/10]<<" puluh";	a=a%10;
			if(a>0)cout<<s[a%10];}}
void ratusan(long long a){
		if(a/100==1){cout<<" seratus";puluhan(a);}
		else if(a/100!=0){cout<<s[a/100]<<" ratus";puluhan(a);}
		else if(a<100) puluhan(a);}
void ribuan(long long a){
		if(a/100000==1 && a%100000==0)cout<<" seratus ribu";
		else if(a/1000==1){cout<<" seribu";}
		else if(a%100000!=0){k=a/1000; 
			if(k!=1){ratusan(k);cout<<" ribu";}}p=a%1000;ratusan(p);}
void banyak(long long a){
if(a<1000000000000000 && a>=1000000000000){k=a/1000000000000;
	if(k!=0){ratusan(k);cout<<" triliyun";}p=a%1000000000000; banyak(p);}
else if(a<1000000000000 && a>=1000000000){k=a/1000000000;
	if(k!=0){ratusan(k);cout<<" milyar";p=a%1000000000; banyak(p);}}
else if(a<1000000000 && a>=1000000){k=a/1000000;
	if(k!=0){ratusan(k);cout<<" juta";}p=a%1000000; ribuan(p);}}
int main(){
	cout<<"Masukan Angka : "; cin>>n;
	cout<<"Angka yang anda masukan :";
	if(n==0)cout<<s[n];
	else if(n<1000)ratusan(n);
	else if(n<1000000&&n>=1000)ribuan(n);
	else if(n>=1000000)banyak(n);}