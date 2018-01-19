1 lxh最简单的解码分析
	av_register_all(); //注册复用器，解复用器等等
		例如 REGISTER_MUXDEMUX (AC3, ac3);
			if (CONFIG_AC3_MUXER)                                         \
				av_register_output_format(&ff_ac3_muxer);     
		avcodec_register_all();