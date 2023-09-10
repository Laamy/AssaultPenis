#pragma once

class physent {
public:
	uintptr_t** VTable;
	Vector3<float> origin; //0x0004 
	Vector3<float> vel; //0x0010 
	Vector3<float> deltapos; //0x001C 
	Vector3<float> newpos; //0x0028 
	Vector3<float> camera; //0x0034 
	float pitchvel; //0x0040 
	float maxSpeed; //0x0044 (dont use this, it'll cause a crash)
	__int32 timeinair; //0x0048 
	float radius; //0x004C 
	float eyeheight; //0x0050 
	float maxeyeheight; //0x0054 
	float aboveeye; //0x0058 
	unsigned char inwater; //0x005C 
	bool onfloor; //0x005D 
	bool onladder; //0x005E 
	bool jumpnext; //0x005F 
	bool jumpd; //0x0060 
	bool crouchedinair; //0x0061 
	bool trycrouch; //0x0062 
	bool cancollide; //0x0063 
	bool stuck; //0x0064 
	bool scoping; //0x0065 
private:
	char pad_0x0066[0x2]; //0x0066 (this is an issue with C++ so these two bytes are never actually used in the game)
public:
	__int32 lastjump; //0x0068 
	float lastjumpheight; //0x006C 
	__int32 lastsplash; //0x0070 
	char move; //0x0074 
	char strafe; //0x0075 
private:
	char pad_0x0076[0x2]; //0x0076 (this is just an issue with C++ so these two bytes are never actually used in the game)
public:
	float eyeheightvel; //0x0078 
	__int32 last_pos; //0x007C 
private:
	char pad_0x0080[0x6C]; //0x0080 (not sure what these are but I'll map them out later)
public:
	__int16 Health; //0x00EC 
};