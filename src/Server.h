# pragma once
# include <memory>
# include "Channel.h"
# include "EventLoop.h"
# include "EventLoopThreadPool.h"

class Server {
public:
  Server(EventLoop *loop, int threadNum, int port);
  ~Server() {}

  EventLoop* getLoop() const {return loop_;}
  void start();
  void handleNewConn();   //定义如何处理新来的socket连接
private:
  bool started_; // 标识服务器是否在运行
  int port_;    // 服务器监听的端口号
  int threadNum_;   // 服务器所使用的线程数量，用来初始化线程池
  int listenFd_;    // 表征服务器监听的socket所拥有的文件描述符，必须声明在acceptChannel_前面
  EventLoop *loop_; // 表示服务器的监听连接的主循环，即主Reactor
  std::unique_ptr<EventLoopThreadPool> threadPool_;   // 存储用于IO的线程，即subReactor所拥有的EventLoop线程从该池中取，减少线程创建和销毁的开销
  std::shared_ptr<Channel> acceptChannel_;    // 表示监听listenFd的Channel类，即对监听socket及其事件回调的封装
private:
  static const int MAXFDS = 10000; // 服务器支持的最大连接数
};