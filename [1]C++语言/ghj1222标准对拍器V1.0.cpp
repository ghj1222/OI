#include <bits/stdc++.h>
using namespace std;

int rand30()
{
	return (rand() << 15) | rand();
}

FILE *work(FILE *fp)
{
	//TODO: 把数据输出到fp指向的文件里
	return fp;
}

int main()
{
	long long t;
	while (1)
	{
		fclose(work(fopen("题目名称.in", "w")));
		printf("正解");
		t = clock();
		system("题目名称.exe < 题目名称.in > 题目名称.out");
		printf("用时%lld\n", clock() - t);
		printf("暴力");
		t = clock();
		system("题目名称bf.exe < 题目名称.in > 题目名称bf.out");
		printf("用时%lld\n", clock() - t);
		if (system("fc 题目名称.out 题目名称bf.out"))
			system("pause");
	}
	return 0;
}
