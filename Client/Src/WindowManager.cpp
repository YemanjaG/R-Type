#include "WindowManager.h"
#include "Core/Coordinator.h"
#include <bitset>
#include <iostream>

extern Coordinator gCoordinator;

void WindowManager::Init(const std::string &windowTitle, int windowWidth, int windowHeight) {
    std::cout <<"hey jude"<< std::endl;
    mWindow.create(sf::VideoMode(windowWidth, windowHeight), windowTitle);
}
//
//void WindowManager::Init(const std::string &windowTitle, unsigned int windowWidth, unsigned int windowHeight,
//                         unsigned int windowPositionX, unsigned int windowPositionY) {
////    glfwInit();
//        std::cout << "hey" << std::endl;
////    mWindow = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), NULL, NULL);
////    mWindow.create(sf::VideoMode(windowWidth, windowHeight), windowTitle);
////        mWindow = sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle.c_str());
////    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
////    glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    // Create OpenGL Context
////    glfwMakeContextCurrent(mWindow);
////    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
////    glfwSwapInterval(2);
//
//    // Configure OpenGL
////    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
////    glEnable(GL_DEPTH_TEST);
//}
//

void WindowManager::Update()
{
//    glfwSwapBuffers(mWindow);

    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);
    mWindow.clear();
    mWindow.draw(shape);
    mWindow.display();
}


void WindowManager::Shutdown()
{
//    glfwDestroyWindow(mWindow);
//    glfwTerminate();
}

void WindowManager::ProcessEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            mWindow.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            bool buttonStateChanged = true;
            if (event.key.code == sf::Keyboard::Escape)
            {
                std::cout << "the escape key was pressed" << std::endl;
//                gCoordinator.SendEvent()
            } else if (event.key.code == sf::Keyboard::Z){
                std::cout << "the Z key was pressed" << std::endl;
            } else if (event.key.code == sf::Keyboard::Q){
                std::cout << "the Q key was pressed" << std::endl;
            } else if (event.key.code == sf::Keyboard::S){
                std::cout << "the S key was pressed" << std::endl;
            } else if (event.key.code == sf::Keyboard::D){
                std::cout << "the D key was pressed" << std::endl;
            } else {
                std::cout << "a key was pressed" << std::endl;
            }

        }
    }

//    bool buttonStateChanged = true;
//
//    if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE))
//    {
//        gCoordinator.SendEvent(Events::Window::QUIT);
//    }
//    else if (glfwGetKey(mWindow, GLFW_KEY_W))
//    {
//        mButtons.set(static_cast<std::size_t>(InputButtons::W));
//    }
//    else if (glfwGetKey(mWindow, GLFW_KEY_A))
//    {
//        mButtons.set(static_cast<std::size_t>(InputButtons::A));
//    }
//    else if (glfwGetKey(mWindow, GLFW_KEY_S))
//    {
//        mButtons.set(static_cast<std::size_t>(InputButtons::S));
//    }
//    else if (glfwGetKey(mWindow, GLFW_KEY_D))
//    {
//        mButtons.set(static_cast<std::size_t>(InputButtons::D));
//    }
//    else if (glfwGetKey(mWindow, GLFW_KEY_Q))
//    {
//        mButtons.set(static_cast<std::size_t>(InputButtons::Q));
//    }
//    else if (glfwGetKey(mWindow, GLFW_KEY_E))
//    {
//        mButtons.set(static_cast<std::size_t>(InputButtons::E));
//    }
//    else
//    {
//        buttonStateChanged = false;
//    }
//
//    if (buttonStateChanged)
//    {
//        Event event(Events::Window::INPUT);
//        event.SetParam(Events::Window::Input::INPUT, mButtons);
//        gCoordinator.SendEvent(event);
//    }
}


