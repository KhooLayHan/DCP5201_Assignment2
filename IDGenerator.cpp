#include <iostream>

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

private:
    int m_ID = 1; 
    int GenerateIDImpl() { return m_ID++; }
    int CurrentIDImpl() { return m_ID; }

    IDGenerator() {};
    ~IDGenerator() {};
};