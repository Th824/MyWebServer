# include <thread>
# include <mutex>
# include <condition_variable>
# include <functional>
# include "noncopyable.h"

// 封装thread方便后续使用
class Thread : noncopyable {
public:
  typedef std::function<void()> threadFun;
  std::thread::id getThreadID() const {return thread_.get_id();}
private:
  threadFun threadFun_;   // 必须定义在thread_前面，这样才能用其来构造thread_
  std::thread thread_;
};