
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char *argv[])
{
	int i,n;
	string str="A B C D E                        ";                             
	int shift_by;
	n=str.size();
	
	// count no of spaces
	int spaces=0;
	for(i=0;i<n-1;i++)
	{
		if(str[i]==' ' && str[i+1]!=' ')
			spaces++;
	}
// Shift characters
	shift_by=2*spaces;
	for(i=n-1;i>=0;i--)
	{
		if(str[i]==' ')
			continue;
		else
			break;
	}
	//cout << "spaces= " << spaces << " i =" << i << endl;
	// Find the last character index which is not space
	for(;i>=0;i--)
	{
		if(str[i]!=' ')
			{
				str[i+shift_by]=str[i];
				
			//	cout << "if case str=" << str << " shift_by=" << shift_by << " i=" << i << endl;
			//	str[i]=' ';
			}
		else 
			{
				if(shift_by>0)
				{
				str[i+shift_by]='0';
				str[i-1+shift_by]='2';
				str[i-2+shift_by]='%';
				shift_by=shift_by-2;
				}
			}
			//cout << "str=" << str << endl;
	}
	
	cout << "str=" << str << endl;
	
	return 0;
			
}
