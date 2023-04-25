#pragma once

#include <map>
#include <memory>
#include <string>
#include <cassert>
#include <SFML/Graphics.hpp>

/**
 * Template that gives a way to interact with different types of resources like Textures, Fonts, Music, etc.
 * @tparam Resource The type of resource. e.g. sf::Texture, sf::Font, etc.
 * @tparam Identifier A way to identify the specific resource. Could be an enum, string, etc.
 */
template<typename Resource, typename Identifier>
class ResourceHolder {
public:
    /**
     * Loads resource from a file
     * @param id Is the id that we want to assign to the resource, to create an \<ID, Resource> map
     * @param filename Is the filepath (path relative to executable path)
     */
    void load(Identifier id, const std::string &filename);

    /**
     * Loads resource from a file
     * @param id Is the id that we want to assign to the resource, to create an `\<ID, Resource>` map
     * @param filename Is the filepath (path relative to executable path)
     * @param secondParam Is an optional parameter, in the case the particular Resource has more parameters
     * in loadFromFile, like sf::Shader
     */
    template<typename Parameter>
    void load(Identifier id, const std::string &filename, const Parameter &secondParam);

    /**
     * Queries a Resource from the mResourceMap, by its id
     * @param id The unique identifier of the resource
     * @return The associated unique pointer to the Resource (sf::Texture, sf::Font, sf::Shader, etc)
     */
    Resource &get(Identifier id);

    /**
     * Queries a Resource from the mResourceMap, by its id
     * @param id The unique identifier of the resource
     * @return The associated unique pointer to the Resource (sf::Texture, sf::Font, sf::Shader, etc) as a const
     */
    const Resource &get(Identifier id) const;  // const at the beginning means return a const object
    // const at the end means it can't modify member variables

private:
    void insertResource(Identifier id, std::unique_ptr<Resource> resource);

private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;  // unique_ptr does not need a destructor (smart pointer)
};

#include "resource_holder.inl"
