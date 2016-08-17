
#include <bits/stdc++.h>
using namespace std;
void reverse(char s[])
{
  
}
int main() {
	int t;int i=0;
  char s[50];
  cin>>t;
  while(i++<t)
  {
   cin>>s;
     int length = strlen(s) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        if(s[i]==s[i+1])
			remove(s, s+length, i);
    }
 
   cout<<s<<endl;
  }
  return 0;
}


