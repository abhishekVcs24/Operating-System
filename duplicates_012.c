#include<stdio.h>


int main(){
int n,i,j,item;
int a[10];
int pos=-1;
printf("enter the length of elements:");
scanf("%d",&n);
for(int i=0;i<n;i++){
    printf("enter the elements:");
    scanf("%d",&a[i]);
}
for (i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(a[i]==a[j]){
            pos=1;
        }
    }
}
if(pos!=-1)
    printf("duplicate found at position %d",pos);
else
    printf("duplicate not found");
return 0;
}
