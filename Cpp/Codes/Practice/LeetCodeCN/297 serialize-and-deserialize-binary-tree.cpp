#include <gtest/gtest.h>
#include <Common/Tree.h>
using namespace std;

namespace LC297
{
	/*
	序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
	请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
	提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

	示例 1：

	输入：root = [1,2,3,null,null,4,5]
	输出：[1,2,3,null,null,4,5]
	示例 2：

	输入：root = []
	输出：[]
	示例 3：

	输入：root = [1]
	输出：[1]
	示例 4：

	输入：root = [1,2]
	输出：[1,2]
 
	提示：

	树中结点数在范围 [0, 104] 内
	-1000 <= Node.val <= 1000

	*/

	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	class Codec {
	public:

		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {

			// 前序遍历
			if (!root) {
				return "#";
			}

			string result = std::to_string(root->val) + '#';
			result += serialize(root->left);
			result += serialize(root->right);
			return result;
		}

		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {

			list<string> values;
			size_t current, prev = 0;
			while (true) {
				current = data.find('#', prev);
				if (current == string::npos) {
					values.push_back(data.substr(prev));
					break;
				}
				else {
					values.push_back(data.substr(prev, current - prev));
					prev = current + 1;
				}
			}
			
			return deserialize(values);
		}

		TreeNode* deserialize(list<string>& data) {

			if (data.empty()) {
				return nullptr;
			}

			auto value = data.front();
			data.pop_front();
			if (value.empty()) {
				return nullptr;
			}

			auto root = new TreeNode(std::stol(value.c_str()));
			root->left = deserialize(data);
			root->right = deserialize(data);
			return root;
		}
	};

	TEST(LeetCodeCN, Codec)
	{
		Codec ser, deser;
		auto data = Tree::toTree("1,2,3,null,null,4,5");
		TreeNode* ans = deser.deserialize(ser.serialize(*data.get()));

		ASSERT_EQ(Tree::toString(ans), "1,2,3,null,null,4,5");
	}



}