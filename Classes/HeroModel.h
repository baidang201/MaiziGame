#ifndef __HEROMODEL_H__
#define __HEROMODEL_H__

#include <string>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class HeroModel : public Ref
{
public:
	HeroModel();
	HeroModel(int heroID, string heroName, string state);
	~HeroModel();


	int m_heroID;
	string m_heroName;
	string m_state;
	string getHeroImage();
};

#endif