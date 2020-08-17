#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Point{
  int x,y;
  Point(){
  }
  Point(int x,int y) : x(x), y(y){
  }
  bool operator < (const Point &v) const {
    if(x == v.x){
      return y < v.y;
    }
    else{
      return x < v.x;
    }
  }
};

int dist(Point p1, Point p2){
  return (p1.x-p2.x) * (p1.x-p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(const Point &u, const Point &v){
  return u.y < v.y;
}

int brute_force(vector<Point> &a, int start, int end){
  int ans = -1;
  for(int i = start ; i < end ; i++){
    for(int j = i + 1 ; j <= end ; j++){
      int d = dist(a[i],a[j]);
      if(ans == -1 || ans > d) ans = d;
    }
  }
  return ans;
}

int go(vector<Point> &a, int start, int end){
  if(end - start <= 2) return brute_force(a,start,end);

  int mid = (start + end)/2;
  int ans = min(go(a,start,mid), go(a,mid+1,end));

  vector<Point> b;

  for(int i = start ; i <= end ; i++){
    int d = a[i].x - a[mid].x;
    if(d*d < ans){
      b.push_back(a[i]);
    }
  }

  sort(b.begin(),b.end(),cmp);

  int m = b.size();
  for(int i = 0 ; i < m - 1 ; i++){
    for(int j = i+1 ; j < m ; j++){
      int d = b[i].y - b[j].y;
      if(d*d < ans){
        int temp = dist(b[i],b[j]);
        if(temp < ans) ans = temp;
      }
      else{
        break;
      }
    }
  }
  return ans;
}


int main(void){
  int n;
  scanf("%d",&n);
  vector<Point> a(n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d %d",&a[i].x,&a[i].y);
  }

  sort(a.begin(),a.end());

  printf("%d\n",go(a,0,n-1));
  return 0;
}
