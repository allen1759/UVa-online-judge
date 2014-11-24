#include<stdio.h>

void quicksort(int a[],int l,int h);

int arr[2000000];
int main()
{
    int n;
    scanf("%d", &n);
    while(n!=0)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&arr[i]);
        quicksort(arr,0,n-1);
        for(int i=0; i<n-1; i++){
            printf("%d ", arr[i]);
        }
        printf("%d", arr[n-1]);
        scanf("%d",&n);
        printf("\n");
    }
    return 0;
}

void quicksort(int a[],int l,int h)
{
    if (l>=h)
        return ;
    int j ,i,key;
    i=l;
    j=h;
    key=a[i];
    while(i<j)
    {
        while(i<j&&a[j]>key)
            j--;
        if (i<j)
            a[i++]=a[j];
        while(i<j&&a[i]<key)i++;
        if (i<j)
            a[j--]=a[i];
    }
    a[i]=key;
    if (l<i-1)
        quicksort(a,l,i-1);
    if (i+1<h)
        quicksort(a,i+1,h);
}
