1 referen
	http://man.linuxde.net/ comman网站
2 command para
(1)$#
	$#表示参数个数
	./test 1 2 3
	$#为3，其中$0为./test $1为1 ...
(2)"="
	= 是最基本的赋值
	:= 是覆盖之前的值
	?= 是如果没有被赋值过就赋予等号后面的值
	+= 是添加等号后面的值

“:=”表示变量的值决定于它在makefile中的位置，而不是整个makefile展开后的最终值。与“=”相反
"="是全局展开后的最终值，无论“=”的位置在哪。
2 Makefile
	(1)默认的CFLAGS
	-Wall	 允许发出Gcc提供的所有有用的报警信息

	(2)动态库 -fPIC -shared		g++ -fPIC -shared -o libdynmath.so DynamicMath.cpp
		 执行的话3选1
		 1. 在/etc/ld.so.conf文件中增加一行include ld.so.conf.d/exe.conf
		 2. 指定LD_LIBRARY_PATH
		 3. 编译的时候指定通过编译选项-Wl， -rpath指定动态搜索的路径
	   静态库 ar -crv  *.a 1.o 2.o
	(3)
	(4)
	(5)
	(6)
	(7)
	(8)
3 command
(1)gzip
	https://www.cnblogs.com/vurtne-lu/p/6208242.html
	
4 shc
	shell脚本机密工具

5 tcpdump
./tcpdump -p udp -i lo -s 65535 -A port 1000
./tcpdump -p tcp -i eth0 -s 65535 -A port 9824

./tcpdump -p tcp -i lo -s 65535 -A port 9824

./tcpdump -p tcp -i lo -s 65535 -A port 9830

./tcpdump -p tcp -i lo -s 65535 -A port 9823

6 ln -s source dest 

