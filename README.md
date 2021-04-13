## 基于libuv的轻量级服务器

#### 特点

利用C++11风格语法封装libuv，提供简洁的服务端接口；

利用libuv事件库提供的异步设计，实现Reactor事件处理模式；

所有的非阻塞异步接口是C++11的functional/bind形式的回调函数；

实现get、post两种请求解析，并利用Radix Tree实现HTTP路径机制。



#### 例子

Echo服务

KV存储服务

（未完待续....）



#### 仍需完善

引入多Reactor