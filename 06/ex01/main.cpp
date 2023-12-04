#include <iostream>


typedef struct Data
{
    int a;
    int b;
} df;

uintptr_t serialize(df* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
};

df* deserialize(uintptr_t raw)
{
    return reinterpret_cast<df *>(raw);
};

int main()
{
    df f;

    f.a = 5;
    f.b = 9;
    df *b = deserialize(serialize(&f));
    std::cout << b->a << "\n" <<  b->b << "\n";
    return 0;
}