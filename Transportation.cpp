#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <utility>

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

    const std::string SetPadding() // Assuming the length or size of the transport is not greater than max_size
    {
        static constexpr std::size_t max_size = 16;

        if (m_TransportationName == "")
            m_TransportationName = "NONE";  

        if (m_TransportationName.size() >= max_size)
            return m_TransportationName;
        
        std::size_t padding_size = max_size - m_TransportationName.size();

        if (padding_size == max_size) // Additional if-checker when transport does not actually exist
            m_TransportationName = "                ";

        for (int i = 0; i != padding_size; i++)
            m_TransportationName.append(" ");

        return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const Transportation& transport)
    {
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

    AirTransport(std::string&& name)
        : m_Name(std::move(name))
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
    {;
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

    LandTransport(std::string&& name)
        : m_Name(std::move(name))
    {}

    ~LandTransport() {}

    const std::string& GetTransportTypeName(int id)
    {
        if (id >= s_LandTransportTypeSize)
            return m_TransportationName = "ERROR";

       m_TransportationName = SetLandTransportTypeName(id);
       return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const LandTransport& land_transport)
    {
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

    WaterTransport(std::string&& name)
        : m_Name(std::move(name))
    {}

    ~WaterTransport() {}

    const std::string& GetTransportTypeName(int id)
    {   
        if (id >= s_WaterTransportTypeSize)
            return m_TransportationName = "ERROR";

        m_TransportationName = SetWaterTransportTypeName(id);
        return m_TransportationName;
    }

    friend std::ostream& operator<<(std::ostream& out, const WaterTransport& water_transport)
    {
        out << static_cast<const Transportation&>(water_transport);
        return out;
    }

private:
    std::string m_Name;
    static constexpr int s_WaterTransportTypeSize = 4;
};