//
// Created by mu on 8/30/22.
//

#ifndef OPENGLLINUXTEST_SCENE_H
#define OPENGLLINUXTEST_SCENE_H


#include <vector>
#include "../engine/GameObject.h"

namespace scenes {

    class Scene {
    public:
        std::vector<engine::GameObject> gameObjects;

        Scene();

        void init();

        virtual void update(float dt) = 0;

        void addObject(engine::GameObject obj);
    };

}

#endif //OPENGLLINUXTEST_SCENE_H
