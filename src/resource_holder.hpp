#pragma once

#include <map>
#include <memory>
#include <string>
#include <cassert>
#include <SFML/Graphics.hpp>


template<typename Resource, typename Identifier>
class ResourceHolder {
public:
    void load(Identifier id, const std::string &filename);

    template<typename Parameter>
    void load(Identifier id, const std::string &filename, const Parameter &secondParam);

    Resource &get(Identifier id);

    const Resource &get(Identifier id) const;  // in order to work with const

private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;  // unique_ptr does not need a destructor (smart pointer)
};

#include "resource_holder.inl"