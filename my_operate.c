
1）
hi3516a 解压密码qddytt
SVN 
langzp langzp_0711_pass
langzp tinybear

2) 一些概念

hisome equipment control protocol(HECP)

tar -czf jpg.tar.gz *.jpg
tar -xzf *.tgz           .

cat /proc/kmsg |

./tcpdump/tcpdumptcp tcpdump -i eth0 port 9830 -w 1.cap
./tcpdump -A -n -x -s 0 tcp port 9830 -w /home/1.cap


　$@  表示目标文件
　　$^  表示所有的依赖文件
　　$<  表示第一个依赖文件
　　$?  表示比目标还要新的依赖文件列表

（2）wildcard、notdir、patsubst的意思：

　　wildcard : 扩展通配符
　　notdir ： 去除路径
　　patsubst ：替换通配符


3）3518 编译命令

setenv serverip 192.168.168.73
setenv ipaddr 192.168.168.235
setenv gatewayip 192.168.168.1
setenv ethaddr 72:E4:47:BC:03:69
saveenv

tftp 81000000 sample.bin
nand erase 0x100000 0x100000
nand write 0x81000000 0x100000 0x700000

setenv bootcmd 'nand read 0x80008000 0x100000 0x100000;go 0x80008000'
saveenv

20170801

make ARCH=arm CROSS_COMPILE=arm-hisiv400-linux- hi3518ev200_config 
make ARCH=arm CROSS_COMPILE=arm-hisiv400-linux-
make ARCH=arm CROSS_COMPILE=arm-hisiv400-linux- DMRFCURB_MCUNET_CBB0_VB100_config 


cp arch/arm/configs/hi3518ev200_full_defconfig  .config
make ARCH=arm CROSS_COMPILE=arm-hisiv400-linux- menuconfig
make ARCH=arm CROSS_COMPILE=arm-hisiv400-linux- uImage -j12

make ARCH=arm CROSS_COMPILE=arm-hisiv400-linux- clean -j12
osdrv/pub/bin/pc/mkyaffs2image100 osdrv/pub/rootfs_glibc osdrv/pub/rootfs_glibc_2k_4bit.yaffs2 1 2

mw.b 82000000 ff 100000
tftp 82000000 u-boot-hi3518ev200.bin
nand erase 0 100000
nand write 82000000 0 100000
reset


3）烧写内核
mw.b 81000000 ff 300000
tftp 81000000 uImage
mw.b 81400000 ff 400000
tftp 81400000 ramdisk.img.gz
bootm 0x81000000
nand erase 100000 300000
nand write 82000000 100000 300000
4)烧写文件系统
mw.b 82000000 ff 2000000
tftp 82000000 rootfs_glibc_2k_4bit.yaffs2
nand erase 400000 2000000
nand write.yaffs 82000000 400000  96d200

setenv bootargs 'mem=64M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=yaffs2 mtdparts=hinand:1M(boot),3M(kernel),32M(rootfs),28M(test)'
setenv bootcmd 'nand read 0x82000000 0x100000 0x300000;bootm 0x82000000'
sa
mount -t nfs -o nolock -o tcp -o rsize=32768,wsize=32768 192.168.168.135:/root/hi3516a/nfs/ /mnt

ping 192.168.168.73


555555555555555555555555

ifconfig eth0 192.168.160.235
mount -t nfs -o nolock -o tcp -o rsize=32768,wsize=32768 192.168.168.10:/home/nfs_roots/nfs_root.hi3516CV300 /mnt
cd /mnt/lang_tmp
cp core_test.bin /tmp/
cd /tmp/
./main

mount -t nfs -o nolock -o tcp -o rsize=32768,wsize=32768 192.168.168.10:/home/nfs_roots/nfs_hisome/his3518E /mnt

3）板子名称 HISOME_RSTI300
DMRFCURB_MCUNET_CBB0_VB100

DM -DEMO板     
RFCURB-板子功能缩写
MCUNET-主控板  网络
CBBO_VB100-版本

4）make ubi文件
tar -zxvf CORE.tgz -C apps_ubi/app_ubi/
cd apps_ubi/;\
./ubifs.sh 005
 
5)HISOME-RSTI300 svn://192.168.168.8/HISOME-RSTI300/trunk
  server.bin 	 svn://192.168.168.8/HS-CIRB-12SE/trunk/up_server 

run clrenv clrimg clrback clrcnf clrlog clrapps clrbuf clrfirsn clrsecsn
 
 dev:    size   erasesize  name
mtd0: 000e0000 00020000 "u-boot"
mtd1: 00020000 00020000 "env"
mtd2: 00800000 00020000 "image"
mtd3: 00800000 00020000 "back"
mtd4: 00600000 00020000 "config"
mtd5: 00700000 00020000 "log"
mtd6: 03000000 00020000 "apps"
mtd7: 03000000 00020000 "buffer"
mtd8: 000c0000 00020000 "fir_sn_mac"
mtd9: 000c0000 00020000 "sec_sn_mac"
mtd10: 00080000 00020000 "reserved"
 
setenv bootargs 'mem=96M console=ttyAMA0,115200 rootwait=1 rw root=/dev/ram0 initrd=0x81500000,0x1000000 init=/init mtdparts=hi_sfc:1M(boot),4M(kernel),25M(rootfs)'


bootdelay=1
baudrate=115200
ethaddr=00:00:23:34:45:66
netmask=255.255.255.0
bootfile="uImage"
bootargs=mem=96M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=jffs2 mtdparts=hi_sfc:1M(boot),4M(kernel),25M(rootfs)
bootcmd=sf probe 0;sf read 0x82000000 0x100000 0x400000;bootm 0x82000000
serverip=192.168.1.73
ipaddr=192.168.1.200
stdin=serial
stdout=serial
stderr=serial
verify=n
ver=U-Boot 2010.06 (Apr 30 2017 - 01:41:34)

Environment size: 429/262140 bytes

sf probe 0
mw.b 82000000 ff 100000
tftp 0x82000000 u-boot-hi3516d.bin
sf probe 0
sf erase 0 100000
sf write 82000000 0 100000	

mw.b 82000000 ff 400000
tftp 82000000 uImage
sf probe 0
sf erase 100000 400000
sf write 82000000 100000 400000


mw.b 82000000 ff 1900000
tftp 0x82000000 jffs2-root-64k.jffs2
tftp 0x82000000 tinybear.jffs2
tftp 0x82000000 1.jffs2
sf probe 0
sf erase 500000 1900000
sf write 82000000 500000 1900000


setenv bootargs mem=96M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=jffs2 mtdparts=hi_sfc:1M(boot),4M(kernel),15M(rootfs)

setenv bootargs 'mem=96M console=ttyAMA0,115200 root=/dev/mtdblock2 rootfstype=jffs2 mtdparts=hi_sfc:1M(boot),4M(kernel),25M(rootfs)'


setenv  bootcmd 'sf probe 0;sf read 0x82000000 0x100000 0x400000;bootm 0x82000000'
mkfs.jffs2 -d rootfs -l -e 0x40000 -o 1.jffs2


setenv bootargs mem=64M console=ttyAMA0,115200 rootwait=1 rw root=/dev/ram0 initrd=0x81400000,0x1000000 init=/init mtdparts=hinand:896K(u-boot),128K(env),8M(image),8M(back),6M(config),7M(log),48M(apps),48M(buffer),768K(fir_sn_mac),768K(sec_sn_mac),-(reserved)


bootargs=mem=64M console=ttyAMA2,115200 rootwait=1 rw root=/dev/ram0 initrd=0x81400000,0x1000000 init=/init mtdparts=hinand:896K(u-boot),128K(env),8M(image),8M(back),6M(config),7M(log),48M(apps),48M(buffer),768K(fir_sn_mac),768K(sec_sn_mac),-(reserved)



printk(KERN_EMERG" %s %d\n", __func__. __LINE__);
echo 3 > /proc/sys/vm/drop_caches