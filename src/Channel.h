# pragma once

#include <memory>
#include <functional>
#include "base/noncopyable.h"

class EventLoop;

class Channel : noncopyable {
public:
  // 定义回调函数的形式
  typedef std::function<void()> Callback;
  EventLoop* loop;  // 一个Channel所属的Eventloop
  int fd;   // Channel关注的fd
  Channel(EventLoop *loop, int fd);   // Channel构造函数，应该在构造连接时由Connection类负责构造
  ~Channel();    // 析构函数，应该由拥有该Channel的连接类来调用
private:
};