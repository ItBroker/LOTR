#include "EntityManager.h"
#include "Entity.h"
void EntityManager::update()
{
	for (auto& e : entities)
		e->update();
}

void EntityManager::draw()
{
	for (auto& e : entities)
		e->draw();
}

void EntityManager::refresh()
{
	for (auto i(0u); i < maxEntities; i++)
	{
		auto& v(gropedEntities[i]);
		v.erase(
			remove_if(begin(v), end(v),
				[i](Entity* mEntity)
				{
					return!mEntity->isActive() || !mEntity->hasGroup(i);
				}), 
			end(v));
	}
	entities.erase(remove_if(begin(entities), end(entities),
		[](const unique_ptr<Entity>& mEntity) {
			return !mEntity->isActive();
		}),
		end(entities));
}

void EntityManager::addEntity(Entity* player)
{	
	unique_ptr<Entity> uPtr{ player };
	entities.emplace_back(move(uPtr));
}

void EntityManager::eraseEntity(Entity* player)
{

}
Entity& EntityManager::addEntity1() {
	Entity* e = new Entity(*this);
	unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(move(uPtr));
	return *e;
}
Entity* EntityManager::cloneEntity(Entity* player)
{

	return nullptr;
}

void EntityManager::AddToGroup(Entity* mEntity, Group mGroup)
{
	gropedEntities[mGroup].emplace_back(mEntity);
}

vector<Entity*>& EntityManager::getGroup(Group mGroup)
{
	return gropedEntities[mGroup];
}
