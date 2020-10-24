#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Determinan matriks 3x3"<<endl;
    cout<<endl;

    int m[3][3];
    int temp, ans=0, x;

    for(int a=0; a<3; a++)
        for(int b=0; b<3; b++)
            cin>>m[a][b];

    for(int a=0; a<3; a++){
        temp = 1;
        for(int b=0; b<3; b++)
            temp *= m[b][(b+a)%3];
        ans += temp;
    }

    for(int a=0; a<3; a++){
        temp = 1;
        x=a;
        for(int b=2; b>=0; b--)
        {
            temp *= m[b][x];
            x = (x+1)%3;
        }
        ans -= temp;
    }

    cout<<ans<<endl;
}
