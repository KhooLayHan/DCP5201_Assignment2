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
    enum class Land
    {
        CAR = 0,
        TRUCK = 1,
        TAXI = 2,
        BUS = 3,
        TRAIN = 4,
        AMBULANCE = 5,
        MOTORBIKE = 6,
        MAX_SIZE = 7
    }; 

    LandTransport() {}

    LandTransport(Land type)
        : m_Type(type)
    {}

    LandTransport(int land_id)
        : m_Type(static_cast<Land>(land_id))
    {}

    ~LandTransport() {}

    const std::string& GetTransportTypeName(int id)
    {
        if (id >= (int)Land::MAX_SIZE)
        {
            std::cout << "Land Transport ID is not available!\n";
            return m_TransportationName = " ";
        }

       // m_TransportationName = SetTransportTypeName(id).at(static_cast<std::size_t>(m_Type));
       return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const LandTransport& land_transport)
    {
        out << "Hello! I'm from LandTransport\n";
        out << static_cast<const Transportation&>(land_transport);
        return out;
    }

private:
    Land m_Type;
    std::string m_Name;

    static constexpr int s_LandTransportTypeSize = 7;
};

class WaterTransport : public Transportation
{
public:
    enum class Water
    {
        SHIP = 0,
        SAILBOAT = 1,
        YACHT = 2,
        SUBMARINE = 3,
        MAX_SIZE = 4
    };

    WaterTransport() {}

    WaterTransport(Water type)
        : m_Type(type)
    {}

    WaterTransport(int water_id)
        : m_Type(static_cast<Water>(water_id))
    {}

    ~WaterTransport() {}

    const std::string& GetTransportTypeName(int id)
    {   
        if (id >= (int)Water::MAX_SIZE)
        {
            std::cout << "Water Transport ID NOT AVAILABLE!\n";
            return m_TransportationName = " ";
        }

      //  m_TransportationName = SetTransportTypeName(id).at(static_cast<std::size_t>(m_Type));
        return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const WaterTransport& water_transport)
    {
        out << "Hello! I'm from WaterTransport\n";
        out << static_cast<const Transportation&>(water_transport);
        return out;
    }

private:
    Water m_Type;
    std::string m_Name;

    static constexpr int s_AirTransportTypeSize = 4;
};