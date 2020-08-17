#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool check_cal[16];
bool check_dig1[31];
bool check_dig2[31];
int n;
int ans = 0;

bool check(int row, int cal){
	if(check_cal[cal]) return false;
	if(check_dig1[row+cal]) return false;
	if(check_dig2[row - cal + n - 1]) return false;
	return true;
}

void solve(int row){
	if(row == n){
		ans++;
		return;
	}
	
	for(int cal = 0 ; cal < n ; cal++){
		if(check(row,cal)){
			check_cal[cal] = true;
			check_dig1[row+cal] = true;
			check_dig2[row - cal + n -1] = true;
			solve(row+1);
			check_cal[cal] = false;
			check_dig1[row+cal] = false;
			check_dig2[row - cal + n -1] = false;
		}
	}
	return;
}

int main() {
	scanf("%d",&n);
	solve(0);
	printf("%d\n",ans);
    return 0;
}