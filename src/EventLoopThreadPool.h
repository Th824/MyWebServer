# pragma once

/*
该文件是EventLoop的线程池 
*/
# include <vector>
# include "EventLoop.h"
# include "EventLoopThread.h"
# include "base/noncopyable.h"

class EventLoopThreadPool : noncopyable {
public:
  // 线程池应该由MainReactor所在的循环创建
  EventLoopThreadPool(EventLoop *loop, int threadNum);
  ~EventLoopThreadPool();

  void start();
  EventLoop* getNextLoop();
private:
  bool started_;
  int threadNum_;
  EventLoop *baseLoop_;
  int next;
  std::vector<std::shared_ptr<EventLoopThread>> threads_;
  std::vector<EventLoop*> loops_;
};