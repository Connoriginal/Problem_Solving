#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>


using namespace std;

int a[1001][3];

int main(int argc, char** argv)
{
	setbuf(stdout,NULL);
	int t;
	scanf("%d",&t);
	for(int i = 0 ; i < t ; i++){
		double ans = 0.0;
		int R,S,E;
		scanf("%d %d %d",&R,&S,&E);
		ans = double(E - S);
		int N;
		scanf("%d",&N);
		for(int j = 0 ; j < N ; j++){
			scanf("%d %d %d",&a[j][0],&a[j][1],&a[j][2]);
		}
		
		for(int j = 0 ; j < N ; j++){
			if(a[j][2] >= R){
				ans += (M_PI - 2) * R;
				ans += 2*(a[j][2] - R);
			}
			else{
				double l = sqrt(pow(R,2) - pow(R-a[j][2],2));
				ans -= 2 * l;
				ans += 2*R*atan(l/(R - a[j][2]));
			}
		}
		
		printf("Case #%d\n",i+1);
		printf("%lf\n",ans);
	}
	return 0;
}