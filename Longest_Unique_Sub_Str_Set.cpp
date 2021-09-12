#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Largest Substring non repeating
// String = abcaeba
// Result = 
//abc
//bcae
//caeb
//eba
 
 void find_unique_sub_str(string & str,vector<string>& v_str)
{
	int i,j,k,n;
	int index_found;
	n=str.size();
	
	if(n==1)
	{
		return ;
	}
	else
	{
		k=0;
		i=0;
		unordered_map<char,int> mp;
		unordered_map<char,int> :: iterator itr;
			string new_str="";
			new_str+=str[i];
			mp[str[i]]=i;
			for(j=i+1;i<j && j<n;j++)
			{
				itr=mp.find(str[j]);
				if(itr==mp.end())
				{
					new_str=new_str+str[j];
					mp[str[j]]=j;
				}
				else
				{
					index_found=itr->second;
					mp[str[j]]=j;
					v_str.push_back(new_str);
					i=index_found+1;
					new_str=str.substr(i,j-i);
					new_str+=str[j];
				}
			}
			v_str.push_back(new_str);
	}
}
void print_vector(vector<string> v)
{
	//cout << "Vector Print" << endl;
	for(auto ss:v)
	{
		cout << ss << endl;
	}	
}


int main(int argc, char *argv[])
{
	string str="abcaeba";
	
	vector <string> v_str;
	
	find_unique_sub_str(str,v_str);
	
	print_vector(v_str);
	
	return 0;
}


