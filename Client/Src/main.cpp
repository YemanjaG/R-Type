#include <SFML/Graphics.hpp>
#include <chrono>
#include <random>

// Components
#include "Components/Player.h"
#include "Components/Renderable.h"
#include "Components/Position.h"
#include "Components/Collidable.h"
#include "Components/Health.h"
#include "Components/SpriteAndTexture.h"

#include "Core/Coordinator.h"
#include "Core/EventManager.h"
#include "Core/SystemManager.h"

#include "Systems/RenderSystem.h"
#include "Systems/PlayerControlSystem.h"

#include "WindowManager.h"


Coordinator gCoordinator;

int main()
{
    gCoordinator.Init();

    WindowManager windowManager;
    windowManager.ProcessEvents();
    windowManager.Init("R-Type", 1000, 1000);

    gCoordinator.RegisterComponent<Player>();
    gCoordinator.RegisterComponent<Position>();
    gCoordinator.RegisterComponent<SpriteAndTexture>();
    gCoordinator.RegisterComponent<RenderSystem>();

    auto renderSystem = gCoordinator.RegisterSystem<RenderSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Renderable>());
        gCoordinator.SetSystemSignature<RenderSystem>(signature);
    }
    renderSystem->Init();

    auto playerControlSystem = gCoordinator.RegisterSystem<PlayerControlSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Player>());
        signature.set(gCoordinator.GetComponentType<Position>());
        signature.set(gCoordinator.GetComponentType<SpriteAndTexture>());
        gCoordinator.SetSystemSignature<PlayerControlSystem>(signature);
    }
    playerControlSystem->Init();

    float dt = 0.0f;
    while (windowManager.mWindow.isOpen())
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        windowManager.ProcessEvents();

        playerControlSystem->Update(dt);
        renderSystem->Update(dt);

        windowManager.Update();
        auto stopTime = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
}