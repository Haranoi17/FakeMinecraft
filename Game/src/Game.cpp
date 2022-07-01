#include "Game.hpp"
#include "Vector3f.hpp"
#include "Utilities.hpp"
#include <functional>

Game::Game()
{
	const sf::VideoMode videoMode{windowSize.x, windowSize.y};
	const sf::ContextSettings context{24, 8, 2};

	m_window.create(videoMode, title, windowStyle, context);

	glewInit();
	initValues();
	initOpenGL();
	initVO();
	reshapeScreen();

	world.prepareBlocksWithAirTouch(player);
	world.prepareToDraw(player);
	prepareMatrices();
}

sf::Time Game::deltaTime()
{
	return updateClock.getElapsedTime();
}

bool Game::isRunning()
{
	return isGameRunning;
}

void Game::startLogic()
{
	std::function<void()> eventHandlingLoop{
		[this]()
		{
			while (isRunning())
			{
				handleEvents();
			}
			m_eventsFinnished = true;
		}};

	std::function<void()> updateLoop{
		[this]()
		{
			while (isRunning())
			{
				const float dt{deltaTime().asSeconds()};
				update(dt);
				// placingAndRemovingBlocks();
				// if (Vector3f{player.position - renderPoint}.length() > 10)
				// {
				// 	needToRefreshBlocks = true;
				// }
				// prepareMatrices();
				// world.prepareBlocksWithAirTouch(player);

				// reRenderWorld();
			}
			m_updateFinnished = true;
		}};

	m_threads.emplace_back(eventHandlingLoop);
	m_threads.emplace_back(updateLoop);

	for (auto &thread : m_threads)
	{
		thread.detach();
	}
}

void Game::drawLoop()
{
	while (isRunning())
	{
		draw();
	}
}

void Game::waitForThreadsToFinnish()
{
	while (!m_updateFinnished && !m_eventsFinnished)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds{50});
	}
}

void Game::initVO()
{
	glGenBuffers(3, VBO.data());
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData), cubeData, GL_STREAM_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(5 * sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	matrices = new glm::mat4[1];
	blockTypes = new float[1];
	prepareMatrices();
	reRenderWorld();
}

void Game::prepareMatrices()
{
	usingPreparedBlocks = true;
	if (!preparingMatrices)
	{
		preparingMatrices = true;
		delete[] matrices;
		delete[] blockTypes;
		world.prepareToDraw(player);

		matrices = new glm::mat4[world.ammountToDraw];
		blockTypes = new float[world.ammountToDraw];
		int iterator = 0;
		sf::Clock test;
		for (Block *block : world.blocksToDraw)
		{
			if (block->m_type != Block::Type::Air)
			{
				blockTypes[iterator] = static_cast<float>(block->m_type);
				matrices[iterator] = glm::translate(glm::mat4(1), glm::vec3(block->m_position.x, block->m_position.y, block->m_position.z));
				iterator++;
			}
		}
		matricesReady = true;
		preparingMatrices = false;
	}
	usingPreparedBlocks = false;
}

void Game::reRenderWorld()
{
	if (matricesReady)
	{
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
		glBufferData(GL_ARRAY_BUFFER, world.ammountToDraw * sizeof(glm::mat4), matrices, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void *)0);
		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void *)sizeof(glm::vec4));
		glEnableVertexAttribArray(5);
		glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void *)(2 * sizeof(glm::vec4)));
		glEnableVertexAttribArray(6);
		glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void *)(3 * sizeof(glm::vec4)));

		glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
		glBufferData(GL_ARRAY_BUFFER, world.ammountToDraw * sizeof(float), blockTypes, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(7);
		glVertexAttribPointer(7, 1, GL_FLOAT, GL_FALSE, sizeof(float), (void *)0);

		glVertexAttribDivisor(3, 1);
		glVertexAttribDivisor(4, 1);
		glVertexAttribDivisor(5, 1);
		glVertexAttribDivisor(6, 1);
		glVertexAttribDivisor(7, 1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		matricesReady = false;
	}
}

void Game::initValues()
{
	dirtTexture = resourceLoader.loadTexture("dirt.jpg");
	woodTexture = resourceLoader.loadTexture("wood.jpg");
	stoneTexture = resourceLoader.loadTexture("stone.png");
	grassTexture = resourceLoader.loadTexture("grass.jpg");
	leavesTexture = resourceLoader.loadTexture("leaves.png");
	skyboxTexture = resourceLoader.loadTexture("skybox.jpeg");
	grassTopTexture = resourceLoader.loadTexture("grassTop.png");

	playerShader = resourceLoader.loadShader("playerShader.vert", "playerShader.frag");
	playerShader.viewLoc = glGetUniformLocation(playerShader.getID(), "view");
	playerShader.modelLoc = glGetUniformLocation(playerShader.getID(), "model");
	playerShader.projectionLoc = glGetUniformLocation(playerShader.getID(), "projection");

	blockShader = resourceLoader.loadShader("blockShader.vert", "blockShader.frag");
	blockShader.projectionLoc = glGetUniformLocation(blockShader.getID(), "projection");
	blockShader.viewLoc = glGetUniformLocation(blockShader.getID(), "view");

	playerShader.use();
	glUniform1i(glGetUniformLocation(playerShader.getID(), "tex0"), 15);

	blockShader.use();
	for (std::vector textureNames{"grassTop", "grassSide", "dirt", "stone", "wood", "leaves"};
		 const auto &[i, textureName] : enumerate(textureNames))
	{
		const GLuint textureLocation = glGetUniformLocation(blockShader.getID(), textureName);
		glUniform1i(textureLocation, i);
	}

	m_window.setMouseCursorVisible(false);
}
void Game::endGracefully()
{
	isGameRunning = false;
}

void Game::handleEvents()
{
	sf::Event event;
	m_window.waitEvent(event);
	
	switch (event.type)
	{
	case sf::Event::Closed:
		isGameRunning = false;
		break;
	case sf::Event::Resized:
		reshapeScreen();
		break;
	}
}

void Game::reshapeScreen()
{
	projection = glm::mat4(1);
	const sf::Vector2u windowSize{m_window.getSize().x, m_window.getSize().y};
	const float aspect = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
	glViewport(0, 0, windowSize.x, windowSize.y);
	projection = glm::perspective(glm::radians(fov), aspect, 0.2f, 1000.0f);
}

void Game::update(float dt)
{
	input.updateMouseAndKeyValues();
	player.cam.updateCameraRotation(sf::Vector2i{input.getMouseDeltaX(), input.getMouseDeltaY()}, mouseSpeed);
	player.cam.updateWalkDirection(input);
	player.walk(input, world, dt);

	player.cam.updatePointToLookAtPosition(player.position);
	player.cam.updateRotationAngles();
	player.cam.updateCameraPosition();

	player.updateGunPos();
}

void Game::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor((GLclampf)0.6, (GLclampf)0.6, (GLclampf)0.6, 1);
	view = player.cam.moveCamera();

	playerShader.use();
	playerShader.setMat4(playerShader.viewLoc, view);
	playerShader.setMat4(playerShader.projectionLoc, projection);

	playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "drawGun"), 0);
	auto [x, y, z] = player.cam.getPosition();
	playerShader.setMat4(playerShader.modelLoc, glm::translate(glm::mat4(1), glm::vec3(x, y, z)));

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	// playerShader.setMat4(playerShader.modelLoc, glm::translate(glm::mat4(1), glm::vec3(player.pos.x, player.pos.y, player.pos.z)));
	// playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "drawGun"), 0);
	// glBindVertexArray(VAO);
	// glDrawArrays(GL_TRIANGLES, 0, 36);

	// model = glm::translate(glm::mat4(1), glm::vec3(player.pos.x, player.pos.y, player.pos.z));
	playerShader.setMat4(playerShader.modelLoc, glm::translate(glm::mat4(1), glm::vec3(player.gunPos.x, player.gunPos.y, player.gunPos.z)));
	playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "gunScale"), 0.05);
	playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "drawGun"), 1);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	blockShader.use();
	blockShader.setMat4(blockShader.viewLoc, view);
	blockShader.setMat4(blockShader.projectionLoc, projection);
	blockShader.setFloat(glGetUniformLocation(blockShader.getID(), "lightX"), player.position.x);
	blockShader.setFloat(glGetUniformLocation(blockShader.getID(), "lightY"), player.position.y);
	blockShader.setFloat(glGetUniformLocation(blockShader.getID(), "lightZ"), player.position.z);

	glBindVertexArray(VAO);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 36, world.ammountToDraw);

	glUseProgram(0);
	glBindVertexArray(0);

	m_window.display();
}

bool Game::checkPlacePossibility(int x, int y, int z)
{
	return world.blocks[x][y][z].m_type == Block::Type::Air && (world.blocks[x - 1][y][z].m_type != Block::Type::Air ||
																world.blocks[x][y - 1][z].m_type != Block::Type::Air ||
																world.blocks[x][y][z - 1].m_type != Block::Type::Air ||
																world.blocks[x + 1][y][z].m_type != Block::Type::Air ||
																world.blocks[x][y + 1][z].m_type != Block::Type::Air ||
																world.blocks[x][y][z + 1].m_type != Block::Type::Air);
}
bool Game::checkDestroyPossibility(int x, int y, int z)
{
	return world.blocks[x][y][z].m_type != Block::Type::Air && (world.blocks[x - 1][y][z].m_type == Block::Type::Air ||
																world.blocks[x][y - 1][z].m_type == Block::Type::Air ||
																world.blocks[x][y][z - 1].m_type == Block::Type::Air ||
																world.blocks[x + 1][y][z].m_type == Block::Type::Air ||
																world.blocks[x][y + 1][z].m_type == Block::Type::Air ||
																world.blocks[x][y][z + 1].m_type == Block::Type::Air);
}

void Game::placingAndRemovingBlocks()
{
	static sf::Clock Timer = sf::Clock();
	static float timePassed = 0;

	int x = player.gunPos.x + 0.25;
	int y = player.gunPos.y + 0.25;
	int z = player.gunPos.z + 0.25;

	if (input.getMouseLeft() && !input.getMouseRight() && player.position.y > 5)
	{
		if (checkDestroyPossibility(x, y, z))
		{
			timePassed += Timer.getElapsedTime().asSeconds();
			if (world.blocks[x][y][z].m_type != Block::Type::Air)
			{
				for (Block *block : world.blocksNextToPlayer)
				{
					if (block->m_position.x == x && block->m_position.y == y && block->m_position.z == z)
					{
						player.slots.push_back(block->m_type);
						block->m_type = Block::Type::Air;
					}
				}
				timePassed = 0;
				needToRefreshBlocks = true;
			}
		}
	}

	if (input.getMouseRight() && !input.getMouseLeft())
	{
		if (checkPlacePossibility(x, y, z))
		{
			timePassed += Timer.getElapsedTime().asSeconds();
			if (player.slots.size())
			{
				std::cout << "a";
				Block::Type tempType = player.slots.back();
				player.slots.pop_back();
				world.blocks[x][y][z].m_type = tempType;
				timePassed = 0;
				needToRefreshBlocks = true;
			}
		}
	}

	if (!input.getMouseLeft() && !input.getMouseRight())
	{
		timePassed = 0;
	}
	Timer.restart();
}

void Game::initOpenGL()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, grassTopTexture.getNativeHandle());
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, grassTexture.getNativeHandle());
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, dirtTexture.getNativeHandle());
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, stoneTexture.getNativeHandle());
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, woodTexture.getNativeHandle());
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, leavesTexture.getNativeHandle());
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glActiveTexture(GL_TEXTURE15);
	glBindTexture(GL_TEXTURE_2D, skyboxTexture.getNativeHandle());
}