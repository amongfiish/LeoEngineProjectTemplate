#include "LeoEngine/Engine.hpp"
#include "LeoEngine/Game.hpp"

#include "LeoEngine/Services.hpp"

#include "LeoEngine/SceneCollection.hpp"
#include "LeoEngine/SceneTest.hpp"

#include "LeoEngine/File.hpp"

int main(int argc, char *argv[])
{
    LeoEngine::Engine leoEngine;
    leoEngine.setFramerate(60);

    LeoEngine::Services::get().getGraphics()->setWindowTitle("LeoEngine Project Template");
    LeoEngine::Services::get().getGraphics()->setWindowDimensions(800, 800);
    LeoEngine::Services::get().getGraphics()->setRenderDimensions(200, 200);
    LeoEngine::Services::get().getGraphics()->setWindowBordered(true);
    LeoEngine::Services::get().getGraphics()->setWindowFullscreen(false);
    LeoEngine::Services::get().getGraphics()->setWindowResizable(true);
    LeoEngine::Services::get().getGraphics()->setWindowGrabCursor(false);
    LeoEngine::File::setWriteDirectory("amongfiish", "LeoEngineProjectTemplate");

    LeoEngine::Game game;

    LeoEngine::SceneCollection& sceneCollection = game.getSceneCollection();
    int testSceneId = sceneCollection.addScene<LeoEngine::SceneTest>();

    sceneCollection.setCurrentScene(testSceneId);
    leoEngine.runGame(game);
    
    return 0;
}

