#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
vector<int> vec(5001);
vector<int> a(5001);
vector<int> b(5001);

int check(vector<int> a, vector<int> b, int n){
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    if(a[i] == b[i]) ans++;
  }
  return ans;
}

int main(int argc, char** argv)
{
  setbuf(stdout,NULL);
	int T, test_case;

	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
      scanf("%d",&a[i]);
    }
    for(int i = 0 ; i < n ; i++){
      scanf("%d",&b[i]);
    }

    Answer = check(a,b,n);
    for(int i = 0 ; i < n-1 ; i++){
      if(a[i] == b[i]) continue;
      else{
        int tmp;
        for(int j = i + 1 ; j < n ; j++){
            if(a[i] == b[j]){
              copy(b.begin(),b.end(),vec.begin());
              reverse(vec.begin()+i,vec.begin()+j+1);
              tmp = check(a,vec,n);
              Answer = max(tmp,Answer);
            }
        }
      }
    }
    printf("Case #%d\n",test_case+1);
    printf("%d\n",Answer);
	}

	return 0;
}
