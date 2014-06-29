ccl
===

c common libs

好的来源:

- nginx
- twemproxy
- redis

- lua
- leveldb

- apache
- libev
- lvs
- nodejs


config
------

1. 需要支持int/string/array


- moosefs: 方便
    - 缺点: 只支持key=v格式, 不支持数组等
- twemproxy:
    - yaml
    - 解析像是xml sax解析, 有各种回调.
- 用lemon/ragel解析
    - ragel 不错, 灵活.
- 用lua
    - 不错
    - http://www.netbsd.org/~mbalmer/lua/lua_config.pdf
    - https://github.com/portl4t/luaconf
    - c++ 用起来会很方便: https://github.com/tynril/luadata/
    - 也是c++的LuaTable++: http://www.fysx.org/2013/10/16/using-lua-scripts-as-config-files-from-c/

LuaTable++
``````````

::

    -- agentsettings.lua
    person = {
        name = "James Bond",
        age = 42.,
        drunken = true,
        address = {
            country = "United Kingdom"
        }
    }

    LuaTable ltable = LuaTable::fromFile("myfile.lua")

    std::string name = ltable["name"];
    double age = ltable["age"];
    bool drunken = ltable["drunken"];
    std::string country = ltable["address"]["country"];

    #Similarly you can set values:
    ltable["drunken"] = false;
    #dump
    std::string config_string = ltable.serialize();

- 小结
    - 简单kv, 使用mfs
    - 复杂点, 用lua.

lua 做config
````````````

::

    interface = {
        device = ’re0’,
        address = ’192.168.1.1’
    }

两个方法
1. c程序通过cfg_get_str() 从LuaState获取值
2. c定义一个config struct, lua中来修改这些值.


string
------

- sds


array
-----


list/queue
----------

1. /usr/include/sys/queue.h (如twemproxy)

2. /usr/src/linux-headers-2.6.32-45/include/linux/list.h
   双链表. 比如olive, 使用list_entry宏获得结构地址::

    #define list_entry(ptr, type, member) \
        ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

hash-table
----------


olive hash.h 自动扩容, 其它方面不好.

log
---

需要解决:
- 多进程写一个日志文件, 怎么不写乱
    - 参考linux O_APPAND
    - ssdb用的时候, 可以选择用锁, 我怀疑是因为他用的是 ``FILE*`` api
- 动态调整日志级别.
    - twemproxy 可以.

arg-parse
---------

https://github.com/visionmedia/mon/blob/master/deps/commander.h

file
----

daemon
------

event
-----

libevent
libuv
libev
自己实现

makefile
========

redis 和lua 都是手写makefile


malloc
======

tcmalloc
--------


jemallc
-------

参考
====

twemproxy
moosefs
redis

压缩
====


zlib
----

snappy
------

一个快速压缩库 leveldb, Hadoop等使用.

http://code.google.com/p/snappy/

lzf
---

redis1.3.6 使用的一个压缩库, 只有2个.h和2个.c, 很方便.

http://oldhome.schmorp.de/marc/liblzf.html
