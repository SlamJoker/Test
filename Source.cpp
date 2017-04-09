#include<iostream>
#define maxsize 1000
using namespace std;

typedef struct Xcode
{
	char *data;
	int n;
}Xcode,*Xcodelist;

int Compare(Xcode &a, Xcode &m,int next[])
{
	int i = 0;
	for (int number = 0; number < a.n; number++)
	{
		if (a.data[number] != m.data[i])
		{
			i = next[i];
			if (i>=0)
			{ }
			else
			{
				i++;
			}
			continue;
		}
		if (i == m.n-1)
		{
			return number - i + 1;
		}
		i++;
	}
	return 0;
}
void getNext(int next[],Xcode &m)
{
	int j = 0;
	int k = -1;
	next[0] = -1;
	while (j < m.n)
	{
		while (k >= 0 && m.data[j] != m.data[k])
			k = next[k];
		k++;
		j++;
		next[j] = k;
	}



}
int main()
{
	Xcode a;
	a.data = "cdababc";
	a.n = 8;
	Xcode m;
	m.data = "abab";
	m.n = 4;
	int next[1000];
	getNext(next, m);
	if (Compare(a, m, next))
	{
		cout << Compare(a, m, next) << endl;
	}

}