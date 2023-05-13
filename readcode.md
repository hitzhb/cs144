# socket.hh

- Socket 类：网络套接字的基类，继承自 FileDescriptor 类，提供了以下公有方法：
  - 构造函数：从一个文件描述符号或一个域、类型、协议创建一个 Socket 对象。
  - bind：将套接字绑定到一个指定的地址。
  - bind_to_device：将套接字绑定到一个指定的设备。
  - connect：将套接字连接到一个指定的对端地址。
  - shutdown：关闭套接字的一部分或全部连接。
  - local_address：返回套接字的本地地址。
  - peer_address：返回套接字的对端地址。
  - set_reuseaddr：允许重用本地地址。
  - throw_if_error：检查是否有错误发生。
- DatagramSocket 类：用于发送和接收数据报的套接字类，继承自 Socket 类，提供了以下公有方法：
  - 构造函数：从一个文件描述符或一个域、类型、协议创建一个 DatagramSocket 对象。
  - recv：接收一个数据报和它的发送者地址。
  - sendto：发送一个数据报到指定的目的地址。
  - send：发送一个数据报到套接字连接的地址（需要先调用 connect）。
- UDPSocket 类：UDP 协议的套接字类，继承自 DatagramSocket 类，提供了以下公有方法：
  - 构造函数：从一个文件描述符或默认参数创建一个 UDPSocket 对象。
- TCPSocket 类：TCP 协议的套接字类，继承自 Socket 类，提供了以下公有方法：
  - 构造函数：从一个文件描述符或默认参数创建一个 TCPSocket 对象。
  - listen：标记套接字为监听状态，准备接受新的连接。
  - accept：接受一个新的连接，并返回一个新的 TCPSocket 对象。
- PacketSocket 类：数据包协议的套接字类，继承自 DatagramSocket 类，提供了以下公有方法：

  - 构造函数：从一个类型和协议创建一个 PacketSocket 对象。
  - set_promiscuous：设置套接字为混杂模式。

  # file_descriptor.hh

  你给我的 file_descriptor 的头文件的 public 的部分有以下几个类和方法：

- FileDescriptor 类：一个对文件描述符的引用计数句柄，提供了以下公有方法：
  - 构造函数：从一个文件描述符号创建一个 FileDescriptor 对象。
  - 析构函数：释放对文件描述符的引用，如果引用计数为零，关闭文件描述符。
  - read：读取数据到一个字符串或一个字符串指针的向量。
  - write：写入数据从一个字符串视图或一个字符串视图的向量，返回写入的字节数。
  - close：关闭文件描述符。
  - duplicate：复制一个 FileDescriptor 对象，增加引用计数。
  - set_blocking：设置文件描述符为阻塞或非阻塞模式。
  - size：返回文件的大小。
  - fd_num：返回文件描述符号。
  - eof：返回是否到达文件末尾。
  - closed：返回是否关闭文件描述符。
  - read_count：返回读取次数。
  - write_count：返回写入次数。
- FDWrapper 类：一个对内核文件描述符的句柄，提供了以下公有方法：
  - 构造函数：从一个文件描述符号创建一个 FDWrapper 对象。
  - 析构函数：关闭文件描述符。
  - close：关闭文件描述符。
  - CheckSystemCall：检查系统调用的返回值，并抛出异常或设置错误标志。
