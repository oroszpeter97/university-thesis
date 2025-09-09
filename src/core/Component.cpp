#include <core/Component.hpp>

Component::Component() {
    std::cout << "Component created." << std::endl;
}

Component::~Component() {
    std::cout << "Component destroyed." << std::endl;
}
