
https://www.bilibili.com/video/BV1FE411P7B3?spm_id_from=333.337.search-card.all.click

## git 

### 版本控制

```
Git bash: linux风格的命令行

Git cmd: windows 风格命令行

git gui：图形 git 不推荐新手用
```

 ### 基本linux命令

```
cd :改变命令
cd ..    回到上一个目录
pwd			显示当前所载目录路径
ls | ll 都是现实当前目录中所有的文件，只不过两个l列出的内容更加详细
touch   新建一个文件 比如 touch index.js  剧户在当前目录下新建一个index.js文件
rm			删除一个文件 比如 rm index.js 会删除 index.js
mkdir		新建一个目录，新建一个文件夹
rm -r 	删除一个文件夹， rm -r scr	删除src目录
mv			移动文件 mv index.html src     index.html是我们要用移动文件 src是目				标文件夹，这样写必须在同一个目录下
reset		初始化终端/清屏
clear		清屏 
history	查看历史命令
help		帮助
exit		退出
#表示注释
```

### git 必要的配置

```
查看配置 					git config -l
查看系统配置 			git config --system --list    --是过滤的意思
查看用户的本地			git config --global --list   
			设置名称邮箱
			
```

```
设置名称邮箱 
git config --global user.name 'yourname'
git config --global user.email 'youremail'

所有的配置的文件，其实都保存在本地 
git 相关配置文件 都安装在Git安装目录下的gitconfig文件下 系统级别 
 
```

###  基本理论

```
命令 
git add .  	 把全部文件都add进去了
git commit -m “加一条message”   把暂存区域的文件提交到 git仓库
git push 		 推送到远程
```



![](/Users/macbookpro/Pictures/md用图片/截屏2022-05-31 14.59.55.png)

History 相当于本地仓库，master 主分支



git 本地有三个工作区域：

工作目录(workinf directory)

暂存区域（stage/index） 本质上是一个文件  

资源库 repository 或者 git directory 或者 history

如果加上远程的gir仓库 （remote directory ）就可以分成四个工作区



.git是隐藏文件夹

<img src="/Users/macbookpro/Pictures/md用图片/截屏2022-05-31 15.14.53.png" style="zoom:50%;" />

![](/Users/macbookpro/Pictures/md用图片/截屏2022-05-31 15.43.29.png) 

 ![](/Users/macbookpro/Pictures/md用图片/截屏2022-05-31 15.46.06.png)

### 本地仓库搭建

```
1 git init   新建隐藏文件 （也可以克隆一个 远程的仓库到本地） git clone url
2
```

### 文件的四种状态

**1.Untracked:**未跟踪,此文件在文件夹中，但是并没有加入git库中，不参与版本控制,通过**git add**状态变成 **Stage** 

**2.Unmodify:**文件已经入库 没修改,即版本库库中的文件快照与文件夹中的完全一致，这种类型的文件有两种去处，如果它被修改，而改变成**Modified**，如果使用 git rm 移出版本库，则称为**Untracked**文件

**3.Modified:**文件已修改,知识修改,并没有进行其他的操作，这个文件也有两个去处,通过**git add** 可进去暂存 **Staged**状态 ,使用 **git checkout** 则丢弃修改过，返回unmodify状态，这个git checkout即从库中取出文件，覆盖当前修改!

**4.Staged:** 暂存状态，执行**git commit** 则将修改同步到库中，这时库中的文件和本地文件又变成一致，文件为 **unmodifty** 状态 执行**git reset HEAD filename** 取消暂存，文件状态为 **Modified**

 ### git 命令

```
git status  					 # 查看所有文件的状态
git status [filename]  # 查看指定文件的状态
git add .							 # 添加所有文件到暂存区
git commit -m '内容 '			 # 提交暂存区的内容到本地仓库 -m 提交信息  

```

### 忽略文件

```
在目录下建立 “.gitignore” 
忽略所有以#开始的文件 #为注释
*.txt 			#忽略所有 .txt结尾的文件，这样的话上传就不会被选中
!lib.txt		#但lib.txt 除外
/temp				#忽略目录下 的其他文件，不包括其他目录temp
 bulid/			# 忽略bulid目录下的所有文件
 doc/*.txt  # 忽略doc目录下所有 txt 文件
```

### gitee的注册和使用

```
# 免密码登陆
进入 c:\User\Administrator\.sh目录
生成公钥匙
ssh-keygen
输入  ssh-keygen -t rsa  -C "你的邮箱"
生成的文件在 用户目录下面.ssh文件里面
复制 .ssh公钥在 Gitee 下面 进行进行绑定
```



Idea 中集成 git

```
三步
git add .
git commit -m 'hello'
git push 
pycharm 红色文件是选中状态,绿色是提交了  

https://gitee.com/min122218/minliang.git

```

