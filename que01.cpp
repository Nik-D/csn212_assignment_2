#include <stdlib.h>
#include<iostream>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int length(int b[], int m)
{
	int c[m][2];
	for (int i = 0; i < m; i++)
		c[i][0] = c[i][1] = 1;
	int res = 1;
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (b[j] < b[i] && c[i][0] < c[j][1] + 1)
				c[i][0] = c[j][1] + 1;
			if( b[j] > b[i] && c[i][1] < c[j][0] + 1)
				c[i][1] = c[j][0] + 1;
		}
		if (res < max(c[i][0], c[i][1]))
			res = max(c[i][0], c[i][1]);
	}
	return res;
}
int main()
{	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<"Length is "<<length(a, n);
	return 0;
}

