```
基本概念
	-数据库(database)
	-集合(collection) #类似于数组
	-文档(document) #最小的单位
	数据库和集合都不需要手动创建，当创建文档，如果文档和数据库不存在，会自动创建文档和数据库
  官方文档：https://docs.mongoing.com/mongo-introduction/databases-and-collections
```

```
基本指令
	show dbs
	show databases
		-显示数据库
	use 数据库名
	db 当前的数据库，当前所载的数据库
	show collections
		-显示数据库中所有的集合
		
collection 为中文的时候
db.getCollection("一品转债").find()..... 
		
```

###  一些语法示例

```
db.getCollection("test").find().limit(1000).skip(0)

一对多：
	先定义一个变量查询用户名的_id，然后通过_id 查找其他
	var user_=cb.collection.find({name:'minliang'})._id
	db.collection.find({user_id:user_})
多对多：
	-分类 -商品

```



### 数据库的插入数据

```
向数据库中插入文档
	
	db.collection.insert(doc)
		-插入一个文档，传多个用列表 db.collection.insert([{},{},{}])
	db.collection.find()  #返回列表
		-查找文档
	db.collection.insertOne()  #返回文档
		-只能传一个
	db.collection.insertMany()
		-传多个		  
	
```

### 数据库查询

```
db.collection.find()
	-查询所有
db.collection.find({字段名：值  })
	- 按条件查询 返回数组
db.collection.find({字段名：值  })[0]
	- 按条件查询,返回满足条件的第一个
db.collection.find({}).count() 或者length（）
	- 返回数量
	
db.coollection.findOne()
	-查询满足条件的第一条文档 返回文档
db.coollection.findOne().name
	-查询满足条件的第一条文档 返回文档 
	
下面的案例返回inventory集合中status等于**"A"或"D"**的所有文档。
	- db.inventory.find( { status: { $in: [ "A", "D" ] } } )
	-SELECT * FROM inventory WHERE status in ("A", "D")

and 条件
下面的案例返回inventory集合中status等于**"A" 并且qty**小于($lt)30的所有文档:
	-db.inventory.find( { status: "A", qty: { $lt: 30 } } )
	-SELECT * FROM inventory WHERE status = "A" AND qty < 30
	
or条件
下面的案例返回inventory集合中status等于**"A" 或者qty**小于($lt)30的所有文档。
	-db.inventory.find( { $or: [ { status: "A" }, { qty: { $lt: 30 } } ] } )
	-SELECT * FROM inventory WHERE status = "A" OR qty < 30
	
同时使用and 和or 条件
下面的案例返回inventory集合中status等于**"A" 并且qty小于 ($lt) 30或者item** 是以p字符开头的所有文档
	-db.inventory.find( {
     status: "A",
     $or: [ { qty: { $lt: 30 } }, { item: /^p/ } ]
} )
	- SELECT * FROM inventory WHERE status = "A" AND ( qty < 30 OR item LIKE "p%")


```

### 查询操作：条件筛选（大于小于）

```
{a:{$gt:10}} 										 找a的值大于10的
{a:{$gt:40,$lt:50}} 						 找a的值大于40 小于50
db.collection.find().limit(10)   前10条数据
db.collection.find().limit(10).skip(10) 显示11-20条

db.collection.find(
	$or:[
			gongzi:{$gt:2500},
			gongzi:{$lt:1000} 
			]
)
#查询工资小于1000 或者工资大于2500的员工

  
$ge:大于
$gte:大于等于
$lt:小于
$lte:小于等于
$ne:不等于
$or
$inc: 自增相当于 +=
$
$
```



### 数据库修改

```
 $set 
 %unset 删除属性，写 不写值都行 
可以用updatex修改多个，不过要加上第三个参数
db.collection.update(
{filter},
{$set:{要修改内容}，
{第三个参数
multi: bool()是否修改第三个}
)

与upsert: true选项一起使用时db.collection.update()。
与upsert: true选项一起使用时db.collection.updateOne()。
与upsert: true选项一起使用时db.collection.updateMany()。
与upsert: true选项一起使用时db.collection.findAndModify()。
与upsert: true选项一起使用时db.collection.findOneAndUpdate()。
与upsert: true选项一起使用时db.collection.findOneAndReplace()。
db.collection.save().
db.collection.bulkWrite().

```

### 数据库删除

```
   db.collection.remove() 
   	-不传参数,会清空整个集合
   	-默认删除所有符合条件的所有文档
   	-修改为删一个 db.collection.remove(filter，true) 
   
   db.collection.deleteOne()
   	-删除一个
   cb.collection.deleteMany()
   	-删除多个
  
```

### 删除集合

```
db.collection.drop();  
	-删除集合
	-删除最后一个集合，数据库也会被删掉
```

### 删除数据库

```
db.dropDataBase();
```

###  隐藏删除

```python
添加isDel列   {isDel:1}
```

 ### 排序

```
db.collection.find().sort({字段1:1升序，字段2:-1降序})
```

### 查询筛选列

```
 db.collection.find({},{ename:1})  多列，只显示ename
 db.collection.find({},{ename:1,_id:-1})  多列，只显示ename 不显示——id
 
 haha
 
 AZ7MK-44Y1J-H819Z-WMYNC-N7ATF

CU702-DRD1M-H89GP-JFW5E-YL8X6

YY5EA-00XDJ-480RP-35QQV-XY8F6

UY758-0RXEQ-M81WP-8ZM7Z-Y3HDA

VF750-4MX5Q-488DQ-9WZE9-ZY2D6

UU54R-FVD91-488PP-7NNGC-ZFAX6

YC74H-FGF92-081VZ-R5QNG-P6RY4

YC34H-6WWDK-085MQ-JYPNX-NZRA2

作者：小土豆dy
链接：https://www.jianshu.com/p/a979f489b47b
来源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



