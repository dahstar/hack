#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() 
{
  int r,l,n;long long int li,ri;long long int max,min;
  cin>>l>>r;min=0;max=0;
  cin>>n;
  for(int i=0;i<n;i++)
  {
  cin>>li>>ri;
  if((li>=l)&&(ri>=r))
  {min++;
max++;
  }
 
  if((li<l)&&(ri>r))
	  max++;
  else if((li>l)&&(ri<=r))
	  max++;
   else if((li>=l)&&(ri<r))
	  max++;
  else{
	  
  }
  
  }
  cout<<min<<" "<<max;
    return 0;
}