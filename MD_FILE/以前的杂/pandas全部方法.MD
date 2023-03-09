# pandas

### 学到那？

https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.where.html  where

## Dataframe

### 检查索引或者列名是不是唯一值

```
df.index.is_unique
df.columns.is_unique
返回布尔
```

### group by 的用法

```python
可以使用聚合函数
> df.groupby(by=['列名']).sum()
> df.groupby(by=["b"], dropna=False).sum() # b里面有na值也可分成一组

df.groupby(
    by=None,
    axis: 'Axis' = 0,
    level: 'Level | None' = None,
    as_index: 'bool' = True,
    sort: 'bool' = True,
    group_keys: 'bool' = True,
    squeeze: 'bool | lib.NoDefault' = <no_default>,
    observed: 'bool' = False,
    dropna: 'bool' = True,
) -> 'DataFrameGroupBy'


```

### df.dtypes

```
查看每列的数据类型
```

### df.axes

```
查看columns 和index
```

### df.ndim

```
查看数据的维度 serise 是1维 df是2维度
```

### df.size

``` 
查看values 的个数
s = pd.Series({'a': 1, 'b': 2, 'c': 3})
s.size
3
df = pd.DataFrame({'col1': [1, 2], 'col2': [3, 4]})
df.size
4
```

### df.shape

``` 
查看数据有几行几列
df = pd.DataFrame({'col1': [1, 2], 'col2': [3, 4]})
df.shape
(2, 2)
df = pd.DataFrame({'col1': [1, 2], 'col2': [3, 4],
                   'col3': [5, 6]})
df.shape
(2, 3)
```

### df.empty

```
查看数据是不是空值 是控制返回true
如果数据只有 np.nan 数据也不是空值 注意
```

### df.astype

```
to_datetime
将参数转换为日期时间。
to_timedelta
将参数转换为 timedelta。
to_numeric
将参数转换为数字类型。
numpy.ndarray.astype
将 numpy 数组转换为指定类型。

df.astype({'列名':'要转换的类型'}) # df.astype('column1':'float64')
要重新赋值才能转换成功


```

### pd.date_range

``` 
创建日期列表
pd.date_range(start='开始日期',freq='d天 w周 y年 5H五小时',periods='int要创建多少个日期', )
```

### df.convert_dtypes()

```
自动转换数据类型，不太好使的样子
```

### df.copy()

```
df.copuy(deep=true) 深拷贝
```

### df.head(), df.tail()

``` 
df.head(3) 取前三行数据
df.head(-3) 返回的数据不包括前三行
```

### df.at['','']      	df.iat[,]

```
df.iat[] 是索引名字和列名的索引
df.at[]是索引和列名的绝对值
```

### df.loc[]

```
df.loc[df['shield'] > 6] 作为条件
df.loc[lambda df: df['shield'] == 8] 用匿名函数

```

###  df.iloc[]

```
df.iloc[0] 返回 Series
df.iloc[[0]] 返回df
df.iloc[lambda x: x.index % 2 == 0]  可以用匿名函数
      a     b     c     d
0     1     2     3     4
2  1000  2000  3000  4000

```



### d.MultiIndex.from_tuples(tuples) 双索引

```
tuples = [
   ('cobra', 'mark i'), ('cobra', 'mark ii'),
   ('sidewinder', 'mark i'), ('sidewinder', 'mark ii'),
   ('viper', 'mark ii'), ('viper', 'mark iii')
]

index = pd.MultiIndex.from_tuples(tuples)
values = [[12, 2], [0, 4], [10, 20],
        [1, 4], [7, 1], [16, 36]]
df = pd.DataFrame(values, columns=['max_speed', 'shield'], index=index)
df
                     max_speed  shield
cobra      mark i           12       2
           mark ii           0       4
sidewinder mark i           10      20
           mark ii           1       4
viper      mark ii           7       1
           mark iii         16      36
           
df.loc[('cobra', 'mark i'), 'shield'] 双索引index用元祖包裹起来
```

###  df.insert

```
df.insert(列的索引，列名，[values],allow_duplicates(是否允许列名重复 布尔))
df = pd.DataFrame({'col1': [1, 2], 'col2': [3, 4]})
df
   col1  col2
0     1     3
1     2     4
df.insert(1, "newcol", [99, 99])
df
   col1  newcol  col2
0     1      99     3
1     2      99     4
df.insert(0, "col1", [100, 100], allow_duplicates=True)
df
   col1  col1  newcol  col2
0   100     1      99     3
1   100     2      99     4

data.insert(1,'code',['您的时代']*len(data.index),allow_duplicates=True)
data
date	code	open	close	high	low	volume	code
0	2019-04-26	您的时代	34.08	33.15	34.75	32.50	120497.0	600848
1	2019-04-29	您的时代	33.70	33.88	35.22	33.61	157261.0	600848
2	2019-04-30	您的时代	33.80	35.22	35.55	33.50	113277.0	600848
3	2019-05-06	您的时代	32.03	31.70	33.18	31.70	112336.0	600848
4	2019-05-07	您的时代	31.00	30.23	31.70	28.73	157289.0	600848
```

### df.item

```
返回可以叠戴的对象
for x,y in df.items()
	x 为 df的列
	y 为 df[x]
```

### df.keys

``` 
df.keys()返回所有列名
```

### df,iterrows()

```
for x in df.iterrows() 
	x[0] 索引名字
	x[1] 一行values
```

### Df.比较值

```
DataFrame.eq
比较 DataFrames 的元素相等性。

DataFrame.ne
比较 DataFrames 的元素不等式。

DataFrame.le
比较 DataFrames 是否小于等于或等于元素。

DataFrame.lt
比较 DataFrames 的严格小于元素不等式。

DataFrame.ge
比较 DataFrames 是否大于等于或等于元素。

DataFrame.gt
比较 DataFrames 的严格大于不等式元素。
```



### df.pop()

```
df.pop('列名') 删除df 列名 有返回值
```



###  df.xs

``` 	
取多个索引
略 有点难


```

###  df.isin()

```
df.isin([列表]) 返回整个df的布尔值
df.isin({'列名'：[列表]})  判断某列是否在列表内
也可以
df['列名'].isin([列表])

```

### df.where

```
df['lie2']=df['lie1'].where(df['lie1'] >1 条件, 不满足条件的结果)
不满足条件的返回nan

```

### df.query()

```
df.query('A > B') 前面的表达式等价于 df[df.A > df.B]

df.query('B == `C C`') 前面的表达式等价于 df[df.B == df['C C']]
```

### df.add() df.div() df.rdiv()

```
df.add(1)    =  df+1
df.div(10)   = df/10
df.rdiv(10)   = 10/df
```

### 在算术运算符的灵活包装器（add、sub、mul、div、mod、pow）中：+、-、*、/、//、%、**。

```
add  +
sub  -
mul  *
div   /
mod  %
pow  **
```

### df.pct_chang()

```
当前元素和先前元素之间的百分比变化 有NULL值得时候，记得填充一下NULL
s = pd.Series([90, 91, 85])
s
0    90
1    91
2    85
dtype: int64

s.pct_change()
0         NaN
1    0.011111
2   -0.065934
dtype: float64

s.pct_change(periods=2)
0         NaN
1         NaN
2   -0.055556
dtype: float64

s.pct_change(fill_method='ffill')
0         NaN
1    0.011111
2    0.000000
3   -0.065934
dtype: float64

```

### df.combine()

```
df1 = pd.DataFrame({'A': [0, 0], 'B': [4, 4]})
>>> df2 = pd.DataFrame({'A': [1, 1], 'B': [3, 3]})
>>> take_smaller = lambda s1, s2: s1 if s1.sum() < s2.sum() else s2
>>> df1.combine(df2, take_smaller)
```

### df.join()

```
表链接有三种方法
1 df.join(other.set_index('key'),on='key')
2 df.set_index('key').join(other.set_index('key'))
3 df.join(other,lsuffix='_left',rsuffix='_right') 
#当有一样列的时候，在左边和右表都加上后缀，区分一下
```

###  df.apply()

```
df.apply(np.sum) 列累加。默认是axis=0
df.apply(np.sum,axis=1) 行累加
df.apply(np.sqrt) 开平方
df.apply(lambda x: [1,2],axis=1) 可以使用匿名函数，axis=1的时候，可以取原df的索引

可以定义一个函数，然后apply 函数
def fuck(x):
    return x **2 +10
df.apply(fuck)


```

### df.applymap()

```
好像和apply 功能一样
当有nan值的时候，可以在括号里面加参数，na_action='ignore'忽略
```

### df.agg()

``` 
对df 使用聚合函数等等
df = pd.DataFrame([[1, 2, 3],
                   [4, 5, 6],
                   [7, 8, 9],
                   [np.nan, np.nan, np.nan]],
                  columns=['A', 'B', 'C'])
df
	A	B	C
0	1.0	2.0	3.0
1	4.0	5.0	6.0
2	7.0	8.0	9.0
3	NaN	NaN	NaN

df.agg(['min','prod'])
	     A	   B	    C
min	  1.0	  2.0	   3.0
prod	28.0	80.0	162.0
```



### df.rolling()

```
滚动几个窗口
df.rolling(2).sum() 滚动两个窗口求和
df.rolling(2, win_type='gaussian').sum(std=3) 高斯分布求标准差？？？
 	
```

### df.ewm

```
实现某种特殊的算法吧，有点看不懂，智商不行
DataFrame.ewm(com=None, span=None, halflife=None, alpha=None, min_periods=0, adjust=True, ignore_na=False, axis=0, times=None)

df = pd.DataFrame({'B': [0, 1, 2, np.nan, 4]})
df
     B
0  0.0
1  1.0
2  2.0
3  NaN
4  4.0

df.ewm(com=0.5).mean()
          B
0  0.000000
1  0.750000
2  1.615385
3  1.615385
4  3.670213

```

### df.clip()

``` 
设定一个区间
df.clip(min,max) 当某列的值比min还小的时候，值就为min

data = {'col_0': [9, -3, 0, -1, 5], 'col_1': [-2, -7, 6, 8, -5]}
df = pd.DataFrame(data)
df
   col_0  col_1
0      9     -2
1     -3     -7
2      0      6
3     -1      8
4      5     -5

df.clip(-4, 6)
   col_0  col_1
0      6     -2
1     -3     -4
2      0      6
3     -1      6
4      5     -4
```

### df.map()

```
city_to_state = { 'San Francisco' : 0, 
                  'Baltimore' : 1, 
                  'Miami' : 2, 
                  'Douglas' : 3, 
                  'Boston' : 4}
1
2
3
4
5
城市名map到洲名，保存到state变量中：

df['state'] = df['city'].map(city_to_state)
df
```

https://img-blog.csdnimg.cn/2020120711590966.png

### df 设置显示 max.display_rows

```
pd.set_option('display.max_rows',5000)  最大行
```

### pd.read_csv

```python
空值预处理
missing_values = ["n/a", "na", "--"]
df = pd.read_csv('property-data.csv', na_values = missing_values)
```

###  contains  判断某个字符串是否包含给定字符

```
df["家庭住址"].str.contains("广")
```



























## 中技巧









