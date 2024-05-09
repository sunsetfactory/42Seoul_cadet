#include "Serializer.hpp"

int main(void)
{
    Data data(42, 21);
    uintptr_t serialized = Serializer::serialize(&data);
    Data *deserialized = Serializer::deserialize(serialized);

    std::cout << "Data: " << deserialized->sirialNumber << ", " << deserialized->value << std::endl;

    return 0;
}