1 shell
	(1)http://blog.csdn.net/u011204847/article/details/51184883
	变量 只对当前shell进程有效的，对当前进程的子进程和其它shell进程无效 
		直接用 a=1
		引用 $a 或者${a}
		取消 unset a
	环境变量 自定义的环境变量对当前shell进程及其子shell进程有效，对其它的shell进程无效
		export VAR_NAME=VALUE
		

	$?：接收上一条命令的返回状态码
		返回状态码在0-255之间
	$#：参数个数
	$*：或者$@：所有的参数
	$$：获取当前shell的进程号（PID）(可以实现脚本自杀)(或者使用exit命令直接退出也可以使用exit [num])

	''单引号不解析变量
	""双引号会解析变量
	``反引号是执行并引用一个命令的执行结果

	for 循环
	for i in {0..9}         for i in {0..9..1} //第三个参数为跨步值
	for i in 0 1 2 3 4 5 6 7 8 9
	
	条件测试 [ $num1 -gt $num2 ]或者test $num1 -gt $num2
		  -gt：大于：
          -lt：小于
          -ge：大于等于
          -le：小于等于
          -eq：等于
          -ne：不等于
	变量是否为空 [ "$str" =  "" ] 或者[ -z $str ]

	条件判断
		if 条件1; then
				   分支1
		elif 条件2; then
				   分支2
		elif 条件3; then
				   分支3
				  ...
		else
				   分支n
		fi
		
	case 语句
		case 变量引用 in
               PATTERN1)
                         分支1
                         ;;
               PATTERN2)
                         分支2
                         ;;
               ...
               *)
                         分支n
                         ;;
               esac
	
	PATTERN 通配机制
		a|b：a或者b
		*：匹配任意长度的任意字符
		?：匹配任意单个字符
		[a-z]：指定范围内的任意单个字符
		

	算术语句 注意中间的空格
		let varName=算术表达式
		 
		varName=$[算术表达式]
		 
		varName=$((算术表达式))
		 
		varName=`expr $num1 + $num2`
		
	逻辑运算
		-a 与
		-o 或
		！ 非
		(1)if [ 条件A -a 条件B ]
		(2)if [ 条件A ] && [条件B ]
		(3)if ((A&&B))
		(4)if [[ A&&B ]]
	
	自定义函数 //必须用function声明吗？
	function 函数名(){  
	...  
	}
	
	read 从终端读入 
		read如果后面不指定变量，那么read命令会将接收到的数据放置在环境变量REPLY中
		read  -s  -p "Enter your password: " passwd

	declare
		用来限定变量的属性
		-r 只读
		-i 整数：某些算术计算允许在被声明为整数的变量中完成，而不需要特别使用expr或let来完成。
		-a 数组
		
	字符串操作
		获取长度
			${#VAR_NAME}
		字符串截取
			${variable:offset:length}或者${variable:offset}
		取尾部的指定个数的字符
			${variable: -length}：注意冒号后面有空格  
	大小写转换
		${variable^^}  小到大
	大-->小：
		${variable,,}
		
	数组
		按索引进行赋值var=([0]=a [3]=b [1]=c)  //???? 其他的会有问题啊
		var=(1 2 3 4 5)
		${#ARRAY[*]}  数组的长度
		${ARRAY[@]:offset:length}  从数组中获取某一片段之内的元素
		
	DATE
		格式化输出 +%Y-%m-%d
		格式%s表示自1970-01-01 00:00:00以来的秒数
		指定时间输出  --date='2009-01-01 11:11:11'
		指定时间输出  --date='3 days ago' （3天之前，3天之后可以用-3
		
	CRONTAB 定时器任务 //

2 Makefile
	变量在声明时需要给予初值，而在使用时，需要给在变量名前加上“$”符号，
	但最好用小括号“（）”或是大括号“{}”把变量给包括起来。
	如果你要使用真实的“$”字符，那么你需要用“$$”来表示。
	
	31 字符串
		$(subst <from>,<to>,<text>) 把字串<text>中的<from>字符串替换成<to>。
		//$(subst ee,EE,feet on the street)
	
		$(patsubst <pattern>,<replacement>,<text>)
		查找<text>中的单词（单词以“空格”、“Tab”或“回车”“换行”分隔）是否符合模式< pattern>
		如果匹配的话，则以<replacement>替换。
		“$(objects:.o=.c)”和“$(patsubst %.o,%.c,$(objects))”

		$(strip <string>)
		功能：去掉<string>;字串中开头和结尾的空字符
		
		$(findstring <find>,<in>)
		功能：在字串<in>中查找<find>字串
		返回：如果找到，那么返回<find>，否则返回空字符串。
		
		$(filter <pattern...>,<text>)
		以<pattern>模式过滤<text>字符串中的单词
			保留符合模式<pattern>的单词。可以有多个模式。
			//$(filter %.c %.s,$(sources))返回的值是“foo.c bar.c baz.s”。
		$(filter-out <pattern...>,<text>)
		
		$(sort <list>)
		给字符串<list>中的单词排序（升序）
		
		word wordlist words
		
		综合练习：override CFLAGS += $(patsubst %,-I%,$(subst :, ,$(VPATH)))
		
	32 文件操作相关函数
		dir 取目录
		notdir 取得文件名字
		
		$(suffix <names...>) 
			返回文件名序列<names>的后缀序列，如果文件没有后缀，则返回空字串
		
		$(basename <names...>)
			返回文件名序列<names>的前缀序列，如果文件没有前缀，则返回空字串。
		
		$(addsuffix <suffix>,<names...>) 
			把后缀<suffix>加到<names>中的每个单词后面
			$(addsuffix .c,foo bar)返回值是“foo.c bar.c”
			
		$(addprefix <prefix>,<names...>) 
			把前缀<prefix>加到<names>中的每个单词前面
			$(addprefix src/,foo bar)返回值是“src/foo src/bar”
			
		$(join <list1>,<list2>)
			$(join aaa bbb , 111 222 333)返回值是“aaa111 bbb222 333”。
			
		foreach 函数
			names := a b c d
			files := $(foreach n,$(names),$(n).o)
				把参数<list>中的单词逐一取出放到参数所指定的变量中，
			然后再执行< text>所包含的表达式。
			
		$(call <expression>,<parm1>,<parm2>,<parm3>,...)
			当make执行这个函数时，<expression>参数中的变量，如$(1)，$(2)，$(3)等，
		会被参数< parm1>，<parm2>，<parm3>依次取代。
		
			reverse =  $(1) $(2)
			foo = $(call reverse,a,b)
			
		“undefined”
		如果<variable>;从来没有定义过，origin函数返回这个值“undefined”。
		“default”
		如果<variable>;是一个默认的定义，比如“CC”这个变量，这种变量我们将在后面讲述。
		“environment”
		如果<variable>;是一个环境变量，并且当Makefile被执行时，“-e”参数没有被打开。
		“file”
		如果<variable>;这个变量被定义在Makefile中。
		“command line”
		如果<variable>;这个变量是被命令行定义的。
		“override”
		如果<variable>;是被override指示符重新定义的。
		“automatic”
		如果<variable>;是一个命令运行中的自动化变量。关于自动化变量将在后面讲述。





				
			
			
			
			
			
			
			
			
			
			
			

