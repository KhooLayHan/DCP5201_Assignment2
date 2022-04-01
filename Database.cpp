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
    std::variant<AirTransport, LandTransport, WaterTransport> m_Transport;
};

class Database
{
public:
    Database() 
    {
        std::cout << "Database Constructor\n";
        if (!m_Data.empty())
            m_Data.clear();
    };

    // Database(const User& user, const std::string& job, const AirTransport& air_transport)
    //     : m_User{ user }, m_Job{ job }, m_AirTransport{ air_transport }
    // {
    // }
        
    // Database(const User& User, const Job& job, const AirTransport& air_transport)
    //     : m_User{ User }, m_Job{ job }, m_AirTransport{ static_cast<AirTransport::Air>(air_transport) }
    // {}

    // Database(const std::string& User, const std::string& job, AirTransport air)
    //     : m_User{ User }, m_Job{ job }, m_AirTransport{ air }
    // {
    //     m_Data.push_back({ m_User, m_Job, m_AirTransport });
    // }

    Database(const std::string& user, const std::string& job, int id, const char* is_transport_type)
        : m_User{ user }, m_TransportType{ is_transport_type }
    {
        if (m_TransportType == "Air")
        {
            m_Job.GetJobFromListing(job);
            m_AirTransport.GetTransportTypeName(id);
            m_Data.push_back({ m_User, m_Job, m_AirTransport });
        }
        else if (m_TransportType == "Land")
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

    // Database(const std::string& User, const std::string& job, int land_id)
    //     : m_User{ User }, m_Job{ job }, m_LandTransport{ land_id }
    // {
    //     m_Data.push_back({ m_User, m_Job, m_LandTransport });
    // }

    // Database(const std::string& User, const std::string& job, int water_id)
    //     : m_User{ User }, m_Job{ job }, m_WaterTransport{ water_id }
    // {
    //     m_Data.push_back({ m_User, m_Job, m_WaterTransport });
    // }

    ~Database() 
    {
        std::cout << "Database Destructor\n"; 
    }

    void AddAirData(const std::string& user, const std::string& job, int air_id)
    {
        m_TransportType = "Air";
        m_User.SetName(user);
        m_Job.GetJobFromListing(job);
        m_AirTransport.GetTransportTypeName(air_id);
        m_Data.push_back({ m_User, m_Job, m_AirTransport });
    }
    
    void AddLandData(const std::string& user, const std::string& job, int land_id)
    {
        m_TransportType = "Land";
        m_User.SetName(user);
        m_Job.GetJobFromListing(job);
        m_LandTransport.GetTransportTypeName(land_id);
        m_Data.push_back({ m_User, m_Job, m_LandTransport });
    }

    void AddWaterData(const std::string& user, const std::string& job, int water_id)
    {
        m_TransportType = "Water";
        m_User.SetName(user);
        m_Job.GetJobFromListing(job);
        m_WaterTransport.GetTransportTypeName(water_id);
        m_Data.push_back({ m_User, m_Job, m_WaterTransport });
    }

    void AddUser(const std::string& user) 
    {
        m_User.SetName(user);
        m_Data.push_back({ m_User });
    }

    void AddJob(const std::string& job)
    {
        m_Job.GetJobFromListing(job);
        m_Data[0].m_Job = m_Job;
    } 

    void AddAirTransport(int id)
    {   
        m_TransportType = "Air";    
        m_AirTransport.GetTransportTypeName(id);
        m_Data[0].m_Transport = m_AirTransport;
    } 
    
    void AddLandTransport(int id)
    {   
        m_TransportType = "Land";    
        m_LandTransport.GetTransportTypeName(id);
        m_Data[0].m_Transport = m_LandTransport;
    } 
    
    void AddWaterTransport(int id)
    {   
        m_TransportType = "Air";    
        m_WaterTransport.GetTransportTypeName(id);
        m_Data[0].m_Transport = m_WaterTransport;
    } 

    void RemoveAll() { m_Data.clear(); }
    void RemoveUser() { m_Data[0].m_User = std::string(""); }
    void RemoveJob() { m_Data[0].m_Job = std::string(""); }
    
    void RemoveTransport() 
    { 
        std::cout << m_TransportType << "\n";

        if (m_TransportType == "Air")
            m_Data[0].m_Transport.emplace<AirTransport>(""); 
        if (m_TransportType == "Land")
            m_Data[0].m_Transport.emplace<LandTransport>(""); 
        if (m_TransportType == "Water")
            m_Data[0].m_Transport.emplace<WaterTransport>(""); 
    }
    
    void ReplaceUser(const std::string& user)
    {
        if (m_Data[0].m_User.GetName() == user)
            std::cout << "User already exist in job listing!\n";

        m_User.SetName(user);
        m_Data[0].m_User = m_User;
    }
    
    void ReplaceJob(const std::string& job)
    {
        if (m_Data[0].m_Job.GetJob() == job)
            std::cout << "Job already exist in job listing!\n";

        m_Job.GetJobFromListing(job);
        m_Data[0].m_Job = m_Job;
    }
    
    void ReplaceTransport(int id)
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

    void Print()
    {
        for (int i = 0; i != m_Data.size(); i++)
        {
            std::cout << "| " << IDGenerator::GenerateID() << "  | ";
            GetUserAtID(i);
            std::cout << " | ";
            GetJobAtID(i);
            std::cout << " | "; 
            GetTransportAtID(i);
            std::cout << "\n";
        }
    }

    // void CheckJobAvailability()
    // {
    //     std::string available_jobs = "Aeroplane";

    //     if (available_jobs == "Aeroplane") 
    //     {
    //         std::cout << m_Name << " are hired to " << m_Job << "!\n"; 
    //         AddUserListing();
    //     } 
    //     else 
    //     {
    //         std::cout << "OOPS! The job is not available\n";
    //         //return false;
    //     }
    // }

    void GetUserAtID(int id = 0) const { std::cout << m_Data[id].m_User.GetName(); }
    void GetJobAtID(int id = 0) const { std::cout << m_Data[id].m_Job.GetJob(); }
    
    void GetTransportAtID(int id) 
    { 
        if (m_TransportType == "Air")
        {
            AirTransport transport = std::get<AirTransport>(m_Data[id].m_Transport);
            std::cout << transport;
        }
        else if (m_TransportType == "Land")
        {
            LandTransport transport = std::get<LandTransport>(m_Data[id].m_Transport);
            std::cout << transport;
        }
        else
        {
            WaterTransport transport = std::get<WaterTransport>(m_Data[id].m_Transport);
            std::cout << transport;
        }
    }

    // static Database& ClearAll() 
    // {
    //     for (int i = 0; i != 10; i++)
    //     {}
    // }

private:
    User m_User;
    Job m_Job;

    AirTransport m_AirTransport;
    LandTransport m_LandTransport;
    WaterTransport m_WaterTransport;

    const char* m_TransportType;

    std::vector<Data> m_Data;
};