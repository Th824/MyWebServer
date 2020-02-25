# pragma once

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <cstring>
# include <unistd.h>
# include "Server.h"
# include "base/utility.h"

/*
在构造函数中，需要初始化线程池，创建用于监听socket连接事件的socket文件描述符，且完成创建和绑定，监听在给定的端口
同时，利用该文件描述符初始化一个接收连接的Channel
*/
Server::Server(EventLoop *loop, int threadNum, int port) 
    : loop_(loop),
      threadNum_(threadNum),
      listenFd_(socket_bind_listen(port_)),
      acceptChannel_(new Channel(loop_, listenFd_)),
      threadPool_(new EventLoopThreadPool(loop_, threadNum_)),
      started_(false) {
  
}

void Server::start() {
  threadPool_->start();
}

void Server::handleNewConn() {
  // 该函数是有新连接到来的回调函数
  // 当有新的socket连接到来的时候，调用该函数将新建的socket连接按照
  // Round-Robin算法分配给线程池中的线程
  struct sockaddr_in clientAddr;
  socklen_t addrLen = sizeof(clientAddr);
  int acceptFd = 0;
  // 每一次处理新连接都是处理到没有新连接为止
  while ((acceptFd = accept(listenFd_, (struct sockaddr*)(&clientAddr), (socklen_t*)(addrLen))) > 0) {
    // 从线程池中获取将该连接分配到的线程
    EventLoop *loop = threadPool_->getNextLoop();
    
    // 超出最大连接数
    if (acceptFd >= MAXFDS) {
      close(acceptFd);
      continue;
    }
  }
}