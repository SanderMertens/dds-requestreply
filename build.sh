idlpp -lisocpp -S helloworld.idl -d gen
g++ client.cpp gen/*.cpp -I gen -g -m32 -I$OSPL_HOME/include -I$OSPL_HOME/include/sys -I$OSPL_HOME/include/dcps/C++/isocpp -I$OSPL_HOME/include/dcps/C++/SACPP -L$OSPL_HOME/lib -ldcpsisocpp -lddskernel -o client
g++ server.cpp gen/*.cpp -I gen -g -m32 -I$OSPL_HOME/include -I$OSPL_HOME/include/sys -I$OSPL_HOME/include/dcps/C++/isocpp -I$OSPL_HOME/include/dcps/C++/SACPP -L$OSPL_HOME/lib -ldcpsisocpp -lddskernel -o server
