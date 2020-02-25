# pragma once

// 根据端口号建立socket，并返回属于该socket的文件描述符
int socket_bind_listen(int port);

// 当一个进程向某个已收到RST的套接字执行写操作时，内核向该进程发送一个SIGPIPE信号。
// 该信号的默认行为是终止进程，因此进程必须捕获它以免不情愿地被终止。
void handle_sigpipe();