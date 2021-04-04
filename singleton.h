#ifndef SINGLETON_H
#define SINGLETON_H

#define IMPLEMENT_SINGLETON(className) template<> Singleton<className>::_pInstance = nullptr

template<typename T>
class Singleton
{
public:
    static T& Instance()
    {
        return *GetInstance();
    }

    static T* GetInstance()
    {
        if (_pInstance == nullptr)
        {
            _pInstance = new T();
        }

        return _pInstance;
    }

    static bool Create()
    {
        if (_pInstance == nullptr)
        {
            _pInstance = new T();
        }

        return _pInstance != nullptr;
    }

    static void Destroy()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

protected:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    static T* _pInstance;
}

#endif // SINGLETON_H
