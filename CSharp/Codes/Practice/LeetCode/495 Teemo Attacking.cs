using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCodes.Codes.Practice.LeetCode
{
    class Solution
    {
        public int FindPoisonedDuration(int[] timeSeries, int duration)
        {
            int sumDuration = 0;
            int lastEnd = 0;
            foreach(int v in timeSeries)
            {
                int dValue = duration;
                if (v < lastEnd)
                {
                    dValue += v - lastEnd;
                }

                sumDuration += dValue;
                lastEnd = v + duration;
            }

            return sumDuration;
        }
    }

    [TestClass()]
    public class TeemoAttackingTests
    {
        [TestMethod()]
        public void FindPoisonedDuration()
        {
            var s = new Solution();
            Assert.AreEqual(s.FindPoisonedDuration(new int[] { 1, 4 }, 2), 4);
        }
    }
}