using UnityEngine;
using System.Collections;
using System.Net;
using System.Net.Sockets;

public class Client : MonoBehaviour {

    //客户端Socket对象
    Socket clientSocket;
    //ip和端口号要与服务器端一致
    const string _ip = "192.168.1.107";
    const int _port = 7788;

	void Start () {

        //实例化Socket对象
        clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        //转化ip并创建远程终结点
        IPAddress ipAddress = IPAddress.Parse(_ip);
        IPEndPoint ipPoint = new IPEndPoint(ipAddress, _port);

        //请求连接服务器
        clientSocket.Connect(ipPoint);
        Debug.Log("Connect success!");
	}
	
}
