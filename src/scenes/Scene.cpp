//
// Created by mu on 8/30/22.
//

#include "Scene.h"

namespace scenes {

    Scene::Scene() {
        init();
    }

    void Scene::init() {

    }

    void Scene::addObject(engine::GameObject obj) {
        gameObjects.push_back(obj);
    }
}