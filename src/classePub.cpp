#include "header.h"
void User::send(std::map<std::string, std::string>& data){
	
	con = new Connection("172.0.0.1");

	auto date = std::chrono::system_clock::now();
 	std::time_t date_time = std::chrono::system_clock::to_time_t(date);
	data["timestamp"] = str(ctime(&date_time));

	cv::Mat image = cv::imread(data["image"], cv::IMREAD_UNCHANGED);
	
	if (image.empty()) {
		std::cout<<"image not found or couldn't be loaded\n";
	}
	else
	{
		std::vector<uchar> encodedImage;
    		cv::imencode(".jpg", image, encodedImage);

		json j(data);
		con.sed_data(j.dump(), encodeImage);
	
		cout<<"Right posted\n";
	}
   }


void User::upload(){
  	
}
