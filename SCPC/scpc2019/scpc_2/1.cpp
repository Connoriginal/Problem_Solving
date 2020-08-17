#include <iostream>
#include <cstdio>
using namespace std;


int prime[30001]; //false가 소수
int Answer;


int check_prime(int x){
  int ans = 0;
  int num[7];

  if(prime[x]) return 0;
  ans++;
  if(x >= 10){
    int tmp = x;
    int size = 1;
    while(tmp>0){
      num[size++] = tmp%10;
      tmp/=10;
    }
    int com = 0;
    for(int i = 1 ; i < size ; i++){
      int a = 0;
      for(int j = size-1 ; j > 0 ; j--){
        if(j == i) continue;
        if(a != 0) a *= 10;
        a += num[j];
      }
      int b = check_prime(a);
      com = max(com,b);
    }
    ans += com;
  }
  return ans;
}


int main(int argc, char** argv)
{
  for(int i = 2 ; i * i < 30001 ; i++){
    for(int j = i*i ; j < 30001 ; j+=i){
      prime[j] = true;
    }
  }
  prime[1] = true; prime[0] = true;

	int T, test_case;
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
    Answer = 0;
    int a_num,b_num;
    scanf("%d %d",&a_num,&b_num);
    int a_score = check_prime(a_num);
    int b_score = check_prime(b_num);

    Answer = (a_score > b_score) ? 1 : (a_score == b_score) ? 3 : 2;

    printf("Case #%d\n",test_case+1);
		printf("%d\n",Answer);
	}

	return 0;
}
