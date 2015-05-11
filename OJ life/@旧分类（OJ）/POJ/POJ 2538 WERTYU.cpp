#include <iostream>
using namespace std;
int main()
{
	char arr[128]; int i; string s;
	for (i=1;i<128;++i)
		arr[i]=i;
	arr['1']='`'; arr['W']='Q'; arr['S']='A'; arr['X']='Z';
	arr['2']='1'; arr['E']='W'; arr['D']='S'; arr['C']='X';
	arr['3']='2'; arr['R']='E'; arr['F']='D'; arr['V']='C';
	arr['4']='3'; arr['T']='R'; arr['G']='F'; arr['B']='V';
	arr['5']='4'; arr['Y']='T'; arr['H']='G'; arr['N']='B';
	arr['6']='5'; arr['U']='Y'; arr['J']='H'; arr['M']='N';
	arr['7']='6'; arr['I']='U'; arr['K']='J'; arr[',']='M';
	arr['8']='7'; arr['O']='I'; arr['L']='K'; arr['.']=',';
	arr['9']='8'; arr['P']='O'; arr[';']='L'; arr['/']='.';
	arr['0']='9'; arr['[']='P'; arr['\'']=';';
	arr['-']='0'; arr[']']='[';
	arr['=']='-';
	
	while (getline(cin,s)){
		for (i=0;i<s.size();++i)
			cout<<arr[s[i]];
		cout<<endl;
	}
	
	return 0;
}
