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

    static std::vector<std::string> JobsListing() // Vector function is made static to prevent modifying it
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
            if (jobs_listing[i] == name) // If manage to search up the name from listing, set it to m_Job and returns it
                return m_Job = name;
        }

        return m_Job = "ERROR"; // Else set m_Job to ERROR and returns it
    }

    const std::string& GetJob() // Assuming the length or size of the job is not greater than max_size
    { 
        static constexpr std::size_t max_size = 13;
        
        if (m_Job == "") // Additional if-checker when job does not actually exist
            m_Job = "NONE";  

        if (m_Job.size() >= max_size)
            return m_Job;
        
        std::size_t padding_size = max_size - m_Job.size(); // Again, getting the padding size to determine the amount of padding needed.

        if (padding_size == max_size) 
            return m_Job = "             ";

        for (int i = 0; i != padding_size; i++) // Appends the extra padding to each m_Job based on the amount
            m_Job.append(" ");

        return m_Job;
    }

    void SetJob(const std::string& job) { m_Job = job; } // Mutator functions

private:
    std::string m_Job;
};