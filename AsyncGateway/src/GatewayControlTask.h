/*
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 tomoaki@tomy-tech.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *  Created on: 2015/05/01
 *    Modified:
 *      Author: Tomoaki YAMAGUCHI
 *     Version: 0.0.0
 */

#ifndef GATEWAYCONTROLTASK_H_
#define GATEWAYCONTROLTASK_H_

#include "lib/ZBStack.h"
#include "lib/ProcessFramework.h"
#include "GatewayResourcesProvider.h"
using namespace tomyAsyncGateway;
/*=====================================
        Class GatewayControlTask
 =====================================*/
class GatewayControlTask : public Thread{
	MAGIC_WORD_FOR_TASK;
public:
	GatewayControlTask(GatewayResourcesProvider* res);
	~GatewayControlTask();

	void run();
private:
	EventQue<Event>* _eventQue;
	GatewayResourcesProvider* _res;
	char _printBuf[512];
	uint8_t _protocol;
	uint8_t _gatewayId;
	string _loginId;
	string _password;
	bool _secure;
	bool _stableNetwork;

	void handleClientMessage(Event*);
	void handleBrokerMessage(Event*);

	void handleSnPublish(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnSubscribe(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnUnsubscribe(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnPingReq(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnPubAck(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnConnect(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnWillTopic(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnWillMsg(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnDisconnect(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnRegister(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnPubRec(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnPubRel(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);
	void handleSnPubComp(Event* ev, ClientNode* clnode, MQTTSnMessage* msg);

	void handlePuback(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	void handlePingresp(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	void handleSuback(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	void handleUnsuback(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	void handleConnack(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	void handlePublish(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	void handleDisconnect(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	void handlePubRec(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	void handlePubRel(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	void handlePubComp(Event* ev, ClientNode* clnode, MQTTMessage* msg);
	char* msgPrint(MQTTSnMessage* msg);
	char* msgPrint(MQTTMessage* msg);
};

#endif /* GATEWAYCONTROLTASK_H_ */