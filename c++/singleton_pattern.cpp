#include <iostream>

class Singleton
{
    private:
        // Instance
        static Singleton* pInstance_;
        Singleton() = default;
        ~Singleton() = default;

    public:
        Singleton(const Singleton&) = delete;
        Singleton(const Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        // Static access method
        static Singleton* getInstance();
};

Singleton* Singleton::pInstance_ = 0;

Singleton* Singleton::getInstance()
{
    // Thread-safe from C++11. One thread initialize, other threads will wait till it complete.
    // 静的ローカル変数を利用すると、実装は楽だがインスタンスの削除タイミングを制御できない
    static Singleton instance;

    return &instance;
}

/*
Singleton* Singleton::getInstance()
{
    // Thread-safeでない double-checked lockingを実装する必要あり
    // if NULL
    if (pInstance_ == 0)
    {
        pInstance_ = new Singleton();
    }
    return pInstance_;
}
*/

int main()
{
    // new Singleton(); -> not working -> private constructor
    Singleton* s = Singleton::getInstance(); // Ok
    Singleton* r = Singleton::getInstance();

    // The addresses will be the same -> static
    std::cout << s << std::endl;
    std::cout << r << std::endl;
    return 0;
}
