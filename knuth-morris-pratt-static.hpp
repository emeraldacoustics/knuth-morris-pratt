#include <cstring>

template <class T, class U = int>
class KnuthMorrisPratt
{
public:
	static const int maxn = 1000;

	int n;
	T p[maxn];
	U f[maxn + 1];

	KnuthMorrisPratt(void) : n(0)
	{

	}

	U & operator [] (const int & x)
	{
		return f[x];
	}

	/*
	 * Process the vector to build the class
	 */
	void build(const T * first, const T * last)
	{
		const T * & p = first;
		n = last - first;
		memcpy(this->p, p, sizeof p[0] * n);
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
	vector<U> calc(const T * first, const T * last) const
	{
		vector<int> ans;
		calc(first, last, ans);
		return ans;
	}

	/*
	 * A simple method to find all occurences
	 */
	void calc(const T * first, const T * last, vector<U> & ans) const
	{
		const T * & t = first;
		const int m = last - first;
		ans.clear();
		for (int i = 0, k = 0; i < m; i++)
		{
			for (; k > 0 && (k == n || p[k] != t[i]); k = f[k]);
			if (p[k] == t[i])
				k++;
			if (k == n)
				ans.push_back(i - n + 1);
		}
	}
};
