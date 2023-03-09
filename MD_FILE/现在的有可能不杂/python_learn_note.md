## python 类的魔法属性

### `__dict__`
>```python
>classname.__dict__ //属性字典
>self.__dict__
>```

### `__getitem__`
>```python
>def __getitem__(self,others):   //取索引 
>	return self.__dict__.get(others,None)
>```

### `__new__`

>```python
>def __new__(cls):   # 开辟内存 暂时不知道怎么用
>  ...
>```

### `__init__`

>```python
>def __init__(self);  ## 初始化
>
>super().__init__(*arg) ; # 按照父类初始化
>```

### `__lshift__`

>```python
>def __lshift__(self,item:int): //左移
>  return self.age << item
>
>```

### `__format__`

> ```python	
> def __format__(self,format_type):
>   return format_type %(d=self)
> ```
>
> 


### `__rshift__`

>```python
> def __lshift__(self,item:int): //右移
>  return self.age >> item
>```




### `__temple__`

>```python
>
>```

