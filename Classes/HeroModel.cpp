#include "HeroModel.h"

HeroModel::HeroModel()
{

}

HeroModel::HeroModel(int heroID, string heroName, string state)
{
	//todo(liyh) ���ɺ�ģ�壿   m_#���� = ����
	m_heroID = heroID;
	m_heroName = heroName;
	m_state = state;
}

HeroModel::~HeroModel()
{

}

string HeroModel::getHeroImage()
{
	return "Hero/Hero" + this->m_state + ".jpg";
}