#include <iostream>
#include <sstream>

class IDGenerator // Singleton Design Pattern
{
public:
    IDGenerator(const IDGenerator&) = delete;
    void operator=(const IDGenerator&) = delete;

    static IDGenerator& GetID()
    {
        static IDGenerator s_ID;
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
        std::stringstream string_stream;
        string_stream << GenerateIDImpl();
        string_stream >> m_StringID;

        if (m_StringID.size() == 1)
            return m_StringID += " ";
        else
            return m_StringID;
    }

    IDGenerator() {};
    ~IDGenerator() {};
};