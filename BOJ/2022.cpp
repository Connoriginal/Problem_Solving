#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
  double x,y,c;
  scanf("%lf %lf %lf",&x,&y,&c);
  double left = 0, right = min(x,y);
  while(abs(right - left) > 1e-6){
    double mid = (left + right) / 2.0;
    double h1 = sqrt(x*x - mid*mid);
    double h2 = sqrt(y*y - mid*mid);
    double h = h1*h2/(h1+h2);
    if(h > c){
      left = mid;
    }
    else{
      right = mid;
    }
  }

  printf("%.3lf\n",left);
  return 0;
}
