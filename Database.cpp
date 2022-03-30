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
    //std::string string_type[] = { (std::string)type };

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
        if (!m_Data.empty())
            m_Data.clear();

        std::cout << "\n\t   JOBS MANAGEMENT SYSTEM\n";
        DisplayLines('-', 51);                          
        std::cout << "| ID | Usernames |     Jobs     |  Transportation |\n";
        DisplayLines('-', 51);
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
        : m_User{ user }, m_Job{ job }, m_TransportType{ is_transport_type }
    {
        if (m_TransportType == "Air")
        {
            m_AirTransport.GetTransportTypeName(id);
            m_Data.push_back({ m_User, m_Job, m_AirTransport });
        }
        else if (m_TransportType == "Land")
        {
            m_LandTransport.GetTransportTypeName(id);
            m_Data.push_back({ m_User, m_Job, m_LandTransport });
        }
        else if (m_TransportType == "Water")
        {
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
        //std::cout << "Database Destructor\n"; 
    }

    void AddAirData(const std::string& user, const std::string& job, int air_id)
    {
        m_TransportType = "Air";
        m_User.SetName(user);
        m_Job.SetName(job);
        m_AirTransport.GetTransportTypeName(air_id);
        m_Data.push_back({ m_User, m_Job, m_AirTransport });
    }
    
    void AddLandData(const std::string& user, const std::string& job, int land_id)
    {
        m_TransportType = "Land";
        m_User.SetName(user);
        m_Job.SetName(job);
        m_LandTransport.GetTransportTypeName(land_id);
        m_Data.push_back({ m_User, m_Job, m_LandTransport });
    }

    void AddWaterData(const std::string& user, const std::string& job, int water_id)
    {
        m_TransportType = "Water";
        m_User.SetName(user);
        m_Job.SetName(job);
        m_WaterTransport.GetTransportTypeName(water_id);
        m_Data.push_back({ m_User, m_Job, m_WaterTransport });
    }

    void AddUser(const std::string& user) 
    {
        m_User.SetName(user);
        m_Data.push_back({ m_User });
    }

    const void RemoveAll() { m_Data.clear(); }
    const void RemoveUser() { m_Data[0].m_User = std::string(""); }
    const void RemoveJob() { m_Data[0].m_Job = std::string(""); }
    const void RemoveTransport() { m_Data[0].m_Transport = std::string(""); }

    void Print()
    {
        for (int i = 0; i != m_Data.size(); i++)
        {
            std::cout << "| " << IDGenerator::GenerateID() << "  | ";
            GetUserAtID(i);
            std::cout << " | " << GetJobAtID(i)
                << " | " << GetTransportAtID(i) << "\n";
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

    // void AddUserListing()
    // {
    //     //auto transport = air_transport.GetTransportTypeName();

    //     m_UserListing.push_back({ m_ID, m_Name, m_Job,  });
    // }


    //const std::string& GetUser() const { return m_Data[0].m_User.GetName(); }
    const void GetUserAtID(int id = 0) const { std::cout << m_Data[id].m_User.GetName(); }

    //const Job& GetJobListing() { return m_Job.JobsListing(1); }
    const std::string& GetJobAtID(int id = 0) const { return m_Data[id].m_Job.GetJob(); }
    
    //const Transportation& GetTransportation() { return m_Transportation.GetName(); }
    
    // template<typename T>
    // const T GetTransportAtID(int id) 
    // { 
    //     T transport;

    //     if (m_TransportType == "Air")
    //         T transport = std::get<AirTransport>(m_Data[id].m_Transport);
    //     else if (m_TransportType == "Land")
    //         T transport = std::get<LandTransport>(m_Data[id].m_Transport);
    //     else 
    //         T transport = std::get<WaterTransport>(m_Data[id].m_Transport);

    //     return transport;
    // }

    const AirTransport GetTransportAtID(int id) 
    { 
        AirTransport transport = std::get<AirTransport>(m_Data[id].m_Transport);
        return transport;
    }

private:
    User m_User;
    Job m_Job;

    AirTransport m_AirTransport;
    LandTransport m_LandTransport;
    WaterTransport m_WaterTransport;

    const char* m_TransportType;

    std::vector<Data> m_Data;
};