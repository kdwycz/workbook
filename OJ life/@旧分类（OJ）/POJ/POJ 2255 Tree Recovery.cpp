#include <iostream>
using namespace std;
string s1, s2;

void findpost(int root, int left, int right);
int main()
{
	while (cin>>s1>>s2){
		findpost(0,0,s2.size()-1);
		cout<<endl;
	}
	return 0;
}

void findpost(int root,int left,int right)
{
	if (left>right) return;
	for (int i=left; i<=right && s1[root]!=s2[i];i++);
	findpost(root + 1, left, i - 1);
	findpost(root + i - left + 1, i + 1, right);
	cout << s2[i];
}
