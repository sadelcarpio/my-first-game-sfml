#include <algorithm>
#include <cassert>
#include "include/scene_node.hpp"

SceneNode::SceneNode() : mChildren(), mParent(nullptr) {
}


void SceneNode::attachChild(SceneNode::Ptr child) {
    child->mParent = this;  // `this` is a pointer to the object
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node) {
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
                              [&](Ptr &p) -> bool {
                                  return p.get() == &node;
                              }); // [&] means return the reference to the filter results
    // Ptr& p is the argument of the filter function
    assert(found != mChildren.end());
    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // Apply total transform
    states.transform *= getTransform();  // overloaded operator, getTransform() inherits from Transformable class

    // Draw node and children with changed transform
    drawCurrent(target, states);
    drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    // do noting, leave it to the specific type of node
}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const Ptr &child: mChildren) {
        child->draw(target, states);
    }
}

void SceneNode::update(sf::Time dt) {
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt) {
}

void SceneNode::updateChildren(sf::Time dt) {
    for (const Ptr &child: mChildren) {
        child->update(dt);
    }
}

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;
    for (const SceneNode* node = this; node != nullptr; node = node->mParent) {
        transform = node->getTransform() * transform;
    }
    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return getWorldTransform() * sf::Vector2f();
}
