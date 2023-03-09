## pandas 

### 验证数据

```
df.shape # (100, 6) 查看行数和列数 
df.info() # 查看索引、数据类型和内存信息 
df.describe() # 查看数值型列的汇总统计 
df.dtypes # 查看各字段类型
df.axes # 显示数据行和列名 
df.columns # 列名
```

### 数据选取

```
# 单一条件
df[df.Q1 > 90] # Q1列大于90的
df[df.team == 'C'] # team列为'C'的
df[df.index == 'Oscar'] # 指定索引即原数据中的name
# 组合条件
df[(df['Q1'] > 90) & (df['team'] == 'C')] # and关系 df[df['team'] == 'C'].loc[df.Q1>90] # 多重筛选

```

### 分组聚合

```
df.groupby('team').sum() # 按团队分组对应列相加
df.groupby('team').mean() # 按团队分组对应列求平均
# 不同列不同的计算方法 
df.groupby('team').agg({'Q1': sum, # 总和
'Q2': 'count', # 总数 'Q3':'mean', # 平均 'Q4': max}) # 最大值
```

### 增加列

```
df['one'] = 1 # 增加一个固定值的列
df['total'] = df.Q1 + df.Q2 + df.Q3 + df.Q4 # 增加总成绩列
# 将计算得来的结果赋值给新列
df['total'] = df.loc[:,'Q1':'Q4'].apply(lambda x:sum(x), axis=1) df['total'] = df.sum(axis=1) # 可以把所有为数字的列相加
df['avg'] = df.total/4 # 增加平均成绩列

df.eval('new_column=old_colume/2')       
```

### 统计分析

```
df.mean() # 返回所有列的均值
df.mean(1) # 返回所有行的均值，
df.corr() # 返回列与列之间的相关系数 
df.count() # 返回每一列中的非空值的个数
df.max() # 返回每一列的最大值 
df.min() # 返回每一列的最小值 
df.median() # 返回每一列的中位数
df.std() # 返回每一列的标准差 
df.var() # 方差
s.mode() # 众数

```

### 绘图

```
df['Q1'].plot() # Q1成绩的折线分布
df.loc[ 'Ben','Q1':'Q4'].plot.bar() # 柱状图 
df.loc[ 'Ben','Q1':'Q4'].plot.barh() # 横向柱状图
df.groupby('team').count().Q1.plot.pie() #饼图
```

###   索引的属性

```
# 常用属性
df.index.name # 名称
df.index.array # array数组 
df.index.dtype # 数据类型 
df.index.shape # 形状
df.index.size # 元素数量 
df.index.values # array数组
# 其他，不常用
df.index.empty # 是否为空 
df.index.is_unique # 是否不重复 
df.index.names # 名称列表 
df.index.is_all_dates # 是否全是日期时间 
df.index.has_duplicates # 是否有重复值 
df.index.values # 索引的值array
```

### 索引的操作

```
# 常用方法
df.index.astype('int64') # 转换类型
df.index.isin() # 是否存在，见下方示例 df.index.rename('number') # 修改索引名称 
df.index.nunique() # 不重复值的数量 df.index.sort_values(ascending=False,) # 排序，倒序 df.index.map(lambda x:x+'_') # map函数处理 df.index.str.replace('_', '') # str替换 df.index.str.split('_') # 分隔
df.index.to_list() # 转为列表 
df.index.to_frame(index=False, name='a') # 转成DataFrame df.index.to_series() # 转为series
df.index.to_numpy() # 转为numpy
df.index.unique() # 去重
df.index.value_counts() # 去重及计数 df.index.where(df.index=='a') # 筛选 df.index.rename('grade', inplace=False) # 重命名索引 df.index.rename(['species', 'year']) # 多层，重命名索引 df.index.max() # 最大值
df.index.argmax() # 最大索引值
df.index.any()
df.index.all()
df.index.T # 转置，在多层索引里很有用
```

### 统计函数

```
df.mean() # 返回所有列的均值 
df.mean(1) # 返回所有行的均值，下同 
df.corr() # 返回列与列之间的相关系数
df.count() # 返回每一列中的非空值的个数 
df.max() # 返回每一列的最大值 
df.min() # 返回每一列的最小值
df.abs() # 绝对值
df.median() # 返回每一列的中位数
df.std() # 返回每一列的标准差，贝塞尔校正的样本标准偏差 
df.var() # 无偏方差
df.sem() # 平均值的标准误差
df.mode() # 众数
df.prod() # 连乘
df.mad() # 平均绝对偏差
df.cumprod() # 累积连乘，累乘
df.cumsum(axis=0) # 累积连加，累加
df.nunique() # 去重数量，不同值的量
df.idxmax() # 每列最大值的索引名
df.idxmin() # 每列最小值的索引名
df.cummax() # 累积最大值
df.cummin() # 累积最小值
df.skew() # 样本偏度(第三阶)
df.kurt() # 样本峰度(第四阶)
df.quantile() # 样本分位数(不同 % 的值)
```

### 非统计计算

```
df.all() # 返回所有列all()值的Series 
df.any()# 四舍五入
df.round(2) # 指定字段指定保留小数位，
df.round({'Q1': 2, 'Q2': 0}) 
df.round(-1) # 保留10位
# 每个列的去重值的数量 
df.nunique()
s.nunique() # 本列的去重值
# 真假检测
df.isna() # 值的真假值替换 
df.notna() # 与上相反
df + 1 # 等运算 
df.add() # 加
df.sub() # 减
df.mul() # 乘
df.div() # 除
df.mod() # 模，除后的余数 
df.pow() # 指数幂 
df.dot(df2) # 矩阵运算
```

### Series 计算

```
# 不重复的值及数量
s.value_counts() s.value_counts(normalize=True) #重复值的频率 
s.value_counts(sort=False) # 不按频率排序
s.unique() # 去重的值 array 
s.is_unique # 是否有重复
# 最大最小值
s.nlargest() # 最大的前5个 
s.nlargest(15) # 最大的前15个
s.nsmallest() # 最小的前5个 
s.nsmallest(15) # 最小的前15个
s.pct_change() # 计算与前一行的变化百分比 s.pct_change(periods=2) # 前两行
s1.cov(s2) # 两个序列的协方差
```

### 位置计算

```
s1.diff() #与上一行的差值
pd.Series([9, 4, 6, 7, 9]).diff(-2)# 后方向，移动两位求差值
# 整体下移一行，最顶的一行为NaN df.shift()
df.shift(3) # 移三行
# 整体上移一行，最底的一行为NaN 
df.Q1.head().shift(-1)
# 向右移动一位 df.shift(axis=1) 
df.shift(3, axis=1) # 移三位 # 向左移动一位
df.shift(-1, axis=1) # 实现了df.Q1.diff() df.Q1 - df.Q1.shift()

```

### 逻辑计算

```
df[df['Q1'] == 8] # Q1等于8 
df[~(df['Q1'] == 8)] # 不等于8 
df[df.name == 'Ben'] # 姓名为Ben 
df[df.Q1 > df.Q2]result.trade_date.day
# 表达式与切片一致
df.loc[df['Q1'] > 90, 'Q1':] # Q1大于90，只显示Q1 
df.loc[(df.Q1 > 80) & (df.Q2 < 15)] # and关系 
df.loc[(df.Q1 > 90) | (df.Q2 < 90)] # or关系 
df.loc[df['Q1'] == 8] # 等于8
df.loc[df.Q1 == 8] # 等于8
df.loc[df['Q1'] > 90, 'Q1':] # Q1大于90，显示Q1及其后所有列

# Q1、Q2成绩全为超过80分的 
df[(df.loc[:,['Q1','Q2']] > 80).all(1)]

# Q1、Q2成绩至少有一个超过80分的 
df[(df.loc[:,['Q1','Q2']] > 80).any(1)]


```

### 函数筛选

```
# 查询最大索引的值
df.Q1[lambda s: max(s.index)] # 值为21 # 计算最大值
max(df.Q1.index) 
df.Q1[df.index==99]
df[lambda df: df['Q1'] == 8] # Q1为8的
df.loc[lambda df: df.Q1 == 8, 'Q1':'Q2'] # Q1为8的，显示 Q1、Q2 
df.loc[:, lambda df: df.columns.str.len()==4] # 由真假值组成的序列 
df.loc[:, lambda df: [i for i in df.columns if 'Q' in i]] # 列名 
df.iloc[:3, lambda df: df.columns.str.len()==2] # 由真假值组成的序

```

### 比较函数

```
# 以下相当于 df[df.Q1 == 60] 
df[df.Q1.eq(60)]df.ne() # 不等于 

!= df.le() # 小于等于 
<= df.lt() # 小于 
< df.ge() # 大于等于 
>= df.gt() # 大于 >
df[df.Q1.ne(89)] # Q1不等于89
df.loc[df.Q1.gt(90) & df.Q2.lt(90)] # and关系，Q1>90，Q2<90

# isin
df[df.team.isin(['A','B'])] # 包含A、B两组的
df[df.isin({'team': ['C', 'D'], 'Q1':[36,93]})] # 复杂查询，其
```

### 查询函数

```
df.query('Q1 > Q2 > 90') # 直接写类型SQL where语句 df.query('Q1 + Q2 > 180')
df.query('Q1 == Q2')
df.query('(Q1<50) & (Q2>40) and (Q3>90)') df.query('Q1 > Q2 > Q3 > Q4')
df.query('team != "C"')
df.query('team not in ("E","A","B")')

# 对于名称中带有空格的列，可以使用反引号引起来 
df.query('B == `team name`')
# 支持传入变量，如大于平均分40分的 
a = df.Q1.mean()
df.query('Q1 > @a+40') 
df.query('Q1 > `Q2`+@a'
)
df.eval()与df.query()类似，也可以用于表达式筛选:
# df.eval()用法与df.query类似 
df[df.eval("Q1 > 90 > Q3 > 10")] 
df[df.eval("Q1 > `Q2`+@a")]

df.filter(items=['Q1', 'Q2']) # 选择两列 
df.filter(regex='Q', axis=1) # 列名包含Q的列 
df.filter(regex='e$', axis=1) # 以e结尾的列 
df.filter(regex='1$', axis=0) # 正则，索引名以1结尾
、df.filter(like='2', axis=0) # 索引中有2的

# 索引中以2开头、列名有Q的
df.filter(regex='^2', axis=0).filter(like='Q', axis=1)

df.select_dtypes(include=['float64']) # 选择float64型数据 df.select_dtypes(include='bool') df.select_dtypes(include=['number']) # 只取数字型 df.select_dtypes(exclude=['int']) # 排除int类型 df.select_dtypes(exclude=['datetime64'])
```

### 数据类型转换

```
s.infer_objects() #推断转换数据类型
s.convert_dtypes() # 转换数据类型 自动
pd.to_numeric() # 转换为数字类型
pd.to_timedelta()
pd.to_datetime(m, errors='coerce') # 错误处理 
pd.to_numeric(m, errors='ignore')
pd.to_numeric(m errors='coerce').fillna(0) # 错误的填充为0
pd.to_datetime(df[['year', 'month', 'day']]) # 组合成日期
df.Q1.astype('int32').dtypes
# dtype('int32')
df.astype({'Q1': 'int32','Q2': 'int32'}).dtypes
```

### 数据排序

```
df.sort_index(ascending=False)# 索引降序 
df.sort_index(axis=1, ascending=False)# 在列索引方向上排序 
s.sort_index() # 升序排列
df.sort_index() # df也是按索引进行排序
df.team.sort_index()
s.sort_index(ascending=False) # 降序排列 
s.sort_index(inplace=True) # 排序后生效，改变原数据
# 索引重新0-(n-1)排，很有用，可以得到它的排序号 s.sort_index(ignore_index=True) s.sort_index(na_position='first') # 空值在前，另'last'表示空值在后 s.sort_index(level=1) # 如果多层，排一级
s.sort_index(level=1, sort_remaining=False) # 这层不排
# 行索引排序，表头排序
df.sort_index(axis=1) # 会把列按列名顺序排列

s.sort_values(ascending=False) # 降序 
s.sort_values(inplace=True) # 修改生效 
s.sort_values(na_position='first') # 空值在前 # df按指定字段排列
df.sort_values(by=['team'])
df.sort_values('Q1')# 按多个字段，先排team，在同team内再看Q1 
df.sort_values(by=['team', 'Q1'])
# 全降序
df.sort_values(by=['team', 'Q1'], ascending=False)
# 对应指定team升Q1降
df.sort_values(by=['team', 'Q1'], ascending=[True, False]) # 索引重新0-(n-1)排
df.sort_values('team', ignore_index=True)

df.set_index('name', inplace=True) # 设置name为索引 
df.index.names = ['s_name'] # 给索引起名
df.sort_values(by=['s_name','team']) # 排序

# 先按Q1最小在前，如果相同，Q2小的在前 
df.nsmallest(5, ['Q1', 'Q2'])
s.nsmallest(3) # 最小的3个 
s.nlargest(3) # 最大的3个
# 指定列
df.nlargest(3, 'Q1') 
df.nlargest(5, ['Q1', 'Q2'])
df.nsmallest(5, ['Q1', 'Q2'])

```

### 替换数据

```
df.replace(0, 5) # 将数据中的所有0换为5
df.replace([0, 1, 2, 3], 4) # 将0~3全换成4
df.replace([0, 1, 2, 3], [4, 3, 2, 1]) # 对应修改
# {'pad', 'ffill', 'bfill', None} 试试
s.replace([1, 2], method='bfill') # 向下填充
df.replace({0: 10, 1: 100}) # 字典对应修改
df.replace({'Q1': 0, 'Q2': 5}, 100) # 将指定字段的指定值修改为100 
df.replace({'Q1': {0: 100, 4: 400}}) # 将指定列里的指定值替换为另一个 
# 使用正则表达式
df.replace(to_replace=r'^ba.$', value='new', regex=True) 
df.replace({'A': r'^ba.$'}, {'A': 'new'}, regex=True) 
df.replace(regex={r'^ba.$': 'new', 'foo': 'xyz'})
df.replace(regex=[r'^ba.$', 'foo'], value='new')

df.fillna(0) # 将空值全修改为0
# {'backfill', 'bfill', 'pad', 'ffill', None}, 默认为None 
df.fillna(method='ffill') # 将空值都修改为其前一个值
values = {'A': 0, 'B': 1, 'C': 2, 'D': 3} 
df.fillna(value=values) # 为各列填充不同的值 
df.fillna(value=values, limit=1) # 只替换第一个
```

### 修改索引名

```
df.rename(columns={'team':'class'}) #修改列名
df.rename(columns={"Q1": "a", "Q2": "b"}) # 对表头进行修改 
df.rename(index={0: "x", 1: "y", 2: "z"}) # 对索引进行修改
df.rename(index=str) # 对类型进行修改 
df.rename(str.lower, axis='columns') # 传索引类型 
df.rename({1: 2, 2: 4}, axis='index')
# 对索引名进行修改
s.rename_axis("animal")
df.rename_axis("animal") # 默认是列索引 
df.rename_axis("limbs", axis="columns") # 指定行索引 
# 索引为多层索引时可以将type修改为class df.rename_axis(index={'type': 'class'})
# 可以用set_axis进行设置修改
s.set_axis(['a', 'b', 'c'], axis=0)
df.set_axis(['I', 'II'], axis='columns') 
df.set_axis(['i', 'ii'], axis='columns', inplace=True)

```

### 操作列和行

```
df['total'] = df.Q1 + df.Q2 + df.Q3 + df.Q4
df['total'] = df.sum(1) # 与以上代码效果相同
df['foo'] = 100 # 增加一列foo，所有值都是100 
df['foo'] = df.Q1 + df.Q2 # 新列为两列相加 
df['foo'] = df['Q1'] + df['Q2'] # 同上
# 把所有为数字的值加起来
df['total'] = df.select_dtypes(include=['int']).sum(1)

df['mean']=df.loc[:,['open','close','high','low']].apply(lambda x:x.mean(),axis=1)

df.insert(1,'sum',df.loc[:,['open','close','high','low']].apply(lambda x:x.sum(),axis=1))

# 增加total列 
df.assign(total=df.sum(1))
df.assign(Q5=[100]*100) # 新增加一列Q5
df = df.assign(Q5=[100]*100) # 赋值生效 
df.assign(Q6=df.Q2/df.Q1) # 计算并增加Q6 
df.assign(Q7=lambda d: d.Q1 * 9 / 5 + 32) # 使用lambda
# 添加一列，值为表达式结果:True或False 
df.assign(tag=df.Q1>df.Q2)
# 比较计算，True为1，False为0 
df.assign(tag=(df.Q1>df.Q2).astype(int))
# 映射文案 
df.assign(tag=(df.Q1>60).map({True:'及格',False:'不及格'}))

# 传入求总分表达式 
df.eval('total = Q1+Q3+Q3+Q4')
df['C1'] = df.eval('Q2 + Q3')
df.eval('C2 = Q2 + Q3') # 计算
a = df.Q1.mean()
df.eval("C3 = `Q3`+@a") # 使用变量
df.eval("C3 = Q2 > (`Q3`+@a)") # 加一个布尔值
df.eval('C4 = name + team', inplace=True) # 立即生效

#增加行
df.loc[100] = ['tom', 'A', 88, 88, 88, 88]
df.loc[101]={'Q1':88,'Q2':99} # 指定列，无数据列值为NaN 
df.loc[df.shape[0]+1] = {'Q1':88,'Q2':99} # 自动增加索引 
df.loc[len(df)+1] = {'Q1':88,'Q2':99}
# 批量操作，可以使用迭代
rows = [[1,2],[3,4],[5,6]]
for row in rows:
    df.loc[len(df)] = row
```

### 合并

```
df = pd.DataFrame([[1, 2], [3, 4]], columns=list('AB'))
df2 = pd.DataFrame([[5, 6], [7, 8]], columns=list('AB'))
df.append(df2)

s1 = pd.Series(['a', 'b'])
s2 = pd.Series(['c', 'd'])
pd.concat([s1, s2])
pd.concat([s1, s2], ignore_index=True) # 索引重新编
# 原数索引不变，增加一个一层索引(keys里的内容)，变成多层索引 pd.concat([s1, s2], keys=['s1', 's2'])
pd.concat([s1, s2], keys=['s1', 's2'],
          names=['Series name', 'Row ID'])
# df同理
pd.concat([df1, df2])
pd.concat([df1, df3], sort=False) pd.concat([df1, df3], join="inner") # 只连相同列 pd.concat([df1, df4], axis=1) # 连接列
```

### 删除空值

```
df.dropna() # 一行中有一个缺失值就删除
df.dropna(axis='columns') # 只保留全有值的列
df.dropna(how='all') # 行或列全没值才删除 
df.dropna(thresh=2) # 至少有两个空值时才删除 
df.dropna(inplace=True) # 删除并使替换生效
```

### 高级过滤

```
# 只保留数字类型列
df = df.select_dtypes(include='number')

# 数值大于70 df.where(df > 70)
# Q1列大于50
df.where(lambda d: d.Q1>50)

# 传入布尔值Series，前三个为真 
df.Q1.where(pd.Series([True]*3))

# 大于等于60分的显示成绩，小于的显示“不及格” df.where(df>=60, '不及格')

# c 定义一个数是否为偶数的表达式
c = df%2 == 0
# 传入c, 为偶数时显示原值减去20后的相反数 df.where(~c, -(df-20))

# 小于60分为不及格
np.where(df>=60, '合格', '不合格')

# 让df.where()中的条件为假，从而应用np.where()的计算结果 df.where(df==9999999, np.where(df>=60, '合格', '不合格'))

(
df.assign(avg=df.mean(1)) # 计算一个平均数
# 通过np.where()及判断平均分是否及格
.assign(及格=lambda d: np.where(d.avg>=60, '是', '否'))
)

df.mask()的用法和df.where()基本相同，唯一的区别是df.mask()将满
足条件的位置填充为NaN。

# 符合条件的为NaN df.mask(s > 80)
# 对满足条件的位置指定填充值 df.Q1.mask(s > 80, '优秀')
# 返回布尔序列，符合条件的行值为True (df.where((df.team=='A') & (df.Q1>60)) == df).Q1
# 返回布尔序列，符合条件的行值为False (df.mask((df.team=='A') & (df.Q1>60)) == df).Q1

# 行列相同数量，返回一个array
df.lookup([1,3,4], ['Q1','Q2','Q3']) # array([36, 96, 61]) 
df.lookup([1], ['Q1']) # array([36])
```

### 数据迭代

```
df.iterrows()
df.itertuples()
df.items()
```

### 函数应用

```
pipe():应用在整个DataFrame或Series上。   df.pipe(函数，函数的参数)
apply():应用在DataFrame的行或列中，默认为列。 
applymap():应用在DataFrame的每个元素中。
map():应用在Series或DataFrame的一列的每个元素中。
transform(): 括号里调用函数

df.pipe(lambda dfdf,x,y:df[(dfdf.open >=x)  & (dfdf.open <=y)],8,10 )
# 将name全部变为小写 
df.name.apply(lambda x: x.lower())

208页面
```

### 分组 groupby

```
df.groupby('trade_date').agg({'vol':sum,'close':'mean'}) #分组之后对不同列的不同操作

df.groupby('ts_code').agg({'close':['mean','std'],'vol':['sum','max','min','std','skew']})
#分组之后列也可以分开操作，colums 变成二维的

df.close.groupby(df.trade_date).count() 
#Series 按照另外一个Series 分组

df.groupby(df.trade_date >'2022-03-01').agg({'close':['mean','std']})#满足条件的分一组
df.groupby(lambda x: x %2==0).agg({'close':['mean','std']})#按照索引是否是偶数
# 按索引是否大于或等于50分为True和False两组 df.groupby(lambda x:x>=50) df.groupby(df.index>=50).sum() # 同上
# 列名包含Q的分成一组
df.groupby(lambda x:'Q' in x, axis=1).sum()

# 按索引奇偶行分为True和False两组 
	df.groupby(df.index%2==0) # 同上例
# 按姓名首字母分组
df.groupby(df.name.str[0])
# 按A及B、其他团队分组 
	df.groupby(df.team.isin(['A','B']))
# 按姓名第一个字母和第二个字母分组 
	df.groupby([df.name.str[0], df.name.str[1]]) 
# 按日期和小时分组
	df.groupby([df.time.date, df.time.hour])

# 按team、姓名首字母是否为元音分组
	df.groupby(['team', df.name.apply(自定义的函数)]).sum()

# 使用pipe调用分组函数 df.pipe(pd.DataFrame.groupby, 'team').sum()
	df.pipe(pd.DataFrame.groupby,'week').mean()
	
#按照1周分组，开盘：第一个价钱 first 收盘 最后一个价钱 last
df.set_index('trade_date').groupby(pd.Grouper(freq='1W')).agg({'open':'first','low':'min','high':'max','close':'last','vol':'sum'})

# 查看分组内容
df.groupby('team').groups

# 查看分组名 
	df.groupby('team').groups.keys()

# 用团队和姓名首字母分组
	grouped2 = df.groupby(['team', df.name.str[0]]) 
# 选择B组、姓名以A开头的数据 					       
	grouped2.get_group(('B', 'A'))
# 获取分组字典数据
	grouped.indices
# 选择A组
	grouped.indices['A']


#groupby apply 函数
df.groupby('ts_code').apply(lambda x:pd.Series({
'max_close':x['close'].max(),
'mean_vol':x['vol'].mean()
}))

#或者自定义函数
def fuck(X):
	d=[]
	d.append(x['close'].max())
	d.append(x['vol'].mean())
	return pd.Series(d,index=['close_max','vol_mean'])
df.groupy('ts_close').apply(fuck)

#查看个股前三个最高价
  def fuck(df_,column):
    return df_[column].sort_values(ascending=False).head(3)

	df.set_index('ts_code').groupby('industry').apply(fuck,3)

# 每组最大值和最小值之和
	df.groupby('team').pipe(lambda x: x.max() + x.min())

#transform()类似于agg()，但与agg()不同的是它返回的是一个与原始 数据相同形状的DataFrame，会将每个数据原来的值一一替换成统计后 的值。例如按组计算平均成绩，那么返回的新DataFrame中每个学生的 成绩就是它所在组的平均成绩。

# 将所有数据替换成分组中的平均成绩 
	df.groupby('team').transform(np.mean)
	df.groupby('team').transform(max) # 最大值 
	df.groupby('team').transform(np.std) # 标准差
# 使用函数，和上一个学生的差值(没有处理姓名列) 
	df.groupby('team').transform(lambda x: x.shift(-1))
# Q1成绩大于60的组的所有成员 
	df[df.groupby('team').transform('mean').Q1 > 60]

#股票个股 行业都有市盈率的时候，可以直接添加个股的平均市盈率 和行业的市盈率
	df['行业市盈率']=df.groupby('行业')['市盈率'].transform(np.mean)
	df['个股市盈率']=df.groupby('股票代码')['市盈率'].transform(np.mean)

#获取分组数据最后一个一个数字
	df['end_values']=df.groupby('ts_code')['close'].transform('last')

#按照分组小于3
	df2[df2.groupby('ts_code')['close'].transform(np.min) <3]

# Q1成绩至少有一个大于97的组
	df.groupby(['team']).filter(lambda x: (x['Q1'] > 97).any())
# 所有成员平均成绩大于60的组
	df.groupby(['team']).filter(lambda x: (x.mean() >= 60).all()) 
# Q1所有成员成绩之和超过1060的组
	df.groupby('team').filter(lambda g: g.Q1.sum() > 1060)


df.groupby('team').first() # 组内第一个 df.groupby('team').last() # 组内最后一个 df.groupby('team').ngroups # 5(分组数) df.groupby('team').ngroup() # 分组序号
grouped.backfill()
grouped.bfill() 
df.groupby('team').head() # 每组显示前5个 
grouped.tail(1) # 每组最后一个 
grouped.rank() # 排序值
grouped.fillna(0)
grouped.indices() # 组名:索引序列组成的字典

gp.nth(1) # 第一个 gp.nth(-1)
# 最后一个 gp.nth([-2, -1])
# 第n个非空项
gp.nth(0, dropna='all')
gp.nth(0, dropna='any')
df.groupby('team').shift(-1) # 组内移动 
grouped.tshift(1) # 按时间周期移动
df.groupby('team').any()
df.groupby('team').all()
df.groupby('team').rank() # 在组内的排名
# 仅 SeriesGroupBy 可用
df.groupby("team").Q1.nlargest(2) # 每组最大的两个 df.groupby("team").Q1.nsmallest(2) # 每组最小的两个 df.groupby("team").Q1.nunique() # 每组去重数量 df.groupby("team").Q1.unique() # 每组去重值 df.groupby("team").Q1.value_counts() # 每组去重值及数量 df.groupby("team").Q1.is_monotonic_increasing # 每组值是否单调递增 df.groupby("team").Q1.is_monotonic_decreasing # 每组值是否单调递减
# 仅 DataFrameGroupBy 可用 df.groupby("team").corrwith(df2) # 相关性


apply():最为灵活的处理方法，可以对数据完成操作后返回各种 形式的数据。 transform():对数据处理完后返回原型形状的数据，可以类比为 对一个汽车不改变结构，只重新进行涂装。 filter():每个分组传入后，通过计算返回这个分组的真假值，所 有为真的留下，作为最终的结果。

```

### 聚合统计

```
  df.groupby('team').describe() # 描述性统计
  df.groupby('team').sum() # 求和 
  df.groupby('team').count() # 每组数量，不包括缺失值 
  df.groupby('team').max() # 求最大值 
  df.groupby('team').min() # 求最小值 
  df.groupby('team').size() # 分组数量 
  df.groupby('team').mean() # 平均值 
  df.groupby('team').median() # 中位数 
  df.groupby('team').std() # 标准差 
  df.groupby('team').var() # 方差
  grouped.corr() # 相关性系数 
  grouped.sem() # 标准误差
  grouped.prod() # 乘积
  grouped.cummax() # 每组的累计最大值 
  grouped.cumsum() # 累加 
  grouped.mad() # 平均绝对偏差

聚合方法agg()
# 所有列使用一个计算方法 
  df.groupby('team').aggregate(sum) 
  df.groupby('team').agg(sum) 
  grouped.agg(np.size) 
  grouped['Q1'].agg(np.mean)

# 每个字段使用多个计算方法 
	grouped[['Q1','Q3']].agg([np.sum, np.mean, np.std])
	
	
# 指定列名，列表是为原列和方法 
  df.groupby('team').Q1.agg(Mean='mean', Sum='sum') 
  df.groupby('team').agg(Mean=('Q1', 'mean'), Sum=('Q2', 'sum')) 
  df.groupby('team').agg(
      Q1_max=pd.NamedAgg(column='Q1', aggfunc='max'),
      Q2_min=pd.NamedAgg(column='Q2', aggfunc='min')
  )
  
df.groupby('team').agg(**{
    '1_max':pd.NamedAgg(column='Q1', aggfunc='max')})
'''
1_max
team
A        96
B        97
C        98
D        80
E        97
'''

时序重采样方法resample()
	df2.groupby('trade_date').resample('20T').sum() 
	# 7天一分组 				
	df.groupby('a').resample('7D').sum()
	# 三个周期一聚合(一分钟一个周期) 
	df.groupby('a').resample('3T').sum() 
	# 30秒一分组 				
	df.groupby('a').resample('30S').sum()
	
# 每组第一个 
	df.groupby('team').first()
#每组最后一个
	df.groupby('team').last()
	
# df.groupby('team').median() 中位数
# df.groupby('team').quantile(0.5)

#pd.cut
 	#可以生成新列，生成的新列的数据类型是category 区间的意思
	df['category']=pd.cut(df['close'],bins=[0,25,50])
	
	#根据区间画饼图。看百分比
	df.close.groupby(pd.cut(df.close,bins=[0,25,60])).count().plot.pie() 
	别忘记加count（） 

#自动分数 pd.qcut
	pd.qcut(df.close,q=3)
# 查看分组区间
	pd.qcut(df.Q1,q=2).unique()
	
df.Q1.groupby(pd.qcut(df.Q1,q=2)).count()


pd.qcut(range(5), 4)
pd.qcut(range(5), 4, labels=False)
# 指定标签名
pd.qcut(range(5), 3, labels=["good", "medium", "bad"]) 
# 返回箱子标签 array([1. , 51.5, 98.]))
pd.qcut(df.Q1, q=2, retbins=True)
# 分箱位小数位数
pd.qcut(df.Q1, q=2, precision=3)
# 排名分3个层次
pd.qcut(df.Q1.rank(method='first'), 3)


```

#### 重要 

```
#按照pe 分组,分别查看个组数据的最大值，最小值，中间值
df.groupby(pd.qcut(df.pe,q=4)).agg(['max','min','mean'])

df.groupby(pd.qcut(df.index,q=20)).agg(['max','min','mean'])

```

### 数据可视化

#### 重要

```
# 可以分组画好多图 折线图
df[['close','trade_date','ts_code']].set_index('trade_date').groupby('ts_code').plot(figsize=(12,6),title='hello')

# 可以分组画好多图 直方图
df[['close','trade_date','ts_code']].set_index('trade_date').groupby('ts_code').plot(kind=‘hist'，figsize=(12,6),title='hello')
```



```
# 分组，设置索引为name
grouped = df.set_index('name').groupby('team') # 绘制图形
grouped.plot()

plot.line:折线图 
plot.pie:饼图 
plot.bar:柱状图 
plot.hist:直方图
plot.box:箱形图 
plot.area:面积图 
plot.scatter:散点图 
plot.hexbin:六边形分箱图
```

### 数据合并

#### df.append

```
df.append(self, other, ignore_index=False,
          verify_integrity=False, sort=False)
          
other:调用方要追加的其他DataFrame或者类似序列内容。可以 放入一个由DataFrame组成的列表，将所有DataFrame追加起来。 
ignore_index:如果为True，则重新进行自然索引。 
verify_integrity:如果为True，则遇到重复索引内容时报错。 
sort:进行排序。 

# 追加多个数据 df1.append([df2, df2, df2])
```

#### df.concat

```
# 语法
pd.concat(objs, axis=0, join='outer',
          ignore_index=False, keys=None,
          levels=None, names=None, sort=False,
          verify_integrity=False, copy=True)
          
objs:需要连接的数据，可以是多个DataFrame或者Series。它是 必传参数。 
axis:连接轴的方法，默认值是0，即按列连接，追加在行后面。 值为1时追加到列后面。 
join:合并方式，其他轴上的数据是按交集(inner)还是并集 (outer)进行合并。
ignore_index:是否保留原来的索引。 
keys:连接关系，使用传递的键作为最外层级别来构造层次结构 索引，就是给每个表指定一个一级索引。
names:索引的名称，包括多层索引。 
verify_integrity:是否检测内容重复。参数为True时，如果合并的 数据与原数据包含索引相同的行，则会报错。


pd.concat([df1, df2])

pd.concat([df1, df2], axis=1).reindex(df1.index)
pd.concat([df1, df2.reindex(df1.index)], axis=1)

z = pd.Series([9, 9], name='z') # 将序列加到新列
pd.concat([df1, z], axis=1)

```

#### pd.merge

```
# 基本语法
pd.merge(left, right, how='inner', on=None, left_on=None, right_
         left_index=False, right_index=False, sort=True,
         suffixes=('_x', '_y'), copy=True, indicator=False,
         validate=None)
         
left、right:需要连接的两个DataFrame或Series，一左一右。 
how:两个数据连接方式，默认为inner，可设置为inner、outer、 left或right。 
on:作为连接键的字段，左右数据中都必须存在，否则需要用 left_on和right_on来指定。
left_on:左表的连接键字段。
right_on:右表的连接键字段。 
left_index:为True时将左表的索引作为连接键，默认为False。 
right_index:为True时将右表的索引作为连接键，默认为False。 
suffixes:如果左右数据出现重复列，新数据表头会用此后缀进行 区分，默认为_x和_y。
```

#### pd.conbine_first

```
df1.combine_first(df2)

# df1 有值的行和列不更新。其他的都更新 空值也会被更新
```

#### conbine

```
df1.combine(df2,func函数)

df1.combine(df2,lambda s1,s2:np.where(s1>s2,s1,s2)) 
#更新df1,那个值小选哪个

df1.combine(df2,np.maximum) 那个大选择哪个
df1.combine(df2,np.minimum) 那个小选哪个


```

#### update

```
df1.update(df2)

```

### compare 对比

```
df1.compare(df2,align_axis=1,keep_equal=False) 数据方式要一摸一样 要不然就出错 相同值会显示nan
align_axis 默认按照列对比 align_axis=0的时候，按照行对比
keep_equal=True 显示相同值
```

### 多重索引

#### 多重索引切片

```

```

### 按照索引排序

```
# 要先给索引起一个名字,然后Sort_values(by='index的名字')
```



```
# 从LIST 建立索引
	mylist=[[1,2,3,4,5],['a','b','c','d','e']]
	mtindex=pd.MultiIndex.from_arrays(mylist,names=['hello','kitty'])
# 从tuple 建立
	mytuple=[(1, 'a'), (2, 'b'), (3, 'c'), (4, 'd')]
	pd.MultiIndex.from_tuples(mytuple,names=['fuck','you'])
	
# 建立有笛卡尔积的多重索引
	a=pd.daterange('2000-01-01','2020-01-01',freq='1y')
	b=list('abcd')
	pd.MultiIndex.from_product([a,b],names=['date','zimu'])
	
# 从DF建立索引
	pd.MultiIndex.from_frame(df,name=['hello','kitty'])
	
# 生成多重索引
	a1=['上证指数','沪深300']
  a2=['high','low','close','open']
  mindex=pd.MultiIndex.from_product([a1,a2],names=['指数','区间'])
  b1=['2021','2022','2023']
  b2=['上半年','下半年']
  mcolumns=pd.MultiIndex.from_product([b1,b2])

  df=pd.DataFrame(index=mindex,columns=mcolumns)
  
# 查看索引层级
	df.index.nlevels
	
# 使用索引名可进行排序，可以指定具体的列 
	df.sort_values(by=['性别', ('2020','下半年')]) 
	df.index.reorder_levels([1,0]) # 等级顺序，互换 
	idx.set_codes([1, 1, 0, 0], level='foo') # 设置顺序 
	df.index.sortlevel(level=0, ascending=True) # 按指定级别排序 		df.index.reindex(df.index[::-1]) # 更换顺序，或者指定一个顺序
	
df.index.get_level_values(0)  #得到索引0层的values
df.index.get_level_values('性别')
df.columns.get_level_values('年份')
df.sort_values(by=['性别',('2019','上半年')],ascending=[False,False]) # 按照两列排名
df.index=df.index.reorder_levels([1,0])   #交换索引位置 df.index.reorder_index([1,0])
df.columns=df.columns.reorder_levels([1,0]) # 交换columns 的位置

df.droplevel(0) # 删除 level=0 的index 索引
df.droplevel(1,axis=1)  # 删除 level=1 的column


df.swaplevel(1,0) #交换索引层级 直接返回df 这条很重要
df.swaplevel(1,0,axis=1)  #交换columns层级 直接返回df 这条很重要

df.index.get_locs(('2','女'))  # 得到iloc 的位置

pd.IndexSlice[['level0列表']:['level1列表']]
fuck=pd.IndexSlice[:,['男','女']] # 索引切片所选择
df.loc[fuck,:]
fuck2=pd.IndexSlice[:,['下半年']]
df.loc[fuck,fuck2]

df.xs(str or tuple,axis=1,level=0) 
#当是str的时候,level 说明层级 
#当是tuple的时候，axis说明是行还是列，就不用说层级了

df.xs(('1','女'),axis=0) 
df.xs('女'，level=1)
df.xs('下半年',axis=1,level=1)


```

### 数据透视

```
df.pivot() 只能简单的汇总 而且index和columns不能有交叉值，否则会报错。用pd.pivot_table 有交叉值不回报错


pd.pivot_table()有以下几个关键参数。


data:要透视的DataFrame对象。
index:在数据透视表索引上进行分组的列。 
values:要聚合的一列或多列。
columns:在数据透视表列上进行分组的列。
aggfunc:用于聚合的函数，默认是平均数mean。
fill_value:透视会以空值填充值。 
margins:是否增加汇总行列。

# 高级聚合
pd.pivot_table(df, index=['A', 'B'], # 指定多个索引
columns=['C'], # 指定列 
values='D', # 指定数据值 
aggfunc=np.sum, # 指定聚合方法为求和 
fill_value=0, # 将聚合为空的值填充为0 
margins=True # 增加行列汇总
)
'''

aggfunc 可以指定为字典{'values'：['聚合函数1','聚合函数2']} aggfunc 为字典的时候，不要有values值

```

#### 堆栈 stack unstack

```
df.stack()  #将一个df变成一个一维数组
S.unstack()  #将一位数组变成一个df
```

### 交叉表 看频次 也可以计算概率 pd.crosstab

```

感觉很时候用在概率与数理统计中使用

交叉值是在表中出现的频次

# 基本语法
pd.crosstab(index, columns, values=None, rownames=None,
            colnames=None, aggfunc=None, margins=False,
            margins_name: str = 'All', dropna: bool = True,
            normalize=False)

index:传入列，如df['A']，作为新数据的索引。 
columns:传入列，作为新数据的列，新数据的列为此列的去重 值。 
values:可选，传入列，根据此列的数值进行计算，计算方法取 
aggfunc参数指定的方法，此时aggfunc为必传。 
aggfunc:函数，values列计算使用的计算方法。  可以是mean sum std median
rownames:新数据和行名，一个序列，默认值为None，必须与 传递的行数、组数匹配。 
colnames:新数据和列名，一个序列，默认值为None;如果传 递，则必须与传递的列数、组数匹配。 
margins:布尔值，默认值为False，添加行/列边距(小计)。 
normalize:布尔值，{'all'，'index'，'columns'}或{0,1}，默认值为False。通过将所有值除以值的总和进行归一化。
     
normalize= 值可以 是{'all'.'columns','index'} 当设置是all的时候，占所有值的百分比 为index的时候，横向百分比
当有values时候，是计算values的值，有values 则必须有聚合函数 aggfunc
margins是添加最后的行值

margins_name='total'可以定义这个汇总行和列的名称:


pd.crosstab(df['A'],df['B'],values=df['C'],aggfunc='sum',margins=True)

B	b1	b2	All
A			
a1	7.0	1.0	8
a2	NaN	7.0	7
All	7.0	8.0	15



```

### 分类交叉

```
# 对分类数据做交叉
one = pd.Categorical(['a', 'b'], categories=['a', 'b', 'c']) 
two = pd.Categorical(['d', 'e'], categories=['d', 'e', 'f']) 
pd.crosstab(one, two)
'''
col_0 d e
row_0
a10
b01
'''
```

### 看到数据融合 看到348页

```
数据融合df.melt()是df.pivot()的逆操作函数，简单来说，它是将指 定的列铺开，放到行上名为variable(可指定)、值为value(可指定) 列。

pd.melt(frame: pandas.core.frame.DataFrame,
        id_vars=None, value_vars=None,
        var_name='variable', value_name='value',
        col_level=None)
```

### 数据可视化 plot

#### style

```

```

#### plot

```
绘图引擎
# 使用bokeh
import pandas_bokeh
pandas_bokeh.output_notebook() # Notebook展示 

Matplotlib(默认) 
hvplot 0.5.1版本及以上 
holoviews 
pandas_bokeh
plotly 4.8版本及以上 Altair


df.head(10).plot.bar('name', ['Q1', 'Q2'], backend='pandas_bok')
```



```
df.plot.line() # 折线的全写方式    波浪
df.plot.bar() # 柱状图 					 看频次 
df.plot.barh() # 横向柱状图(条形图) 
df.plot.hist() # 直方图 
df.plot.box() # 箱形图 
df.plot.kde() # 核密度估计图        看正太分布
df.plot.density() # 同df.plot.kde()
df.plot.area() # 面积图            看所占比例比率
df.plot.pie() # 饼图                value 为nan 填充0 为负数 报错
df.plot.scatter() # 散点图         看线形关系
df.plot.hexbin() # 六边形箱体图，或简称六边形图

参数：title 标题
		fontsize 字体大小
		figsize 图像大小	
		grid  背景辅助线
		color 颜色
		rot 主轴的方向
		subplots=True。 多个子图

固定显示大小
import matplotlib.pyplot as plt 
plt.rcParams['figure.figsize'] = (15.0, 8.0) # 固定显示大小

线条样式
df[:5].plot(style=':') # 虚线
df[:5].plot(style='-.')# 虚实相间 
df[:5].plot(style='--') # 长虚线 
df[:5].plot(style='-') # 实线(默认) 
df[:5].plot(style='.') # 点 
df[:5].plot(style='*-') # 实线，数值为星星 
df[:5].plot(style='^-') # 实线，数值为三角形


 plt.rcParams['figure.figsize'] = (15.0, 8.0) # 固定显示大小 
 plt.rcParams['font.family'] = ['sans-serif'] # 显示中文问题
 plt.rcParams['font.sans-serif'] = ['SimHei'] # 显示中文问题 
 plt.rcParams['axes.unicode_minus'] = False # 显示负号
```



