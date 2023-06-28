#include "header.h"
User::con = new Connection("172.0.0.1");
User::Users(string id, string Nom) : data["id"](Id), data["name"](Nom) {}
User::Users(string Nom, string Pwd, string Email) : data["name"](Nom), data["pwd"](Pwd), data["email"](Email) 
	{
		create_user();
	}

void User::poster(string contenu, string image) {
    	try{
		std::map<std::string, std::string> tmp;
    		Publication p = new Publication;
		
		tmp["id_U"] = data["id"];
		cout<<"The content of your publication : ";
		cin>>tmp["content"];
		cout<<"The Image's path of your publication : ";
		cin>>tmp["image"];
    		
		p.send(tmp);
    	}
    	catch(...)
    	{
    		cout<<"Création de post impossible."<<"\n";
	}
}

void User::upload() {
	std::string idPub;
	try{
    		Publication P = new Publication();
    		p.upload_all();
    		cin<<idPub;
    		p.upload(id, idPub);
    	}
    	catch(...)
    	{
    		cout<<"Impossible de charger les publications.\n";
    	}
}

void* User::connect(string n, string p)
{
	User *tmp = NULL;
	std::map<std::string, std::string> d2;
	
	int c = int c = con.checkUser(d1, d2);
	if (c != -1)
	{
		tmp = new User(d2["id"], d2["name"]);
		return (tmp);
	}
	return (tmp);
}

int createUser()
{
	std::map<std::string, std::string> d1 = {"name":name, "pwd":pwd, "email":email};

	int c = con.create_user(d1);
	if (c != -1)
	{
		cout<<"Successfull Sign In\n";
	}

}
