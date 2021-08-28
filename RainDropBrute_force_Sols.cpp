
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*
Problem on Rain drop
Find the water stored at the top of the building.

Approach 1: Brute Force
Complexity  O(N*N)
*/

#include <iostream>
#include <vector>

using namespace std;

int find_max(vector<int> v);
int find_min(int i,vector<int> v);

int main(int argc, char *argv[])
{
	
		int i;
		int total_water_stored=0;	
	vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
	
	int rain_here=0;
	for(i=0;i<v.size();i++)
	{
		//rain_here=find_min(i,v)-v[i];
		if((rain_here=find_min(i,v)-v[i]) > 0)
		{
			cout << "rain_here=" << rain_here << endl;
			total_water_stored+=rain_here;
		}
		else
			rain_here=0;
			
		cout <<"i="<< i << "   total=" << total_water_stored << endl;
	}	
	//total_water_stored=find_min(7,v)-3;	
	cout << "Result =" << total_water_stored << endl;	
		return 0;	
}

int find_max(vector<int> v)
{
	if(v.size()==0)
		return -1;

	int max=v[0];
	int i;
	
	for(i=1;i<v.size();i++)
	{
		if(max<v[i])
		{
			max=v[i];
		}
	}
	return max;
}


int find_min(int i,vector<int> v)
{
	int index;
	int max_left,max_right;
	vector<int> pk_l;
	vector<int> pk_r;
	if(i != 0)
	{	
		for(index=0;index<i;index++)
		{
			pk_l.push_back(v[index]);
		}
		//left.assign(v.begin(),&v.at(i-1));
	}
	
	else
	{
		cout << "i is zero" << endl;
	}
	
	if(i!=v.size()-1)
	{
		for(index=i+1;index<v.size();index++)
		{
			pk_r.push_back(v[index]);
		}
		//right.assign(&v.at(i+1),v.end());
	}
	
	max_left=find_max(pk_l);
	max_right=find_max(pk_r);
	
	cout << "max_left=" << max_left << endl;
	cout << "max_right=" << max_right << endl;
	
	return (max_left>max_right)?max_right:max_left;
	
}


