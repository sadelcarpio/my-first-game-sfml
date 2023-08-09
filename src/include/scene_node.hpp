#pragma once

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

/**
 * Allows for a tree structure of drawable scenes. Each SceneNode can have multiple children, and allows working with
 * orientation/position (transforms) wrt the parent SceneNode instead of absolute values.
 */
class SceneNode : public sf::Transformable, public sf::Drawable,
                  private sf::NonCopyable {
public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    /**
     * Constructor. mChildren (default: empty vector) and mParent (default: nullptr) are passed as initialization list
     */
    SceneNode();

    /**
     * Attaches a child into the SceneNode.
     * @param child is a unique pointer to a SceneNode
     */
    void attachChild(Ptr child);

    /**
     * Detaches a child from the SceneNode
     * @param node child SceneNode to detach
     * @return the detached SceneNode
     */
    Ptr detachChild(const SceneNode &node);

    /**
     * Updates the complete tree of the SceneNode by calling both updateCurrent and updateChildren
     * @param dt constant time per frame
     */
    void update(sf::Time dt);

    sf::Transform getWorldTransform() const;

    sf::Vector2f getWorldPosition() const;

private:
    /**
     * Draws the complete tree of SceneNodes.
     * @param target where the tree is going to be drawn on (a RenderWindow)
     * @param states additional information about rendering (blend mode, transform, used texture/shader)
     */
    void draw(sf::RenderTarget &target,
              sf::RenderStates states) const override;  // allows for internal use when calling `window.draw(*node)`

    /**
     * Draws the current SceneNode. Implementation depends on the specific type of drawable
     * @param target where the tree is going to be drawn on (a RenderWindow)
     * @param states additional information about rendering (blend mode, transform, used texture/shader)
     */
    virtual void drawCurrent(sf::RenderTarget &target,
                             sf::RenderStates states) const;

    /**
     * Draws all children of a SceneNode. Since it is a tree it goes recurrently drawing until no children is left.
     * @param target where the tree is going to be drawn on (a RenderWindow)
     * @param states additional information about rendering (blend mode, transform, used texture/shader)
     */
    void drawChildren(sf::RenderTarget &target, sf::RenderStates states) const;

    /**
     * Update attributes of current SceneNode
     * @param dt constant time per frame
     */
    virtual void updateCurrent(sf::Time dt);

    /**
     * Update attributes of the children of SceneNode
     * @param dt constant time per frame
     */
    void updateChildren(sf::Time dt);

private:
    std::vector<Ptr> mChildren;
    SceneNode *mParent;
};
