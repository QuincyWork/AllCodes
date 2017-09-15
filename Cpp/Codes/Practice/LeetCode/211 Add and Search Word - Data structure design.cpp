#include <gtest/gtest.h>
#include <list>
using namespace std;

class WordDictionary {

private:
	const static int  MAX_LETTER_SIZE = 27;
	const static char STRING_END_TAG = 'z'+1;

	struct TireNode
	{
		char nodeValue;
		TireNode* childNodes[MAX_LETTER_SIZE];

		TireNode()
			: nodeValue(0)
		{
			memset(childNodes,0,sizeof(childNodes));
		}

		TireNode(char value)
			: nodeValue(value)
		{
			memset(childNodes,0,sizeof(childNodes));
		}
	};

	TireNode m_RootNode;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string value) {
        
		value += STRING_END_TAG;
		int currentIdx = 0;
		int length = value.length();
		TireNode* pCurrentNode = &m_RootNode;
		TireNode* pChildNode = NULL;

		do
		{
			bool bExists = false;
			char currentChar = value[currentIdx++];
			pChildNode = pCurrentNode->childNodes[currentChar % MAX_LETTER_SIZE];			
			if (pChildNode==NULL)
			{
				TireNode* node = new TireNode(currentChar);
				node->nodeValue = currentChar;
				pCurrentNode->childNodes[currentChar % MAX_LETTER_SIZE] = node;				
				pCurrentNode = node;
			}
			else
			{
				pCurrentNode = pChildNode;
			}

		}while(currentIdx < length);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string value) {
        		
		value += STRING_END_TAG;
		int currentIdx = 0;
		int length = value.length();		
		
		return searchChild(&m_RootNode,value,0,length);
    }

private:

	bool searchChild(TireNode* root, string& value, int start, int end)
	{
		bool bResult = false;
		TireNode* pCurrentNode = root;
		TireNode* pChildNode = NULL;

		if (start == end)
		{
			return true;
		}

		char cValue = value[start];
		if (cValue == '.')
		{			
			for (int i=0; i<MAX_LETTER_SIZE; ++i)
			{
				pChildNode = pCurrentNode->childNodes[i];
				if (pChildNode && searchChild(pChildNode,value,start+1,end))
				{
					bResult = true;
					break;
				}
			}
		}
		else
		{
			pChildNode = pCurrentNode->childNodes[cValue % MAX_LETTER_SIZE];
			if (pChildNode)
			{
				bResult = searchChild(pChildNode,value,start+1,end);
			}
		}		

		return bResult;
	}
};


TEST(LeetCodeMock,tWordDictionary)
{
	WordDictionary d;
	d.addWord("bad");
	d.addWord("dad");
	d.addWord("mad");

	ASSERT_TRUE(d.search("bad"));
	ASSERT_FALSE(d.search("pad"));
	ASSERT_TRUE(d.search(".ad"));
	ASSERT_TRUE(d.search("b.."));
}