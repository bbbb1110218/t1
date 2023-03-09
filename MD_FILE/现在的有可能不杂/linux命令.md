# 目录  看完P15 ，14分钟

## /etc  配置

```bash
/etc/motd  # 查看欢迎内容
/etc/issue   # 查看登陆前信息
/etc/shells # 查看所有shell
/etc/hostname #查看主机名
/etc/profile.d/env.sh  #修改命令行提示符
/etc/bashrc #全局修改 所有用户可见
/etc/DIR_COLORS #定义文件的颜色
```

## /tmp 临时

```bash

```

## /opt第三方软件

```
```

## /sys 硬件相关

```bash
```

## /var 可变日志数据

```bash
```



## /bin	二进制程序

```bash

```

## /boot 启动目录

```bash

```
## /home 家目录

```bash
/home/usename/.bashrc #放别名 Ubantu下面可以用 Centos不能
```
## /lib 库

```
32位的库
```

## /median 多媒体挂载点

```

```

## /dev 各种硬件

```bash
/dev/sda  #硬盘
```
/usr/lib/ubuntu-release-upgrader/release-upgrade-motd

## /proc 内存数据

```bash
/proc/cpuinfo CPU信息
/proc/meminfo 内存信息
```

## /usr 待用/

```bash
/usr/../man bangzhu 帮助文档
/usr/share/doc 帮助文档
```

-- -

# 命令

## A

```bash
alias 	# 命令别名 优先级 别名，内部命令，外部命令| 临时生效
	alias commands="全部命令"
	alias py="python3"
	永久生效:放文件里面  source  ~/.bashrc 

```

## B

```bash
bc #计算器
	-obase=2 输出二进制
basename #
	
```


## C

```bash
curl  #查看网页文本
cat  #查看文件
clear #清除屏幕
CTRL+C #强行退出，可能会丢失信息
CTRL+D #非强行退出，不会丢失信息 =logout
clock 主板时间 硬件时间
	clock -W 修改硬件时间
	clock -S 修改系统时间
cal #查看日历
	cal 月 年  查看日历
cd #切换目录
	cd- 上一次目录
chown 
	修改所有者
cp
		#拷贝
crontab -l
	查看定时配置

```

## D

```bash
dnf # centos8 的yum
dirname #当前目录	
date #显示当前时间
	-date 062018302020.30 修改时间 断电丢失 在内存中修改
	-月日时分年.秒
	- `date +%F` 显示当前日期
	-touch `date +%F`.TXT #从创建今天日期的记事本
	-touch `hostname`_`$(date +%F)`.txt
	-touch `date -d '-2 day' +%F`.log  //新建前两天日期的日志文件 2023-01-02.log

```

## E

```bash
echo  #显示
	-echo $PATH
	-n 不换行
	-e  显示特殊符号 echo -e '\a' 发出声音
	- echo "hello,kitty" >> temp.txt （>>追加模式 >擦除模式）
	
	
echo $SHELL	// 查看shell
exit # 退出
enable # 显示全部内部命令  
	enable -n commads #禁用内部命令
	enable commands  #启用命令
export
```


## F

```bash
file  #文件类型
	-f 读取内容
	-文本 ELF格式
	-非文本
free #查看内存 
	-h 人类友好
	-也可以 cat /proc/meminfo

```

端口放行

```bash
查看防火墙状态
	firewall-cmd --state
running代表防火墙正在运行中,如果防火墙处在关闭状态,则运行下面命令开启防火墙
	systemctl start firewalld.service
查看某个端口是否放行
	firewall-cmd --query-port=端口号/tcp
放行指定端口
	firewall-cmd --zone=public --add-port=8080/tcp --permanent
重启防火墙
	systemctl restart firewalld.service
重新载入配置
	firewall-cmd --reload
```



## G

```bash
gedit  #文本工具
g++ 
	用法：g++ [选项] 文件...
选项：
  -pass-exit-codes         在某一阶段退出时返回其中最高的错误码。
  --help                   显示此帮助说明。
  --target-help            显示目标机器特定的命令行选项。
  --help={common|optimizers|params|target|warnings|[^]{joined|separate|undocumented}}[,...]。
                           显示特定类型的命令行选项。
 （使用‘-v --help’显示子进程的命令行参数）。
  --version                显示编译器版本信息。
  -dumpspecs               显示所有内建 spec 字符串。
  -dumpversion             显示编译器的版本号。
  -dumpmachine             显示编译器的目标处理器。
  -print-search-dirs       显示编译器的搜索路径。
  -print-libgcc-file-name  显示编译器伴随库的名称。
  -print-file-name=<库>    显示 <库> 的完整路径。
  -print-prog-name=<程序>  显示编译器组件 <程序> 的完整路径。
  -print-multiarch         显示目标的标准 GNU 三元组（被用于库路径的一部分）。
  -print-multi-directory   显示不同版本 libgcc 的根目录。
  -print-multi-lib         显示命令行选项和多个版本库搜索路径间的映射。
  -print-multi-os-directory 显示操作系统库的相对路径。
  -print-sysroot           显示目标库目录。
  -print-sysroot-headers-suffix 显示用于寻找头文件的 sysroot 后缀。
  -Wa,<选项>               将逗号分隔的 <选项> 传递给汇编器。
  -Wp,<选项>               将逗号分隔的 <选项> 传递给预处理器。
  -Wl,<选项>               将逗号分隔的 <选项> 传递给链接器。
  -Xassembler <参数>       将 <参数> 传递给汇编器。
  -Xpreprocessor <参数>    将 <参数> 传递给预处理器。
  -Xlinker <参数>          将 <参数> 传递给链接器。
  -save-temps              不删除中间文件。
  -save-temps=<参数>       不删除中间文件。
  -no-canonical-prefixes   生成其他 gcc 组件的相对路径时不生成规范化的
                           前缀。
  -pipe                    使用管道代替临时文件。
  -time                    为每个子进程计时。
  -specs=<文件>            用 <文件> 的内容覆盖内建的 specs 文件。
  -std=<标准>              假定输入源文件遵循给定的标准。
  --sysroot=<目录>         将 <目录> 作为头文件和库文件的根目录。
  -B <目录>                将 <目录> 添加到编译器的搜索路径中。
  -v                       显示编译器调用的程序。
  -###                     与 -v 类似，但选项被引号括住，并且不执行命令。
  -E                       仅作预处理，不进行编译、汇编或链接。
  -S                       编译到汇编语言，不进行汇编和链接，
  -c                       编译、汇编到目标代码，不进行链接。
  -o <文件>                输出到 <文件>。
  -pie                     生成动态链接的位置无关可执行文件。
  -shared                  生成一个共享库。
  -x <语言>                指定其后输入文件的语言。
                           允许的语言包括：c、c++、assembler、none
                           ‘none’意味着恢复默认行为，即根据文件的扩展名猜测
                           源文件的语言。

以 -g、-f、-m、-O、-W 或 --param 开头的选项将由 g++ 自动传递给其调用的
 不同子进程。若要向这些进程传递其他选项，必须使用 -W<字母> 选项。
```

```bash
gcc 编译命令
	gcc -E -P main.c -I head_file_path -Lhead_file.h -o target_file
	
	-E 预编译 
	-P 去掉目标文件中的注释
	-I 头文件路径
	-l 紧接着 要链接的头文件  如果头文件为 myhead.h. 应该是 -lmyhead.h 不需要加空格
	-o 链接的目标文件
```

```bash
g++ 命令支持很多参数，它们的作用是不同的。这里列出一些常用的参数： 
  -o：指定输出文件的名称；
  -I：指定头文件的搜索路径；
  -L：指定库文件的搜索路径；
  -l：指定要链接的库；
  -c：只编译不链接；
  -Wall：开启所有警告；
  -g：添加调试信息；
  -std：指定C++标准，可以是c++11、c++14等；
  -O：指定优化级别；
  -D：定义一个宏；
  -v：显示编译和链接的过程；
  -help：显示帮助信息。
```



## H

```bash
hostname #查看主机名
hostname -I # 查看ip
hostname  your-hostname  #修改主机名  不能用下划线，可以用横线 临时修改 在内存中修改
hostnamectl set-hostname your-hostname  #永久修改hostname 修改硬盘文件 也修改内存 （/etc/homename）
history  #历史输入命令
	- !命令编号 可以重复执行
  -c 清除历史
  -!string  包含string 倒数的命令 
  -export HISTTIMEFORMAT ="%F %T `whoami` " 写在文件 .bash_profile 里面
hash   #哈希 已经执行过的命令 放hash 里面 哈希表
	hash -r # 清除缓存
help  # 显示内部命令 的帮助文档
hexdump #查看十六进制
	-c 可以看字母	
halt #关机
help 
```

## I

```bash
init 3 #命令行界面
init 5 # 图形界面
init 6  #重新启动
init 0 # 关机
id 用户名
	-查看用户 
	-u uid
info 命令 #查看帮助
iconv #转换编码
	-f 原始格式
	-t 转换格式
	-o 输出文件
	
ifconfig
	查看IP 网卡信息 回环端口
	自己ping 回环端口可以测试自己ipv4 网线是不是正常
```


## J

```bash

```

## K

```bash

```


## L

```bash
lscpu # 查看cput信息
	-cat /proc/cpuinfo 也可以看到
logout # 退出
lsblk  #显示硬盘 查看硬盘信息
	-cat /proc/paritions
ls 查看目录
	-R 递归
	-d 查看目录本身
	- --ctime=ctime atime 
last reboot 
	查看系统重启情况(常用方法)：
ln:
    新建快捷方式用ln
    ls -s 源文件 挂在到哪里
    ln -s /Users/min122218/Nas_Data /Users/min122218/Desktop/Nas_data
    
```

## M

```bash
mv #文件移动
	mv -r #递归移动 移动目录
man COMMANDS#帮助文档
	- /搜索关键字 往下搜  ?关键字 网上搜
	-man -f 
	-man -a COMMANDS 看所有帮助文档
	-用whatis 命令。然后看第几章节 
	-whatis passwd 
	-显示第几章
	-passwd(5) 。。  这是第五章 可以 使用  man 5 passwd
	-man -k string 搜索 string 所带的命令
	 
```


```bash
mount
在macOS上，可以使用“mount”命令来挂载文件。以下是挂载文件的步骤：
打开“终端”应用程序
确保您已经创建了一个用于挂载文件的目录。如果没有，请使用以下命令创建一个：
sudo mkdir /Volumes/my_drive
请注意，“my_drive”应替换为您想要将文件挂载到的目录的名称。
使用以下命令挂载文件：
sudo mount -t filesystem_type /path/to/image_file /Volumes/my_drive

其中“filesystem_type”应替换为文件系统类型（例如，“ntfs”、“hfs”或“exfat”），而“/path/to/image_file”应替换为您要挂载的文件的路径。同样，“my_drive”应替换为您要将文件挂载到的目录名称。

如果一切顺利，您现在应该能够通过打开“Finder”并单击位于侧边栏中的挂载的驱动器来访问该文件。

卸载文件时，请使用以下命令：

sudo umount /Volumes/my_drive

这将卸载挂载的文件并使其从文件系统中删除。
```



## N

```bash
nano 编辑器
	脱字符(^)表示Ctrl键  ^X表示的就是组合键Ctrl+X
	CTRL+C 显示光标在文本编辑缓冲区中的位置
	CTRL+G  显示nano的主帮助窗口
	CTRL+J 调整当前文本段落
	CTRL+K 剪切文本行，并将其保存在剪切缓冲区
  CTRL+O  将当前文本编辑缓冲区的内容写入文件
  CTRL+R 将文件读入当前文本编辑缓冲区
  CTRL+T 启动可用的拼写检查器
  CTRL+U 将剪切缓冲区中的内容放入当前行
  CTRL+V 翻动到文本编辑缓冲区中的下一页内容
  CTRL+W 在文本编辑缓冲区中搜索单词或短语
  CTRL+X 关闭当前文本编辑缓冲区 退出nano，返回shell
  CTRL+Y 翻动到文本编辑缓冲区中的上一页内容

      ， 
	
	
```

## O

```bash

```


## P

```bash
pwd #显示当前路径
PS1="[修改命令行提示符]"  #修改命令行提示符
ps #查看进程
poweroff #关机

```


## Q

```bash

```

## R

```bash
runlevel   #查看模式（图形模式还是命令行模式）
	-N 表示模式 
reboot  # 重启计算机
```


## S

```bash
sudo  -i # 切换root
ssh  #远程
source  #写的配置文件生效
shutdown #关机或者重启
	shutdown +10 十分钟之后关机
	shutdown 02:30 2点30关机
sleep #休眠
sudo -i
systemctl 
	systemctl enable --now autofs 开机启动autofs
	systemctl start autofs	启动autofs 
	systemctl enable autofs 开机启动autofs
stat 查看文件时间
	
	
```

```bash
ssh 老链接不上
  需要先安装openssh-server,生成公钥ssh-keygen -A 
  install openssh-setver
  ssh-keygen -A
  线程查看sshd 是否工作
  ps aux |grep sshd
  which sshd
  systemctl enable sshd
  
```

```bash
添加sudo 权限
useradd min122218	
passwd min122218
vi /etc/sudoers

添加权限  
## Allows people in group wheel to run all commands

# %wheel        ALL=(ALL)       ALL  删除这行注释
%wheel        ALL=(ALL)       ALL

usermod –aG wheel min122218. 
添加到wheel 组 

```

```bash
亚马逊云 允许密码远程登录
sed -ri 's/^#?(PasswordAuthentication)\s+(yes|no)/\1 yes/' /etc/ssh/sshd_config

sed -ri 's/^#?(PermitRootLogin)\s+(yes|no)/\1 yes/' /etc/ssh/sshd_config

sed -ri 's/^/#/;s/sleep 10"\s+/&\n/' /root/.ssh/authorized_keys
service sshd restart
```



## T

```bash
tty  #当前操作的终端窗口
type 命令  #查看命令路径  -a all
tmux #分屏啥的
touch #建立文件
	-a 改变atime 和 ctime
	-m 改变mtime 和 ctime
	-c 如果文件不存在，则不创建
```

```bash
traceroute 测试IP 或者网络是否被封锁

```


## U

```bash
uname -r  查看版本
uptime #显示开机时间
unalias #取消别名 临时生效 修改内存

top 
	显示内存消耗 消耗高内存的放在前面
```



## V

```bash
vim 
	vim file 
	一般是浏览模式
	: 编辑模式 wq 保存退出:q 直接退出
	:1 光标去第一行 
	:98 光标去98行
	/你要搜索的字符
		/typedef  向下搜索搜索typedef 	.\{-} 多个字符
		/typedef.\{-}size_t 向下搜索从typedef 到size_t
	?你要搜索的字符
		？typedef 向上搜索typedef
vim 命令行模式 
	-h 左移动一个字符
	-j:下移一行(文本中的下一行)。
  -k:上移一行(文本中的上一行)。 
  -l:右移一个字符。
  -G：最后一行
  -gg 开始行
  -ctrl+F 下翻一屏
  -ctrl+b 上翻一屏
  -q:如果未修改缓冲区数据，退出。
  -q!:取消所有对缓冲区数据的修改并退出。
  -w filename:将文件保存到另一个文件中。
  -wq:将缓冲区数据保存到文件中并退出。
  
vim 编辑数据
	-x 删除当前光标所在位置的字符
	-dd 删除当前光标所在行
	-dw 删除当前光标所在位置的单词
	-d$ 删除当前光标所在位置至行尾的内容
	-J 删除当前光标所在行行尾的换行符(拼接行)
	-u 撤销前一编辑命令
	-a 在当前光标后追加数据 
	-A 在当前光标所在行行尾追加数据
  -r char 用char替换当前光标所在位置的单个字符 
  -R text 用text覆盖当前光标所在位置的数据，直到按下ESC键
  
  复制和粘贴
  -y yw表示复制一个单词，y$表示复制到行尾
  -p 粘贴
  
  查找
  ?word 向上查找
  /word 向下查找
  -:s/old/new/g:一行命令替换所有old。
  -:n,ms/old/new/g:替换行号n和m之间所有old。
  -:%s/old/new/g:替换整个文件中的所有old。
  -:%s/old/new/gc:替换整个文件中的所有old，但在每次出现时提示。
  -n 下一个
  -N 上一个
  
```


## W

```bash
  who #查看所有登录的信息
  whoami #显示当前身份
  who am i   #显示当前身份
  which  #查看外部命令的路径
  whereis #显示路径 和帮助文档
  w #查看登录用户，并且在干啥
  whatis #描述命令的功能
 		-mandb 生成帮助文档
 		
```

## X

```bash
xxd 查看二进制文件
```


## Y

```bash
yum  Centos安装
	yum install nano 
	
```

## Z

```bash

```

## 变量

```bash
$HISTSIZE
	#命令保存历史
```

## 其他功能命令

```
定时重启 
	https://blog.csdn.net/qq_29364417/article/details/101765014

```



#	命令行扩展

```bash
shell:
	linux ：bash 
	mac：zsh
内部命令：放/bin/bash  或内建
	非内部命令：放其他文件
	用type 命令 检查路径
$PATH:
	环境变量，
\COMMANDS
	内部命令 
命令格式
	COMMANDS [OPTIONS...] [ARGUMENTS...]
	命令 选项 参数
	选项特定功能
	多个命令用；批量执行
	一个命令多行执行 
查看系统发行版本
	cat /etc/redhat-release Centos
	cat /etc/os-release	Ubantu
编码：
	保存在硬盘的格式
字符集：
	二进制和字符的对应关系
$LANG：
	字符集 变量
man ascii：
	ascii 表
ctrl+l：
	清除屏幕
$(CMD) 或者 `CMD`
	'单引号' 强引用，当作字符串,变量和命令都不识别
	"双引号" 弱引用，可以识别变量，不识别命令  
	`命令`  反向单引号  可以执行命令,变量和命令都识别
	$(CMD) 变量和命令都可以识别
{}	#可以实现打印重复字符串的简化形式
	-echo file{1，4，5} #file1  file2 file3
	-touch myhead{.h,.cpp} #创建出文件 myhead.cpp  myhead.h
	-echo {1..10..2} # 1 3 5 7 9
	-echo {00..10..2}  # 00 02 04 06 08 10
	-echo file{1..10}.{txt,log} #生成20个文件
	-echo myhead.{h，cpp} # myhead.h myhead.cpp
ctrl+各种快捷键：
	-ctrl+s 阻止 屏幕输出 冻结屏幕。ctrl+解锁
	-ctrl+a 行首
	-ctrl+e 行尾
	-ctrl+b 光标左移
	-ctrl+f 光标右移
	-ctrl+u 删除光标前面的
	-ctrl+k 删除光标后面的
	-ctrl+xx 切换行首行位吧
查看帮助｜帮助文档咋看
	-type COMMANS 内部命令 help COMMANS  外部 COMMANS --help
	-COMMANDS --help
	-COMMANDS -h
	-[]表示可选项
	-caps or <>表示变化数据
	-...表示一个列表
	- x|y|z 表示  x or y or z
	- -abc 表示 -a -b -c
	-{}表示分组 
	
	
```

# 文件系统

```bash


颜色
      蓝色 文件夹 
      绿色 可执行文件
      红色 压缩文件 
      浅蓝色 链接文件 
      白色 一般文件
      黄色 特殊其他文件

文件类型
      -d 文件夹
      -c 字符文件
      - - 一般文件
      -p 管道文件		软件A 与 软件B 同学 
      -b 块设备 block
      -l 链接文件
      -s 套接字文件 socket 进程通信 单项传输
相对路径和绝对路径
			-绝对路径 /开始
			-相对路径 当前路径开始
文件时间
		-mtime modify time 修改时间 ls 显
		-ctime change time 属性更改
		-atime access time 被读时间
dos2unix or unix2dos
		-dos2unix 转换格式
		-windows 换行 \r\n
		-linux 换行\n
文件的通配符 
	- * 匹配零个恶或者多个字符｜ 不能匹配隐藏文件
	- ？匹配任何单个字符
	- ～当前家目录
	- ～min 用户～min家目录
	- ～+和. 当前工作目录
	- -前一个工作目录
	- [0-9] 匹配单个数字范围
	- [a-z]匹配a-z aAbBcC 不包括大写Z
	- [A-Z]匹配A-Z
	- [^0-9] 取非0-9
	-用法 tou
	-[wang] 匹配wang任意一个
	-[^wang] 排除wang
		
	
 	
```

我们把 
�
(
�
)
=
�
+
1
f(x)=x+1f, left parenthesis, x, right parenthesis, equals, x, plus, 1 和 
�
(
�
)
=
2
�
g(x)=2xg, left parenthesis, x, right parenthesis, equals, 2, x 相加，得到一个新的函数。
f(x)+g(x) =(x+1)+(2x)=x+1+2x=3x+1<!---->

