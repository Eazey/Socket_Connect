using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace Socket_ArtCreateSpace
{
    class Program
    {
        const string _ip = "192.168.1.107";
        const int _port = 7788;

        static void Main(string[] args)
        {
            //创建服务器端的Socket的实例  
            Socket serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            //创建终结点需要IPAddress类型的对象来表示ip
            //可以用Parse方法将ip字符串转化为IPAddress类型的点分十进制的ipv4地址
            IPAddress ipAddress = IPAddress.Parse(_ip);
            //创建终结点，绑定IP和端口号
            IPEndPoint ipPoint = new IPEndPoint(ipAddress, _port);
            //绑定终结点，使其作为服务器进程在网络中的唯一标识
            serverSocket.Bind(ipPoint);
            //开始监听，并指定最大连接数
            serverSocket.Listen(100);
            Console.WriteLine("Server socket is running......");

            //Accept方法会阻塞程序运行，如果有客户端请求连接
            //连接成功后这个方法返回一个Socket，以此创建与客户端连接的端点
            //然后执行下一条打印的语句
            Socket clientSocket = serverSocket.Accept();
            Console.WriteLine("A client is connected!");

            Console.ReadKey();
        }
    }
}
