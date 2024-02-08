#include<stdio.h>
#include<string.h>
#define MOD 1000000007

int countHomogenous(char *s){
    int n = strlen(s);
    long long ans = 0;
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && s[j] == s[i]) j++;
        int len = j - i;
        ans += (long long)len * (len + 1) / 2;
        ans %= MOD;
        i = j;
    }
    return ans;
}
int main(){
	char a[100000];
	printf("Enter a word: ");
	scanf("%s",a);
	printf("Number of homogenous substrings is %d",countHomogenous(a));
	return 0;
}
