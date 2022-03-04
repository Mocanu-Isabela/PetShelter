#ifndef DOG_H_EXCEPTIONS_H
#define DOG_H_EXCEPTIONS_H

using namespace std;

class Exception : public exception
{
private:
    string _message;
public:
    Exception(const string& message) : _message(message){}
    const char* what() const noexcept override
    {
        return _message.c_str();
    }
};

#endif //DOG_H_EXCEPTIONS_H
