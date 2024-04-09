#include "shared_ptr_toy.h"


shared_ptr_toy::shared_ptr_toy()
{
    object = nullptr;
}
shared_ptr_toy::shared_ptr_toy(std::string& name)
{
    object = new Toy(name);
    count++;
}


shared_ptr_toy::shared_ptr_toy(Toy& other)
{
    object = new Toy(other);
}


// shared_ptr_toy::~shared_ptr_toy()
// {
//     delete object;
//     count--;
// }

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& other)
{
    if (this == &other) return *this;

    if (object != nullptr) delete object;
    object = new Toy(*other.object);
    count++;
    return *this;
}

bool shared_ptr_toy::operator==(const shared_ptr_toy& other)
{
    return this == &other;
}

shared_ptr_toy::operator bool()
{
    return object != nullptr;
}

int shared_ptr_toy::use_count()
{
    return count;
}

// void shared_ptr_toy::reset() 
// {
//     count = 0;
//     delete object;
// }


/* ================================= */

shared_ptr_toy make_shared_toy(const Toy& inToy)
{
    Toy* newToy = new Toy(inToy);
    return shared_ptr_toy(*newToy);
}

shared_ptr_toy make_shared_toy(std::string inName)
{
    Toy* newToy = new Toy(inName);
    return shared_ptr_toy(*newToy);
}