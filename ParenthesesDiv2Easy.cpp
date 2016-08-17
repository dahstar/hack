#include<vector>
#include<iostream>
#include<string>
using namespace std;
class ParenthesesDiv2Easy
{
public :
	 int getDepth(string s)
	{
		int max=0;int count=0;
		for(size_t i=0;i<s.length();i++)
		{
			if(s[i]=='(')
				count++;
			if(s[i]==')')
			{if(count>max)
			max=count;
			count=0;
			}
		}
		return max;

	}
};
int main()
{
	ParenthesesDiv2Easy pr;
	cout<<pr.getDepth("((())())(((())(()))()");
	system("pause");
	return 0;
}
