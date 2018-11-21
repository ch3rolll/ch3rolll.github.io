# Spatial searching algos and tools

## Intro
Processing and displaying spatial data at scale, there’s no concept more useful and important than a spatial index.

Spatial indices are a family of algorithms that arrange geometric data for efficient search. For example, doing queries like “return all buildings in this area”, “find 1000 closest gas stations to this point”, and returning results within milliseconds even when searching millions of objects.

### Tools build by Mapbox (JS)
- rbush
- rbush-knn
- kdbush
- geokdbush

Source:
(https://blog.mapbox.com/a-dive-into-spatial-search-algorithms-ebd0c5e39d2a)

## Spatial search problems
Nearest neighbors and range queries. Both serve as a building block for many geometric and GIS problems.

### KNN
Intuitive way:

1. Calculate the distances from the query point to every other point.
2. Sort those points by distance.
3. Return the first K items.

### Range and radius queries
Retrieve all points inside…
- a rectangle? (range query)
- a circle? (radius query)

### Spatial trees

All spatial data structures share the same principle to enable efficient search: branch and bound. It means arranging data in a tree-like structure that allows discarding branches at once if they do not fit our search criteria.

#### R-Tree
1. 9 rectangular boxes with about the same number of points
2. take each box and sort it into 9 smaller boxes
3. repeat the same process a few more times until the final boxes contain 9 points at most

#### K-d tree
Instead of sorting the points into several boxes at each tree level, we sort them into two halves (around a median point) — either left and right, or top and bottom, alternating between x and y split on each level.
