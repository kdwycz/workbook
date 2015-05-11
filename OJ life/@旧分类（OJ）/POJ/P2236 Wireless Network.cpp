#include <iostream>
#include <cmath>
using namespace std;

struct coordinate{
	int x,y;
}coo[1010];
int set[1010] = { 0 }, map[1010][1010] = { 0 };
int n,d,x,y,i,j;
string s;

int FindSet(int x);
void Union(int x,int y);
int main()
{
	cin>>n>>d;
	for (i=1;i<=n;++i)
		cin>>coo[i].x>>coo[i].y;

	for (i=1;i<n;++i)
		for (j=i+1;j<=n;++j)
			if (sqrt((coo[i].x - coo[j].x)*(coo[i].x - coo[j].x) + (coo[i].y - coo[j].y)*(coo[i].y - coo[j].y)) <= d){
				map[i][j] = 1;
				map[j][i] = 1;
			}

	while (cin >> s)
		if (s == "O"){
			cin >> x;
			set[x] = x;
			for (i = 1; i <= n;++i)
				if ((map[x][i] == 1)&&(set[i]))
					Union(x, i);
		}     
		else{
			cin >> x >> y;
			if (FindSet(x) == FindSet(y))
				cout << "SUCCESS\n";
			else
				cout << "FAIL\n";
		}

	return 0;
}

int FindSet(int x){
	if (set[x] != x)
		set[x] = FindSet(set[x]);
	return set[x];
}

void Union(int x, int y){
	y = FindSet(y);
	set[y] = x;
	return;
}
