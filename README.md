# dds-requestreply
A request-reply example using vanilla DDS

## Description
A server and a client process exchanging one request and a reply. Note that DDS is not a client-server technology but rather acts like a realtime distributed database. To 'emulate' request reply, this example uses a request & reply topic.

## Building
A simple build.sh file is included that builds the project. Note that the build.sh file is written for [OpenSplice](https://github.com/PrismTech/opensplice).

## Usage
Run the following commands:
```
./server &
./client
```
Output:
```
 >> request: 0, 'Hello'
 >> reply: 0, 'World'
```
