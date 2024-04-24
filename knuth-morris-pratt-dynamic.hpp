#include <vector>

using namespace std;

template <class T, class U = int>
class KnuthMorrisPratt
{
public:
	int n;
	vector<T> p;
	vector<U> f;

	KnuthMorrisPratt() : n(0)
	{
		f.resize(n + 1);
		fill(f.begin(), f.end(), 0);
	}

	U & operator [] (const int & x)
	{
		return f[x];
	}

	/*
	 * Process the vector to build the class
	 */
	void build(const vector<T> & p)
	{
		this->p = p;
		n = p.size();
		f.resize(n + 1);
		f[0] = f[1] = 0;
		for (int i = 1, k; i < n; i++)
		{
			for (k = f[i]; k > 0 && p[k] != p[i]; k = f[k]);
			if (p[k] == p[i])
				k++;
			f[i + 1] = k;
		}
	}

	/*
	 * A simple method to find all occurences
	 */
	vector<U> calc(const vector<T> & t) const
	{
		vector<int> ans;
		calc(t, ans);
		return ans;
	}

	/*
	 * A simple method to find all occurences
	 */
	void calc(const vector<T> & t, vector<U> & ans) const
	{
		const int m = t.size();
		ans.clear();
		for(int i = 0, k = 0; i < m; i++)
		{
			for (; k > 0 && (k == n || p[k] != t[i]); k = f[k]);
			if (p[k] == t[i])
				k++;
			if (k == n)
				ans.push_back(i - n + 1);
		}
	}
};
