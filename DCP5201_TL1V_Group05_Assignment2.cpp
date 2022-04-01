#include <iostream>
#include <string>

#include "Database.cpp"

/*
    This program uses C++17.
*/

void PrintProgramHeader()
{
    std::cout << "\n\t       JOBS MANAGEMENT SYSTEM\n";
    DisplayLines('-', 52);                          
    std::cout << "| ID | Username |      Job      |  Transportation  |\n";
    DisplayLines('-', 52);
}

void PrintProgramFooter()
{
    DisplayLines('-', 52);
    std::cout << "Thank you for using the Jobs Management System.";
}

int main()
{
    PrintProgramHeader();

    //std::string* username_ = new std::string;

    // std::string username;
    // std::cout << "Enter Username: ";
    // std::getline(std::cin >> std::ws, username);

    // std::cout << username;

    //Database database("Charles", "Train Driver", 0);
    
    //database.Print();

    //database.AddAirData("Henry", "Astronaut", 5);

    Database database_[5];

    database_[0] = { "Lee", "Astronaut", 5, "Air" };
    database_[1] = { "Henry", "Train Driver", 4, "Land" };
    database_[2] = { "Ling", "Sailor", 0, "Water" };

    // User user;

    // // Database* database = new Database[3]{
    // //     { "Charles", "Astronaut", 5, "Air" },
    // //     { "Henry", "Train Driver", 4, "Air" },
    // //     { "Ling", "Sailor", 0, "Air" },
    // // };

    
    // // for (int i = 0; i != 5; i++)
    // // {
    // //     database[i].Print();
    // // }
    database_[3].AddAirData("Vincent", "Aeronaut", 4);

    // // // for (int i = 0; i != 4; i++)
    // // // {
    // // //     database_[i].Print();
    // // // }

     database_[4].AddUser("WIcked");
    database_[4].AddJob("Train Driver");
    database_[4].AddAirTransport(3);
    static constexpr int database_size = sizeof(database_) / sizeof(database_[0]);

    //database_[0].RemoveUser();
    // database_[2].RemoveJob();
    // database_[3].RemoveTransport();

    database_[0].ReplaceUser("");
    // database_[1].ReplaceJob("Taxi Driver");
    for (int i = 0; i != database_size; i++)
    {
        database_[i].Print();
    }

    // database_[3].RemoveUser();

    // database_[2].RemoveTransport();
    // //Rivky
    // database_[1].RemoveTransport();

    // database_[0].RemoveJob();
    // // for (int i = 0; i != database_size; i++)
    // // {
    // //     database_[i].Print();
    // // }

    // // database_[2].RemoveAll();

    // for (int i = 0; i != database_size; i++)
    // {
    //     database_[i].Print();
    // }


    //  //database[3].Print();
    
    // // for (int i = 0; i != 5; i++)
    // // {
    // //     database[i].Print();
    // // }
    // // std::string job;
    // // std::cout << "Enter Job: ";
    // // std::getline(std::cin >> std::ws, job);
    
    //Person person(username, job);
    //person.GetName();
    //person.GetJob();

    //delete[] database;
   // database = nullptr;

    //delete username_;
    //username_ = nullptr;

    // Job job;

    // job.GetJobFromListing("Taxi Driver");

    PrintProgramFooter();

}