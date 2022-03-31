#pragma once
#include<vector>
#include<memory>

#include "ECS.h"
using namespace std;

class EntityManager {
private:
    vector<unique_ptr<Entity>> entities;
    array<vector<Entity*>, maxEntities> gropedEntities;
public:
    EntityManager() = default;
    ~EntityManager() = default;
    void update();
    void draw();
    void refresh();
    void addEntity(Entity* player);
    void eraseEntity(Entity* player);
    Entity* cloneEntity(Entity* player);
    Entity& addEntity1();
    void AddToGroup(Entity* mEntity, Group mGroup);
    vector<Entity*>& getGroup(Group mGroup);
};