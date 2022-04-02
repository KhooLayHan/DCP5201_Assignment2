#include <iostream>
#include <string>
#include <vector>

/*
Transportation {
    air: ["Aeroplane", "Helicopter", "Jet", "Airship", "Hot Air Balloon", "Space Shuttle"],
    land: ["Car", "Truck", "Taxi", "Bus", "Train", "Ambulance", "Motorbike"],
    water: ["Ship", "Sailboat", "Yacht", "Submarine"]
}
*/

class Job
{
public:
    Job() {}

    Job(const std::string& name)
        : m_Job(name)
    {}

    static std::vector<std::string> JobsListing()
    {
        static std::vector<std::string> jobs = {
            "Pilot", "Aeronaut", "Astronaut", 
            "Truck Driver", "Taxi Driver", "Bus Driver", "Train Driver", "Paramedic", "Motorcyclist",
            "Sailor", "Submariner", "Seafarer"
        };

        return jobs;
    }

    const std::string GetJobFromListing(const std::string& name)
    {
        auto jobs_listing = JobsListing();

        for (int i = 0; i != jobs_listing.size(); i++)
        {
            if (jobs_listing[i] == name)
                return m_Job = name;
        }

        return m_Job = "ERROR";
    }

    const std::string& GetJob() // Assuming the length or size of the job is not greater than max_size
    { 
        static constexpr std::size_t max_size = 13;
        
        if (m_Job.size() >= max_size)
            return m_Job;
        
        std::size_t padding_size = max_size - m_Job.size();

        if (padding_size == max_size) // Additional if-checker when job does not actually exist
            return m_Job = "             ";

        for (int i = 0; i != padding_size; i++)
            m_Job.append(" ");

        return m_Job;
    }

private:
    std::string m_Job;
};