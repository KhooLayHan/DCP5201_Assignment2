#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <vector>

class Transportation 
{
public:
    Transportation() {}

    Transportation(const std::string& name)
        : m_TransportationName(name) 
    {}

    ~Transportation() {}

    // static std::string_view SetDefaultTransportTypeName() { return "None"; }

    static std::string_view SetAirTransportTypeName(int index)
    {
        static constexpr std::array names = {
            "Aeroplane", "Helicopter", "Jet", "Airship", "Hot Air Balloon", "Space Shuttle"
        };
   
        return names[index];
    }
    
    static std::string_view SetLandTransportTypeName(int index)
    {
        static constexpr std::array names = {
            "Car", "Truck", "Taxi", "Bus", "Train", "Ambulance", "Motorbike"
        };
   
        return names[index];
    }
    
    static std::string_view SetWaterTransportTypeName(int index)
    {
        static constexpr std::array names = {
            "Ship", "Sailboat", "Yacht", "Submarine"
        };
   
        return names[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const Transportation& transport)
    {
        //out << "From Transportation base class\n";
        out << transport.m_TransportationName;
        return out;
    }

protected:
    std::string m_TransportationName;
};

class AirTransport : public Transportation
{
public:
    AirTransport() {}

    AirTransport(const std::string& name)
        : m_Name{ name }
    {}

    ~AirTransport() {}

    const std::string& GetTransportTypeName(int id)
    {
        if (id >= s_AirTransportTypeSize)
            return m_TransportationName = "ERROR";
    
        m_TransportationName = SetAirTransportTypeName(id);
        return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const AirTransport& air_transport)
    {
        //out << "Hello! I'm from AirTransport\n";
        out << static_cast<const Transportation&>(air_transport);
        return out;
    }

private:
    std::string m_Name;

    static constexpr int s_AirTransportTypeSize = 6;
};

class LandTransport : public Transportation
{
public:
    LandTransport() {}

    LandTransport(const std::string& name)
        : m_Name{ name }
    {}

    ~LandTransport() {}

    const std::string& GetTransportTypeName(int id)
    {
        if (id >= s_LandTransportTypeSize)
            return m_TransportationName = "ERROR";

       return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const LandTransport& land_transport)
    {
        //out << "Hello! I'm from LandTransport\n";
        out << static_cast<const Transportation&>(land_transport);
        return out;
    }

private:
    std::string m_Name;

    static constexpr int s_LandTransportTypeSize = 7;
};

class WaterTransport : public Transportation
{
public:
    WaterTransport() {}

    WaterTransport(const std::string& name)
        : m_Name(name)
    {}

    ~WaterTransport() {}

    const std::string& GetTransportTypeName(int id)
    {   
        if (id >= s_WaterTransportTypeSize)
            return m_TransportationName = "ERROR";

        return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const WaterTransport& water_transport)
    {
        //out << "Hello! I'm from WaterTransport\n";
        out << static_cast<const Transportation&>(water_transport);
        return out;
    }

private:
    std::string m_Name;

    static constexpr int s_WaterTransportTypeSize = 4;
};