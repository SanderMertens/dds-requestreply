#include "helloworld_DCPS.hpp"

class DataHandler {
public:
    DataHandler() { } ;
    void operator() (dds::sub::DataReader<Hello::World>& dr) {
        /* Take all received samples from reader */
        dds::sub::LoanedSamples<Hello::World> samples = dr.take();
    } 
};

int main(int argc, char *arv[])
{
    /* Create DomainParticipant - this connects the application to DDS */
    dds::domain::DomainParticipant dp( 0 );

    /* Create a topic - this is like a db table or queue (depending on QoS). */
    dds::topic::qos::TopicQos qos = dp.default_topic_qos() 
        << dds::core::policy::History::KeepAll() /* Setup as a queue - don't overwrite responses */
        << dds::core::policy::Reliability::Reliable(); /* Send data reliably */
    dds::topic::Topic<Hello::World> topicRequest( dp, "Request", qos );
    dds::topic::Topic<Hello::World> topicReply( dp, "Reply", qos );

    /* Create a datareader and datawriter for reading and writing to 'HelloWorld' */
    dds::sub::qos::DataReaderQos drQos = qos;
    dds::sub::DataReader<Hello::World> dr( dp, topicRequest, drQos );
    dds::pub::DataWriter<Hello::World> dw( dp, topicReply, qos );

    /* Create a readcondition which triggers on all samples */
    dds::sub::cond::ReadCondition rc(dr, dds::sub::status::DataState(), DataHandler()) ;

    /* Create a waitset that will block until data is received */
    dds::core::cond::WaitSet ws;

    /* Add the readcondition to a waitset */
    ws += rc;

    /* Wait for a client to request 'Hello' */
    ws.dispatch();

    /* Reply with 'World' */
    dw << Hello::World(0, "World");
    
    return 0;
}
