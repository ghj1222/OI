bitset<16> x;//定义一个长度为16的bitset
bitset<16> y(2333);//用数字定义bitset
bitset<16> z(string("100101"));//用字符串(从右到左)定义
x.any(), x.none();//返回是否有1/是否全0
x.count();//返回1的个数，O(n)
x.flip();//不加参数全翻转
x.flip(5);//翻转第5位 返回*this
x.operator[5];//返回第5位的左值
x.set();//全设为1 以下均返回*this
x.set(5);//第5位设为1
x.set(5, 0);//第5位设为0
x.reset();//全设为0
x.reset(5);//第5位设为0
x.size();//返回大小
