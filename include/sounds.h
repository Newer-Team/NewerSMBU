
#pragma once

#include "nw4f.h"

class SoundActor : public nw::snd::SoundActor {
	public:
	~SoundActor();	
	virtual void vf34(const char *soundName, u32);

	u32 _64;
	u32 _68;
	u32 _6C;
	u32 _70;
};

class UsedByMovingSoundActor : public sead::IDisposer {
	public:
	u32 _10;
	float _14;
};

class MovingSoundActor : public SoundActor {
	public:
	float _74;
	u32 _78;
	float _7C;
	float _80;
	UsedByMovingSoundActor _84[6];
	u32 _114[2];
};

class BasicSoundActor : public SoundActor {
	public:
		static BasicSoundActor *instance;

		void playSound(const char *soundName, Vec2 *screenPos, u32);
};

class AmbientSoundActor : public SoundActor {
	public:
	~AmbientSoundActor();
	virtual void vf3C(); //deleted
	virtual void vf44(); //deleted
	virtual void updateSound(const char *soundName, u32); //deleted
	virtual void updateSound(const char *soundName, u32, u32); //deleted
};

class AmbientSoundPlayer : public AmbientSoundActor {
	public:
	static AmbientSoundPlayer *instance;
	
	void updateSound(const char *soundName, u32);
	void updateSound(const char *soundName, u32, u32);
};

class SoundSystem {
	/* incomplete */
	public:
		static SoundSystem *instance;

		nw::snd::SoundArchive *getSoundArchive();
		void playSound(const char *, u32);
};
