#include<stdio.h>
int isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int dx = abs(fx - sx), dy = abs(fy - sy);
    if(sx==fx && sy==fy){
        return (t>1||t==0);
    }
    int ex= abs(dy-dx);
    return (dy<dx?dy:dx)+ex <=t;
}
int main(){
	int x1,y1,x2,y2,t1;
	printf("Enter the x and y coordinate of current position: ");
	scanf("%d%d",&x1,&y1);
	printf("Enter the x and y coordinate of final position: ");
	scanf("%d%d",&x2,&y2);
	printf("Enter time: ");
	scanf("%d",&t1);
	int a=isReachableAtTime(x1,y1,x2,y2,t1);
	if(a==1){
		printf("The given cell is reachable at final cell in given cell.");
	}
	else{
		printf("The given cell is not reachable at final cell in given cell.");
	}
	return 0;
}
