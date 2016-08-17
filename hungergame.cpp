#include<iostream>
#include<cstdio>
#include<cmath>
#define mod 1000000007
using namespace std;
int main()
{
	long long n, k;
	cin >> n >> k;
	long long *a;
	a = new long long[n];
	int i;
	for ( i = 0; i < n; i++)
		cin >> a[i];
	
	double *loga;
	loga = new double[n];
	double *dist;
	dist = new double[n];
	long long *cost;
	cost = new long long[n];
	for (i = 0; i < n; i++)
	{
		loga[i] = log(a[i]);
		//cout << "log(" << a[i] << ")=" << loga[i] << endl;
	}
	
	for (i = 1; i < n; i++)
	{
		dist[i] = 1e9;
		//cout << dist[i] << endl;
	}
	dist[0] = 0;


	cost[0] = a[0];
	int cur;
	bool *vis;
	vis = new bool[n];
	for (i = 0; i < n; i++)
		vis[i] = false;
	double path;
	for (i = 0; i < n; i++)
	{
		//cout << "i=" << i << endl;
		cur = -1;
		for (int j = i - k; j <= i + k; j++)
		{
			if (j >= 0 && j < n )
			{
				if (vis[j])continue;
				if (cur == -1 || dist[j] < dist[cur])
					cur = j;
			}
		}
		vis[cur] = true;
		//cout << "Current:" << cur << endl;
		for (int j = cur +1; j <= cur + k; j++)
		{
			if (j >= 0 && j < n )
			{
				path = dist[cur] +  j;
				if (path < dist[j])
				{
					dist[j] = path;//cout<<vis[j]<<" ";
					if(path!=0)
					cout <<  path << endl;
					
					cost[j] = (cost[cur] * a[j]) % mod;
					//cout << "cost[" << j << "]=" <<cost[cur]<<"*"<<a[j]<<"="<< cost[j] << endl;
					if (j == n - 1)
					{
						 cout << cost[n - 1] << endl;
						return 0;
					}
				}
			}
		}
	}
	
	cout << cost[n-1] << endl;
	return 0;
}
