#include <iostream>
#include <string>
#include <variant>
#include <vector>

#include "Transportation.cpp"
#include "Job.cpp"
#include "User.cpp"
#include "IDGenerator.cpp"

void DisplayLines(char type, int count) 
{   
    for (int i = 0; i != count; i++)
    {
        std::cout << type;
    }

    std::cout << "\n"; 
}

struct Data
{
    User m_User;
    Job m_Job;
    std::variant<AirTransport, LandTransport, WaterTransport> m_Transport; // std::variant is used so we can access the 3 classes with just one variable
};

class Database
{
public:
    Database() 
    {
        if (!m_Data.empty()) // If data in database is not empty, then clears it first. 
            m_Data.clear();  // Can't say it is ever used since destructors are called automatically.
    };

    // Parameterized Constructor that sets the value to its individual element 
    Database(const std::string& user, const std::string& job, int id, std::string is_transport_type)
        : m_User{ user }, m_TransportType{ is_transport_type }
    {
        if (m_TransportType == "Air") // First we get the type of transport, then inserts the data to vector m_Data 
        {
            m_Job.GetJobFromListing(job);
            m_AirTransport.GetTransportTypeName(id);
            m_Data.push_back({ m_User, m_Job, m_AirTransport });
        }
        else if (m_TransportType == "Land") // The same goes for the following if-else if statements as well
        {
            m_Job.GetJobFromListing(job);
            m_LandTransport.GetTransportTypeName(id);
            m_Data.push_back({ m_User, m_Job, m_LandTransport });
        }
        else if (m_TransportType == "Water")
        {
            m_Job.GetJobFromListing(job);
            m_WaterTransport.GetTransportTypeName(id);
            m_Data.push_back({ m_User, m_Job, m_WaterTransport });
        }
    }

    ~Database() {}

    void AddAirData(const std::string& user, const std::string& job, int air_id) // Add full details of AirTransport
    {
        m_TransportType = "Air";
        m_User.SetName(user);
        m_Job.GetJobFromListing(job);
        m_AirTransport.GetTransportTypeName(air_id);
        m_Data.push_back({ m_User, m_Job, m_AirTransport });
    }
    
    void AddLandData(const std::string& user, const std::string& job, int land_id) // Add full details of LandTransport
    {
        m_TransportType = "Land";
        m_User.SetName(user);
        m_Job.GetJobFromListing(job);
        m_LandTransport.GetTransportTypeName(land_id);
        m_Data.push_back({ m_User, m_Job, m_LandTransport });
    }

    void AddWaterData(const std::string& user, const std::string& job, int water_id) // Add full details of WaterTransport
    {
        m_TransportType = "Water";
        m_User.SetName(user);
        m_Job.GetJobFromListing(job);
        m_WaterTransport.GetTransportTypeName(water_id);
        m_Data.push_back({ m_User, m_Job, m_WaterTransport });
    }

    void AddUser(const std::string& user) // Just adds the new user to m_Data with push_back()
    {
        m_User.SetName(user);
        m_Data.push_back({ m_User });
    }

    void AddJob(const std::string& job) // Just adds the new job to m_Data
    {
        m_Job.GetJobFromListing(job);
        m_Data[0].m_Job = m_Job;
    } 

    void AddAirTransport(int id) // Just adds the new air transport to m_Data
    {   
        m_TransportType = "Air";    
        m_AirTransport.GetTransportTypeName(id);
        m_Data[0].m_Transport = m_AirTransport;
    } 
    
    void AddLandTransport(int id) // Just adds the new land transport to m_Data
    {   
        m_TransportType = "Land";    
        m_LandTransport.GetTransportTypeName(id);
        m_Data[0].m_Transport = m_LandTransport;
    } 
    
    void AddWaterTransport(int id) // Just adds the new water transport to m_Data
    {   
        m_TransportType = "Air";    
        m_WaterTransport.GetTransportTypeName(id);
        m_Data[0].m_Transport = m_WaterTransport;
    } 

    // Member functions to remove the data at the specified index.
    void RemoveAll() { m_Data.clear(); }
    void RemoveUser() { m_Data[0].m_User = std::string(""); }
    void RemoveJob() { m_Data[0].m_Job = std::string(""); }
    
    void RemoveTransport() // For RemoveTransport(), we will need to get the type of m_Transport first
    { 
        // std::cout << m_TransportType << "\n";

        if (m_TransportType == "Air")
            m_Data[0].m_Transport.emplace<AirTransport>(""); 
        if (m_TransportType == "Land")
            m_Data[0].m_Transport.emplace<LandTransport>(""); 
        if (m_TransportType == "Water")
            m_Data[0].m_Transport.emplace<WaterTransport>(""); 
    }
    
    void ReplaceUser(const std::string& user) // Replace the old user with new user data
    {
        if (m_Data[0].m_User.GetName() == user)
            std::cout << "User already exist in job listing!\n";

        m_User.SetName(user);
        m_Data[0].m_User = m_User; // push_back() is not needed since we are just overriding the value
    }
    
    void ReplaceJob(const std::string& job) // Replace the old job with new job data
    {
        if (m_Data[0].m_Job.GetJob() == job)
            std::cout << "Job already exist in job listing!\n";

        m_Job.GetJobFromListing(job);
        m_Data[0].m_Job = m_Job;
    }
    
    void ReplaceTransport(int id) // Again, first get the type of m_Transport, and replace it with the new data
    {
        if (m_TransportType == "Air")
        {
            m_AirTransport.GetTransportTypeName(id);
            m_Data[0].m_Transport = m_AirTransport;
        }
        else if (m_TransportType == "Land")
        {
            m_LandTransport.GetTransportTypeName(id);
            m_Data[0].m_Transport = m_LandTransport;
        }
        else
        {
            m_WaterTransport.GetTransportTypeName(id);
            m_Data[0].m_Transport = m_WaterTransport;
        }
    }

    void Print() // Print and display the table to to console screen
    {
        for (int i = 0; i != m_Data.size(); i++)
        {
            std::cout << "| " << IDGenerator::GenerateIDToString() << " | "
                << GetUserAtID(i) << " | " << GetJobAtID(i) << " | " 
                << GetTransportAtID(i) << " |\n";
        }
    }

    const std::string& GetUserAtID(int id = 0) { return m_Data[id].m_User.GetName(); } // Getter functions 
    const std::string& GetJobAtID(int id = 0) { return m_Data[id].m_Job.GetJob(); }

    // This function is where we utlised the friend and operator overloading function implemented in class Transportation
    const std::string GetTransportAtID(int id) 
    {
        if (m_TransportType == "") // If error-checker when the type is not available 
        {
            // If variable is undefined or null, just set a default
            m_Data[id].m_Transport.emplace<AirTransport>("");
            AirTransport transport = std::get<AirTransport>(m_Data[id].m_Transport); 
            return transport.SetPadding(); 
        }
        else if (m_TransportType == "Air")
        {
            AirTransport transport = std::get<AirTransport>(m_Data[id].m_Transport);
            return transport.SetPadding(); // Setting the extra padding as necessary
        }
        else if (m_TransportType == "Land")
        {
            LandTransport transport = std::get<LandTransport>(m_Data[id].m_Transport);
            return transport.SetPadding();;
        }
        else
        {
            WaterTransport transport = std::get<WaterTransport>(m_Data[id].m_Transport);
            return transport.SetPadding();;
        }
    }

private:
    User m_User;
    Job m_Job;

    AirTransport m_AirTransport;
    LandTransport m_LandTransport;
    WaterTransport m_WaterTransport;

    std::string m_TransportType;

    std::vector<Data> m_Data; // Storing the struct Data type to std::vector
};