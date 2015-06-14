#include "ServerModel.h"

ServerModel::ServerModel()
{

}

ServerModel::ServerModel(int serverID, string serverName, string state)
{
	//todo(liyh) Éú³ÉºêÄ£°å£¿   m_#£¨£© = £¨£©
	m_serverID = serverID;
	m_serverName = serverName;
	m_state = state;
}

ServerModel::~ServerModel()
{

}

string ServerModel::getStateImage()
{
	return "Login/selectServer_state" + this->m_state + ".png";
}