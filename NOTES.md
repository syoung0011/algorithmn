> **通用笔记**
>
> 跨专题的积累：C++ 前置知识、工具链、通用方法论。
> 各专题的心得记录在对应目录的 `NOTES.md` 中。

# 基本

## 力扣相关

![image-20260816194038042](NOTES.assets/image-20260816194038042.png)

## CPU 地址位数与最值位数无关

![image-20260816212938989](NOTES.assets/image-20260816212938989.png)

# C++	

![image-20260816214940924](NOTES.assets/image-20260816214940924.png)

## 头文件

### 万能头文件

![image-20260816215032791](NOTES.assets/image-20260816215032791.png)

### 最值头文件

![image-20260816232138239](NOTES.assets/image-20260816232138239.png)

![image-20260816232151974](NOTES.assets/image-20260816232151974.png)

![image-20260816232200880](NOTES.assets/image-20260816232200880.png)

## STL

### vector 

#### 常用成员

`size()` 是O(1)；`erase()` 是 O(n)；

#### 二维数组

![image-20260817102752078](NOTES.assets/image-20260817102752078.png)

### string

#### 常用成员

`size()` 是O(1)；

![image-20260818134800103](NOTES.assets/image-20260818134800103.png)

### 哈希相关

![image-20260819150015990](NOTES.assets/image-20260819150015990.png)

![image-20260819150125134](NOTES.assets/image-20260819150125134.png)

当我们要使用集合来解决哈希问题的时候，优先使用**unordered_set**，因为它的查询和增删效率是最优的，如果需要集合是有序的，那么就用set，如果要求不仅有序还要有重复数据的话，那么就用multiset。

![image-20260819151514106](NOTES.assets/image-20260819151514106.png)

那么再来看一下map ，在map 是一个key value 的数据结构，map中，对key是有限制，对value没有限制的，因为key的存储方式使用红黑树实现的。优先使用**unordered_map**。

其他语言例如：java里的HashMap ，TreeMap 都是一样的原理。可以灵活贯通。

虽然std::set和std::multiset 的底层实现基于红黑树而非哈希表，它们通过红黑树来索引和存储数据。不过给我们的使用方式，还是哈希法的使用方式，即依靠键（key）来访问值（value）。所以使用这些数据结构来解决映射问题的方法，我们依然称之为哈希法。std::map也是一样的道理。

#### 补充

这里在说一下，一些C++的经典书籍上 例如STL源码剖析，说到了hash_set hash_map，这个与unordered_set，unordered_map又有什么关系呢？

实际上功能都是一样一样的， 但是unordered_set在C++11的时候被引入标准库了，而hash_set并没有，所以建议还是使用unordered_set比较好，这就好比一个是官方认证的，hash_set，hash_map 是C++11标准之前民间高手自发造的轮子。![image-20260819152347358](NOTES.assets/image-20260819152347358.png)

## IO

### 加速

![image-20260816224017396](NOTES.assets/image-20260816224017396.png)

![image-20260817102638390](NOTES.assets/image-20260817102638390.png)

### ACM格式的IO

![image-20260816232828461](NOTES.assets/image-20260816232828461.png)

注：io写在while里比较新奇。

![image-20260816232237589](NOTES.assets/image-20260816232237589.png)

注：别写成%d %d，不然匹配任意空白字符就G了，因为必须输入非法字符才能到下一次，比如a,b。

## 结构体

![image-20260816232648223](NOTES.assets/image-20260816232648223.png)

![image-20260816232701506](NOTES.assets/image-20260816232701506.png)

![image-20260816232648223](NOTES.assets/image-20260816232648223.png)

![image-20260816232701506](NOTES.assets/image-20260816232701506.png)

注：力扣不用后者就是因为默认私有外部方法没法访问。

## 禁用拷贝

![image-20260816232442185](NOTES.assets/image-20260816232442185.png)

![image-20260816232449524](NOTES.assets/image-20260816232449524.png)

![image-20260816232457325](NOTES.assets/image-20260816232457325.png)

![image-20260816232540761](NOTES.assets/image-20260816232540761.png)

![image-20260816233125816](NOTES.assets/image-20260816233125816.png)

## 指针

### 野指针

![image-20260816232636946](NOTES.assets/image-20260816232636946.png)

### 空指针

![image-20260817100717201](NOTES.assets/image-20260817100717201.png)

![image-20260817100826775](NOTES.assets/image-20260817100826775.png)

![image-20260817101022574](NOTES.assets/image-20260817101022574.png)

![image-20260817100958574](NOTES.assets/image-20260817100958574.png)

# CLion相关 

## 如何运行

### ide

![image-20260816233238396](NOTES.assets/image-20260816233238396.png)

### cmd

![image-20260816233522136](NOTES.assets/image-20260816233522136.png)

注：尽量不要中文名，MSVC可以构建，但要配置什么utf。MinGW直接就是失败。

## 快捷键

### 运行

![image-20260816233700174](NOTES.assets/image-20260816233700174.png)

![image-20260816233718318](NOTES.assets/image-20260816233718318.png)

### 编辑

![image-20260816233741307](NOTES.assets/image-20260816233741307.png)

![image-20260816233755475](NOTES.assets/image-20260816233755475.png)

### 项目

![image-20260816233835983](NOTES.assets/image-20260816233835983.png)

![image-20260816233840023](NOTES.assets/image-20260816233840023.png)

![image-20260816233843822](NOTES.assets/image-20260816233843822.png)

ctrl+alt+enter 在上方插入空行

### 自定义

![image-20260816233923808](NOTES.assets/image-20260816233923808.png)

## 其他设置

### md预览

![image-20260817100334432](NOTES.assets/image-20260817100334432.png)



# 其他

## commit风格

![image-20260816234213336](NOTES.assets/image-20260816234213336.png)

即[xxx] xxx的提交格式。

![image-20260817184448470](NOTES.assets/image-20260817184448470.png)

![image-20260817184522482](NOTES.assets/image-20260817184522482.png)

## 金句

- 一入循环深似海，从此 offer 是路人
- 抓住循环不变式，否则做题就是个死循环
