#include <stdio.h>
#include <stdlib.h>


void sort(int*arr,int l,int r)
{
    int i=l, j=r;
    int d;
    int m=arr[(l+r)/2];
    while(i<=j)
    {
        for(; arr[i]<m; i++);
        for(; arr[j]>m; j--);
        if(i<=j)
        {
            d=arr[i];
            arr[i++]=arr[j];
            arr[j--]=d;
        }
    }
    if(l<j) sort(arr,l,j);
    if(i<r) sort(arr,i,r);
 
}
int main()
{

    int i, n;
    
scanf("%d", &n);
    
int mass [n];
    
for (i = 0; i<n; i++) 
scanf("%d", &mass[i]);
sort(mass,0,n-1);

    
for (i = 0; i<n; i++) 
printf("%d ", mass[i]);
printf("\n");    
return 1;
}
