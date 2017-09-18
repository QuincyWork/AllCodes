#include <gtest/gtest.h>
using namespace std;

static char verdata[100] = {0};
bool isBadVersion(int version)
{
	return verdata[version-1];
}

int find(int l, int r)
{
	if (l==r)
	{
		return l;
	}

	int mid = l + (r-l) / 2;
	if (isBadVersion(mid))
	{
		return find(l, mid);
	}
	else
	{
		return find(mid+1, r);
	}
}

int firstBadVersion(int n)
{
	return find(1, n);
}

TEST(Pratices, tFirstBadVersion)
{
	memset(verdata +60,1,40);
	int result = firstBadVersion(100);
}