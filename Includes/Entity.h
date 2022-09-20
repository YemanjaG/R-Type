//
// Created by Gabriel de Taxis on 19/09/2022.
//

#ifndef R_TYPE_ENTITY_H
#define R_TYPE_ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>

// A simple type alias
using Entity = std::uint32_t;
using ComponentType = std::uint8_t;


// Used to define the size of arrays later on
const Entity MAX_ENTITIES = 5000;
// Used to define the size of arrays later on
const ComponentType MAX_COMPONENTS = 32;

struct Transform
{
    Vec3 position;
    Quat rotation;
    Vec3 scale;
};

class EntityManager
{
public:
    EntityManager()
    {
        // Initialize the queue with all possible entity IDs
        for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
        {
            mAvailableEntities.push(entity);
        }
    }

    Entity CreateEntity()
    {
        assert(mLivingEntityCount < MAX_ENTITIES && "Too many entities in existence.");

        // Take an ID from the front of the queue
        Entity id = mAvailableEntities.front();
        mAvailableEntities.pop();
        ++mLivingEntityCount;

        return id;
    }

    void DestroyEntity(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        // Invalidate the destroyed entity's signature
        mSignatures[entity].reset();

        // Put the destroyed ID at the back of the queue
        mAvailableEntities.push(entity);
        --mLivingEntityCount;
    }

    void SetSignature(Entity entity, Signature signature)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        // Put this entity's signature into the array
        mSignatures[entity] = signature;
    }

    Signature GetSignature(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        // Get this entity's signature from the array
        return mSignatures[entity];
    }

private:
    // Queue of unused entity IDs
    std::queue<Entity> mAvailableEntities{};

    // Array of signatures where the index corresponds to the entity ID
    std::array<Signature, MAX_ENTITIES> mSignatures{};

    // Total living entities - used to keep limits on how many exist
    uint32_t mLivingEntityCount{};
};

#endif //R_TYPE_ENTITY_H
