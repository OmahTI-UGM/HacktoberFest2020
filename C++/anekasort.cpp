#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef int larik[260000];

long long c=0,ccc;
int n,cc=0,p=0;

void cetakdata(larik x,int n)
{int i;
 for (i=1;i<=n;i++) {
    cout<<x[i]<<" ";
   }
 cout<<endl;
 cout<<endl;getch();
}

void sortI1(larik x,int aw,int ak)
{int i,j,a;
    for(int i=aw+1;i<=ak;i++){
      j=i-1;a=x[i];
      while (j>0 && x[j]>a)
       { x[j+1]=x[j];  
         j--;
       } 
       x[j+1]=a;
     }
}

void tukar(int &a,int &b)
{int t;
  t=a;a=b;b=t;c++;
}

void sortI(larik x,int n)
{int i,j,a;
    for(int i=2;i<=n;i++){
      j=i-1;a=x[i];
      while (j>0 && x[j]>a)
       { x[j+1]=x[j];  j--;
       } 
       x[j+1]=a;
     }
}
void sortS(larik x,int n)
{int i,j,t ;
 for (i=1;i<=n-1;i++)
  for (j=i+1;j<=n;j++) {
   if (x[i]<x[j]) tukar(x[i],x[j]);
  }
}    
void sortB(larik x,int n)
{int i,j,t ;
 for (i=1;i<=n-1;i++)
  for (j=1;j<=n-i;j++) {
   if (x[j]>x[j+1]) tukar(x[j],x[j+1]);}
  }


void partisiA(larik x,int aw,int ak,int &id)
{ int i,j,t,pivot;
   pivot=x[aw];j=aw;
   for (i=aw+1;i<=ak;i++)
     if (x[i]<pivot) {
       j++;t=x[i];x[i]=x[j];x[j]=t;
     }
  x[aw]=x[j];x[j]=pivot;
  id=j;
//  cetakdata(x,n);
}
void partisiAR(larik x,int aw,int ak,int &id)
{ int i,r,j,t,pivot;
   r=rand()%(ak-aw+1)+aw;
   pivot=x[r];x[r]=x[aw];x[aw]=pivot;
   j=aw;
   for (i=aw+1;i<=ak;i++)
     if (x[i]<pivot) {
       j++;t=x[i];x[i]=x[j];x[j]=t;
     }
  x[aw]=x[j];x[j]=pivot;
  id=j;
}

void partisiR(larik x,int aw,int ak,int &j)
{ int i,r,t,pivot;
  r=rand()%(ak-aw+1)+aw;
  pivot=x[r];x[r]=x[aw];x[aw]=pivot;
  i=aw;j=ak;
  while (i<j){
    while ((x[i]<=pivot)&&(i<ak)) i++;
    while ((x[j]>pivot)&&(j>aw)) j--;
    if (i<j) {t=x[i];x[i]=x[j];x[j]=t;}
  }
  x[aw]=x[j];x[j]=pivot;
}

void partisi(larik x,int aw,int ak,int &j)
{ int i,t,pivot;
  pivot=x[aw];
  i=aw;j=ak;
  while (i<j){
    while ((i<ak)&&(x[i]<=pivot)) i++;
    while ((j>aw)&&(x[j]>pivot)) j--;  
    if (i<j) {t=x[i];x[i]=x[j];x[j]=t;}
  }
  x[aw]=x[j];x[j]=pivot;
//  cetakdata(x,n);
}

void qsort(larik x,int aw,int ak)
{int j;
  if (aw<ak) {
     partisiA(x,aw,ak,j);
     qsort(x,aw,j-1);
     qsort(x,j+1,ak);
  }
}

void merge(larik x, int aw,int mid,int ak)
{larik z;  int i,j,k,l;
  i=aw;j=mid+1;k=aw;
  do {cc++;
    if(x[i]<=x[j]) {z[k]=x[i];i++;}
    else {z[k]=x[j];j++;}
    k++;}
  while ((i<=mid) && (j<=ak));
  if (i>mid) for (l=j;l<=ak;l++) {z[k]=x[l];k++;}
  else for (l=i;l<=mid;l++) {z[k]=x[l];k++;}
  for (k=aw;k<=ak;k++) x[k]=z[k];
}
void mergesort(larik x,int aw,int ak)
{int mid;
  if(aw<ak) {
    mid =(aw+ak)/2;
    mergesort(x,aw,mid);
    mergesort(x,mid+1,ak);
    merge(x,aw,mid,ak);
  }
}

void MergeQuick(larik x,int aw,int ak)
{int mid;
  if(ak-aw<1000) qsort(x,aw,ak);
  else {
    mid =(aw+ak)/2;
    MergeQuick(x,aw,mid);
    MergeQuick(x,mid+1,ak);
    merge(x,aw,mid,ak);
  }
}

void cauntingsort(larik x,int n)
{int t[101]={0},i,j=1;
   for (i=1;i<=n;i++) t[x[i]]++;
   for (i=1;i<=100;i++) 
   while (t[i]>=1) {
     x[j]=i;j++;t[i]--;
   }
}

void buatdata(larik x,int &n)
{int i;
 cout<<"banyak data :";cin>>n;
 srand(time(NULL));
 for (i=1;i<=n;i++) {
    x[i]= rand()*23456%1000000+1;
//    cout<<x[i]<<" ";
   }
// cout<<endl;
 cout<<endl;
}

void create_heap(larik a,int n)
{
int q,i,j,key;
  for(q=2;q<=n;q++)
  {
    i=q;
    key=a[i];
    j=i/2;
    while(i>1 && key>a[j])
      {
         a[i]=a[j];
         i=j;
         j=i/2;
         if(j<1)
            j=1;
      }
    a[i]=key;
    }
}

void sort_heap(larik a,int n)
{
int q,i,j,key,temp;
  create_heap(a,n);
  for(q=n;q>=1;q--)
  {
     temp=a[1];
     a[1]=a[q];
     a[q]=temp;
     i=1;
     key=a[i];
     j=2*i;
     if(j+1 < q)
     {
         if(a[j+1] > a[j])
            j++;
        }
     while(j<=q-1 && key<a[j])
     {
       a[i]=a[j];
       i=j;
       j=2*i;
       if(j+1 < q)
       {
          if(a[j+1] > a[j])
             j++;
       }
       else break;
     }
     a[i]=key;
    }
}

main()
{ int i,j;
  larik x;
  buatdata(x,n);
//  cetakdata(x,n);
    // cauntingsort(x,n);
    //sortS(x,n);
  clock_t begin_time = clock();
    sortI(x,n);
    // MergeQuick(x,1,n);
    //sort_heap(x,n);
    //mergesort(x,1,n);
  cout << float( clock () - begin_time )/CLOCKS_PER_SEC<<endl;
  //cetakdata(x,n);
  //ccc=(n/2)*(n-1);
 // cout<<"\n TUKAR = "<<c;//<<" B/S = "<<c;
 getch();
}
