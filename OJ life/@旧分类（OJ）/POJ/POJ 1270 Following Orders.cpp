#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int ctoi[128], map[21][21], du[21], i,j, k;
char itoc[21];
bool un[21];
string s;

void Topological(int x, string s){
	int i;
	s += itoc[x];
	un[x] = 1;
	if (s.size() == k){
		cout << s << endl;
		un[x] = 0;
		return;
	}
	for (i = 1; i <= k; ++i)
		if (map[x][i] == 1){
		map[x][i] = 2;
		du[i]--;
		}
	for (i = 1; i <= k; ++i)
		if (du[i] == 0 && un[i]==0)
			Topological(i, s);
	for (i = 1; i <= k; ++i)
		if (map[x][i] == 2){
			map[x][i] = 1;
			du[i]++;
		}
	un[x] = 0;
}

int main()
{
	while (getline(cin, s)){
		memset(ctoi, 0, sizeof(ctoi));
		memset(itoc, 0, sizeof(itoc));
		memset(map , 0, sizeof(map));
		memset(du, 0, sizeof(du));
		memset(un, 0, sizeof(un));
		k = 0;
		for (i = 0; i<s.size(); i += 2){
			k++;
			itoc[k] = s[i];
			ctoi[s[i]] = k;
		}
		getline(cin, s);
		for (i = 0; i<s.size(); i += 4){
			map[ctoi[s[i]]][ctoi[s[i+2]]] = 1;
			du[ctoi[s[i+2]]]++;
		}
		for (i = 1; i <= k; ++i)
			if (du[i] == 0)
				Topological(i, "");
		cout<<endl;
	}
	return 0;
}
