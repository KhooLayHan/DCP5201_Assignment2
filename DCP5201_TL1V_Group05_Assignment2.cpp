#include <iostream>
#include <string>

#include "Database.cpp"

int main()
{
    //std::string* username_ = new std::string;

    // std::string username;
    // std::cout << "Enter Username: ";
    // std::getline(std::cin >> std::ws, username);

    // std::cout << username;

    //Database database("Charles", "Train Driver", 0);
    
    //database.Print();

    //database.AddAirData("Henry", "Astronaut", 5);

    Database database_[5];

    database_[0] = { "Charles", "Astronaut", 7, "Air" };
    database_[1] = { "Henry", "Train Driver", 4, "Air" };
    database_[2] = { "Ling", "Sailor", 0, "Air" };

    User user;

    // Database* database = new Database[3]{
    //     { "Charles", "Astronaut", 5, "Air" },
    //     { "Henry", "Train Driver", 4, "Air" },
    //     { "Ling", "Sailor", 0, "Air" },
    // };

    
    // for (int i = 0; i != 5; i++)
    // {
    //     database[i].Print();
    // }
    database_[3].AddAirData("Vincent", "Aeronaut", 2);

    // for (int i = 0; i != 4; i++)
    // {
    //     database_[i].Print();
    // }

    database_[4].AddUser("WIcked");

    static constexpr int database_size = sizeof(database_) / sizeof(database_[0]);

    // for (int i = 0; i != database_size; i++)
    // {
    //     database_[i].Print();
    // }

    database_[3].RemoveUser();

    database_[2].RemoveTransport();
    database_[1].RemoveTransport();

    database_[0].RemoveJob();
    for (int i = 0; i != database_size; i++)
    {
        database_[i].Print();
    }

     //database[3].Print();
    
    // for (int i = 0; i != 5; i++)
    // {
    //     database[i].Print();
    // }
    // std::string job;
    // std::cout << "Enter Job: ";
    // std::getline(std::cin >> std::ws, job);
    
    //Person person(username, job);
    //person.GetName();
    //person.GetJob();

    //delete[] database;
   // database = nullptr;

    //delete username_;
    //username_ = nullptr;
}