#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

map<string, int> m;
map<string, int>::iterator it;
int p[5000];
int count[5000]={0};
void ini(int n)
{
	int i;
	for(i=0;i<n;i++) p[i]=i;
}

int Find(int x)
{
	return (p[x]==x) ? x : (p[x]=Find(p[x]));
}

void Union(int x,int y)
{
	p[Find(x)]=Find(y);
}

int main()
{
	int num, rela;
	int i;
	string type,s1,s2;
	while(scanf("%d %d", &num,&rela)!=EOF)
	{
		if(num==0&&rela==0)
			return 0;
		ini(num);
		int ans=0;
		for(i=0;i<num;i++)
		{
			cin >> type;
			m[type]=i;
		}
		for(i=0;i<rela;i++)
		{
			cin >> s1 >> s2;
			Union(m[s1],m[s2]);
		}
		for(i=0;i<5000;i++)
			count[i]=0;
		for(i=0;i<num;i++)
				count[Find(i)]++;
		for(i=0;i<num;i++)
			if(ans<count[i])
				ans=count[i];
		printf("%d\n",ans);
		for(it=m.begin();it!=m.end();++it)
			m.erase(it);
	}
	return 0;
}	
