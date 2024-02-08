#include<stdio.h>
int compare(const void *a, const void *b) {
    double d1 = *(double*)a;
    double d2 = *(double*)b;
    
    if (d1 < d2) return -1;
    else if (d1 > d2) return 1;
    else return 0;
}
int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize) {
	int i;
    double time[distSize];
    for (i = 0; i < distSize; i++) {
        time[i] = (double)dist[i] / speed[i];
    }

    qsort(time, distSize, sizeof(double), compare);

    int eliminated = 0;
    for (i = 0; i < distSize; i++) {
        if (time[i] <= i) {
            break;
        }
        eliminated++;
    }

    return eliminated;
}
int main(){
	int n,spd[n],dis[n],i;
	printf("Enter the number of monsters: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the distance of a monster: ");
	    scanf("%d",&dis[i]);
	}
	for(i=0;i<n;i++){
		printf("Enter the speed of a monster: ");
	    scanf("%d",&spd[i]);
	}
	printf("Maximum number of monsters that can be eliminated is %d",eliminateMaximum(dis,n,spd,n));
	return 0;
}
