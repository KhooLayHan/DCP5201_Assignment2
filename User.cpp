#include <iostream>
#include <string>

class User
{
public:
    User() {}

    User(const std::string& name) // Constructor to initialize the username
        : m_Name(name)
    {}

    ~User() {}

    const std::string& GetName() // Assuming the length or size of the username is not greater than max_size
    {
        static constexpr std::size_t max_size = 8;
        
        if (m_Name.size() >= max_size)
            return m_Name;
        
        std::size_t padding_size = max_size - m_Name.size();

        for (int i = 0; i != padding_size; i++)
            m_Name.append(" ");

        return m_Name;
    }
    
    void SetName(const std::string& name) { m_Name = name; }

    friend User operator<<(std::ostream& out, const User& user);

private:
    std::string m_Name;
};

// User operator<<(std::ostream& out, const User& user)
// {
//     return user.GetName();
// }