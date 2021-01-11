#include "TargetLayer.h"
#include "MinHook.h"
#include "GameManager.h"

bool __fastcall TargetLayer::initHook(CCLayer* self) {
	void* gm = GameManager::getSharedState();
	bool result = init(self);
	if (!GameManager::getGameVariable(gm, "mp-show")) {
		auto children = self->getChildren();
		CCMenu* menu = (CCMenu*)children->objectAtIndex(1);

		auto menuObjs = menu->getChildren();

		CCNode* mapPack = (CCNode*)menuObjs->objectAtIndex(8);

		menu->removeChild(mapPack, true);

		CCNode* Featured = (CCNode*)menuObjs->objectAtIndex(6);
		CCNode* HOF = (CCNode*)menuObjs->objectAtIndex(7);
		CCNode* Search = (CCNode*)menuObjs->objectAtIndex(8);

		CCNode* Create = (CCNode*)menuObjs->objectAtIndex(0);
		CCNode* Saved = (CCNode*)menuObjs->objectAtIndex(1);
		CCNode* Scores = (CCNode*)menuObjs->objectAtIndex(2);

		Featured->setPositionX(Create->getPositionX());
		HOF->setPositionX(Saved->getPositionX());
		Search->setPositionX(Scores->getPositionX());
	}
	return result;
}

void TargetLayer::mem_init() {
	size_t base = reinterpret_cast<size_t>(GetModuleHandle(0));

	MH_CreateHook(
		(PVOID)(base+ 0x4DE40),
		TargetLayer::initHook,
		(LPVOID*)&TargetLayer::init
	);
}
