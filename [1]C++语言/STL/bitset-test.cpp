#include <bits/stdc++.h>
using namespace std;

//尖括号里的数字是大小，必须是常量
bitset<16> x;//创建一个大小为2333的bitset
bitset<16> test1(243);//用十进制数
bitset<16> test2(0xfc);//其实别的进制也行
bitset<16> test3(string("1010010101"));//甚至字符串也行

int main()
{
	cout << test1 << endl;//输出bitset(按位输出)
	cout << test2 << endl;
	cout << test3 << endl;
	cout << x.size() << endl;//大小(16)
	cout << x.count() << endl;//1个个数 复杂度O(n)
	cout << x.any() << endl;//是否有1
	cout << x.none() << endl;//是否没有1
	x.set(5);//将第5位变为1(从0开始计数)
	x.set(5, 0);//将第5位变为0
	x.reset();//清空为0
	x.reset(5);//将第5位变为0
	x.flip();//取反
	x.flip(5);//第5位取反
	return 0;
}
