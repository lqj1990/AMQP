#include<iostream>
#include<SimpleAmqpClient\SimpleAmqpClient.h>
using namespace std;
using namespace AmqpClient;

void main() {
	string in_message = "hello world";
	string EXCHANGE_NAME = "log";
	string QUEUE_NAME = "test_queue";
	Channel::ptr_t channel = Channel::Create();
	channel->DeclareExchange(EXCHANGE_NAME,"fanout");
	BasicMessage::ptr_t message = BasicMessage::Create(in_message);
	channel->BasicPublish("", QUEUE_NAME, message, false, false);
	cout << " [x] Sent 'Hello World!'" << endl;
}
