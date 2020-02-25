/*
该文件是模型中subReactor所在的EventLoop线程的抽象
*/

# include <thread>
# include <functional>
# include "base/noncopyable.h"

class EventLoopThread : noncopyable {
public:
  typedef std::function<void()> ThreadFun;
  EventLoopThread();
  ~EventLoopThread();
private:
  ThreadFun threadFun;
  EventLoop *loop_;
  std::thread thread_;
};