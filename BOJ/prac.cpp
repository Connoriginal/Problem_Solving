#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char str1[100],str2[100];

int main(void){
  string str3;
  //fgets(str1,100,stdin);
  //scanf("%[^\n]\n",str2);
  getline(cin,str3);
  //cout << str1 << '\n';
  //cout << str2 << '\n';
  cout << str3 <<'\n';
  return 0;
}
