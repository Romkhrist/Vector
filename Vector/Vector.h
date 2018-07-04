#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <cstring>
#include <cstddef>

template<typename T>
class Vector
{   
    public:
        Vector(const std::size_t size = 5);
        Vector(const Vector<T>& v);

        ~Vector();

        void push_back(const T& value);
        void pop_back();
        void insert(const std::size_t& index, const T& value);
        void reserve(const std::size_t& size);
        
        inline std::size_t length() const;
        inline std::size_t capacity() const;
        inline std::size_t get_Rate() const;
        inline void        set_Rate(const std::size_t& rate);

        T          operator[](const std::size_t& index) const;
        Vector<T>& operator=(const Vector<T>& v);

    private:        
        std::size_t size;                        //capacity of v
        std::size_t count;                       //count of added elements
        std::size_t rate;                        //rate of v array size increasing
        T           *arr;                        //heart of v - dynamic array

        template<typename T1>
        friend std::ostream& operator<<(std::ostream& out, const Vector<T1>& v);
};

//public members {

template<typename T>
Vector<T>::Vector(const std::size_t size)
    :size(size), count(0), rate(5)
{
    arr = new T[size];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v)
    :size(v.size), count(v.count), rate(v.rate)
{
    arr = new T[size];
    memmove(arr, v.arr, sizeof(T) * count);
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] arr;
    arr = nullptr;
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
    if(count == size)
    {
        reserve(size + rate);
    }
    
    arr[count++] = value;
}

template<typename T>
void Vector<T>::pop_back()
{
    if(!count)
    {
        return;
    }
    
    count--;
}

template<typename T>
void Vector<T>::insert(const std::size_t& index, const T& value)
{
    if(index >= count || index < 0)
    {
        throw "Incorrect index!";
    }
    
    if(count == size)
    {
        reserve(size + rate);
    }
    
    for(std::size_t i = count - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = value;
    count++;
}

template<typename T>
void Vector<T>::reserve(const std::size_t& size)
{
    if(size <= 0)
    {
        return;
    }
    
    this->size = size;
    T *new_arr = new T[size];
    memmove(new_arr, arr, sizeof(T) * count);
    delete arr;
    arr = new_arr;
}

template<typename T>
inline std::size_t Vector<T>::length() const
{
    return count;
}

template<typename T>
inline std::size_t Vector<T>::capacity() const
{
    return size;
}

template<typename T>
inline std::size_t Vector<T>::get_Rate() const
{
    return rate;
}

template<typename T>
inline void Vector<T>::set_Rate(const std::size_t& rate)
{
    if(rate <= 0)
    {
        return;
    }
    
    this->rate = rate;
}

template<typename T>
T Vector<T>::operator[](const std::size_t& index) const
{
    if(index >= count)
    {
        throw "Index out of range!";
    }
    
    return arr[index];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    size  = v.size;
    count = v.count;
    
    delete[] arr;
    arr = new T[size];
    memmove(arr, v.arr, count * sizeof(T));
    
    return *this;
}

//} public members

//friends {

template<typename T1>
std::ostream& operator<<(std::ostream& out, const Vector<T1>& v)
{
    for(std::size_t i = 0; i < v.length(); i++)
    {
        out << v[i] << " ";
    }
    
    return out;
}

//} friends

#endif
