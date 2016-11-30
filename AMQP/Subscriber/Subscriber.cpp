#include<iostream>
#include<SimpleAmqpClient\SimpleAmqpClient.h>

using namespace std;
using namespace AmqpClient;

void main(){
	string in_message = "hello world";
	string EXCHANGE_NAME = "log";
	string QUEUE_NAME = "test_queue";
	Channel::ptr_t channel = Channel::Create();
	channel->DeclareQueue(QUEUE_NAME);
	channel->BindQueue(QUEUE_NAME, EXCHANGE_NAME, "");
	cout << "[*] Waiting for logs. To exit press CTRL+C" << endl;
	string consumer = channel->BasicConsume(QUEUE_NAME, "", true, false);
	Envelope::ptr_t received;
	while (1) {
		bool a = channel->BasicConsumeMessage(consumer, received, 100);
		if (a) {
			string y = received->Message()->Body();
			cout << y << endl;
		}
	}
}