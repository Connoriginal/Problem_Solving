#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

char a[26], txt[300001];
int alen,txtlen;
int l,r;

char lstk[300001], rstk[300001];
int lp = 0,rp = 0;

bool op = true;

bool check(void){
  if(op){
    if(lp < alen) return false;
    for(int i = 0 ; i < alen ; i++){
      if(lstk[lp - alen + i] != a[i]) return false;
    }
    lp = lp - alen;
  }
  else{
    if(rp < alen - 1) return false;
    for(int i = 0 ; i < alen ; i++){
      if(rstk[rp - 1 - i] != a[i]) return false;
    }
    rp = rp - alen;
  }
  return true;
}

int main(void){
  scanf("%s %s",a,txt);
  alen = strlen(a);
  txtlen = strlen(txt);
  l = 0, r = txtlen - 1;

  while(l<=r){
    if(op){
      lstk[lp++] = txt[l];
      if(txt[l] == a[alen-1] && check()){
        op = false;
      }
      l++;
    }
    else{
      rstk[rp++] = txt[r];
      if(txt[r] == a[0] && check()){
        op = true;
      }
      r--;
    }
  }
  op = true;

  if(rp){
    while(rp--){
      lstk[lp++] = rstk[rp];
      if(rstk[rp] == a[alen-1]) check();
    }
  }

  for(int i = 0 ; i < lp ; i++){
    printf("%c",lstk[i]);
  }
  printf("\n");
  return 0;
}
