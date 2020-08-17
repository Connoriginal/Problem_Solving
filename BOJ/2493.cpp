#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <stack>


using namespace std;
int N;
stack<pair<int,int>> stk;
int tmp;

int main(void){
	scanf("%d",&N);
	
	for(int i = 1 ; i < N + 1 ; i++){
		scanf("%d",&tmp);
		while(!stk.empty()){
			if(stk.top().second > tmp){
				printf("%d ",stk.top().first);
				break;
			}
			stk.pop();
		}
		if(stk.empty())
			printf("%d ",0);
		stk.push(make_pair(i,tmp));
	}
	printf("\n");
	return 0;
}

/*
#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <stack>


using namespace std;
int N;
long long array[500001];
stack<int> stk;
bool check;

int main(void){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++)
		scanf("%lld",&array[i]);
	stk.push(0);
	printf("%d ",0);
	for(int i = 1 ; i < N ; i++){
		check = false;
		while(!stk.empty()){
			if(array[stk.top()] < array[i])
				stk.pop();
			else{
				printf("%d ",stk.top()+1);
				check = true;
				break;
			}
		}
		if(check == false)
			printf("%d ",0);
		stk.push(i);
	}
	printf("\n");
	return 0;
}
*/