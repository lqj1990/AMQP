#include<iostream>
#include<SimpleAmqpClient\SimpleAmqpClient.h>
#include<windows.h>
using namespace std;
using namespace AmqpClient;
void main() {
	Channel::ptr_t channel = Channel::Create();
	string QUEUE_NAME = "hello";
	BasicMessage::ptr_t message = BasicMessage::Create("message body");
	channel->DeclareQueue(QUEUE_NAME);
	string consumer = channel->BasicConsume(QUEUE_NAME, "", true, false);
	cout << " [*] Waiting for messages. To exit press CTRL+C" << endl;
	Envelope::ptr_t received;
	while (1) {
		bool a = channel->BasicConsumeMessage(consumer, received, 100);
		if (a) {
			string y = received->Message()->Body();
			cout << y << endl;
		}
	}
}