ccl
===

c common libs


config
------

- twemproxy:
    - yaml
    - 解析像是xml sax解析, 有各种回调.
- moosefs: 方便
    - 缺点: 只支持key=v格式, 不支持数组等
- 用lemon/ragel解析
    - ragel 不错, 灵活.

log
---

需要解决:
- 多进程写一个日志文件, 怎么不写乱
    - 参考linux O_APPAND
    - ssdb用的时候, 可以选择用锁, 我怀疑是因为他用的是 ``FILE*`` api
- 动态调整日志级别.
    - twemproxy 可以.

list/queue
----------

1.  /usr/include/sys/queue.h (如twemproxy)

2. /usr/src/linux-headers-2.6.32-45/include/linux/list.h


hash-table
----------

arg-parse
---------

https://github.com/visionmedia/mon/blob/master/deps/commander.h

string
------


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


参考
====

twemproxy
moosefs
redis

jemallc
=======

zlib
====

snappy
======

一个快速压缩库 leveldb, Hadoop等使用.

http://code.google.com/p/snappy/


