#include"Scene.h"

void Scene::Update() {
	//petamos las cosas que hay que petar
	for (int i = _Objects.size() - 1; i >= 0; i--) {
		if (_Objects[i]->IsPrivateDestroy()) {
			delete _Objects[i];
			_Objects.erase(_Objects.begin() + i);
		}
	}

	for (int i = _ui.size() - 1; i >= 0; i--) {
		if (_ui[i]->IsPrivateDestroy()) {
			delete _ui[i];
			_ui.erase(_ui.begin() + i);
		}
	}



	//... faltan cosas con el spawner

	//updateamos
	for (Object* o : _Objects)
		o->Update();

	for (Object* UI : _ui)
		UI->Update();
	// miramos collisiones

	int sizeObjects = _Objects.size();

	for (int i = 0; i < sizeObjects; i++) {
		for (int j = 0; j < _Objects.size(); j++) {
			if (_Objects[i]->GetRigidBody()->CheckCollision(_Objects[j]->GetRigidBody())) {
				//cosas
			}
		}
	}

	int sizeUI = _ui.size();
	for (int i = 0; i < sizeUI; i++) {
		for (int j = 0; j < _ui.size(); j++) {
			if (_ui[i]->GetRigidBody()->CheckCollision(_ui[j]->GetRigidBody())) {
				//cosas

			}
		}
	}
}