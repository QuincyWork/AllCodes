using Microsoft.VisualStudio.TestTools.UnitTesting;
using CSharpCodes.Codes.Practice.LeetCode;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCodes.Codes.Practice.LeetCode.Tests
{
    [TestClass()]
    public class TeemoAttackingTests
    {
        [TestMethod()]
        public void FindPoisonedDurationTest()
        {
            var s = new TeemoAttacking();
            Assert.AreEqual(s.FindPoisonedDuration(new int[] { 1, 4 }, 2), 4);
        }
    }
}