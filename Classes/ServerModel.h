#ifndef __SERVERMODEL_H__
#define __SERVERMODEL_H__

#include <string>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class ServerModel : public Ref
{
public:
	ServerModel();
	ServerModel(int serverID, string serverName, string state);
	~ServerModel();


	int m_serverID;
	string m_serverName;
	string m_state;
	string getStateImage();
};

#endif