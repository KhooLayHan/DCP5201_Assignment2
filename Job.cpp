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
    Job() {}

    Job(const std::string& name)
        : m_Job(name)
    {}

    const std::string GetJobFromListing(const std::string& name)
    {
        static std::vector<std::string> jobs = {
            "Pilot", "Aeronaut", "Astronaut", 
            "Truck Driver", "Taxi Driver", "Bus Driver", "Train Driver", "Paramedic", "Motorcyclist",
            "Sailor", "Submariner", "Seafarer"
        };

        for (int i = 0; i != jobs.size(); i++)
        {
            if (jobs[i] == name)
            {
                //std::cout << name << " " << i;   
                m_Job = name;
                return m_Job;
            }
            else 
            {
                //std::cout << D
            }
        }

        return "Can't find specify name from job listing!";
    }

    const std::string& GetJob() const { return m_Job; }
    const std::string& GetJob(int index) const { return m_JobListing[index]; }

    void SetName(const std::string& job) { m_Job = job; }

private:
    std::string m_Job;
    std::vector<std::string> m_JobListing;
};