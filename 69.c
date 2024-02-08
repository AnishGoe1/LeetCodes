#include<stdio.h>
int mySqrt(int x){
    long int y=0;
    while(y*y<=x){
        y++;
    }
    return y-1;
}
int main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("SQRT of %d is %d",n,mySqrt(n));
	return 0;
}

