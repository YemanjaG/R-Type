#include "RenderSystem.h"

#include "../Components/Renderable.h"
#include "../Core/Coordinator.h"
#include <cmath>


extern Coordinator gCoordinator;


void RenderSystem::Init()
{
//    gCoordinator.AddEventListener(METHOD_LISTENER(Events::Window::RESIZED, RenderSystem::WindowSizeListener));
}


void RenderSystem::Update(float dt)
{
    for (auto const& entity : mEntities) {

    }
}

void RenderSystem::WindowSizeListener(Event& event)
{
//    auto windowWidth = event.GetParam<unsigned int>(Events::Window::Resized::WIDTH);
//    auto windowHeight = event.GetParam<unsigned int>(Events::Window::Resized::HEIGHT);
//
//    auto& camera = gCoordinator.GetComponent<Camera>(mCamera);
//    camera.projectionTransform = Camera::MakeProjectionTransform(45.0f, 0.1f, 1000.0f, windowWidth, windowHeight);
}

