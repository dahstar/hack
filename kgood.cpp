#include<iostream>
#include<string>
#include<algorithm>
#include <time.h>

using namespace std;
int isgood(string s,int k)
{
	int count1=0;
	for(int i=0;i<s.length();i++)
		if(s[i]!=' ')
     	for(int j=i+1;j<s.length();j++)
			
			{
				if((i!=j)&&(s[i]!=s[j]))
		{
			
			if(abs(count(s.begin(),s.end(),s[i])-count(s.begin(),s.end(),s[j]))>k)
			{count1+=1;s[i]=' ';s[j]=' ';
			}
		
		}
		}
			return count1;
 
}
int main()
{
	
	int t=0;string s="";int k=0;string s1="";

	cin>>t;
	    

	for(int i=0;i<t;i++)
	{
		cin>>s1>>k;
	s+=to_string(isgood(s1,k))+"\n";
 

	}
	cout<<s;
	

	return 0;
} 
