#include <iostream>
#include <sstream>

class IDGenerator // Singleton Design Pattern
{
public:
    IDGenerator(const IDGenerator&) = delete; 
    void operator=(const IDGenerator&) = delete; 

    static IDGenerator& GetID() // This functions acts as the global access point that calls the GenerateIDToStringImpl() method
    {
        static IDGenerator s_ID; // Static instance so that objects are only created once.
        return s_ID;
    }

    static int GenerateID() { return GetID().GenerateIDImpl(); }
    static int GetCurrentID() { return GetID().CurrentIDImpl(); }
    static std::string GenerateIDToString() { return GetID().GenerateIDToStringImpl(); }

private:
    int m_ID = 1;
    std::string m_StringID; 
    int GenerateIDImpl() { return m_ID++; }
    int CurrentIDImpl() { return m_ID; }

    std::string GenerateIDToStringImpl()
    {
        std::stringstream string_stream; // Returning m_ID to a stringstream since it's not possible to cast an int to string
        string_stream << GenerateIDImpl();
        string_stream >> m_StringID;

        if (m_StringID.size() == 1) // Append m_StringID with extra padding as well for cleaner output table 
            return m_StringID += " ";
        else
            return m_StringID;
    }

    IDGenerator() {}; // Constructors and destructors are made private to avoid creating new objects.
    ~IDGenerator() {};
};