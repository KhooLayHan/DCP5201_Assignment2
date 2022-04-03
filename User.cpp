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
        static constexpr std::size_t max_size = 8; // Is initialized in compile-time rather than in run-time with constexpr keyword, and static makes it not modifiable
        
        if (m_Name.size() >= max_size)
            return m_Name;
        
        std::size_t padding_size = max_size - m_Name.size(); // Get the padding size needed to tell the code how much extra padding is needed.

        if (padding_size == max_size) // Returns an "empty" m_Name string with size of 8.
            return m_Name = "        ";

        for (int i = 0; i != padding_size; i++) // Append extra padding to m_Name by default so output table looks clean
            m_Name.append(" ");

        return m_Name;
    }
    
    void SetName(const std::string& name) { m_Name = name; } // Mutator functions

    friend User operator<<(std::ostream& out, const User& user);

private:
    std::string m_Name;
};

// User operator<<(std::ostream& out, const User& user)
// {
//     return user.GetName();
// }