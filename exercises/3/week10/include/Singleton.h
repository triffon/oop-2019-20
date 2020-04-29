#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
    private:
        ///  Here will be the instance stored.
        static Singleton* instance;
        /// The data of the singleton that holds. Could be anything. I am using int for simplicity
        int data;
        /// Private constructor to prevent instancing from the outside world.
        Singleton();

    public:
        /// trivial getters and setters
        int getData()const;
        void setData(int data);
        /// Static access method.
        static Singleton* getInstance();
};

#endif // SINGLETON_H
