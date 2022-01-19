#ifndef WRAPPER_H
#define WRAPPER_H


template< class T>
class Wrapper
{
public:
    Wrapper()
    { DataPtr=nullptr;}

    Wrapper(const T& inner)
    {
        DataPtr = inner.clone();
    }

    ~Wrapper()
    {
        if (DataPtr !=0)
            delete DataPtr;
    }

    Wrapper(const Wrapper<T>& original)
    {
        if (original.DataPtr !=0)
            DataPtr = original.DataPtr->clone();
        else
            DataPtr=nullptr;
    }

    Wrapper& operator=(const Wrapper<T>& original)
    {
        if (this != &original)
        {
            if (DataPtr!=0)
                delete DataPtr;
            DataPtr = (original.DataPtr != nullptr) ?
                        original.DataPtr->clone() :  nullptr;
        }
        return *this;
    }

    T& operator*()
    {
        return *DataPtr;
    }

    const T& operator*() const
    {
        return *DataPtr;
    }
    const T* const operator->() const
    {
        return DataPtr;
    }
    T* operator->()
    {
        return DataPtr;
    }
private:
    T* DataPtr;
};

#endif // WRAPPER_H
