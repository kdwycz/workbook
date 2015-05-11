#include <iostream>
using namespace std;
 
const int dx[6] = { -1, 1, 0, 0, 0, 0 },
		  dy[6] = { 0, 0, -1, 1, 0, 0 },
		  dz[6] = { 0, 0, 0, 0, -1, 1 },
		  
		  maxm = 50, maxn = 125000;

struct point{
	int x, y, z, step;
}queue[maxn];

int n, a, b, c, t, map[maxm][maxm][maxm];

int check(point, int);
int bfs();
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	while (n--){
		cin>>a>>b>>c>>t;
		for (int i = 0; i<a; ++i)
			for (int j = 0; j<b; ++j)
				for (int k = 0; k<c; ++k)
					cin>>map[i][j][k];
		cout<<bfs()<<endl;
	}
	return 0;
}

int bfs(){
	int fa = 0, so = 0, i;
	point temp;
	queue[0].x = 0; queue[0].y = 0;
	queue[0].z = 0; queue[0].step = 0;
	while (fa <= so && so<maxn && queue[fa].step<t){
		for (i = 0; i<6; ++i){
			temp.x = queue[fa].x + dx[i];
			temp.y = queue[fa].y + dy[i];
			temp.z = queue[fa].z + dz[i];
			temp.step = queue[fa].step + 1;
			if (check(temp, so)){
				if (temp.x == (a - 1) && temp.y == (b - 1) && temp.z == (c - 1))
					return temp.step;
				queue[++so] = temp;
			}
		}
		++fa;
	}
	return -1;
}

int check(point temp, int so){
	int x=a+b+c-temp.x-temp.y-temp.z;
	int y=t-temp.step;
	if (temp.x >= 0 && temp.x<a && temp.y >= 0 && temp.y<b && temp.z >= 0 && temp.z<c && map[temp.x][temp.y][temp.z]==0 && y>=x)
		for (int i = 0; i <= so; ++i){
			if (temp.x == queue[i].x && temp.y == queue[i].y && temp.z == queue[i].z)
				return 0;
		}
	else
		return 0;
	return 1;
}
