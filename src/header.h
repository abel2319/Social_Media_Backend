#ifndef __HEADER_H
#define __HEADER_H

#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <opencv2/opencv.hpp>
#include </usr/include/opencv4/opencv2/opencv.hpp>
#include <nlohmann/json.hpp>
#include <sys/socket.h>
#include <arpa/inet.h>

using json = nlohmann::json;

class User
{
	
   //string id;
   //string name;
   //string pwd;
   //string email;
   //Instead of take all parameters separetly, I will take the; in a map
   std::map<std::string, std::string> data;
   Connection con;
public:
    Users(std::string, std::string);
    Users(std::string, std::string, std::string);


    void poster(std::string, std::string);

    void upload(); 

    void* connect(std::string, std::string);

    int create_user();
};

class Publication {
	std::string id_U;
	Connection con;

  Public:

  void send(std::map<std::string, std::string>&);


  void upload();

};

class Connection
{
	int sock_conn;
	int sock_bind;
	int server_sock;

	public:
		Connection(string);
		
		void send_image(const std::vector<uchar>&);

		void send_data(const std::string& );
		void send_data(const std::string& , const std::vector<uchar>& );
		std::vector<uchar> receiveImageData()
		std::string receiveSerializedMapData()

		void upload(string );

		int checkUser(const std::map<std::string, std::string>& , std::map<std::string, std::string>& );
		void close_connection();
		int createUser(const std::map<std::string, std::string, std::string>);
};


std::string serializeMap(const std::map<std::string, std::string>&);
std::map<std::string, std::string> deserializeMap(const std::string& ) {
#endif
