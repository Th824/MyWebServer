# pragma once

# include "base/noncopyable.h"

// 该类封装了一个TCP连接，当客户端建立连接事件产生时，调用产生封装对应的socket连接
class TCPConnection : noncopyable {
public:
  TCPConnection();
};