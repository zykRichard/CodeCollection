int a0, b0, c0;
int av, bv, cv;
// 这里的a0,b0,c0代表题目中给定的需要判断最后ABC三个水杯的状态
// av, bv, cv表示水杯最大容量
int check(int a, int b, int c)
{
    if (a == a0 && b == b0 && c == c0)
        return 1;
    else
        return 0;
}; // 和你的check一样

int solver(int t, int a, int b, int c)
{
    // dfs
    // t 代表还可以进行的倒水次数
    // a, b, c代表当前水杯的水量
    // 接下来只需要对六种情况进行dfs递归即可

    // 首先判断递归终止条件：
    // t == 0，不可以再倒水，直接return 0，代表这种状态不对
    // t != 0 且 check 通过，代表这种状态已经是满足的了，return 1
    if (t == 0)
        return 0;
    if (t != 0 && check(a, b, c))
        return 1;

    // 接下来进行递归：
    // 利用这三个变量表示六种情况处理后的水杯中水量
    int am[6], bm[6], cm[6];

    // 情况A：2 -> 1
    // 逻辑和你写的代码是一样的
    am[0] = a + b > av ? av : a + b; // 如果不会三目运算拆成if语句也可以
    bm[0] = 0;
    cm[0] = c;

    // 情况B：1 -> 2
    am[1] = 0;
    bm[1] = a + b > bv ? bv : a + b;
    cm[1] = c;

    // ... 其他情况同理， 六种情况全部存在数组里面了
    // 接下来dfs递归
    // 基于这样一个判断，如果这六种情况种有一种情况是满足的，那么当前情况也是满足的
    return (
        solver(t - 1, am[0], bm[0], cm[0]) ||
        solver(t - 1, am[1], bm[1], cm[1]) ||
        solver(t - 1, am[2], bm[2], cm[2]) ||
        solver(t - 1, am[3], bm[3], cm[3]) ||
        solver(t - 1, am[4], bm[4], cm[4]) ||
        solver(t - 1, am[5], bm[5], cm[5]));
}
