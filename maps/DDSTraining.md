# DDS Training

## Day 1

### RTI overview

- Over 960 unique projects (30+ AD car company)
- RTI excels at Operational systems (Data centric)
- A next generation infra: 
1. RTI DataBus - DDS interioerability Protocol.
2. Routing Services: very broad use cases. Not mess up with different Apps
3. Persistence server
4. Security: encryption of data
- Paterns: Data-centric Request-Reply && Pub/Sub
- 

#### persistence service
1. store data in-momery or database configurable
2. ensure reliable data availability, even if publisher fails
3. update new subscribers efficiently w/o loading data writers
4. Fault tolerance benefits

#### Wireshark with RTPS Dissector

#### Qs
1. Two commonality of Operational Systems?
- mission-critical
- Data-centric

### Fundamentals

- data-centric
- Publish-sub model
- Data-centric interfaces
- API terminology
- Quality of Service

#### Decoupled applications
- Applications declare intents to publish or subscribe to a topic
- No prior knowledge about each other

#### QoS -- Quality of Service
QoS governs behavior of all objects

#### Data writer
Pub is a wrapper + QoS