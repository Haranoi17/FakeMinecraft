#include <externs.hpp>
#include <dealWithCollisions.hpp>

void dealWithCollisions() 
{
	btBroadphaseProxy *playerProxy = player->playerRigidBody->getBroadphaseProxy();

	for (auto &enemy : enemies) 
	{
		btBroadphaseProxy *enemyProxy = enemy->enemyRigidBody->getBroadphaseProxy();
		
		if (dynamicsWorld->getPairCache()->findPair(playerProxy, enemyProxy)) 
		{
			player->takeDmg(enemy->dmg);
		}
		
		for (auto &bullet : bullets) 
		{
			btBroadphaseProxy *bulletProxy = bullet->getBroadphaseProxy();

			if (dynamicsWorld->getPairCache()->findPair(bulletProxy, enemyProxy)) 
			{
				dynamicsWorld->removeRigidBody(bullet);
				bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());

				if (enemy->hp - player->dmg > 0) 
				{
					enemy->takeDmg(player->dmg);
				}
				else 
				{
					dynamicsWorld->removeRigidBody(enemy->enemyRigidBody);
					enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
				}
			}
		}	
	}
}
