#include "HeroModel.h"

HeroModel::HeroModel()
{

}

HeroModel::HeroModel(int heroID, string heroName, string state)
{
	//todo(liyh) Éú³ÉºêÄ£°å£¿   m_#£¨£© = £¨£©
	m_heroID = heroID;
	m_heroName = heroName;
	m_state = state;

	m_HP = 200;
	m_MP = 300;
	m_attack = 20;
	m_defense = 30;
}

HeroModel::~HeroModel()
{

}

string HeroModel::getHeroImage()
{
	return "Hero/Hero" + this->m_state + ".jpg";
}