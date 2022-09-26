//
// Created by Gabriel de Taxis on 20/09/2022.
//

#include "PlayerControlSystem.h"

#include "../Components/Player.h"
#include "../Components/Position.h"
#include "../Core/Coordinator.h"


extern Coordinator gCoordinator;


void PlayerControlSystem::Init()
{
    gCoordinator.AddEventListener(METHOD_LISTENER(Events::Window::INPUT, PlayerControlSystem::InputListener));
}

void PlayerControlSystem::Update(float dt)
{
    for (auto& entity : mEntities)
    {
    	auto& position = gCoordinator.GetComponent<Position>(entity);


    	if (mButtons.test(static_cast<std::size_t>(InputButtons::W)))
    	{
    		position.z += (dt * 10.0f);
    	}
    	else if (mButtons.test(static_cast<std::size_t>(InputButtons::S)))
    	{
    		position.z -= (dt * 10.0f);
    	}
    	if (mButtons.test(static_cast<std::size_t>(InputButtons::Q)))
    	{
    		position.y += (dt * 10.0f);
    	}
    	else if (mButtons.test(static_cast<std::size_t>(InputButtons::E)))
    	{
    		position.y -= (dt * 10.0f);
    	}
    	if (mButtons.test(static_cast<std::size_t>(InputButtons::A)))
    	{
    		position.x += (dt * 10.0f);
    	}
    	else if (mButtons.test(static_cast<std::size_t>(InputButtons::D)))
    	{
    		position.x -= (dt * 10.0f);
    	}
    }
}

void PlayerControlSystem::InputListener(Event& event)
{
    mButtons = event.GetParam<std::bitset<8>>(Events::Window::Input::INPUT);
    std::cout << mButtons << std::endl;
}
