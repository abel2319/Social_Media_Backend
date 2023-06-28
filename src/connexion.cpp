#include "header.h"
	User::Connection(string ip)
		{
			sock_conn = socket(AF_INET, SOCK_STREAM, 0);
			sock_bind = socket(AF_INET, SOCK_STREAM, 0);

			if (sock_conn == -1) {
				// Handle socket creation error
				std::cout<<"Unable to connect to the server"<<"\n";
			}

			struct sockaddr_in server;
			server.sin_family = AF_INET;
			server.sin_port = htons(5125);  // Port number to connect to
			server.sin_addr.s_addr = inet_addr(ip);  // Server IP address

			if (connect(sock_conn, (struct sockaddr*)&server, sizeof(server)) < 0) {
				// Handle connection error
				std::cout<<"Unable to connect to the server"<<"\n";
			}

			struct sockaddr_in serverAddress;
			serverAddress.sin_family = AF_INET;
			serverAddress.sin_port = htons(5125);
			serverAddress.sin_addr.s_addr = INADDR_ANY;

			if (bind(sock_bind, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
				// Handle bind error
				std::cout<<"Unable to connect to the server"<<"\n";
			}

			if (listen(sock_bind, 1) < 0) {
				// Handle listen error
				std::cout<<"Unable to connect to the server"<<"\n";
			}
			
			struct sockaddr_in serverAddress;
			socklen_t clientAddressLength = sizeof(serverAddress);
			server_sock = accept(sock_bind, (struct sockaddr*)&clientAddress, &clientAddressLength);
			if (server_sock < 0) {
				cout<<"connectio to server error\n";
			}
		}
		
		void User::send_image(const std::vector<uchar>& imageData)
		{
			ssize_t totalBytesSent = 0;
			const uchar* dataPtr = imageData.data();
			size_t remainingBytes = imageData.size();

			while (remainingBytes > 0) {
				ssize_t bytesSent = send(sock_conn, dataPtr, remainingBytes, 0);
				if (bytesSent == -1) {
					// Handle send error
					break;
				}

				totalBytesSent += bytesSent;
				dataPtr += bytesSent;
				remainingBytes -= bytesSent;
			}
		}

		void User::send_data(const std::string& serializedMap)
		{
			ssize_t totalBytesSent = 0;
			const char* dataPtr = serializedMap.c_str();
			size_t remainingBytes = serializedMap.length();

			while (remainingBytes > 0) {
				ssize_t bytesSent = send(sock_conn, dataPtr, remainingBytes, 0);
				if (bytesSent == -1) {
 					cout<<"Connection failed please try again";
					break;
				}

				totalBytesSent += bytesSent;
				dataPtr += bytesSent;
				remainingBytes -= bytesSent;
			}
		}
		void User::send_data(const std::string& serializedMap, const std::vector<uchar>& imageData)
		{
			ssize_t totalBytesSent = 0;
			const char* dataPtr = serializedMap.c_str();
			size_t remainingBytes = serializedMap.length();

			while (remainingBytes > 0) {
				ssize_t bytesSent = send(sock_conn, dataPtr, remainingBytes, 0);
				if (bytesSent == -1) {
 					// Handle send error
 					cout<<"Connection failed please try again";
					break;
				}

				totalBytesSent += bytesSent;
				dataPtr += bytesSent;
				remainingBytes -= bytesSent;
			}
			send_image(imageData);
		}

	std::vector<uchar> receiveImageData(int clientSock)
	{
		std::vector<uchar> imageData;

		while (true) {
			std::array<uchar, 4096> buffer;
			ssize_t bytesRead = recv(clientSock, buffer.data(), buffer.size(), 0);
			if (bytesRead == -1) 
			{
				cout<<"Handle receive error\n";
				break;
			}

			if (bytesRead == 0)
			{
				cout<<"Connection closed by the server\n";
				break;
			}

			imageData.insert(imageData.end(), buffer.begin(), buffer.begin() + bytesRead);
		}

    		return imageData;
	}

	std::string Connection::receiveSerializedMapData()
	{
		std::string serializedMapData;

		while (true) {
			char buffer[4096];
			ssize_t bytesRead = recv(server_sock, buffer, sizeof(buffer), 0);
			if (bytesRead == -1)
			{
				cout<<"Receive error\n";
				break;
			}

			if (bytesRead == 0)
			{
				cout<<"Connection closed by the client\n";
				break;
			}

			serializedMapData.append(buffer, bytesRead);
		}

		return serializedMapData;
	}

	void Connection::upload(string )
	{
			
	}

		int Connection::checkUser(const std::map<std::string, std::string> d1, std::map<std::string, std::string>& d2)
		{
			
		}
		int Connection::createUser(const std::map<std::string, std::string> d1, std::map<std::string, std::string>& d2)
		{
			
		}
		
		void Connection::close_connection()
		{
			close(sock_conn);
			close(sock_bind);
		}
