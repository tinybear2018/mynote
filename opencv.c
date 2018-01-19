sed -i "s/root\/hi3516a\/cmake-2.8.9-Linux-i386/usr/g" ` grep "root/hi3516a/cmake-2.8.9-Linux-i386" . -rl`

export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/home/langzp/opencv/local/lib/pkgconfig/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/buffer/tinybear_install/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/app/lib
arm-hisiv400-linux-g++ face.cpp -I/home/langzp/opencv/tinybear_install/include/opencv -I/home/langzp/opencv/tinybear_install/include -o face -L /home/langzp/opencv/tinybear_install/lib/ -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts.a -lopencv_video -lopencv_videostab -lrt -lpthread -lm -ldl

 -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts.a -lopencv_video -lopencv_videostab -lrt -lpthread -lm -ldl

 编译：
arm-hisiv400-linux-g++ face.cpp -I/home/langzp/opencv/tinybear_install/include/opencv -I/home/langzp/opencv/tinybear_install/include -o face -L /home/langzp/opencv/tinybear_install/lib/ -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videostab -lrt -lpthread -lm -ldl

sed -i "s/root\/hi3516a\/cmake-2.8.9-Linux-i386/usr/g" ` grep "root/hi3516a/cmake-2.8.9-Linux-i386" . -rl`

cd /lib/
ln -sf /home/buffer/tinybear_install/lib/libopencv_calib3d.so ./libopencv_calib3d.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_contrib.so ./libopencv_contrib.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_core.so ./libopencv_core.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_features2d.so ./libopencv_features2d.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_flann.so ./libopencv_flann.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_gpu.so ./libopencv_gpu.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_highgui.so ./libopencv_highgui.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_imgproc.so ./libopencv_imgproc.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_legacy.so ./libopencv_legacy.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_ml.so ./libopencv_ml.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_nonfree.so ./libopencv_nonfree.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_objdetect.so ./libopencv_objdetect.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_photo.so ./libopencv_photo.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_stitching.so ./libopencv_stitching.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_superres.so ./libopencv_superres.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_video.so ./libopencv_video.so
ln -sf /home/buffer/tinybear_install/lib/libopencv_videostab.so ./libopencv_videostab.so
cd /home/buffer

export PATH=$PATH:/root/hi3516a/opencv/cmake-3.8.2-Linux-x86_64/bin

移植说明：
1 本地安装

cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=INSTALL_PATH SOURCE_PATH
make
make install

g++ -ggdb   `pkg-config --cflags opencv` -o face_pc face.cpp `pkg-config --libs opencv`
2 移植到linux开发板
参考
1. 修改编译出来的脚本build目录和install目录以及cmake工具目录（交叉编译工具目录一致，不用修改）
2. 将上述文件生成scripts.tgz（某些版本cmake没有CUDA选项，在make时候出错，在CMakeCache.txt中去除WITH_CUDA）
	sed -i "s/install_hi3518_400/install_hi3716_200/g" ` grep "install_hi3518_400" . -rl`
	sed -i "s/root\/hi3516a\/cmake-2.8.9-Linux-i386/usr/g" ` grep "root/hi3516a/cmake-2.8.9-Linux-i386" . -rl`
	更换编译器
	sed -i "s/arm-hisiv400-linux/arm-hisiv200-linux/g" ` grep "arm-hisiv400-linux" . -rl`
3. 进入build目录，make make_install