
#include<iostream>
#include<vector>

using namespace std;

vector<int>  find_max_left(vector<int>v);
vector<int>  find_max_right(vector<int>v);


int main(int argc, char *argv[])
{
	int i;
	int total_rain=0;
	int mins;
	int val=min(3,3);
	cout << val << endl;
	vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
	
	vector<int>pk_ll=find_max_left(v);
	
	vector<int>pk_rr=find_max_right(v);

	
	for(i=0;i<v.size();i++)
	{
		//min=(pk_ll[i]<pk_rr[i])?pk_ll[i]:pk_rr[i];
		//if(pk_ll[i]==pk_rr[i])
			//min=0;
			
		mins=min(pk_ll[i],pk_rr[i]);
		cout << pk_ll[i] <<" \t" <<  pk_rr[i] << endl;
		cout << "i=" << i << " min=" << mins << endl;
		total_rain+= mins-v[i];	
		cout << "total_rain=" << total_rain << endl;
	}
	
	cout << "Result=" << total_rain << endl;
			
	return 0;
}

vector<int>  find_max_left(vector<int>v)
{
	int i,j;
	vector<int> ll;
	int max=v[0];
	ll.push_back(max);
		for(i=1;i<v.size();i++)
		{
			if(max < v[i])
			{
				max=v[i];	
			}
			ll.push_back(max);	
		}
		return ll;	
}


vector<int>  find_max_right(vector<int>v)
{
	int i;
	int end_idx=v.size();
	vector<int> rr;
	int max=v[end_idx-1];
	rr.push_back(max);
		for(i=end_idx-2;i>=0;i--)
		{
			if(max < v[i])
			{
				max=v[i];	
			}
			rr.push_back(max);	
		}
		return rr;	
}
