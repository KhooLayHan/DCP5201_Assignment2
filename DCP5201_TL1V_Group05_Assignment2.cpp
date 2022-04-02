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
    std::cout << "\n      JOBS MANAGEMENT SYSTEM (ALPHA BUILD v0.01)\n";
    DisplayLines('-', 54);                          
    std::cout << "|  ID  | Username |      Job      |  Transportation  |\n";
    DisplayLines('-', 54);
}

void PrintProgramFooter()
{
    DisplayLines('-', 54);
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
    const std::string GetJobDetails() { std::getline(std::cin >> std::ws, m_Job); return m_Job;}
    const int GetTransportDetails() { std::cin >> m_TransportCode; return m_TransportCode; }
    
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
        CONSOLE("Welcome to Jobs Management System. I'm CONSOLE, your trusty partner for this Alpha build.\n";)

        char manager_demo_request;
        CONSOLE("Dear Manager, would you like to use the Demo session? (Recommended for first-time users) [Y/N] ");
        std::cin >> manager_demo_request;

        if (manager_demo_request == 'Y' || manager_demo_request == 'y')
        {
            CONSOLE("Initializing Demo session...\n");
            CONSOLE("Demo session enabled\n");
            RequestFirstInstruction();
        }

        CONSOLE("OK. Enabling Live session... Bye!");
        exit(EXIT_SUCCESS);
    }

    void OnShutDown()
    {
        CONSOLE("Thank you for using the Jobs Management System.\n");
        CONSOLE("Exiting... Demo session.\n");
        CONSOLE("Demo session Disabled\n");

        exit(EXIT_SUCCESS);
    }

    void Init() 
    {
        OnStartUp();
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
        int id; // NOTE: The Database can only stored 10 elements (the size is hard-coded).
        std::string user_input;
        
        CONSOLE("What is your next desired task? ");
        std::cin >> user_input >> id;

        std::string message_code = Instructions(user_input);

        while (message_code == "-1")
        {
            CONSOLE("Please try again. Type carefully. ");
            std::cin >> user_input >> id;
            message_code = Instructions(user_input);
        }

        RequestSecondInstruction(message_code, id);
    } 

    void RequestSecondInstruction(const std::string& message, int index = -1)
    {
        std::string username = "", job = "";
        int transport_code = 0;

        if (message == "AddAirData")    
        {
            CONSOLE("Enter the data fields for the instruction " << message << ". ");
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database[index].AddAirData(username, job, transport_code);
        }
        else if (message == "AddLandData")    
        {
            CONSOLE("Enter the data fields for the instruction " << message << ". ");
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database[index].AddLandData(username, job, transport_code);
        }
        else if (message == "AddWaterData")    
        {
            CONSOLE("Enter the data fields for the instruction " << message << ". ");
            const auto [username, job, transport_code] = m_UserInput.GetFullDetails();
            m_Database[index].AddWaterData(username, job, transport_code);
        }
        else if (message == "AddUser")    
        {
            CONSOLE("Enter the user for the instruction " << message << ". ");
            const std::string& username = m_UserInput.GetUserDetails();
            m_Database[index].AddUser(username);
        }
        else if (message == "AddJob")    
        {
            CONSOLE("Enter the job for the instruction " << message << ". ");
            const std::string& job = m_UserInput.GetJobDetails();
            m_Database[index].AddJob(job);
        }
        else if (message == "AddAirTransport")    
        {
            CONSOLE("Enter the transportation for the instruction " << message << ". ");
            const int& transport_code = m_UserInput.GetTransportDetails();
            m_Database[index].AddAirTransport(transport_code);
        }
        else if (message == "AddLandTransport")    
        {
            CONSOLE("Enter the transportation for the instruction " << message << ". ");
            const int& transport_code = m_UserInput.GetTransportDetails();
            m_Database[index].AddLandTransport(transport_code);
        }
        else if (message == "AddWaterTransport")    
        {
            CONSOLE("Enter the transportation for the instruction " << message << ". ");
            const int& transport_code = m_UserInput.GetTransportDetails();
            m_Database[index].AddWaterTransport(transport_code);
        }
        else if (message == "RemoveAll")    
        {
            CONSOLE("Removing all elements from index " << index << " for instruction " << message << ".\n");
            m_Database[index].RemoveAll();
        }
        else if (message == "RemoveUser")    
        {
            CONSOLE("Removing user from index " << index << " for instruction " << message << ".\n");
            m_Database[index].RemoveUser();
        }
        else if (message == "RemoveJob")    
        {
            CONSOLE("Removing job from index " << index << " for instruction " << message << ".\n");
            m_Database[index].RemoveJob();
        }
        else if (message == "RemoveTransport")    
        {
            CONSOLE("Removing transportation from index " << index << " for instruction " << message << ".\n");
            m_Database[index].RemoveTransport();
        }
        else if (message == "ReplaceUser")    
        {
            CONSOLE("Enter the user at index " << index << " for instruction " << message << ". ");
            const std::string& username = m_UserInput.GetUserDetails();
            m_Database[index].ReplaceUser(username);
        }
        else if (message == "ReplaceJob")    
        {
            CONSOLE("Enter the job at index " << index << " for instruction " << message << ". ");
            const std::string& job = m_UserInput.GetJobDetails();
            m_Database[index].ReplaceJob(job);
        }
        else if (message == "ReplaceTransport")    
        {
            CONSOLE("Enter the transportation at index " << index << " for instruction " << message << ". ");
            const int& transport_code = m_UserInput.GetTransportDetails();
            m_Database[index].ReplaceTransport(transport_code);
        }
        else if (message == "Print") // For Print() function ....
        {
            PrintProgramHeader();

            if (index >= 0 && index <= 9)
                m_Database[index].Print(); // If index is within a range, program will only print at that index
            else
            {
                for (int i = 0; i != database_size; i++) // If index is not within range, program will print all elements.
                    m_Database[i].Print();  
            }
        
            PrintProgramFooter();
        }

        if (message == "End") // Index doesn't matter, just type "End"
        {
            PrintProgramHeader();
            for (int i = 0; i != database_size; i++) // Prints again but with finalized table
                m_Database[i].Print(); 
            PrintProgramFooter();
            
            OnShutDown();
        }

        RequestFirstInstruction();
    }

private:
    static constexpr int database_size = 9; // Hardcoded value for max database size

    Database m_Database[database_size];
    UserInput m_UserInput;
};

int main()
{
    Database* database = new Database[3]{ 
        { "Charles", "Astronaut", 5, "Air" },
        { "Henry", "Train Driver", 4, "Air" },
        { "Ling", "Sailor", 0, "Air" },
    };

    Database db_[3] = {
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

    UserInput user_input;
    Console console;

    PrintProgramHeader();
    PrintProgramFooter();

    //console.Init();

    static constexpr std::size_t database_size = sizeof(db_) / sizeof(db_[0]);

    //  std::cout << "\n\t       JOBS MANAGEMENT SYSTEM\n";
    //     DisplayLines('-', 52);                          
    //     std::cout << "| ID | Username |      Job      |  Transportation  |\n";
    //     DisplayLines('-', 52);

    // for (int i = 0; i != database_size; i++)
    // {
    //     db_[i].Print();

    // }

    //  DisplayLines('-', 52);
    //     std::cout << "Thank you for using the Jobs Management System.\n";

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