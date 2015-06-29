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

	Vector<HeroModel*> m_heros;
	Vector<ServerModel*> m_servers;
	Vector<HeroModel*> m_partners;

private:
	static RuntimeParam* _instance;

	RuntimeParam();
	~RuntimeParam();
};


#endif /* defined(__RuntimeParam__) */