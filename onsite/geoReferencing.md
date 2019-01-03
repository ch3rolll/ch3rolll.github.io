# Uber

- [Here](https://eng.uber.com/h3/)

## Uber H3

### Why hexagons?

1. hexagons minimize the quantization error introduced when users move through a city. 
2.  Same distance to adjacent eight areas.
3. Alternating CW CCW 19.1˚ rotations of 7 children 1/7th the area.
4. A global grid system usually requires at least two things: a map projection and a grid laid on top of the map. Which causes the distortion. The best project is Dymaxion


### Why H3?

1.  Indexing Functions: geo2H3(), H3ToGeo(), H3toGeoBoundary().




# Google S2 square


# Lyft

## Georeferencing
### Constrians
1. countours
2. pickup time

### Database

Lyft used mongoDB at the begining.


### Algos
#### Longitudinal Sorting

if we sorted the outer and inner loops by longitude, we could short circuit out of that loop when we’ve passed this maximum distance

#### Rerouting

- Do NOT change the next stop

#### Route Swapping
