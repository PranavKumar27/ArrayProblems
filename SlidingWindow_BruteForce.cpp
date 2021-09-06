#include <iostream>
#include <vector>
//#include <pair>
//#include <bits/stdc++.h>
using namespace std;

// Numbers are 1 2 3 4 5 2 3 5 6 2 3 4 1 5
// Find all the sets of numbers whose sum is k. where k=8
// 3 5
// 6 2
// 3 4 1
#define K 8

vector<int> Result;

void subSetSumEqualsK(vector<int> v)
{
	int i,j;
	int n;
	
	n=v.size();
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=i;sum!=K && sum<K;j++)
		{
			sum+=v[j];
			
			if(sum==K)
			{
				Result.push_back(i);
				Result.push_back(j);
				vector<int> out(v.begin()+i,v.begin()+j+1);
				
				for(auto m:out)
				{
					cout << m << ",";
				}
				cout << endl;
			}
		}
	}
	cout << "Result in indexs in vector=" << endl;
	
	for(auto q:Result)
	{
		cout << q << ",";
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	vector<int> v= {1,2,3,4,5,2,3,5,6,2,3,4,1,5};
	
	subSetSumEqualsK(v);
	
	return 0;	
}
