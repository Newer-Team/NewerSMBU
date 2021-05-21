
#pragma once

#define IMPORT_STATE(CLASS, NAME) static State<Class> StateID_##NAME

#define DECLARE_STATE(CLASS, NAME) \
	static State<CLASS> StateID_##NAME; \
	void beginState_##NAME(); \
	void executeState_##NAME(); \
	void endState_##NAME();
	
#define CREATE_STATE(CLASS, NAME) \
	State<CLASS> CLASS::StateID_##NAME \
		(&CLASS::beginState_##NAME, \
		&CLASS::executeState_##NAME, \
		&CLASS::endState_##NAME);

extern u32 CurrentStateID;
		
class StateBase {
	public:
	u32 id;
	
	virtual ~StateBase();
	virtual u32 getStateId();
};

template <class TOwner>
class State : public StateBase {
	public:
	typedef void (TOwner::*funcptr)();
	State(funcptr begin, funcptr execute, funcptr end) {
		id = ++CurrentStateID;
		beginState = begin;
		executeState = execute;
		endState = end;
	};

	funcptr beginState;
	funcptr executeState;
	funcptr endState;
};

template <class TOwner>
class StateMgrVirt {
	virtual void vf0C(); //deleted;
	virtual void *beginState(State<TOwner> *);
	virtual void endState();
	virtual void *changeState(State<TOwner> *);
	virtual void clearState(void *);
	virtual void beginRelated(void *);
};

template <class TOwner> class StateMgr;

class StateClass {
	public:
	void *stateMgr;
	u32 beginSomething;
	u32 executeSomething;
	u32 defaultSomething;
	
	void executeState();
};

template <class TOwner>
class StateMgrBase : public StateMgrVirt<TOwner> {
	public:
	void * executeRelated;
	TOwner *owner;
	u32 _C;
	StateClass stateClass;
	u32 _20;
};

template <class TOwner>
class StateMgr : public StateMgrBase<TOwner> {
	public:
		void *_24;
};
