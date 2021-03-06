 ///
 /// @file    test_server.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-25 22:03:48
 ///
 
#include "MyConf.h"
#include "SpellcorrectServer.h"
#include "CacheManager.h"
#include <iostream>

int main(void)
{

	MyConf::getInstance()->init("/home/xisha/00文本纠错/conf/my.conf");
	//MyConf::getInstance()->init("./conf/my.conf"); //相对路径读取文件出错
	MyConf::getInstance()->show();

	CacheManager::initCache(wd::str2int(MyConf::getInstance()->getMap()["my_thread_num"]),
							MyConf::getInstance()->getMap()["my_cache"]);
	CacheManager::getCache(0).debug();

	wd::SpellcorrectServer server;
	server.start();

	return 0;
}
