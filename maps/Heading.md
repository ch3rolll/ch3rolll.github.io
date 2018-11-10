# Heading

## Definition

(Acoording to [Here](https://www.igismap.com/formula-to-find-bearing-or-heading-angle-between-two-points-latitude-longitude/))
Bearing or heading is used to define navigation generally in the field of aircraft or marine or Vehicle navigation or while working for land surveying. 

Bearing can be defined as direction or an angle, between the north-south line of earth or meridian and the line connecting the target and the reference point. 

While Heading is an angle or direction where you are currently navigating in.  This means to reach a particular destination you need to adjust your heading direction with the bearing.

## Determine left & right

Conditions | Range(Left) | Range (right)
---|---|---
heading [0, 90) | [heading, heading + 180] | 
heading [90, 180) | [heading, heading + 180]| 
heading [180, 270) | [heading, 360] + [0, heading - 180] |
heading [270, 360) | [heading, 360] + [0, heading - 180] |

## Formula

```python
def cal_heading(lat1, lon1, lat2, lon2):
'''
Input: lat1, lon1, lat2, lon2, in degrees
Output: bearing, in radian
From point1 -> point2
'''
    lat1 = radians(lat1)
    lon1 = radians(lon1)
    lat2 = radians(lat2)
    lon2 = radians(lon2)
    
    deltaLon = lon2 - lon1
    X = cos(lat2) * sin(deltaLon)
    Y = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(deltaLon)
    bearing = atan2(X, Y)
    return bearing
```

```python
def haversine(lat1, lon1, lat2, lon2):
    """
    Calculate the great circle distance between two points 
    on the earth (specified in decimal degrees)
    """
    # convert decimal degrees to radians 
    lon1, lat1, lon2, lat2 = map(radians, [lon1, lat1, lon2, lat2])

    # haversine formula 
    dlon = lon2 - lon1 
    dlat = lat2 - lat1 
    a = sin(dlat/2)**2 + cos(lat1) * cos(lat2) * sin(dlon/2)**2
    c = 2 * asin(sqrt(a)) 
    r = 6371000 # Radius of earth in meters. Use 3956 for miles
    return c * r

```


```python

def dist_lonlat(lon, lat, dist, heading):
    """
    Given a lon, lat  and heading and dist
    return a new position
    
    Example:
        dist_lonlat(-1.7297222222222224, 53.32055555555556, 2000, 90)
        (-1.6996112176328169, 53.320551765142014)
        
    """
    
    lon, lat, heading = map(math.radians, [lon, lat, heading])
    R = 6371000 # Radius of earth in meters. Use 3956 for miles
    
    phi = dist/R
    
    lat2 = math.asin(math.sin(lat) * math.cos(phi) + math.cos(lat) * math.sin(phi) * math.cos(heading))
    
    X = math.sin(heading) * math.sin(phi) * math.cos(lat)
    Y = math.cos(phi) - math.sin(lat) * math.sin(lat2)
    
    lon2 = lon + math.atan2(X, Y)
    
    return math.degrees(lon2), math.degrees(lat2)
```

## Tool
https://www.igismap.com/map-tool/bearing-angle