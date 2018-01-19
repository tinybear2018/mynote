1 sscanf 
	成功则返回参数数目，失败则返回0。
	struct tm tmts;
	retval=sscanf(value,"%d-%d-%d %d:%d:%d",
		&tmts.tm_year,&tmts.tm_mon, &tmts.tm_mday,
		&tmts.tm_hour, &tmts.tm_min, &tmts.tm_sec);
2 fopen
	r+具有读写属性，从文件头开始写，保留原文件中没有被覆盖的内容；
	w+具有读写属性，写的时候如果文件存在，会被清空，从头开始写。
	r 打开只读文件，该文件必须存在。 
	r+ 打开可读写的文件，该文件必须存在。 
	w 打开只写文件，若文件存在则文件长度清为0，即该文件内容会消失。若文件不存在则建立该文件。 
	w+ 打开可读写文件，若文件存在则文件长度清为零，即该文件内容会消失。若文件不存在则建立该文件。 
	a 以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。 
	a+ 以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 
3 int fseek( FILE *stream, long offset, int origin );
	origin SEEK_SET 文件开头  0
		   SEEK_CUR 		  1	
		   SEEK_END           2

4 rewind 功能是将文件内部的指针重新指向一个流的开头

5
