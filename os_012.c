#include<stdio.h>


int main(){
int n,i,item;
int a[10];
int pos=-1;
printf("enter the length of elements:");
scanf("%d",&n);
for(int i=0;i<n;i++){
    printf("enter the elements:");
    scanf("%d",&a[i]);
}
printf("enter the element to search:");
scanf("%d",&item);
for (int i=0;i<n;i++){
    if(item==a[i])
       pos=i;
}
if(pos!=-1)
    printf("element found at position %d",pos);
else
    printf("element not found");
return 0;
}
