#UDP broadcast client/server Sample code
This sample demo how to broadcast and receive udp packets.

# Code Description

#How to test
1. build code
<pre>$ mk.sh build</pre>

2. check `build` directory and find out build result as below: 
<pre>
udp_client - application which broadcast udp packets
udp_server - application which receive udp packets
lib_common.so - shared library
</pre>

3. type `mk.sh test` to test. you will see test result like below:
<pre>$ mk.sh test </pre>

4. remove all build result
<pre>$ mk.sh clean</pre> 


