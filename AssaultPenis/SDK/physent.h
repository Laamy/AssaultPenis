#pragma once

#define loopi(NUMGUNS) for (int i = 0; i < NUMGUNS; i++)
enum { GUN_KNIFE = 0, GUN_PISTOL, GUN_CARBINE, GUN_SHOTGUN, GUN_SUBGUN, GUN_SNIPER, GUN_ASSAULT, GUN_GRENADE, GUN_AKIMBO, NUMGUNS };

class physent { // i might make a bhop
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
	bool crouching; //0x0061 
	bool crouchedinair; //0x0062 
	bool trycrouch; //0x0063 
	bool cancollide; //0x0064 
	bool stuck; //0x0065 
	bool scoping; //0x0066 
private:
	char pad_0x0066[0x1]; //0x0066 (this is an issue with C++ so this byte is never actually used in the game)
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
	char pad_0x0080[0x6C]; //0x0080 (this is most likely dynent)
public:
	int health; //0x00EC 
	int armour; //0x00F0
	int primary; //0x00F4
	int nextprimary; //0x00F8
	int gunselect; //0x00FC
	bool akimbo; //0x0100
	int ammo[NUMGUNS]; //0x0104
	int mag[NUMGUNS]; //0x0118
	int gunwait[NUMGUNS]; //0x012C
	int pstatshots[NUMGUNS]; //0x0140
	int pstatdamage[NUMGUNS]; //0x0154

public: // Functions
	__forceinline bool isAlive() {
		return health > 0;
	}

	// https://github.com/assaultcube/AC/blob/master/source/src/entity.h#L149C14-L149C14
	__forceinline void resetinterp()
	{
		newpos = origin;
		newpos.z -= eyeheight;
		deltapos = Vector3<float>(0, 0, 0);
	}

	// https://github.com/assaultcube/AC/blob/master/source/src/entity.h#L156C6-L156C6
	__forceinline void reset()
	{
		vel.x = vel.y = vel.z = eyeheightvel = 0.0f;
		move = strafe = 0;
		timeinair = lastjump = lastsplash = 0;
		onfloor = onladder = inwater = jumpnext = jumpd = crouching = crouchedinair = trycrouch = stuck = false;
		last_pos = 0;
	}

	// https://github.com/assaultcube/AC/blob/master/source/src/entity.h#L326
	__forceinline void respawn()
	{
		health = 100;
		armour = 0;
		gunselect = 0; // GUN_PISTOL, GUN_KNIFE
		akimbo = false;
		loopi(NUMGUNS) ammo[i] = mag[i] = gunwait[i] = 0;
		ammo[1] = mag[1] = 1;
	}
};