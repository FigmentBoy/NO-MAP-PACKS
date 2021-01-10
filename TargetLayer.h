#pragma once
#include "cocos2d.h"
using namespace cocos2d;

namespace TargetLayer {
	inline bool(__thiscall* init)(CCLayer* self);
	bool __fastcall initHook(CCLayer* self);

	void mem_init();
}
