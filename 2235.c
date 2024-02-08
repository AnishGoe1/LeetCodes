#include<stdio.h>
int sum(int num1, int num2) {
    return num1+num2;
}
int main(){
	int x,y;
	printf("Enter a number: ");
	scanf("%d",&x);
	printf("Enter a number: ");
	scanf("%d",&y);
	printf("Sum of %d and %d is %d",x,y,sum(x,y));
	return 0;
}
