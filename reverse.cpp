
#include <bits/stdc++.h>
using namespace std;
void reverse(char s[])
{
    int length = strlen(s) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
int main() {
	int t;int i=0;
  char s[50];
  cin>>t;
  while(i++<t)
  {
   cin>>s;
  reverse(s);
   cout<<s<<endl;
  }
  return 0;
}


