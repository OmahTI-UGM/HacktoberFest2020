#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
	
	int x,a,b,c,d,e,f,g;
	string z;
		
	do{
		cout<<"Menu : "<<"\n1. Perkalian"<<"\n2. Pangkat"<<"\n3. Faktorial"<<"\n Pilihan : ";
		cin>>x;
	
		if(x==1){
			cout<<"\nProgram Perkalian";
			cout<<"\nBilangan	: ";
			cin>>a;
			cout<<"Dikali		: ";
			cin>>b;
		int j=b;
			cout<<endl;
			cout<<a;
			b--;
				while(b!=0){
					cout<<" + "<<a;
					b--;
				}
			cout<<" = "<<a*j;
			
		}
		
		else if(x==2){
			cout<<"\nProgram Perpangkatan";
			cout<<"\nBilangan	: ";
			cin>>c;
			cout<<"Pangkat		: ";
			cin>>d;
		int h=d, m=c, k=c;
			cout<<c;
			d--;
				while(d!=0){
					cout<<" x "<<c;
					d--;
				}
			for(f=h;f>1;f--){
				k=k*m;
			}
			cout<<" = "<<k;
		
		}
	
		else if(x==3){
			cout<<"\nProgram Faktorial";
			cout<<"\nBilangan : ";
			cin>>e;
			int i=e;
			cout<<e;
				while(e>1){
					e--;
					cout<<" x "<<e;
				}
			int y=1;
			for(g=i; g>1;g--){
				y=y*g;
			}
			cout<<" = "<<y;
			
		}
	
		cout<<"\nLagi (y/n)?";
			cin>>z;
		cout<<endl;
	}while(z=="y");
	return 0;
}