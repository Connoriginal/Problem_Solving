#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int arr[10001];

void swap(int x, int y){
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
	return;
}

bool pre_per(int* arr, int n){
	int i = n-1;
	while(i > 0 && arr[i-1] < arr[i]) i--;
	if(i == 0) return false;
	int j = n-1;
	while(arr[i-1] < arr[j]) j--;
	swap(i-1,j);
	reverse(arr+i,arr+n);
	return true;
}

int main(void){
	int N;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d",&arr[i]);
	
	if(pre_per(arr,N)){
		for(int i = 0 ; i < N ; i++)
			printf("%d ",arr[i]);
	}
	else
		printf("-1");
	printf("\n");
	return 0;
}

