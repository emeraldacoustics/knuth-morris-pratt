#include <iostream>
#include "knuth-morris-pratt-dynamic.hpp"

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	string txt, pat;

	cin >> txt >> pat;

	/*
	 * Prepare a vector to be processed by the build method
	 * This could be a bit annoying for manipulating strings, but 
	 */
	vector<char> patv(pat.length(), 0);
	for (int i = 0; i < pat.length(); i++)
		patv[i] = pat[i];
	
	KnuthMorrisPratt<char> KMP;
	KMP.build(patv);

	vector<int> res;
	for (int i = 0, k = 0; i < txt[i]; i++)
	{
		for (; k > 0 && (k == pat.length() || txt[i] != pat[k]); k = KMP[k]);
		if (txt[i] == pat[k])
			k++;
		
		// Found a pattern
		if (k == pat.length())
			res.push_back(i - pat.length() + 1);
	}

	for (const auto & x : res)
		cout << x << endl;

	return 0;
}
