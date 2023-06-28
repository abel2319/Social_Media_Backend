#include "header.h"

int main()
{
	int c;
	string name, pwd, email;
	std::cout<<"*********************************************************"<<"\n";
	std::cout<<"**                                                     **"<<"\n";
	std::cout<<"**            Welcome to our Instagram App             **"<<"\n";
	std::cout<<"**                                                     **"<<"\n";
	std::cout<<"*********************************************************"<<"\n";

	std::cout<<"Have you already an Account ? \n 0(No) \n 1(yes)"<<"\n";
	std::cin>>c;
	if (c == 0)
	{
		std::cout<<"No problem, you can create ones right now"<<"\n";
		std::cout<<"Please enter your full name : ";
		std::cin>>name;
		std::cout<<"Your email : ";
		std::cin>>email;
		std::cout<<"Your password : ";
		std::cin>>pwd;

		User newU = new User(name, pwd, email);
		std::cout<<"Congratulation"<<"\n";
	}
	else
	{
		std::cout<<"Please enter your full name : ";
		std::cin>>name;
		std::cout<<"Your pwd : ";
		std::cin>>pwd;
		
		User *currentU = User.connect(name, pwd);
		if(currentU != NULL)
		{
			std::cout<<"Welcom"<<name<<"\n";
			while (true)
			{
				std::cout<<"Oparations available : 1(post a publication) \n 2(upload a publication) \n Make a choice : ";
				std::cin>>c;
				if(c == 1)
					currentU->send();
				else
					currentU->upload()
			}

		}
		else
			std::cout<<"Sorry you are not register yet"<<"\n";
	}
	return (0);
}
