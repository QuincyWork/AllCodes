using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCodes.Codes.Practice.LeetCode
{
    class MinimumTimeDifference
    {
        int GetMinutes(string time)
        {            
            string[] times = time.Split(':');
            return Convert.ToInt32(times[0]) * 60 + Convert.ToInt32(times[1]);
        }

        public int FindMinDifference(IList<string> timePoints)
        {            
            List<string> sortedTimePoints = timePoints.ToList();
            sortedTimePoints.Sort();
            
            int lastMinutes = GetMinutes(sortedTimePoints.Last());
            int miniDelta = int.MaxValue;

            for (int i = 0; i < timePoints.Count; i++)          
            {
                int value = GetMinutes(sortedTimePoints[i]);
                int delta = Math.Abs(value - lastMinutes);
                delta = Math.Min(delta, 24 * 60 - delta);                
                if (delta < miniDelta)
                {                    
                    miniDelta = delta;
                }

                lastMinutes = value;
            }

            return miniDelta;
        }
    }

    [TestFixture]
    public class MinimumTimeDifferenceTests
    {
        [Test]
        public void FindMinDifference()
        {
            var s = new MinimumTimeDifference();
            Assert.AreEqual(s.FindMinDifference(new string[] { "23:59", "00:00"}), 1);
            Assert.AreEqual(s.FindMinDifference(new string[] { "00:00","23:59", "00:00" }), 0);
            Assert.AreEqual(s.FindMinDifference(new string[] { "05:31", "22:08", "00:35" }), 147);
        }
    }
}
