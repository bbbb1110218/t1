###  基本概念和数据可视化


** *

 **统计**

​	描述性统计（通过样本数据的研究，反应总体数据的参数）

​		-找统计量

​	推断性统计（通过小样本的预测，判断总体数据的参数）

​		-验证

**数据尺度**

​	-名义尺度 统计男女 

​	-序列尺度 没办法加减程序（基金经理排序）

​	-区间尺度 有排名的情况下 数据见的尺度有意义（比赛跑步）可以加减不可以乘除（时间温度是区间尺度）没有真正的零点

​	-比例尺度 最强的分类方式，有真正的零点

**算数的平均**

​	截面数据（某一天的全部股票走势）

​	时间序列数据（一系列按照时间来排列的数据）

**平均数**

​	**算术平均**：算术的均值容易收到极值的影响

​	**几何平均**：平均每年的收益率 第一年利息1% 第二年2% 第三年3% 平均每年的收益率计算方法

​						((1+0.01)*(1+0.02)*(1+0.03)) **(1/3)-1  每年乘以，然后开三次跟 减1

​	**调和平均**：数量除每个测量数据的倒数之和  买了两次股票价钱是10元和15元 按照调和平均的算法应该均价是

​						2/(1/10+1/15) 结果为12

``` html
几何平均数和调和平均数都是对数据进行惩罚 调和平均数的惩罚力度更大

算术平均数代表不了数据的波动率，几何平均数可以

算基金经理的收益波动率 第一个三年的收益是12，12，12 百分比 第二个是11，12，13个百分比

几何平均数的算法 第一个 （12 * 12 * 12） ** （1/3） 收益是 12 

							第二个 （11 * 12* 13）  ** （1/3） 收益是  11.972157672

几何平均测量的是多期的表现：比如有100块 三年的投资回报率是 100% 100% -100% 算术平均 的平均收益率是-33%
																																	几何平均 算出来的平均收益率是 0 
```

**众数**：分布中频率最高的数就是众数

**中位数**：中间的数

分位数的计算方法：

```
loc=（样本数量+1）*（百分位值）
样本有100个的时候 求50%分位。  
```









