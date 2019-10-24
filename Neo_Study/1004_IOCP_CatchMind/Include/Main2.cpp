#pragma once
#include <WinSock2.h>
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <unordered_map>
#include <SDKDDKVer.h>
//#include "..\..\..\..\..\source\repos\Study_Server-NEO-\1007_CatchMind_Server\Common\PACKET_HEADER_CATCH_MIND.h"
//#include "..\..\..\\Study_Server-NEO-\1007_CatchMind_Server\Common\PACKET_HEADER_CATCH_MIND.h"

using namespace std;

#define MAX_BUFFER 1024
#define SERVER_PORT 9000
//#define SERVER_IP		"192.168.200.115" 집
#define SERVER_IP		"10.30.10.210" // 네오플

// 클라용 IOCP 임시 

struct stSOCKETINFO
{
	WSAOVERLAPPED	overlapped;
	WSABUF			dataBuf;
	SOCKET			socket;
	char			messageBuffer[MAX_BUFFER];
	int				recvBytes;
	int				sendBytes;
};

int main()
{
	WSADATA wsaData;

	int nRet = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (nRet != 0) {
		cout << "Error >> " << WSAGetLastError() << endl;
		return false;
	}

	// TCP 소켓 생성
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		cout << "Error >> " << WSAGetLastError() << endl;
		return false;
	}

	cout << "Socket " << endl;

	// 접속할 서버 정보를 저장할 구조체
	SOCKADDR_IN stServerAddr;

	char	szOutMsg[MAX_BUFFER];
	char	sz_socketbuf_[MAX_BUFFER];
	stServerAddr.sin_family = AF_INET;

	// 접속할 서버 포트 및 IP
	stServerAddr.sin_port = htons(SERVER_PORT);
	stServerAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	nRet = connect(clientSocket, (sockaddr*)& stServerAddr, sizeof(sockaddr));
	if (nRet == SOCKET_ERROR) {
		cout << "Error >> " << WSAGetLastError() << endl;
		return false;
	}

	cout << "< Connected >" << endl;

	//주고받는것 시작하는 부분
	while (true) {
		 cout << ">>";
		 cin >> szOutMsg;
		if (_strcmpi(szOutMsg, "quit") == 0) break;

		int nSendLen = send(clientSocket, szOutMsg, strlen(szOutMsg), 0);

		if (nSendLen == -1) {
			cout << "Error : " << WSAGetLastError() << endl;
			return false;
		}

		 cout << "Message sended : bytes[" << nSendLen << "], message : [" <<
			szOutMsg << "]" <<  endl;

		int nRecvLen = recv(clientSocket, sz_socketbuf_, 1024, 0);

		if (nRecvLen == 0) {
			 cout << "Client connection has been closed" <<  endl;
			closesocket(clientSocket);
			return false;
		}
		else if (nRecvLen == -1) {
			cout << "Error : " << WSAGetLastError() << endl;
			closesocket(clientSocket);
			return false;
		}

		sz_socketbuf_[nRecvLen] = NULL;
		cout << "Message received : bytes[" << nRecvLen << "], message : [" <<
			sz_socketbuf_ << "]" << endl;
	}

	closesocket(clientSocket);
	cout << "Client has been terminated..." << endl;

	return 0;
}