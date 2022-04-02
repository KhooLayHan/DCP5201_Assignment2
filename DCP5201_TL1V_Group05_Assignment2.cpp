#include <algorithm>
#include <array>
#include <iostream>
#include <string>

#include "Database.cpp"

#define CONSOLE(x) std::cout << "[CONSOLE] " << x;

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
    std::cout << "Thank you for using the Jobs Management System.\n";
}

void Message(const std::string& message)
{
    std::cout << message << "\n";
}

class UserInput // Custom "Whatever" Design Pattern
{
public:
    UserInput() {}
    ~UserInput() {}

    const std::tuple<std::string, std::string, int> GetFullDetails()
    {
        std::getline(std::cin >> std::ws, m_Username); // NOTE: Assuming for manager to press space after inserting a new value!
        std::getline(std::cin >> std::ws, m_Job);
        std::cin >> m_TransportCode;

        return { m_Username, m_Job, m_TransportCode };
    }

    const std::string GetUserDetails() { std::getline(std::cin >> std::ws, m_Username); return m_Username; }
    const std::string GetJobDetails() { std::getline(std::cin >> std::ws, m_Job); return m_Username;}
    const int GetTransportDetails() { std::cin >> m_TransportCode; return m_TransportCode; }
    
    const std::string RemoveUserDetails() { std::getline(std::cin >> std::ws, m_Username); return m_Username; }
    const std::string RemoveJobDetails() { std::getline(std::cin >> std::ws, m_Job); return m_Username;}
    const int RemoveTransportDetails() { std::cin >> m_TransportCode; return m_TransportCode; }

    void ReplaceUserDetails() { std::getline(std::cin >> std::ws, m_Username); }
    void ReplaceJobDetails() { std::getline(std::cin >> std::ws, m_Job); }
    void ReplaceTransportDetails() { std::cin >> m_TransportCode; }

private:
    std::string m_Username;
    std::string m_Job;
    int m_TransportCode;
};

class Console
{
public:
    Console() {}
    ~Console() {}

    void OnStartUp()
    {
        std::string requesting_demo_or_not;
        CONSOLE("Dear Manager, would you like to use the Demo version? (Recommended for first-time users) [Y/N] ");


    }

    static std::string Instructions(const std::string& instruction)
    {
        static constexpr std::array instructions_list = {
            "Error", // In case of a falsely-inserted instruction 
            "AddAirData", "AddLandData", "AddWaterData",
            "AddUser", "RemoveUser", "ReplaceUser",
            "AddJob", "RemoveJob", "ReplaceJob",
            "AddAirTransport", "AddLandTransport", "AddWaterTransport", "RemoveTransport", "ReplaceTransport",
            "RemoveAll", "Print", "End"
        };

        auto result = std::find(instructions_list.begin(), instructions_list.end(), instruction); 

        if (result != std::end(instructions_list))
            return instruction;

        CONSOLE("Failure to process given instruction.\n");
        return "-1"; // Error code for easier debugging
    }

    void RequestFirstInstruction()
    {
        std::string user_input;
        CONSOLE("What is your next desired task? ");
        std::cin >> user_input;
        std::string message_code = Instructions(user_input);

        while (message_code == "-1")
        {
            CONSOLE("Please try again. Type carefully. ");
            std::cin >> user_input;
            message_code = Instructions(user_input);
        }

        RequestSecondInstruction(message_code);
    } 

    void RequestSecondInstruction(const std::string& message)
    {
        std::string username = "", job = "";
        int transport_code = 0;

        if (message == "AddAirData")    
        {
            CONSOLE("Enter the data fields for the instruction " << message << ". ");
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
            RequestFirstInstruction();
        }
        else if (message == "AddLandData")    
        {
            CONSOLE("Enter the data fields for the instruction " << message << ". ");
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddLandData(username, job, transport_code);
            RequestFirstInstruction();
        }
        else if (message == "AddWaterData")    
        {
            CONSOLE("Enter the data fields for the instruction " << message << ". ");
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddWaterData(username, job, transport_code);
            RequestFirstInstruction();
        }
        // if (message == "AddUser")    
        // {
        //     const std::string& username = m_UserInput.GetUserDetails();
        //     m_Database.AddAirData(username, job, transport_code);
        // }
        // if (message == "AddAirData")    
        // {
        //     const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
        //     m_Database.AddAirData(username, job, transport_code);
        // }
        // if (message == "AddAirData")    
        // {
        //     const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
        //     m_Database.AddAirData(username, job, transport_code);
        // }
        // if (message == "AddAirData")    
        // {
        //     const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
        //     m_Database.AddAirData(username, job, transport_code);
        // }
        // if (message == "AddAirData")    
        // {
        //     const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
        //     m_Database.AddAirData(username, job, transport_code);
        // }
        // if (message == "AddAirData")    
        // {
        //     const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
        //     m_Database.AddAirData(username, job, transport_code);
        // }
        // if (message == "AddAirData")    
        // {
        //     const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
        //     m_Database.AddAirData(username, job, transport_code);
        // }
        else if (message == "Print")    
        {
            m_Database.Print();
        }

        // If message == "End"

    }

    void OnShutDown()
    {
        CONSOLE("Thank you for using the Jobs Management System.\n");
        
    }

    void Init() 
    {
        OnStartUp();
        OnShutDown();
    }

private:
    //std::string m_UserInput;

    Database m_Database;
    UserInput m_UserInput;
};

int main()
{
    Database* database = new Database[3]{ 
        { "Charles", "Astronaut", 5, "Air" },
        { "Henry", "Train Driver", 4, "Air" },
        { "Ling", "Sailor", 0, "Air" },
    };

    if(!database)
    {
        std::cout << "Can't initialize memory for database!\n";
        return 0;
    }

    //database[0].AddAirData("Vincent", "Astronaut", 1);

    // UserInput user_input;
    // Console console;

    // console.RequestFirstInstruction();

    static constexpr int database_size = sizeof(database) / sizeof(database[0]);

    for (int i = 0; i != 3; i++)
    {
        database[i].Print();

    }

    // Message("What do you want to do next?\n");
    
    // std::string user_input;
    // std::cin >> user_input;

    // if (user_input == "")

    // PrintProgramHeader();

    //std::string* username_ = new std::string;

    // std::string username;
    // std::cout << "Enter Username: ";
    // std::getline(std::cin >> std::ws, username);

    // std::cout << username;

    //Database database("Charles", "Train Driver", 0);
    
    //database.Print();

    //database.AddAirData("Henry", "Astronaut", 5);

//     Database database_[5];

//     database_[0] = { "Lee", "Astronaut", 5, "Air" };
//     database_[1] = { "Henry", "Train Driver", 4, "Land" };
//     database_[2] = { "Ling", "Sailor", 0, "Water" };

//     // User user;

//     // // Database* database = new Database[3]{
//     // //     { "Charles", "Astronaut", 5, "Air" },
//     // //     { "Henry", "Train Driver", 4, "Air" },
//     // //     { "Ling", "Sailor", 0, "Air" },
//     // // };

    
//     // // for (int i = 0; i != 5; i++)
//     // // {
//     // //     database[i].Print();
//     // // }
//     database_[3].AddAirData("Vincent", "Aeronaut", 4);

//     // // // for (int i = 0; i != 4; i++)
//     // // // {
//     // // //     database_[i].Print();
//     // // // }

//      database_[4].AddUser("WIcked");
//     database_[4].AddJob("Train Driver");
//     database_[4].AddAirTransport(3);
//     static constexpr int database_size = sizeof(database_) / sizeof(database_[0]);

//     //database_[0].RemoveUser();
//     // database_[2].RemoveJob();
//     // database_[3].RemoveTransport();

//     database_[0].ReplaceUser("");
//     // database_[1].ReplaceJob("Taxi Driver");
//     for (int i = 0; i != database_size; i++)
//     {
//         database_[i].Print();
//     }

//     // database_[3].RemoveUser();

//     // database_[2].RemoveTransport();
//     // //Rivky
//     // database_[1].RemoveTransport();

//     // database_[0].RemoveJob();
//     // // for (int i = 0; i != database_size; i++)
//     // // {
//     // //     database_[i].Print();
//     // // }

//     // // database_[2].RemoveAll();

//     // for (int i = 0; i != database_size; i++)
//     // {
//     //     database_[i].Print();
//     // }


//     //  //database[3].Print();
    
//     // // for (int i = 0; i != 5; i++)
//     // // {
//     // //     database[i].Print();
//     // // }
//     // // std::string job;
//     // // std::cout << "Enter Job: ";
//     // // std::getline(std::cin >> std::ws, job);
    
//     //Person person(username, job);
//     //person.GetName();
//     //person.GetJob();

//     //delete[] database;
//    // database = nullptr;

//     //delete username_;
//     //username_ = nullptr;

//     // Job job;

//     // job.GetJobFromListing("Taxi Driver");

    //PrintProgramFooter();

//    exit(0);

    delete[] database;
    // std::cin.get();
}