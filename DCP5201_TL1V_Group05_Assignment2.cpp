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
    UserInput() = delete;
    UserInput(const UserInput&) = delete;
    ~UserInput() = delete;
    void operator=(const UserInput&) = delete;

    const std::tuple<std::string, std::string, int> GetFullDetails()
    {
        std::getline(std::cin >> std::ws, m_Username);
        std::getline(std::cin >> std::ws, m_Job);
        std::cin >> m_TransportCode;

        return { m_Username, m_Job, m_TransportCode };
    }

    void GetUsernameDetails() { std::getline(std::cin >> std::ws, m_Username); }
    void GetJobDetails() { std::getline(std::cin >> std::ws, m_Job); }
    void GetTransportDetails() { std::cin >> m_TransportCode; }
    
    void RemoveUsernameDetails() { std::getline(std::cin >> std::ws, m_Username); }
    void RemoveJobDetails() { std::getline(std::cin >> std::ws, m_Job); }
    void RemoveTransportDetails() { std::cin >> m_TransportCode; }

    void ReplaceUsernameDetails() { std::getline(std::cin >> std::ws, m_Username); }
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
        CONSOLE("Dear Manager, would you like to use the Demo version? (Recommended for first-time users) [Y/N]");


    }

    static std::string Instructions(const std::string& instruction)
    {
        static constexpr std::array instructions_list = {
            "Error", // In case of a falsely-inserted instruction 
            "AddAirData", "AddLandData", "AddWaterData",
            "AddUser", "RemoveUser", "ReplaceUser",
            "AddJob", "RemoveJob", "ReplaceJob",
            "AddAirTransport", "AddLandTransport", "AddWaterTransport", "RemoveTransport", "ReplaceTransport",
            "RemoveAll", "Print"
        };

        auto result = std::find(instructions_list.begin(), instructions_list.end(), instruction); 

        if (result != std::end(instructions_list))
            return instruction;

        CONSOLE("Failure to process given instruction.\n");
        return "ERROR CODE: -1";   
    }

    void RequestFirstInstruction()
    {
        std::string user_input;
        CONSOLE("What is your next desired task?");
        std::cin >> user_input;
        std::string message_code = Instructions(m_UserInput);

        do 
        {
            CONSOLE("Please try again.\nType carefully.");
            std::cin >> m_UserInput;
            message_code = Instructions(m_UserInput);
        }
        while (message_code != "1");

        RequestSecondInstruction(message_code);
    } 

    void RequestSecondInstruction(const std::string& message)
    {
        CONSOLE("Enter the data fields of the instruction " << message << ".\n");

        std::string username = "", job = "";
        int transport_code = 0;

        if (message == "AddAirData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
        }
        else if (message == "AddLandData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddLandData(username, job, transport_code);
        }
        else if (message == "AddWaterData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddWaterData(username, job, transport_code);
        }
        if (message == "AddAirData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
        }
        if (message == "AddAirData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
        }
        if (message == "AddAirData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
        }
        if (message == "AddAirData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
        }
        if (message == "AddAirData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
        }
        if (message == "AddAirData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
        }
        if (message == "AddAirData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
        }
        if (message == "AddAirData")    
        {
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database.AddAirData(username, job, transport_code);
        }
    }

    void OnShutDown()
    {
        CONSOLE("Thank you for using the Jobs Management System.\n");
        
    }

    void Init() 
    {
        OnStartUp();
        PrintProgramHeader();
        PrintProgramFooter();
        OnShutDown();
    }

private:
    //std::string m_UserInput;

    Database m_Database;
    UserInput m_UserInput;
};

int main()
{
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

    PrintProgramFooter();

//    exit(0);

}