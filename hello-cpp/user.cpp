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

int User::hashCode()
{
    return sizeof(this->name);
}

User& User::operator ++()
{
    this->id = this->id + 1;
    return *this;
}

User User::operator ++(int)
{
    this->id++;
    std::cout << "++" << std::endl;
    return *this;
}

User User::operator +(User user)
{

    this->id = this->id + user.id;
    return *this;
}


