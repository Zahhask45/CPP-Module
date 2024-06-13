#include "Serializer.hpp"

int main(void) {
    Data *data = new Data;
    data->bana = 42;
    data->na = "Hello World";

    uintptr_t dataSerialized = Serializer::serialize(data);
    Data *dataDeserialized = Serializer::deserialize(dataSerialized);

    std::cout << "Data bana: " << dataDeserialized->bana << std::endl;
    std::cout << "Data na: " << dataDeserialized->na << std::endl;
    if (dataDeserialized->bana == data->bana && dataDeserialized->na \
    == data->na) {
        std::cout << "Data deserialized is the same as data serialized" \
        << std::endl;
    } else {
        std::cout << "Data deserialized is not the same as data serialized" \
        << std::endl;
    }
    delete data;

    return (0);
}
