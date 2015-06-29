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


	m_heros = Vector<HeroModel*>();
	m_heros.pushBack(new HeroModel(1, "Mage1", "1"));
	m_heros.pushBack(new HeroModel(2, "Mage2", "2"));
	m_heros.pushBack(new HeroModel(3, "Mage3", "3"));
	m_heros.pushBack(new HeroModel(4, "Mage4", "4"));

	m_partners = Vector<HeroModel*>();
	m_partners.pushBack(new HeroModel(1, "Partner1", "1"));
	m_partners.pushBack(new HeroModel(2, "Partner2", "2"));
	m_partners.pushBack(new HeroModel(3, "Partner3", "3"));
	m_partners.pushBack(new HeroModel(4, "Partner4", "4"));
	m_partners.pushBack(new HeroModel(5, "Partner5", "5"));
	m_partners.pushBack(new HeroModel(6, "Partner6", "6"));

	m_servers = Vector<ServerModel*>();
	m_servers.pushBack(new ServerModel(1, "1服—水", "2"));
	m_servers.pushBack(new ServerModel(2, "2服—生命", "2"));
	m_servers.pushBack(new ServerModel(3, "3服—盾", "3"));
	m_servers.pushBack(new ServerModel(4, "4服—雪", "4"));
	m_servers.pushBack(new ServerModel(5, "5服—电", "1"));
	m_servers.pushBack(new ServerModel(6, "6服—奥术", "3"));
	m_servers.pushBack(new ServerModel(7, "7服—石", "1"));
	m_servers.pushBack(new ServerModel(8, "8服—火", "1"));


}

RuntimeParam::~RuntimeParam()
{
}