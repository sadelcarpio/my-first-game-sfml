template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &filename) {
    std::unique_ptr<Resource> texture(new Resource());
    if (!texture->loadFromFile(filename))
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);  // assert that second element is true (element was successfully inserted. only works in debug
}

template<typename Resource, typename Identifier>
template<typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &filename,
                                                const Parameter &secondParam) {
    std::unique_ptr<Resource> texture(new Resource());
    if (!texture->loadFromFile(filename, secondParam))
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
}

template<typename Resource, typename Identifier>
Resource &ResourceHolder<Resource, Identifier>::get(Identifier id) {
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *(found->second);
}

template<typename Resource, typename Identifier>
const Resource &ResourceHolder<Resource, Identifier>::get(Identifier id) const {
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *(found->second);
}
