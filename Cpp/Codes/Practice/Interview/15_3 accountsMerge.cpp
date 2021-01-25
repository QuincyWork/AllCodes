#include <gtest/gtest.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
����һ���б� accounts��ÿ��Ԫ�� accounts[i] ��һ���ַ����б����е�һ��Ԫ�� accounts[i][0] �� ���� (name)������Ԫ���� emails ��ʾ���ʻ��������ַ��
���ڣ�������ϲ���Щ�ʻ�����������ʻ�����һЩ��ͬ���ʼ���ַ���������ʻ��ض�����ͬһ���ˡ���ע�⣬��ʹ�����ʻ�������ͬ�����ƣ�����Ҳ�������ڲ�ͬ���ˣ���Ϊ���ǿ��ܾ�����ͬ�����ơ�һ�����������ӵ�������������ʻ������������ʻ���������ͬ�����ơ�
�ϲ��ʻ��󣬰����¸�ʽ�����ʻ���ÿ���ʻ��ĵ�һ��Ԫ�������ƣ�����Ԫ���ǰ�˳�����е������ַ��accounts �������������˳�򷵻ء�
���� 1:
Input:
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation:
  ��һ���͵����� John ��ͬһ���ˣ���Ϊ�����й�ͬ�ĵ����ʼ� "johnsmith@mail.com"��
  �ڶ��� John �� Mary �ǲ�ͬ���ˣ���Ϊ���ǵĵ����ʼ���ַû�б������ʻ�ʹ�á�
  ���ǿ������κ�˳�򷵻���Щ�б������[['Mary'��'mary@mail.com']��['John'��'johnnybravo@mail.com']��
  ['John'��'john00@mail.com'��'john_newyork@mail.com'��'johnsmith@mail.com']]��Ȼ�ᱻ���ܡ�

ע�⣺
accounts�ĳ��Ƚ���[1��1000]�ķ�Χ�ڡ�
accounts[i]�ĳ��Ƚ���[1��10]�ķ�Χ�ڡ�
accounts[i][j]�ĳ��Ƚ���[1��30]�ķ�Χ�ڡ�
*/

namespace IV15_3
{
	class Solution {
	public:
		vector<vector<string>> accountsMerge1(vector<vector<string>>& accounts) {

			vector<pair<string, set<string>>> caches;
			for (auto& account : accounts)
			{
				bool bfind = false;
				for (auto& cache : caches)
				{
					for (int i = 1; i < account.size(); ++i)
					{
						if (cache.second.find(account[i]) != cache.second.end())
						{
							cache.second.insert(account.begin() + 1, account.end());
							bfind = true;
							break;
						}
					}

					if (bfind)
					{
						break;
					}
				}

				if (!bfind)
				{
					caches.push_back(make_pair(account[0], set<string>(account.begin()+1, account.end())));
				}
			}

			auto result = vector<vector<string>>();
			for (auto& i : caches)
			{
				vector<string> v;
				v.push_back(i.first);
				v.insert(v.begin()+1,i.second.begin(),i.second.end());

				result.push_back(v);
			}

			return result;
		}

		vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

			auto caches = unordered_map<string, unordered_set<string>>();
			for (auto& account : accounts)
			{
				for (int i = 1; i < account.size(); ++i)
				{
					//caches[account[i]]
				}
			}
		}

	};

	TEST(Interview, accountsMerge)
	{
		Solution s;
		vector<vector<string>> d{ {"John", "johnsmith@mail.com", "john00@mail.com"},{"John", "johnnybravo@mail.com"},{"John", "johnsmith@mail.com", "john_newyork@mail.com"},{"Mary", "mary@mail.com" } };
		//auto r = s.accountsMerge(d);
	}
}