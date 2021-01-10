#include "TargetLayer.h"
#include "MinHook.h"

bool __fastcall TargetLayer::initHook(CCLayer* self) {
	bool result = init(self);
	auto children = self->getChildren();
	CCMenu* menu = (CCMenu*)children->objectAtIndex(1);

	auto menuObjs = menu->getChildren();

	CCNode* mapPack = (CCNode*)menuObjs->objectAtIndex(8);

	menu->removeChild(mapPack, true);

	CCNode* HOF = (CCNode*)menuObjs->objectAtIndex(7);
	CCNode* Featured = (CCNode*)menuObjs->objectAtIndex(6);
	CCNode* Search = (CCNode*)menuObjs->objectAtIndex(8);

	float width = HOF->getScaledContentSize().width;

	HOF->setPositionX(0);
	Featured->setPositionX(-width - 10);
	Search->setPositionX(width + 10);

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