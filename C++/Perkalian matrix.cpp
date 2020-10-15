#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n,x,y,temp;

    cout<<"Input size of the first matrix : ";
    cin>>n>>m;
    cout<<"Input size of the second matrix : ";
    cin>>x>>y;

    if(m != x)
        cout<<"Invalid size"<<endl;

    int m1[n][m],m2[x][y],ans[n][y];

    for(int a=0; a<n; a++)
        for(int b=0; b<m; b++)
            cin>>m1[a][b];

    cout<<endl;

    for(int a=0; a<x; a++)
        for(int b=0; b<y; b++)
            cin>>m2[a][b];

    cout<<endl;

    for(int a=0; a<n; a++){
        for(int b=0; b<y; b++) {
            temp=0;
            for(int c=0; c<n; c++)
                temp += m1[a][c] * m2[c][b];
            ans[a][b] = temp;
            cout<<ans[a][b]<<' ';
        }
        cout<<endl;
    }

}
