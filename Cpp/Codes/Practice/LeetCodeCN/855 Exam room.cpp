#include <gtest\gtest.h>
using namespace std;

class ExamRoom {
public:
	ExamRoom(int N) {
		
		m_nSize = N;
		m_vecSeats.clear();
	}

	int seat() {

		int nPos = 0;
		if (!m_vecSeats.empty())
		{
			if (m_vecSeats.size() == 1)
			{
				nPos = m_nSize - 1;
			}
			else
			{
				int prevValue = 0;
				for (size_t i = 1; i < m_vecSeats.size(); ++i)
				{
					int delta = (m_vecSeats[i] - m_vecSeats[i - 1]) / 2;
					if (delta > prevValue)
					{
						prevValue = delta;
						nPos = m_vecSeats[i-1] + delta;
					}
				}
			}
		}
		
		m_vecSeats.push_back(nPos);
		sort(m_vecSeats.begin(), m_vecSeats.end());

		return nPos;
	}

	void leave(int p) {

		for (auto it = m_vecSeats.begin(); it != m_vecSeats.end(); ++it)
		{
			if (*it == p)
			{
				m_vecSeats.erase(it);
				break;
			}
		}
	}

private:

	vector<int> m_vecSeats;
	int m_nSize = 0;
};

TEST(LeetCodeCN, tExamRoom)
{
	ExamRoom room(10);
	int v = room.seat();
	v = room.seat();
	v = room.seat();
	v = room.seat();
	room.leave(4);
	v = room.seat();
}
