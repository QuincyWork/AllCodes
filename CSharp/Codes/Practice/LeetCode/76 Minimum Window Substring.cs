using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCodes.Codes.Practice.LeetCode
{
    class MinimumWindowSubstring
    {
        public string MinWindow(string s, string t)
        {
            string result = "";
            if (s.Length == 0 || t.Length == 0)
            {
                return result;
            }
                        
            int[] preRecord = Enumerable.Repeat(1, s.Length + 1).ToArray();
            int[] currentRecord = Enumerable.Repeat(0, s.Length + 1).ToArray();

            for (int i=0; i < t.Length; ++i)
            {
                for (int j = 0; j < s.Length; ++j)
                {
                    if (j >= i)
                    {
                        // 计算包含当前字符的最短后缀字符串长度.                        
                        //   当前字符如果相同，则后缀长度为1
                        //   当前字符如果不同，并且已有后缀包含，则后缀长度加1
                        //   当前字符如果不同，并且没有后缀包含，则后缀长度0
                        currentRecord[j + 1] =
                            (t[i] == s[j]) ? 
                                1 : (currentRecord[j] == 0 ? 0 : currentRecord[j] + 1);
                    }

                    // 计算包含所有字符的最短后缀字符串长度                    
                    //   如果没有后缀字符串包含之前字符或包含当前字符，则整个也不包含
                    if (preRecord[j + 1] == 0 ||
                        currentRecord[j + 1] == 0 )
                    {
                        preRecord[j + 1] = 0;
                    }
                    else
                    {
                        //  在包含之前字符后缀长度，当前字符后缀长度，匹配的字符长度之间获取最大值
                        preRecord[j + 1] = Math.Max(
                            Math.Max(currentRecord[j + 1], preRecord[j + 1]),
                            i+1);
                    }
                }

                currentRecord = Enumerable.Repeat(0, s.Length + 1).ToArray();
            }

            int minPos = 0;
            int minValue = int.MaxValue;
            for (int i = 1; i < preRecord.Length; ++i)
            {
                int v = preRecord[i];
                if (v != 0 && v < minValue)
                {
                    minPos = i;
                    minValue = v;
                }
            }

            for (int i = minPos - minValue; i < minPos && i >=0 ; ++i)
            {
                result += s[i];
            }

            return result;
        }
    }

    [TestFixture]
    public class MinimumWindowSubstringTests
    {
        [Test]
        public void MinWindow()
        {
            var s = new MinimumWindowSubstring();
            Assert.AreEqual(s.MinWindow("ADOBECODEBANC", "ABC"), "BANC");
            Assert.AreEqual(s.MinWindow("ADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANC", "ABC"), "BANC");
            Assert.AreEqual(s.MinWindow("A", "A"), "A");
            Assert.AreEqual(s.MinWindow("A", "B"), "");
            Assert.AreEqual(s.MinWindow("A", "AA"), "");
            Assert.AreEqual(s.MinWindow("AAA", "AA"), "AA");
            Assert.AreEqual(s.MinWindow("ABC", "CBA"), "ABC");
        }
    }
}
