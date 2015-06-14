#ifndef __RUNTIMEPARAM_H__
#define __RUNTIMEPARAM_H__

#include "ServerModel.h"
#include "HeroModel.h"

class RuntimeParam
{
public:
	static RuntimeParam* getInstance();
	ServerModel* m_currentServer;
	HeroModel* m_currentHero;

private:
	static RuntimeParam* _instance;

	RuntimeParam();
	~RuntimeParam();
};


#endif /* defined(__RuntimeParam__) */