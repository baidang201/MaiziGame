#include "RuntimeParam.h"

RuntimeParam* RuntimeParam::_instance = nullptr;

RuntimeParam* RuntimeParam::getInstance()
{
	if(nullptr == _instance)
	{
		_instance = new RuntimeParam();
	}
	return _instance;
}

RuntimeParam::RuntimeParam()
{
	m_currentServer = new ServerModel();
	m_currentHero = new HeroModel();
}

RuntimeParam::~RuntimeParam()
{
}