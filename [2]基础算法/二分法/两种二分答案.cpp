//0和1是valid的返回值，X是答案位置
//1. [111111X|0000000]
while (l < r)
{
	int mid = (l + r + 1) / 2;
	if (valid(mid)) l = mid;
	else r = mid - 1;
}
//2. [000000X|1111111]
while (l < r)
{
	int mid = (l + r + 1) / 2;
	if (valid(mid)) r = mid - 1;
	else l = mid;
}
//3. [1111111|X000000]
while (l < r)
{
	int mid = (l + r) / 2;
	if (valid(mid)) l = mid + 1;
	else r = mid;
}
//4. [0000000|X111111]
while (l < r)
{
	int mid = (l + r) / 2;
	if (valid(mid)) r = mid;
	else l = mid + 1;
}
