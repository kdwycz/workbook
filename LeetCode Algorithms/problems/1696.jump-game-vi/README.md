第一反应是个简单的O(n^2)的dp，状态转移方程是``dp[i] += max(dp[max(i - k, 0): i])``不出意料的TLE了。然后仔细一看数据量是10^6……那要把其中一个n优化到logn。

期间还试验了下评论区里说的[优化方法](./answer_tle2.py)，然而被数据制裁了。

重新学习了下线段树的写法。[写了一个](./answer_tle3.py)，又TLE了。

无奈去看题解，发现都是用单调队列做的。为什么对这个名词没印象，一定是我太菜了……那就学下单调队列。看起来这个数据结构非常适合处理数组中一段连续元素的极值问题