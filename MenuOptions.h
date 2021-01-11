#pragma once

namespace MenuOptions {

	inline int(__thiscall* addToggle)(void* self, const char* display, const char* key, const char* extraInfo);
	inline bool(__thiscall* init)(void*);
	bool __fastcall initHook(void* self);
	void mem_init();
}