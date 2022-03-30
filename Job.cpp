#include <ctime>
#include <iostream>
#include <string>
#include <vector>

int GetRandomJobListing(int min, int max)
{   
    static constexpr double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

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
    Job() 
    {
        for (int i = 0; i != s_JobsLength; i++)
        {
            m_Job = JobsListing(GetRandomJobListing(0, s_JobsLength));
            m_JobListing.push_back(m_Job);
        }
    }

    Job(const std::string& name)
        : m_Job(name)
    {}

    static std::string& JobsListing(int index)
    {
        static std::string jobs[] = {
            "Pilot", "Aeronaut", "Astronaut", 
            "Truck Driver", "Taxi Driver", "Bus Driver", "Train Driver", "Paramedic", "Motorcyclist",
            "Sailor", "Submariner", "Seafarer"
        };

        return jobs[index];
    }
    
    const std::string& GetJob() const { return m_Job; }
    const std::string& GetJob(int index) const { return m_JobListing[index]; }

    void SetName(const std::string& job) { m_Job = job; }

private:
    std::string m_Job;
    static constexpr int s_JobsLength = 10;
    std::vector<std::string> m_JobListing;
};