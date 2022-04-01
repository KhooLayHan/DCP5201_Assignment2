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
            if (jobs_listing[i] != name)
            {
                return "Can't find specify job from job listing!\n";
            }   

            return m_Job = name;
        }

        return "None";
    }

    const std::string& GetJob() const { return m_Job; }
    void SetName(const std::string& job) { m_Job = job; }

private:
    std::string m_Job;
};