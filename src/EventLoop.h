# pragma once

#include <functional>
#include <vector>
#include <memory>

#include "base/noncopyable.h"

class Epoll;
class Channel;

class EventLoop : noncopyable {
public:
  EventLoop();
  ~EventLoop();

  // 始终处于loop的状态，因此需要定义一些可以插入loop的函数
  void loop();

  void quit();

private:
// 状态变量
  bool looping_;  // 表示是否在循环中
  bool quit_;
  bool eventHandling_;
  bool callingPendingFunctors_;

  std::shared_ptr<Epoll> poller_;
  std::vector<Functor> pendingFunctors_;

};