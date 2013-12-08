#include "user.h"

User::User()
{
}

User::User(int id, std::string name)
{
    this->id = id;
    this->name = name;
}

User::~User()
{
    std::cout << "~User()" << std::endl;
}

void User::show()
{
    std::cout << "User[" << "id:" << this->id << ",name:" << this->name << "]" << std::endl;
}


