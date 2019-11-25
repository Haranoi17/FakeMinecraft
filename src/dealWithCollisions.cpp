#include <externs.hpp>
#include <dealWithCollisions.hpp>

void dealWithCollisions() 
{
	btBroadphaseProxy *playerProxy = player->RigidBody->getBroadphaseProxy();

	for (auto &block : blocks) 
	{
		btBroadphaseProxy *blockProxy = block->RigidBody->getBroadphaseProxy();
		
		if (dynamicsWorld->getPairCache()->findPair(playerProxy, blockProxy)) 
		{
			player->takeDmg(block->dmg);
		}
		
		for (auto &bullet : bullets) 
		{
			btBroadphaseProxy *bulletProxy = bullet->getBroadphaseProxy();

			if (dynamicsWorld->getPairCache()->findPair(bulletProxy, blockProxy)) 
			{
				dynamicsWorld->removeRigidBody(bullet);
				bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());

				if (block->hp - player->dmg > 0) 
				{
					block->takeDmg(player->dmg);
				}
				else 
				{
					dynamicsWorld->removeRigidBody(block->RigidBody);
					blocks.erase(std::remove(blocks.begin(), blocks.end(), block), blocks.end());
				}
			}
		}	
	}
}
