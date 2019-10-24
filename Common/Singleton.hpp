#pragma once
template <typename T>
class Singleton
{
public:
    T &instance()
    {
        static T t;
        return t;
    }
    virtual ~Singleton() {}

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

protected:
    Singleton() {}
};