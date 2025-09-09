#include <components/Transform.hpp>

Transform::Transform() {
    std::cout << "Transform component created." << std::endl;
}

Transform::~Transform() {
    std::cout << "Transform component destroyed." << std::endl;
}

void Transform::Update(float deltaTime) {
    // Update the transformation matrix based on input or other factors
}
