#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <string.h>
#include <queue>
#include <iterator>
using namespace std;
ifstream f("f.txt");
class Compare
{
public:
	bool operator()(pair<string, int> cuv1, pair<string, int> cuv2)
	{
		if (cuv1.second < cuv2.second)
			return true;
		if (cuv1.second > cuv2.second)
			return false;
		if (cuv1.first < cuv2.first)
			return false;
		return true;
	}
};
int main()
{
	string s, aux = "";
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> coada;
	int j = 0;
	getline(f, s);
	map<string, int> Map;
	cout << s << endl;
	cout << s.size() << endl;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' || s[i] == '!' || s[i] == '?' || s[i] == '.' || s[i] == ',' || i == s.size() - 1)
		{
			if (aux != "")
				Map[aux]++;
			aux = "";
		}
		else
			aux += tolower(s[i]);
	}
	/*
	for (map<string, int>::iterator i = Map.begin();i != Map.end();i++)
		cout << i->first << " " << i->second << endl;
	*/
	for (map<string, int>::iterator i = Map.begin(); i != Map.end(); i++)
		coada.push(pair<string, int>(i->first, i->second));
	while (!coada.empty())
	{
		cout << coada.top().first << " " << coada.top().second << endl;
		coada.pop();
	}
	return 0;
}