# knuth-morris-pratt
An easy-to-use class that implements Knuth-Morris-Pratt algorithm.

This class can handle any data types.
For example, `KnuthMorrisPratt<int> KMP;` or `KnuthMorrisPratt<char> KMP;`.

`build()` method calculates suffix links for the give array passed as a parameter.

You can easily access suffix link values via the index operator.
Suffix link values are stored in `f`.
If `f[x]` equals `y`, `p[:x]` both begins with and ends with `p[:y]`.

Refer example.cpp to see how it works.
```
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
	 * This could be a bit annoying for manipulating strings,
	 * but will prove useful for handling other data types.
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

```
