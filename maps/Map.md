# What is HD Map?
HD Map is short for High Definition, which mean it has more detailed informations than navigation maps.

1. It is lane-level Maps, which means you have a smaller basic unit - lane, rather than road. So the topology/association are based on lanes.  For example, for Highways in China, the speed limits differ from lanes. From left to right, the speed limits are 110-120, 90-110, 70-90.

2. How detailed you express an object (lane-marking, symbols, traffic-signs, traffic lights)? Take stop signs for instance, you will get the 3D location, the height of the pole, the color, the shape, the category, and the content of the sign. And of course, the association of the sign to the related lane/lanes.

3. It can also store you memory, which is a fusion result of all history info. What ppl usually do is they take fused lidar/camera point clouds, project to 2D space, could be ground or the side. And query that info when you drive around the area to get a more precise localization.

4. So of course, the size would be 100X larger, which increase the complexity and runtime on quering the data.

# What does HD Map do?

1. Map validation. Validate the map data delivered from map vendors. Validate the relative accuracy, data continuity(curvature, slope) road-connectivity, rso-lane association
2. Map matching. Given a vehicle position, we need to query the database suffiently fast, which requires us to build a DB with great schema.
3. Map reconstructor. The format and data schema is not necessarily same as what we want. --> Map horizon
4. Map Horizon. Horizon's strucure has to be as generic as possbile, since we are not only dealing with Highway, but also urban. For example, how to deal with bi-directinal lane is really important.
5. Map update. The whole process has to be closed-loop to make the HD-map up-to-date. Otherwise, your memeory is not that trustworthy.


# Why HD Map?
1. HD Map is the best sensor for autonomous driving cars, which gurantees the longest range and best accuracy from fusion result. At the same time, it is fosho the best and most robust sensor in the car with longest range if we keep it up-to-date. 
2. It is so complaicated that not a single model to fit all seconarios. For example, there are so many different models: 
	- lane-based, road-based. 
	- Do you need different models for highways and urban roads?
	- Vision-based and lidar-based

3. And there is a lot of new topics for HD Maps as well. How do you fuse the new observations with your old HD map data and eventaully update your map to keep it fresh.


Opensource maps:
http://download.geofabrik.de/asia.html