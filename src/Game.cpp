#include "Game.h"

Game::Game()
	:mWindow(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
	, mPlayer()
	, food()
	, mBoulder1()
	, mBoulder2()
	, mBoulder3()
	, mBoulder4()
{
	srand(time(NULL));
	float x1 = 75 + (std::rand() % (150 - 75 + 1) + 50);
	float randDist = 75 + (std::rand() % (150 - 75 + 1));
	float x2, x3, x4;
	float randFoodHeight = (60 + std:: rand() % (76 - 60 + 1));

	mPlayer.setRadius(18.f);
	mPlayer.setOrigin(mPlayer.getRadius(), mPlayer.getRadius());
	mPlayer.setPosition(68.3, 88);
	mPlayer.setFillColor(sf::Color::Transparent);
	mPlayer.setScale(.15f, .15f);

	food.setRadius(4.f);
	food.setOrigin(food.getRadius(), food.getRadius());
	food.setPosition(x1, randFoodHeight);
	food.setFillColor(sf::Color::Transparent);

	rectPlayerSprite = sf::IntRect(0, 0, 32, 32);
	rectBoulderSprite = sf::IntRect(1200, 0, 200, 195);

	playerTexture.loadFromFile("Assets/octopus_sprite_sheet.png");
	sPlayerSprite.setTexture(playerTexture);
	sPlayerSprite.setTextureRect(rectPlayerSprite);
	sPlayerSprite.setScale(.5f, .5f);
	sPlayerSprite.setOrigin(mPlayer.getRadius(), mPlayer.getRadius());
	sPlayerSprite.setPosition(69, 90);

	mPlayerLife.loadFromFile("Assets/octopus_life_sprite.png");
	mPlayerLife.setSmooth(true);
	sPlayerLife1.setTexture(mPlayerLife);
	sPlayerLife1.setScale(0.5f, 0.5f);
	sPlayerLife1.setPosition(555.f, 0.f);

	mBoulderTexture.loadFromFile("Assets/boulderCreationSheet.png");
	mBoulderTexture.setSmooth(true);

	sObstacle1.setTexture(mBoulderTexture);
	sObstacle1.setTextureRect(rectBoulderSprite);
	sObstacle1.setOrigin(100, 100);
	sObstacle1.setPosition(x1, groundHeight);
	sObstacle1.setScale(0.1f, 0.1f);

	x2 = x1 + randDist;

	sObstacle2.setTexture(mBoulderTexture);
	sObstacle2.setTextureRect(rectBoulderSprite);
	sObstacle2.setOrigin(100, 100);
	sObstacle2.setPosition(x2, groundHeight);
	sObstacle2.setScale(0.1f, 0.1f);

	x3 = x2 + randDist;

	sObstacle3.setTexture(mBoulderTexture);
	sObstacle3.setTextureRect(rectBoulderSprite);
	sObstacle3.setOrigin(100, 100);
	sObstacle3.setPosition(x3, groundHeight);
	sObstacle3.setScale(0.1f, 0.1f);

	x4 = x3 + randDist;

	sObstacle4.setTexture(mBoulderTexture);
	sObstacle4.setTextureRect(rectBoulderSprite);
	sObstacle4.setOrigin(100, 100);
	sObstacle4.setPosition(x4, groundHeight);
	sObstacle4.setScale(0.1f, 0.1f);
	
	mBoulder1.setRadius(50.f);
	mBoulder1.setOrigin(50, 50);
	mBoulder1.setPosition(sObstacle1.getPosition());
	mBoulder1.setFillColor(sf::Color::Transparent);
	mBoulder1.setScale(.1f, .1f);

	mBoulder2.setRadius(50.f);
	mBoulder2.setOrigin(50, 50);
	mBoulder2.setPosition(sObstacle2.getPosition());
	mBoulder2.setFillColor(sf::Color::Transparent);
	mBoulder2.setScale(.1f, .1f);

	mBoulder3.setRadius(50.f);
	mBoulder3.setOrigin(50, 50);
	mBoulder3.setPosition(sObstacle3.getPosition());
	mBoulder3.setFillColor(sf::Color::Transparent);
	mBoulder3.setScale(.1f, .1f);

	mBoulder4.setRadius(50.f);
	mBoulder4.setOrigin(50, 50);
	mBoulder4.setPosition(sObstacle4.getPosition());
	mBoulder4.setFillColor(sf::Color::Transparent);
	mBoulder4.setScale(.1f, .1f);

	boulders.push_back(mBoulder1);
	boulders.push_back(mBoulder2);
	boulders.push_back(mBoulder3);
	boulders.push_back(mBoulder4);

	mGreenBlobTexture.loadFromFile("Assets/Green_blob.png");
	sBlob.setTexture(mGreenBlobTexture);
	sBlob.setOrigin(48, 44);
	sBlob.setPosition(x1, randFoodHeight);
	sBlob.setScale(.11f, .11f);

	mPlayerLife.setSmooth(true);
	sPlayerLife2.setTexture(mPlayerLife);
	sPlayerLife2.setScale(0.5f, 0.5f);
	sPlayerLife2.setPosition(580.f, 0.f);

	mPlayerLife.setSmooth(true);
	sPlayerLife3.setTexture(mPlayerLife);
	sPlayerLife3.setScale(0.5f, 0.5f);
	sPlayerLife3.setPosition(605.f, 0.f);

	mPlayerView.zoom(.1f);

	backgroundTexture.loadFromFile("Assets/mountain-bg.png");
	s.setTexture(backgroundTexture);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::Time timeElapsed;

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error loading file!";
	}

	while (mWindow.isOpen())
	{
		processEvents();

		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > TimePerFrame)
		{
			
			timeSinceLastUpdate -= TimePerFrame;
			timeElapsed += sf::seconds(1.f);

			sPlayerSprite.setTextureRect(rectPlayerSprite);

			if ((int)timeElapsed.asSeconds() % 120 == 0)
				sPlayerSprite.setColor(sf::Color::White);

			sObstacle1.setTextureRect(rectBoulderSprite);
			sObstacle2.setTextureRect(rectBoulderSprite);
			sObstacle3.setTextureRect(rectBoulderSprite);
			sObstacle4.setTextureRect(rectBoulderSprite);

			processEvents();
			update(TimePerFrame, timeElapsed);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			mIsMovingUp = false;
			mIsJumping = false;
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time TimePerFrame, sf::Time timeElapsed)
{
	movement = sf::Vector2f(0.f, 0.f);

	if (mIsMovingUp)
	{
		movement.y -= 300.f;
		movement.x += PlayerSpeed * 1.5;
		rectPlayerSprite.top = 96;

		if ((int)timeElapsed.asSeconds() % 10 == 0)
		{
			if (rectPlayerSprite.left == 160)
				rectPlayerSprite.left = 0;
			else
				rectPlayerSprite.left += 32;
		}
	}
	else if (mIsMovingDown)
	{
		movement.x += PlayerSpeed;

		rectPlayerSprite.top = 160;

		if ((int)timeElapsed.asSeconds() % 10 == 0)
		{
			if (rectPlayerSprite.left == 96)
				rectPlayerSprite.left = 0;
			else
				rectPlayerSprite.left += 32;
		}
	}
	else if (mIsMovingRight)
	{
		movement.x += PlayerSpeed;

		if (sPlayerSprite.getScale().x < 0)
			sPlayerSprite.scale(-1.f, 1.f);

		rectPlayerSprite.top = 32;

		if (rectPlayerSprite.left > 96)
			rectPlayerSprite.left = 0;

		if ((int)timeElapsed.asSeconds() % 10 == 0)
		{
			if (rectPlayerSprite.left == 96)
				rectPlayerSprite.left = 0;
			else
				rectPlayerSprite.left += 32;
		}
	}
	else if (mIsJumping)
	{
		movement.y -= 300.f;
		movement.x += PlayerSpeed * 1.5;
		rectPlayerSprite.top = 96;

		if ((int)timeElapsed.asSeconds() % 10 == 0)
		{
			if (rectPlayerSprite.left == 160)
				rectPlayerSprite.left = 0;
			else
				rectPlayerSprite.left += 32;
		}
	}

	if ((int)timeElapsed.asSeconds() % 5 == 0)
	{
		if (rectBoulderSprite.left <= 200)
		{
			implode = true;
		}
		else if (rectBoulderSprite.left >= 1200)
		{
			implode = false;
		}

		if(!implode)
		{
			rectBoulderSprite.left -= 200;
		}
		else if(implode)
		{
			rectBoulderSprite.left += 200;
		}
	}

	if (mPlayer.getPosition().x >= s.getPosition().x + 580)
	{
		s.move(271, 0);
	}

	sBlob.rotate(1.f);

	sObstacle1.rotate(1.f);
	sObstacle2.rotate(2.f);
	sObstacle3.rotate(3.f);
	sObstacle4.rotate(4.f);

	mBoulder1.rotate(1.f);
	mBoulder2.rotate(2.f);
	mBoulder3.rotate(3.f);
	mBoulder4.rotate(4.f);

	mPlayerView.setCenter(mPlayer.getPosition());
	mPlayerView.setCenter(sPlayerSprite.getPosition());

	mPlayer.move(movement * TimePerFrame.asSeconds());
	sPlayerSprite.move(movement * TimePerFrame.asSeconds());

	Collision(food, mPlayer, mPlayer.getPosition());
}

void Game::render()
{
	sf::Text score("Score: " + std::to_string(scoreCount), font);
	score.setCharacterSize(18);
	score.setFillColor(sf::Color::White);
	score.setStyle(sf::Text::Regular);
	score.setPosition(10.f, 5.f);

	sf::Text deaths(std::to_string(deathCount) + "x", font);
	deaths.setCharacterSize(18);
	deaths.setFillColor(sf::Color::White);
	deaths.setStyle(sf::Text::Regular);
	deaths.setPosition(540.f, 7.5f);
	
	sf::Text GameDone(gameOver, font);
	sf::FloatRect textRect = GameDone.getLocalBounds();
	GameDone.setCharacterSize(24);
	GameDone.setFillColor(sf::Color::Red);
	GameDone.setStyle(sf::Text::Regular);
	GameDone.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	GameDone.setPosition(400.f, 240.f);

	mWindow.clear();

	mWindow.draw(s);
	mWindow.draw(sBlob);
	mWindow.draw(food);
	mWindow.draw(mBoulder1);
	mWindow.draw(mBoulder2);
	mWindow.draw(mBoulder3);
	mWindow.draw(mBoulder4);
	mWindow.draw(mPlayer);
	mWindow.draw(sPlayerSprite);
	mWindow.draw(sObstacle1);
	mWindow.draw(sObstacle2);
	mWindow.draw(sObstacle3);
	mWindow.draw(sObstacle4);

	mWindow.setView(mWindow.getDefaultView());

	mWindow.draw(sPlayerLife1);
	mWindow.draw(sPlayerLife2);
	mWindow.draw(sPlayerLife3);
	mWindow.draw(deaths);
	mWindow.draw(score);
	mWindow.draw(GameDone);
	
	mWindow.setView(mPlayerView);

	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W && mPlayer.getPosition().y >= groundHeight)
	{
		if (mIsMovingDown == true)
		{
			rectPlayerSprite.top = 32;
			mIsMovingRight = isPressed;
		}
		else
		{
			mIsMovingUp = isPressed;
		}
		mIsMovingDown = false;
	}
	else if (key == sf::Keyboard::S && mPlayer.getPosition().y >= groundHeight)
	{
		mIsMovingDown = isPressed;
		mIsMovingUp = false;
		mIsMovingLeft = false;
		mIsMovingRight = false;
	}
	else if (key == sf::Keyboard::D)
	{
		mIsMovingRight = isPressed;
		mIsMovingUp = false;
		mIsMovingDown = false;
		mIsMovingLeft = false;
	}
	else if (key == sf::Keyboard::Space && mPlayer.getPosition().y >= groundHeight)
	{
		mIsJumping = isPressed;
		mIsMovingUp = true;
		mIsMovingDown = false;
	}
	else if (key == sf:: Keyboard::R)
	{
		mWindow.close();
		Game::Game().run();
	}
	else if (key == sf::Keyboard::Escape)
	{
		mWindow.close();
	}
}

void Game::Collision(sf::CircleShape shape1, sf::CircleShape shape2, sf::Vector2f shape2pos)
{
	float xMove = 75 + (std::rand() % (150 - 75 + 1));
	float randFoodHeight = (60 + std::rand() % (76 - 60 + 1));

	sf::FloatRect rect1 = shape1.getGlobalBounds();
	sf::FloatRect rect2 = shape2.getGlobalBounds();

	float dx = (shape1.getPosition().x + (rect1.width / 2)) - (shape2.getPosition().x + (rect2.width / 2));
	float dy = (shape1.getPosition().y + (rect2.height / 2)) - (shape2.getPosition().y + (rect2.height / 2));
	float distance = std::sqrt((dx * dx) + (dy * dy));

	if ((int)distance <= (int)(rect1.width / 2) + (int)(rect2.width / 2 + 5))
	{
		if (scoreStore == 0)
		{
			int x = sObstacle4.getPosition().x - sObstacle1.getPosition().x + xMove;
			food.setPosition(sObstacle2.getPosition().x, randFoodHeight);
			sBlob.setPosition(sObstacle2.getPosition().x, randFoodHeight);
			sPlayerSprite.setColor(sf::Color::Green);
			sObstacle1.move(x, 0);
			mBoulder1.setPosition(sObstacle1.getPosition().x, sObstacle1.getPosition().y);
			scoreStore++;
		}
		else if (scoreStore == 1)
		{
			int x = sObstacle1.getPosition().x - sObstacle2.getPosition().x + xMove;
			food.setPosition(sObstacle3.getPosition().x, randFoodHeight);
			sBlob.setPosition(sObstacle3.getPosition().x, randFoodHeight);
			sPlayerSprite.setColor(sf::Color::Green);
			sObstacle2.move(x, 0);
			mBoulder2.setPosition(sObstacle2.getPosition().x, sObstacle2.getPosition().y);
			scoreStore++;
		}
		else if (scoreStore == 2)
		{
			int x = sObstacle2.getPosition().x - sObstacle3.getPosition().x + xMove;
			food.setPosition(sObstacle4.getPosition().x, randFoodHeight);
			sBlob.setPosition(sObstacle4.getPosition().x, randFoodHeight);
			sPlayerSprite.setColor(sf::Color::Green);
			sObstacle3.move(x, 0);
			mBoulder3.setPosition(sObstacle3.getPosition().x, sObstacle3.getPosition().y);
			scoreStore++;
		}
		else if (scoreStore == 3)
		{
			int x = sObstacle3.getPosition().x - sObstacle4.getPosition().x + xMove;
			scoreStore = 0;
			food.setPosition(sObstacle1.getPosition().x, randFoodHeight);
			sBlob .setPosition(sObstacle1.getPosition().x, randFoodHeight);
			sPlayerSprite.setColor(sf::Color::Green);
			sObstacle4.move(x, 0);
			mBoulder4.setPosition(sObstacle4.getPosition().x, sObstacle4.getPosition().y);
		}
		
		if (deathCount < 3)
			PlayerSpeed += 6;
		else
			PlayerSpeed += 3;

		scoreCount++;
	}

	if (food.getPosition().x < shape2.getPosition().x)
	{
		sPlayerSprite.setColor(sf::Color::Magenta);
		sPlayerSprite.setPosition(shape2.getPosition().x - 150, 90);
		mPlayer.setPosition(shape2.getPosition().x - 150, 90);
		
		scoreCount--;

		if (PlayerSpeed < 160.f)
			PlayerSpeed = 80.f;
		else
			PlayerSpeed /= 2;
	}


	sf::FloatRect boulderRect1 = mBoulder1.getGlobalBounds();

	dx = (mBoulder1.getPosition().x + (boulderRect1.width / 2)) - (shape2.getPosition().x + (rect2.width / 2));
	dy = (mBoulder1.getPosition().y + (boulderRect1.height / 2)) - (shape2.getPosition().y + (rect2.height / 2));
	distance = std::sqrt((dx * dx) + (dy * dy));

	if ((int)distance <= (int)(boulderRect1.width / 2) + (int)(rect2.width / 2 + 5))
	{
		sPlayerSprite.setColor(sf::Color::Red);
		sPlayerSprite.setPosition(shape2.getPosition().x - 50, 90);
		mPlayer.setPosition(shape2.getPosition().x - 50, 90);
		PlayerSpeed = 80.f;
		deathCount--;
	}
	
	sf::FloatRect boulderRect2 = mBoulder2.getGlobalBounds();

	dx = (mBoulder2.getPosition().x + (boulderRect2.width / 2)) - (shape2.getPosition().x + (rect2.width / 2));
	dy = (mBoulder2.getPosition().y + (boulderRect2.height / 2)) - (shape2.getPosition().y + (rect2.height / 2));
	distance = std::sqrt((dx * dx) + (dy * dy));

	if ((int)distance <= (int)(boulderRect2.width / 2) + (int)(rect2.width / 2 + 5))
	{
		sPlayerSprite.setColor(sf::Color::Red);
		sPlayerSprite.setPosition(shape2.getPosition().x - 50, 90);
		mPlayer.setPosition(shape2.getPosition().x - 50, 90);
		PlayerSpeed = 80.f;
		deathCount--;
	}

	sf::FloatRect boulderRect3 = mBoulder3.getGlobalBounds();

	dx = (mBoulder3.getPosition().x + (boulderRect3.width / 2)) - (shape2.getPosition().x + (rect2.width / 2));
	dy = (mBoulder3.getPosition().y + (boulderRect3.height / 2)) - (shape2.getPosition().y + (rect2.height / 2));
	distance = std::sqrt((dx * dx) + (dy * dy));

	if ((int)distance <= (int)(boulderRect3.width / 2) + (int)(rect2.width / 2 + 5))
	{
		sPlayerSprite.setColor(sf::Color::Red);
		sPlayerSprite.setPosition(shape2.getPosition().x - 50, 90);
		mPlayer.setPosition(shape2.getPosition().x - 50, 90);
		PlayerSpeed = 80.f;
		deathCount--;
	}

	sf::FloatRect boulderRect4 = mBoulder4.getGlobalBounds();

	dx = (mBoulder4.getPosition().x + (boulderRect4.width / 2)) - (shape2.getPosition().x + (rect2.width / 2));
	dy = (mBoulder4.getPosition().y + (boulderRect4.height / 2)) - (shape2.getPosition().y + (rect2.height / 2));
	distance = std::sqrt((dx * dx) + (dy * dy));

	if ((int)distance <= (int)(boulderRect4.width / 2) + (int)(rect2.width / 2 + 5))
	{
		sPlayerSprite.setColor(sf::Color::Red);
		sPlayerSprite.setPosition(shape2.getPosition().x - 50, 90);
		mPlayer.setPosition(shape2.getPosition().x - 50, 90);
		PlayerSpeed = 80.f;
		deathCount--;
	}

	if (deathCount == 2)
	{
		sPlayerLife3.setColor(sf::Color::Transparent);
	}
	if (deathCount == 1)
	{
		sPlayerLife2.setColor(sf::Color::Transparent);
	}
	if (deathCount == 0)
	{
		sPlayerLife1.setColor(sf::Color::Transparent);
		PlayerSpeed = 0;
		gameOver = "GAME OVER! PRESS R TO PLAY AGAIN.";
	}

	if (shape2pos.y <= groundHeight && (mIsJumping == false || mIsMovingUp == false))
	{
		sPlayerSprite.move(0, GravitySpeed);
		mPlayer.move(0, GravitySpeed);
	}

	if (shape2pos.y <= ceilingHeight)
	{
		mIsJumping = false;
		mIsMovingUp = false;
	}
}