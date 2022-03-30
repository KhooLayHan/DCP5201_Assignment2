#include <string>

class User
{
public:
    User() {}

    User(const std::string& name)
        : m_Name(name)
    {}

    ~User() {}

    const std::string& GetName() const { return m_Name; }
    void SetName(const std::string& name) { m_Name = name; }

    friend User operator<<(std::ostream& out, const User& user);

private:
    std::string m_Name;
};

// User operator<<(std::ostream& out, const User& user)
// {
//     return user.GetName();
// }