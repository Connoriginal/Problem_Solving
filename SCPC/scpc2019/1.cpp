#include <iostream>
#include <cstdio>

using namespace std;

int Answer;

int d[1000020];
int sum[1000020];


int main(int argc, char** argv)
{
    setbuf(stdout,NULL);
	int T, test_case;

	scanf("%d",&T);
	d[0] = 0; d[1] = 0; d[2] = 1;
	sum[0] = 0; sum[1] = 0; sum[2] = 1;
	for(int i = 3 ; i <= 1000000 ; i+=2){
	    d[i+1] = d[(i+1)/2] + 1;
		d[i] = d[i+1] + 1;
		sum[i] = sum[i-1] + d[i];
		sum[i+1] = sum[i] + d[i+1];
	}
	
	for(test_case = 0; test_case  < T; test_case++)
	{
        int N1, N2;
        scanf("%d %d",&N1,&N2);
		
		Answer = sum[N2] - sum[N1-1];
		
		
		printf("Case #%d\n",test_case+1);
		printf("%d\n",Answer);
	}

	return 0;
}