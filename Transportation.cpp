#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <utility>

class Transportation // Base class
{
public:
    Transportation() {}

    Transportation(const std::string& name)
        : m_TransportationName(name) 
    {}

    ~Transportation() {}

    // static std::string_view SetDefaultTransportTypeName() { return "None"; }

    static std::string_view SetAirTransportTypeName(int index) // static AirTransport listing to prevent modification
    {
        static constexpr std::array names = {
            "Aeroplane", "Helicopter", "Jet", "Airship", "Hot Air Balloon", "Space Shuttle"
        };

        return names[index];
    }

    static std::string_view SetLandTransportTypeName(int index) // static LandTransport listing to prevent modification
    {
        static constexpr std::array names = {
            "Car", "Truck", "Taxi", "Bus", "Train", "Ambulance", "Motorbike"
        };

        return names[index];
    }

    static std::string_view SetWaterTransportTypeName(int index) // static WaterTransport listing to prevent modification
    {
        static constexpr std::array names = {
            "Ship", "Sailboat", "Yacht", "Submarine"
        };

        return names[index];
    }

    const std::string SetPadding() // Assuming the length or size of the transport is not greater than max_size
    {
        static constexpr std::size_t max_size = 16;

        if (m_TransportationName == "") // Additional if-checker when transport does not actually exist
            m_TransportationName = "NONE";  // If does not exists, set m_TransportationName to NONE

        if (m_TransportationName.size() >= max_size)
            return m_TransportationName;
        
        std::size_t padding_size = max_size - m_TransportationName.size(); // Getting the total padding size again 

        if (padding_size == max_size) 
            m_TransportationName = "                "; 

        for (int i = 0; i != padding_size; i++) // Appends at the end of the m_TransportationName string with the needed padding size
            m_TransportationName.append(" ");

        return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const Transportation& transport)
    {
        out << transport.m_TransportationName; // Using a friend function and operator overloading of << to get m_TransportationName from Base class. 
        return out;
    }

protected:
    std::string m_TransportationName;
};

class AirTransport : public Transportation // Derived class
{
public:
    AirTransport() {}

    AirTransport(std::string&& name) // Using r-value references and move constructors to avoid copying
        : m_Name(std::move(name))
    {}

    ~AirTransport() {}

    const std::string& GetTransportTypeName(int id)
    {
        if (id >= s_AirTransportTypeSize) // If-checker to check whether the id value is greater than 6 and assigns ERROR to m_TransportationName 
            return m_TransportationName = "ERROR"; 

        m_TransportationName = SetAirTransportTypeName(id); // Else gets the name from listing and returns it
        return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const AirTransport& air_transport)
    {;
        out << static_cast<const Transportation&>(air_transport); // Using static_cast of Derived class to Base class to get the m_TransportationName  
        return out;
    }

private:
    std::string m_Name;
    static constexpr int s_AirTransportTypeSize = 6;
};

class LandTransport : public Transportation // Derived class
{
public:
    LandTransport() {}

    LandTransport(std::string&& name) // Using r-value references and move constructors to avoid copying
        : m_Name(std::move(name))
    {}

    ~LandTransport() {}

    const std::string& GetTransportTypeName(int id)
    {
        if (id >= s_LandTransportTypeSize) // If-checker to check whether the id value is greater than 7 and assigns ERROR to m_TransportationName
            return m_TransportationName = "ERROR";

       m_TransportationName = SetLandTransportTypeName(id); // Else gets the name from listing and returns it
       return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const LandTransport& land_transport)
    {
        out << static_cast<const Transportation&>(land_transport); // Using static_cast of Derived class to Base class to get the m_TransportationName  
        return out;
    }

private:
    std::string m_Name;
    static constexpr int s_LandTransportTypeSize = 7; // Instead of using const which is done in run-time, constexpr ensures the variable is initialized in compile-time.
};

class WaterTransport : public Transportation // Derived class
{
public:
    WaterTransport() {}

    WaterTransport(std::string&& name) // Using r-value references and move constructors to avoid copying
        : m_Name(std::move(name))
    {}

    ~WaterTransport() {}

    const std::string& GetTransportTypeName(int id)
    {   
        if (id >= s_WaterTransportTypeSize) // If-checker to check whether the id value is greater than 4 and assigns ERROR to m_TransportationName
            return m_TransportationName = "ERROR"; 

        m_TransportationName = SetWaterTransportTypeName(id); // Else gets the name from listing and returns it
        return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const WaterTransport& water_transport)
    {
        out << static_cast<const Transportation&>(water_transport); // Using static_cast of Derived class to Base class to get the m_TransportationName  
        return out;
    }

private:
    std::string m_Name;
    static constexpr int s_WaterTransportTypeSize = 4; 
};