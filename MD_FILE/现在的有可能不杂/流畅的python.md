```
本笔记来自 流畅的python
```
[toc]

## chapter1:数据模型

>
>魔法函数
>```python
>----------------------------------------------------------------
>def __len__(self):					#可以返回长度
>  	return len(somthing)
>----------------------------------------------------------------
>def __getitem__(self,position):  ##可以切片 迭代 for循环 判断
>  	return self.list[position]		##Card('Q', 'hearts') in deck True
>----------------------------------------------------------------
>def __mul__(self.other):			##乘法
>  return Vector(self.x * scalar, self.y * scalar)
>----------------------------------------------------------------
>def __repr__(self):		## 显示的字符 它能把一个对象用字符串的形式表达出来以便辨认
>	return 'Vector(%r, %r)' % (self.x, self.y)
>----------------------------------------------------------------
>def __str__(self):		## 			str()
>  return "something"
>----------------------------------------------------------------
>def __add__(self):				##加法
>  x = self.x + other.x
>  y = self.y + other.y
>  return Vector(x, y)
>
>----------------------------------------------------------------
>def __mul__(self, scalar):			# 乘法
>	return Vector(self.x * scalar, self.y * scalar)
>
>----------------------------------------------------------------
>
>def __bool__(self):							bool(somthing)
>  	return bool(self.x or self.y)
>
>
>
>
>
>
>```
>
>![](/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-10-12 22.48.05.png)

## chapter 数据结构

>
>
>**容器序列**
>
>> list、tuple 和 collections.deque 这些序列能存放不同类型的数据。
>
>**扁平序列**
>
>>str、bytes、bytearray、memoryview 和 array.array，这类序列只能容纳一种类型。
>
>**可变序列**
>
>> list、bytearray、array.array、collections.deque 和 memoryview。
>
>**不可变序列**
>
>> tuple、str 和 bytes

图 2-1 显示了可变序列(MutableSequence)和不可变序列(Sequence)的差异，同时也 能看出前者从后者那里继承了一些方法。虽然内置的序列类型并不是直接从 Sequence 和 MutableSequence这两个抽象基类(Abstract Base Class，ABC)继承而来的，但是了解这 些基类可以帮助我们总结出那些完整的序列类型包含了哪些功能。

​			 		 		 		 		<img src="/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-10-12 22.59.54.png" style="zoom:50%;" /> 	

图 2-1:这个 UML 类图列举了 collections.abc 中的几个类(超类在左边，箭头从子类指向超类， 斜体名称代表抽象类和抽象方法)

>Filter 用法：
>
>```python
>filter(lambda x:x >100, [100,400,7]) ;生成一个迭代器 用列表装一下就行了
>
>```
>
>map的用法
>
>```python
>  ## map(函数，要操作的数据或者列表)		；生成一个map bool对象。用列表装一下也可以 活着循环
>  
>  [i for i in map(lambda x:x >100,[100,400,1])]
>  [False, True, False]
>
>```
>
>
>
>

![](/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-10-12 23.59.41.png)

![](/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-10-12 23.59.57.png)
