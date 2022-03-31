#pragma once
#include "ECS.h"
#include <memory>
#include <vector>
#include "Component.h"
#include "Transform.h"
#include "EntityManager.h"
class EntityManager;
class Entity
{
private:
    EntityManager& manager;
public:
    Entity(EntityManager &mManager): manager{ mManager } {}
    Entity() = default;
    virtual ~Entity() = default;
    template <typename T, typename... TArgs> 
    inline T& addComponent(TArgs &&...args) {
        T* comp(new T(forward<TArgs>(args)...));
        
        unique_ptr<Component> uPtr{ comp };
        components.emplace_back(move(uPtr));
        comp->entity = this;
        if (comp->init())
        {
            comp->entity = this;
            compList[getComponentTypeID<T>()] = comp;
            compBitset[getComponentTypeID<T>()] = true;
            
            return *comp;
        } 
        else
            return *static_cast<T*>(nullptr);
       ;
    
        
    }
    template <typename T> 
    inline  T& getComponent() const {
        auto ptr(compList[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
    template <typename T> 
    inline bool hasComponent() const {
        return compBitset[getComponentTypeID<T>()];
    }
    inline bool isActive() const { return active; }
    inline void destroy() { active = false; }

    inline void update() {
        for (auto& c : components)
            c->update();
    }
    inline void draw() {
        for (auto& c : components)
            c->draw();
    };
    inline bool hasGroup(Group mGroup)
    {
        return groupBitset[mGroup];
    }
    inline void addGroup(Group mGroup)
    {
        groupBitset[mGroup] = true;
        manager.AddToGroup(this, mGroup);
    }
    inline void delGroup(Group mGroup)
    {
        groupBitset[mGroup] = false;
    }
private:
    bool active = true;
	ComponentList compList;
	ComponentBitset compBitset;
    GroupBitset groupBitset;
	vector<unique_ptr<Component>> components;
   
};