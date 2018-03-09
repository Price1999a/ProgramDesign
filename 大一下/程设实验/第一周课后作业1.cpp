#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	for (int i1 = 0; i1 < n; i1++)
	{
		char vowel[100] = {}, word[100] = {};
		char temp;
		int n1 = 0, m = 0, v = 0, w = 0;
		//cin.sync();
		cin >> temp;
		while (temp != '\n')
		{
			if (temp == 'a' || temp == 'e' || temp == 'u' || temp == 'i' || temp == 'o')
			{
				vowel[v] = temp;
				v++;
				word[w] = 'A';
			}
			else
				word[w] = temp;
			w++;
			temp = getchar();
		}
		cin >> m;
		for (int i = 0; i < w; i++)
			if (word[i] == 'A')
			{
				word[i] = vowel[m%v];
				m++;
			}
		cout << word << endl;
	}

	system("pause");
	return 0;
}